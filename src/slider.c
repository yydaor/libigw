/*

	This file is part of libigw.

	slider.c
	Slider widget

	Copyright (C) 2012
	Papadopoulos Nikolaos

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 3 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General
	Public License along with this program; if not, write to the
	Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
	Boston, MA 02110-1301 USA

*/

#include <string.h>
#include "type.h"
#include "callback.h"
#include "igw.h"
#include "slider.h"

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

int gwSlider(GWslider_t *p)
{
	int retcode = 0;

	if (p == NULL)
		return retcode;
	
	/* Check for hot */
	if (gwTestMouseHit(	(float)p->widget.position.x, (float)p->widget.position.y, 
						(float)p->widget.width, (float)p->widget.height)) {
		g_gwContext.id_hot = p->widget.id;

		/* Check for active */
		if (g_gwContext.mouse.button[GW_MOUSE_BUTTON_LEFT] == GW_BUTTON_STATE_DOWN) {
			if (g_gwContext.id_active == 0) {
				g_gwContext.id_active = p->widget.id;
			} 
			else if (g_gwContext.id_active == p->widget.id) {
				retcode = 1;
				p->value = (float)(g_gwContext.mouse.position.x - p->widget.position.x) / (float)p->widget.width;
			}
		}
	}

	float nl0x = (float)p->widget.position.x + (float)p->widget.width;
	float nl0y = (float)p->widget.position.y + (float)p->widget.height;

	/* Draw */	
	gwDrawBox(	(float)p->widget.position.x, (float)p->widget.position.y,
				(float)p->widget.width,	(float)p->widget.height,
				&(p->widget.color[GW_WIDGET_COLOR_BACKGROUND_A]),
				&(p->widget.color[GW_WIDGET_COLOR_BACKGROUND_B]));

	gwDrawLine(	nl0x, nl0y, (float)p->widget.position.x, nl0y, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));
			
	gwDrawLine(	nl0x, nl0y, nl0x, (float)p->widget.position.y, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));

	gwDrawLine(	(float)p->widget.position.x, (float)p->widget.position.y,
				(float)p->widget.position.x, nl0y, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B]));

	gwDrawLine(	(float)p->widget.position.x, (float)p->widget.position.y, 
				nl0x, (float)p->widget.position.y, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B]));
	
	float hwidt  = p->widget.width / 25.f;
	float hwidt2 = hwidt / 2.f;
	float hposx = (float)p->widget.position.x + (float)p->value * p->widget.width - hwidt2 + 1;
	float hposxmax = (float)p->widget.position.x + (float)p->widget.width - hwidt - 2.f;

	float hx = hposx > (float)p->widget.position.x + 2.f ? 
		(hposx > hposxmax ? hposxmax : hposx) : (float)p->widget.position.x + 1.f;
	float hy = (float)p->widget.position.y + 2.f;
	float hw = hwidt;
	float hh = (float)p->widget.height - 4.f;

	float nl1x = hx + hw;
	float nl1y = hy + hh;

	if (g_gwContext.id_hot == p->widget.id) {
		gwDrawBox(	hx,	hy, hw, hh,
						&(p->widget.color[GW_WIDGET_COLOR_FOREGROUND_A_HOT]),
						&(p->widget.color[GW_WIDGET_COLOR_FOREGROUND_B_HOT]));
	} else {
		gwDrawBox(	hx,	hy, hw, hh,
					&(p->widget.color[GW_WIDGET_COLOR_FOREGROUND_A]),
					&(p->widget.color[GW_WIDGET_COLOR_FOREGROUND_B]));		
	}

	gwDrawLine(	nl1x, nl1y, hx, nl1y, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B]));
			
	gwDrawLine(	nl1x, nl1y, nl1x, hy, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B]));

	gwDrawLine(	hx, hy, hx, nl1y, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));

	gwDrawLine(	hx, hy, nl1x, hy, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));

	return retcode;
}

#ifdef __cplusplus
	}   /* extern "C" */
#endif /* __cplusplus */
