/*

	This file is part of libigw.

	checkbox.c
	Checkbox widget

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
#include "checkbox.h"

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

GWint gwCheckbox(GWcheckbox_t *p)
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
				retcode = 1;
				p->status = (p->status == 1 ? 0 : 1);
				g_gwContext.id_active = p->widget.id;
			}
		}
	}

	/* Draw */
	if (g_gwContext.id_hot == p->widget.id) {
		if (g_gwContext.id_active == p->widget.id) { /* Hot, Active */
			gwDrawBox(	(GWfloat)p->widget.position.x, 
						(GWfloat)p->widget.position.y,
						(GWfloat)p->widget.width,
						(GWfloat)p->widget.height,
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BACKGROUND_A_ACTIVE : GW_WIDGET_COLOR_FOREGROUND_A]),
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BACKGROUND_B_ACTIVE : GW_WIDGET_COLOR_FOREGROUND_B]));

			gwDrawLine(	(GWfloat)p->widget.position.x + (GWfloat)p->widget.width, 
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						(GWfloat)p->widget.position.x, 
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_B_ACTIVE : GW_WIDGET_COLOR_BEVEL_B]));
			
			gwDrawLine(	(GWfloat)p->widget.position.x + (GWfloat)p->widget.width, 
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						(GWfloat)p->widget.position.x + (GWfloat)p->widget.width,
						(GWfloat)p->widget.position.y, 
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_B_ACTIVE : GW_WIDGET_COLOR_BEVEL_B]));	

			gwDrawLine(	(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y,
						(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_A_ACTIVE : GW_WIDGET_COLOR_BEVEL_A]));

			gwDrawLine(	(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y, 
						(GWfloat)p->widget.position.x + (GWfloat)p->widget.width,
						(GWfloat)p->widget.position.y, 
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_A_ACTIVE : GW_WIDGET_COLOR_BEVEL_A]));

			if(p->status) {
				gwDrawLine(	p->widget.position.x + 1,
							p->widget.position.y + 1,
							p->widget.position.x + p->widget.width - 2,
							p->widget.position.y + p->widget.height - 2,
							&(p->widget.color[GW_WIDGET_COLOR_TEXT_ACTIVE]));
				
				gwDrawLine(	p->widget.position.x + 1,
							p->widget.position.y + p->widget.height - 2,
							p->widget.position.x + p->widget.width - 2,
							p->widget.position.y + 1,
							&(p->widget.color[GW_WIDGET_COLOR_TEXT_ACTIVE]));
			}

		} else { /* Hot, Not active */
			gwDrawBox(	(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y,
						(GWfloat)p->widget.width, 
						(GWfloat)p->widget.height,
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BACKGROUND_A_ACTIVE : GW_WIDGET_COLOR_FOREGROUND_A_HOT]),
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BACKGROUND_B_ACTIVE : GW_WIDGET_COLOR_FOREGROUND_B_HOT]));

			gwDrawLine(	(GWfloat)p->widget.position.x + (GWfloat)p->widget.width, 
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_B_ACTIVE : GW_WIDGET_COLOR_BEVEL_B]));
			
			gwDrawLine(	(GWfloat)p->widget.position.x + (GWfloat)p->widget.width, 
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						(GWfloat)p->widget.position.x + (GWfloat)p->widget.width, 
						(GWfloat)p->widget.position.y, 
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_B_ACTIVE : GW_WIDGET_COLOR_BEVEL_B]));

			gwDrawLine(	(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y,
						(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height,
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_A_ACTIVE : GW_WIDGET_COLOR_BEVEL_A]));

			gwDrawLine(	(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y, 
						(GWfloat)p->widget.position.x + (GWfloat)p->widget.width,
						(GWfloat)p->widget.position.y,
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_A_ACTIVE : GW_WIDGET_COLOR_BEVEL_A]));
	
			if(p->status) {
				gwDrawLine(	p->widget.position.x + 1,
							p->widget.position.y + 1,
							p->widget.position.x + p->widget.width - 2,
							p->widget.position.y + p->widget.height - 2,
							&(p->widget.color[GW_WIDGET_COLOR_TEXT_HOT]));
				
				gwDrawLine(	p->widget.position.x + 1,
							p->widget.position.y + p->widget.height - 2,
							p->widget.position.x + p->widget.width - 2,
							p->widget.position.y + 1,
							&(p->widget.color[GW_WIDGET_COLOR_TEXT_HOT]));
			}
		}

	} else {
		if (g_gwContext.id_active == p->widget.id) { /* Not hot, Active */
			gwDrawBox(	(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y,
						(GWfloat)p->widget.width,
						(GWfloat)p->widget.height,
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BACKGROUND_A_ACTIVE : GW_WIDGET_COLOR_FOREGROUND_A]),
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BACKGROUND_B_ACTIVE : GW_WIDGET_COLOR_FOREGROUND_B]));

			gwDrawLine(	(GWfloat)p->widget.position.x + (GWfloat)p->widget.width,
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						(GWfloat)p->widget.position.x, 
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_B_ACTIVE : GW_WIDGET_COLOR_BEVEL_B]));
			
			gwDrawLine(	(GWfloat)p->widget.position.x + (GWfloat)p->widget.width,
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						(GWfloat)p->widget.position.x + (GWfloat)p->widget.width,
						(GWfloat)p->widget.position.y, 
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_B_ACTIVE : GW_WIDGET_COLOR_BEVEL_B]));

			gwDrawLine(	(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y,
						(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_A_ACTIVE : GW_WIDGET_COLOR_BEVEL_A]));

			gwDrawLine(	(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y, 
						(GWfloat)p->widget.position.x + (GWfloat)p->widget.width,
						(GWfloat)p->widget.position.y, 
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_A_ACTIVE : GW_WIDGET_COLOR_BEVEL_A]));

			if(p->status) {
				gwDrawLine(	p->widget.position.x + 1,
							p->widget.position.y + 1,
							p->widget.position.x + p->widget.width - 2,
							p->widget.position.y + p->widget.height - 2,
							&(p->widget.color[GW_WIDGET_COLOR_TEXT_ACTIVE]));
				
				gwDrawLine(	p->widget.position.x + 1,
							p->widget.position.y + p->widget.height - 2,
							p->widget.position.x + p->widget.width - 2,
							p->widget.position.y + 1,
							&(p->widget.color[GW_WIDGET_COLOR_TEXT_ACTIVE]));
			}

		} else { /* Not hot, Not active */
			gwDrawBox(	(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y,
						(GWfloat)p->widget.width,
						(GWfloat)p->widget.height,
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BACKGROUND_A_ACTIVE : GW_WIDGET_COLOR_FOREGROUND_A]),
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BACKGROUND_B_ACTIVE : GW_WIDGET_COLOR_FOREGROUND_B]));

			gwDrawLine(	(GWfloat)p->widget.position.x + (GWfloat)p->widget.width,
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_B_ACTIVE : GW_WIDGET_COLOR_BEVEL_B]));
			
			gwDrawLine(	(GWfloat)p->widget.position.x + (GWfloat)p->widget.width,
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						(GWfloat)p->widget.position.x + (GWfloat)p->widget.width,
						(GWfloat)p->widget.position.y, 
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_B_ACTIVE : GW_WIDGET_COLOR_BEVEL_B]));

			gwDrawLine(	(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y,
						(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y + (GWfloat)p->widget.height, 
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_A_ACTIVE : GW_WIDGET_COLOR_BEVEL_A]));

			gwDrawLine(	(GWfloat)p->widget.position.x,
						(GWfloat)p->widget.position.y, 
						(GWfloat)p->widget.position.x + (GWfloat)p->widget.width,
						(GWfloat)p->widget.position.y, 
						&(p->widget.color[p->status ? GW_WIDGET_COLOR_BEVEL_A_ACTIVE : GW_WIDGET_COLOR_BEVEL_A]));

			if(p->status) {
				gwDrawLine(	p->widget.position.x + 1,
							p->widget.position.y + 1,
							p->widget.position.x + p->widget.width - 2,
							p->widget.position.y + p->widget.height - 2,
							&(p->widget.color[GW_WIDGET_COLOR_TEXT]));
				
				gwDrawLine(	p->widget.position.x + 1,
							p->widget.position.y + p->widget.height - 2,
							p->widget.position.x + p->widget.width - 2,
							p->widget.position.y + 1,
							&(p->widget.color[GW_WIDGET_COLOR_TEXT]));
			}
		}
	}

	return retcode;
}

#ifdef __cplusplus
	}   /* extern "C" */
#endif /* __cplusplus */
