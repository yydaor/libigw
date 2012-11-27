/*

	This file is part of libigw.

	label.c
	Label widget

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
#include "label.h"

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

GWint gwLabel(GWlabel_t *p)
{
	if (p == NULL)
		return 0;
	
	/* Draw */
	gwDrawText(	(GWfloat)p->widget.position.x, (GWfloat)p->widget.position.y,
				(GWfloat)p->widget.position.x + (GWfloat)p->widget.width,
				(GWfloat)p->widget.position.y + (GWfloat)p->widget.height,
				&(p->widget.color[GW_WIDGET_COLOR_TEXT]), p->text);

	return 0;
}

#ifdef __cplusplus
	}   /* extern "C" */
#endif /* __cplusplus */
