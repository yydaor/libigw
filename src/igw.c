/*

	This file is part of libigw.

	igw.c
	MIGW

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


#include "igw.h"

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

GWcontext_t g_gwContext;

void gwViewport(GWuint w, GWuint h)
{
	g_gwContext.viewport.width = w;
	g_gwContext.viewport.height = h;
}

void gwSetHot(GWuint id)
{
	g_gwContext.id_hot = id;
}

void gwSetActive(GWuint id)
{
	g_gwContext.id_active = id;
}

void gwUpdateMousePosition(GWuint x, GWuint y)
{
	g_gwContext.mouse.position.x = x;
	g_gwContext.mouse.position.y = y;
}

void gwUpdateMouseButtonState(GW_MOUSE_BUTTON id, GWuint s)
{
	g_gwContext.mouse.button[id] = s;
}

int gwTestMouseHit(GWfloat x, GWfloat y, GWfloat w, GWfloat h)
{
	return (
		g_gwContext.mouse.position.x >= x 		&&
		g_gwContext.mouse.position.y >= y 		&&
		g_gwContext.mouse.position.x <= x + w 	&&
		g_gwContext.mouse.position.y <= y + h
	);
}

#ifdef __cplusplus
 	}   /* extern "C" */
#endif /* __cplusplus */
