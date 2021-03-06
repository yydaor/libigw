/*

	This file is part of libigw.

	progress.c
	Progress bar widget

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
#include "progress.h"

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

GWint gwProgress(GWprogress_t *p)
{
	GWint retcode = 0;

	if (p == NULL)
		return retcode;

	GWfloat ln0x = (GWfloat)p->widget.position.x + (GWfloat)p->widget.width;
	GWfloat ln0y = (GWfloat)p->widget.position.y + (GWfloat)p->widget.height;
	
	gwDrawBox(	(GWfloat)p->widget.position.x, 
				(GWfloat)p->widget.position.y,
				(GWfloat)p->widget.width,
				(GWfloat)p->widget.height,
				&(p->widget.color[GW_WIDGET_COLOR_BACKGROUND_A]),
				&(p->widget.color[GW_WIDGET_COLOR_BACKGROUND_B]));


	gwDrawLine(	ln0x, ln0y, (GWfloat)p->widget.position.x, ln0y, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));

	gwDrawLine(	ln0x, ln0y, ln0x, (GWfloat)p->widget.position.y, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));

	gwDrawLine(	(GWfloat)p->widget.position.x, (GWfloat)p->widget.position.y,
				(GWfloat)p->widget.position.x, ln0y, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B]));

	gwDrawLine(	(GWfloat)p->widget.position.x,(GWfloat)p->widget.position.y, 
				ln0x, (GWfloat)p->widget.position.y, 
				&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B]));

	if (p->value > 0.f) {
		GWfloat hx = (GWfloat)p->widget.position.x + 2.f;
		GWfloat hy = (GWfloat)p->widget.position.y + 2.f;
		GWfloat hw = (GWfloat)p->widget.width * p->value - 3.f;
			  hw = hw > 0.f ? hw : 0.f;
		GWfloat hh = (GWfloat)p->widget.height - 3.f;

		GWfloat ln1x = hx + hw;
		GWfloat ln1y = hy + hh;

		gwDrawBox(	hx, hy,	hw,	hh,
					&(p->widget.color[GW_WIDGET_COLOR_FOREGROUND_A]),
					&(p->widget.color[GW_WIDGET_COLOR_FOREGROUND_B]));
			
		gwDrawLine(	ln1x, ln1y, hx, ln1y,
					&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B]));
	
		gwDrawLine(	ln1x, ln1y, ln1x, hy, 
					&(p->widget.color[GW_WIDGET_COLOR_BEVEL_B]));
	
		gwDrawLine(	hx, hy, hx, ln1y, 
					&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));
	
		gwDrawLine(	hx, hy, ln1x, hy, 
					&(p->widget.color[GW_WIDGET_COLOR_BEVEL_A]));
	}

	return retcode;
}

#ifdef __cplusplus
	}   /* extern "C" */
#endif /* __cplusplus */
