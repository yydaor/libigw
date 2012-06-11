/*

	This file is part of libigw.

	type.h
	Basic data types

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

#ifndef LIBIGW_TYPE_H_INCLUDED
#define LIBIGW_TYPE_H_INCLUDED

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

/* Enumerations */
enum GW_BUTTON_STATE
{
	GW_BUTTON_STATE_UP,
	GW_BUTTON_STATE_DOWN
};

typedef enum GW_BUTTON_STATE GW_BUTTON_STATE;

/* Fundamental types */
typedef unsigned char	GWuchar;
typedef char 			GWchar;
typedef unsigned short	GWushort;
typedef short			GWshort;
typedef unsigned int 	GWuint;
typedef int 			GWint;
typedef float 			GWfloat;
typedef double 			GWdouble;

/* Point types */
struct GWpoint2ui_t	{ GWuint	x, y; };
struct GWpoint2i_t	{ GWint		x, y; };
struct GWpoint2f_t	{ GWfloat	x, y; };
struct GWpoint3ui_t	{ GWuint	x, y, z; };
struct GWpoint3i_t	{ GWint		x, y, z; };
struct GWpoint3f_t	{ GWfloat	x, y, z; };

typedef struct GWpoint2ui_t	GWpoint2ui_t;
typedef struct GWpoint2i_t	GWpoint2i_t;
typedef struct GWpoint2f_t	GWpoint2f_t;
typedef struct GWpoint2ui_t GWpoint2ui_t;
typedef struct GWpoint2i_t	GWpoint2i_t;
typedef struct GWpoint2f_t	GWpoint2f_t;

/* Color types */
struct GWcolor3d_t { GWchar	 r, g, b; };
struct GWcolor3f_t { GWfloat r, g, b; };
struct GWcolor4d_t { GWchar	 r, g, b, a; };
struct GWcolor4f_t { GWfloat r, g, b, a; };

typedef struct GWcolor3d_t	GWcolor3d_t;
typedef struct GWcolor3f_t	GWcolor3f_t;
typedef struct GWcolor4d_t	GWcolor4d_t;
typedef struct GWcolor4f_t	GWcolor4f_t;

#ifdef __cplusplus
	}   /* extern "C" */
#endif /* __cplusplus */

#endif /* LIBIGW_TYPE_H_INCLUDED */
