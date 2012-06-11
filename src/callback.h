/*

	This file is part of libigw.

	callback.h
	Callbacks

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


#ifndef LIBIGW_CALLBACK_H_INCLUDED
#define LIBIGW_CALLBACK_H_INCLUDED

#include "type.h"

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

void gwBegin();
void gwEnd();

void gwPostRedisplay();

void gwDrawBox(GWfloat x, GWfloat y, GWfloat w, GWfloat h, GWcolor4f_t *col_a, GWcolor4f_t *col_b);
void gwDrawLine(GWfloat x0, GWfloat y0, GWfloat x1, GWfloat y1, GWcolor4f_t *col);
void gwDrawText(GWfloat x, GWfloat y, GWcolor4f_t *col, const GWchar *str);

float gwTextLength(const char *str);

#ifdef __cplusplus
	}   /* extern "C" */
#endif /* __cplusplus */

#endif /* LIBIGW_CALLBACK_H_INCLUDED */
