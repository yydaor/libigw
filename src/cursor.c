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
#include "cursor.h"

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

GWint gwCursor(GWcursor_t *p)
{
	if (p == NULL)
		return 0;
	
	/* Sync position with mouse */
	p->widget.position.x = g_gwContext.mouse.position.x;
	p->widget.position.y = g_gwContext.mouse.position.y;

	GWfloat px = (GWfloat)p->widget.position.x - (GWfloat)p->widget.width;
		  px = (px > 0.f ? px : p->widget.position.x);
	GWfloat py = (GWfloat)p->widget.position.y - (GWfloat)p->widget.height;
		  py = (py > 0.f ? py : p->widget.position.y);
	GWfloat nx = (GWfloat)p->widget.position.x + (GWfloat)p->widget.width;
		  nx = (nx < g_gwContext.viewport.width ? nx : p->widget.position.x);
	GWfloat ny = (GWfloat)p->widget.position.y + (GWfloat)p->widget.height;
		  ny = (ny < g_gwContext.viewport.height ? ny : p->widget.position.y);

	/* Draw */
	gwDrawLine(p->widget.position.x, p->widget.position.y, px, py,
		&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));
		
	gwDrawLine(p->widget.position.x, p->widget.position.y, nx, ny, 
		&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));
	
	gwDrawLine(p->widget.position.x, p->widget.position.y, px, ny, 
		&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));
	
	gwDrawLine(p->widget.position.x, p->widget.position.y, nx, py,
		&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));

	return 1;
}

#ifdef __cplusplus
	}   /* extern "C" */
#endif /* __cplusplus */
