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

GWint gwSlider(GWslider_t *p)
{
	GWint retcode = 0;

	if (p == NULL)
		return retcode;
	
	/* Check for hot */
	GWint res = 0;

	gwTestMouseHit(&res, (GWfloat)p->widget.position.x, (GWfloat)p->widget.position.y, 
		(GWfloat)p->widget.width, (GWfloat)p->widget.height);

	if (res) {
		g_gwContext.id_hot = p->widget.id;

		/* Check for active */
		if (g_gwContext.mouse.button[GW_MOUSE_BUTTON_LEFT] == GW_BUTTON_STATE_DOWN) {
			if (g_gwContext.id_active == 0) {
				g_gwContext.id_active = p->widget.id;
			} 
			else if (g_gwContext.id_active == p->widget.id) {
				retcode = 1;
				p->value = (GWfloat)(g_gwContext.mouse.position.x - p->widget.position.x) / (GWfloat)p->widget.width;
			}
		}
	}

	GWfloat nl0x = (GWfloat)p->widget.position.x + (GWfloat)p->widget.width;
	GWfloat nl0y = (GWfloat)p->widget.position.y + (GWfloat)p->widget.height;

	/* Draw */	
	gwDrawBox(	(GWfloat)p->widget.position.x, (GWfloat)p->widget.position.y,
				(GWfloat)p->widget.width,	(GWfloat)p->widget.height,
				&(p->widget.color[GW_WIDGET_COLOR_BACKGROUND_A]),
				&(p->widget.color[GW_WIDGET_COLOR_BACKGROUND_B]));

	gwDrawLine(	nl0x, nl0y, (GWfloat)p->widget.position.x, nl0y, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));
			
	gwDrawLine(	nl0x, nl0y, nl0x, (GWfloat)p->widget.position.y, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));

	gwDrawLine(	(GWfloat)p->widget.position.x, (GWfloat)p->widget.position.y,
				(GWfloat)p->widget.position.x, nl0y, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B]));

	gwDrawLine(	(GWfloat)p->widget.position.x, (GWfloat)p->widget.position.y, 
				nl0x, (GWfloat)p->widget.position.y, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B]));
	
	GWfloat hwidt  = p->widget.width / 25.f;
	GWfloat hwidt2 = hwidt / 2.f;
	GWfloat hposx = (GWfloat)p->widget.position.x + (GWfloat)p->value * p->widget.width - hwidt2 + 1;
	GWfloat hposxmax = (GWfloat)p->widget.position.x + (GWfloat)p->widget.width - hwidt - 2.f;

	GWfloat hx = hposx > (GWfloat)p->widget.position.x + 2.f ? 
		(hposx > hposxmax ? hposxmax : hposx) : (GWfloat)p->widget.position.x + 1.f;
	GWfloat hy = (GWfloat)p->widget.position.y + 2.f;
	GWfloat hw = hwidt;
	GWfloat hh = (GWfloat)p->widget.height - 4.f;

	GWfloat nl1x = hx + hw;
	GWfloat nl1y = hy + hh;

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
