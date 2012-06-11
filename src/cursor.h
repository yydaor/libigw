/*

	This file is part of libigw.

	cursor.h
	Cursor widget

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


#ifndef LIBIGW_CURSOR_H_INCLUDED
#define LIBIGW_CURSOR_H_INCLUDED

#include "type.h"
#include "widget.h"

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

struct GWcursor_t
{
	GWwidget_t widget;
};

typedef struct GWcursor_t GWcursor_t;

int gwCursor(GWcursor_t *p);

#ifdef __cplusplus
	}   /* extern "C" */
#endif /* __cplusplus */

#endif /* LIBIGW_CURSOR_H_INCLUDED */
