/*

	This file is part of libigw.

	context.h
	Context

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


#ifndef LIBIGW_CONTEXT_H_INCLUDED
#define LIBIGW_CONTEXT_H_INCLUDED

#include "type.h"
#include "mouse.h"
#include "viewport.h"

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

/* Context */
struct GWcontext_t
{
	/*
		The item that is below the mouse cursor.
	*/
	GWuint id_hot;

	/* 
		The item that is currently being interacted with.
		An item becomes active when the left mouse button
		is clicked on it. If the button remains pressed
		and the mouse is dragged away from the item, the
		item remains active, but looses the hot state.
	*/
	GWuint id_active;

	GWmouse_t mouse;
	GWviewport_t viewport;
};

typedef struct GWcontext_t GWcontext_t;

#ifdef __cplusplus
	}   /* extern "C" */
#endif /* __cplusplus */

#endif /* LIBIGW_CONTEXT_H_INCLUDED */
