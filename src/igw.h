/*

	This file is part of libigw.

	igw.h
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


#ifndef LIBIGW_IGW_H_INCLUDED
#define LIBIGW_IGW_H_INCLUDED

#include "callback.h"
#include "type.h"
#include "context.h"

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

/* GLOBALS */
extern GWcontext_t g_gwContext;									/* Global context. */

/* FUNCTIONS */
void gwSetViewport(GWuint w, GWuint h);							/* Set the viewport dimensions. */
void gwGetViewport(GWuint *w, GWuint *h);						/* Get the viewport dimensions. */

void gwSetHot(GWuint id);										/* Set the id of the hot widget. */
void gwSetActive(GWuint id);									/* Set the id of the active widget. */

void gwPushKey(GWkey k);										/* Push a key id in the key list */
void gwPopKey(GWkey *k);										/* Pop a key id from the key list */
void gwUpdateMousePosition(GWuint x, GWuint y);					/* Set the mouse position. */
void gwUpdateMouseButtonState(GW_MOUSE_BUTTON id, GWuint s);	/* Set the mouse button state. */

void gwTestMouseHit(GWint *res, GWfloat x, GWfloat y,			/* Test if the mouse pointer is within the given boundaries. */
		 GWfloat w, GWfloat h);

#ifdef __cplusplus
	}   /* extern "C" */
#endif /* __cplusplus */

#endif /* LIBIGW_IGW_H_INCLUDED */
