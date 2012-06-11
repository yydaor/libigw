/*

	This file is part of libigw.

	button.c
	Button widget

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
#include "button.h"

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

int gwButton(GWbutton_t *p)
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
				retcode = 1;
				g_gwContext.id_active = p->widget.id;
			}
		}
	}
	
	/* Draw */
	if (g_gwContext.id_hot == p->widget.id) {
		if (g_gwContext.id_active == p->widget.id) { /* Hot, Active */
			gwDrawBox(	(float)p->widget.position.x, 
						(float)p->widget.position.y,
						(float)p->widget.width,
						(float)p->widget.height,
						&(p->widget.color[GW_WIDGET_COLOR_FOREGROUND_A_ACTIVE]),
						&(p->widget.color[GW_WIDGET_COLOR_FOREGROUND_B_ACTIVE]));

			gwDrawLine(	(float)p->widget.position.x + (float)p->widget.width, 
						(float)p->widget.position.y + (float)p->widget.height, 
						(float)p->widget.position.x, 
						(float)p->widget.position.y + (float)p->widget.height, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B_ACTIVE]));
			
			gwDrawLine(	(float)p->widget.position.x + (float)p->widget.width, 
						(float)p->widget.position.y + (float)p->widget.height, 
						(float)p->widget.position.x + (float)p->widget.width,
						(float)p->widget.position.y, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B_ACTIVE]));

			gwDrawLine(	(float)p->widget.position.x,
						(float)p->widget.position.y,
						(float)p->widget.position.x,
						(float)p->widget.position.y + (float)p->widget.height, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A_ACTIVE]));

			gwDrawLine(	(float)p->widget.position.x,
						(float)p->widget.position.y, 
						(float)p->widget.position.x + (float)p->widget.width,
						(float)p->widget.position.y, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A_ACTIVE]));
	
			gwDrawText(	(float)p->widget.position.x + (float)p->widget.width / 2.f - gwTextLength(p->text) / 2.f, 
						(float)p->widget.position.y + (float)p->widget.height / 2.f,
						&(p->widget.color[GW_WIDGET_COLOR_TEXT_ACTIVE]), p->text);

		} else { /* Hot, Not active */
			gwDrawBox(	(float)p->widget.position.x,
						(float)p->widget.position.y,
						(float)p->widget.width, 
						(float)p->widget.height,
						&(p->widget.color[GW_WIDGET_COLOR_FOREGROUND_A_HOT]),
						&(p->widget.color[GW_WIDGET_COLOR_FOREGROUND_B_HOT]));

			gwDrawLine(	(float)p->widget.position.x + (float)p->widget.width, 
						(float)p->widget.position.y + (float)p->widget.height, 
						(float)p->widget.position.x,
						(float)p->widget.position.y + (float)p->widget.height, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A_HOT]));
			
			gwDrawLine(	(float)p->widget.position.x + (float)p->widget.width, 
						(float)p->widget.position.y + (float)p->widget.height, 
						(float)p->widget.position.x + (float)p->widget.width, 
						(float)p->widget.position.y, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A_HOT]));

			gwDrawLine(	(float)p->widget.position.x,
						(float)p->widget.position.y,
						(float)p->widget.position.x,
						(float)p->widget.position.y + (float)p->widget.height, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B_HOT]));

			gwDrawLine(	(float)p->widget.position.x,
						(float)p->widget.position.y, 
						(float)p->widget.position.x + (float)p->widget.width,
						(float)p->widget.position.y,
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B_HOT]));
	
			gwDrawText(	(float)p->widget.position.x + (float)p->widget.width / 2.f - gwTextLength(p->text) / 2.f, 
						(float)p->widget.position.y + (float)p->widget.height / 2.f,
						&(p->widget.color[GW_WIDGET_COLOR_TEXT_HOT]), p->text);
		}
	} else {
		if (g_gwContext.id_active == p->widget.id) { /* Not hot, Active */
			gwDrawBox(	(float)p->widget.position.x,
						(float)p->widget.position.y,
						(float)p->widget.width,
						(float)p->widget.height,
						&(p->widget.color[GW_WIDGET_COLOR_FOREGROUND_A_ACTIVE]),
						&(p->widget.color[GW_WIDGET_COLOR_FOREGROUND_B_ACTIVE]));

			gwDrawLine(	(float)p->widget.position.x + (float)p->widget.width,
						(float)p->widget.position.y + (float)p->widget.height, 
						(float)p->widget.position.x, 
						(float)p->widget.position.y + (float)p->widget.height, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B_ACTIVE]));
			
			gwDrawLine(	(float)p->widget.position.x + (float)p->widget.width,
						(float)p->widget.position.y + (float)p->widget.height, 
						(float)p->widget.position.x + (float)p->widget.width,
						(float)p->widget.position.y, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B_ACTIVE]));

			gwDrawLine(	(float)p->widget.position.x,
						(float)p->widget.position.y,
						(float)p->widget.position.x,
						(float)p->widget.position.y + (float)p->widget.height, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A_ACTIVE]));

			gwDrawLine(	(float)p->widget.position.x,
						(float)p->widget.position.y, 
						(float)p->widget.position.x + (float)p->widget.width,
						(float)p->widget.position.y, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A_ACTIVE]));
	
			gwDrawText(	(float)p->widget.position.x + (float)p->widget.width / 2.f - gwTextLength(p->text) / 2.f, 
						(float)p->widget.position.y + (float)p->widget.height / 2.f,
						&(p->widget.color[GW_WIDGET_COLOR_TEXT_HOT]), p->text);

		} else { /* Not hot, Not active */
			gwDrawBox(	(float)p->widget.position.x,
						(float)p->widget.position.y,
						(float)p->widget.width,
						(float)p->widget.height,
						&(p->widget.color[GW_WIDGET_COLOR_FOREGROUND_A]), 
						&(p->widget.color[GW_WIDGET_COLOR_FOREGROUND_B]));

			gwDrawLine(	(float)p->widget.position.x + (float)p->widget.width,
						(float)p->widget.position.y + (float)p->widget.height, 
						(float)p->widget.position.x,
						(float)p->widget.position.y + (float)p->widget.height, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B]));
			
			gwDrawLine(	(float)p->widget.position.x + (float)p->widget.width,
						(float)p->widget.position.y + (float)p->widget.height, 
						(float)p->widget.position.x + (float)p->widget.width,
						(float)p->widget.position.y, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B]));

			gwDrawLine(	(float)p->widget.position.x,
						(float)p->widget.position.y,
						(float)p->widget.position.x,
						(float)p->widget.position.y + (float)p->widget.height, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));

			gwDrawLine(	(float)p->widget.position.x,
						(float)p->widget.position.y, 
						(float)p->widget.position.x + (float)p->widget.width,
						(float)p->widget.position.y, 
						&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));
	
			gwDrawText(	(float)p->widget.position.x + (float)p->widget.width / 2.f - gwTextLength(p->text) / 2.f, 
						(float)p->widget.position.y + (float)p->widget.height / 2.f,
						&(p->widget.color[GW_WIDGET_COLOR_TEXT]), p->text);
		}
	}

	return retcode;
}

#ifdef __cplusplus
	}   /* extern "C" */
#endif /* __cplusplus */
