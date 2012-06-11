/*

	This file is part of libigw.

	widget.h
	Widget

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

#ifndef LIBIGW_WIDGET_H_INCLUDED
#define LIBIGW_WIDGET_H_INCLUDED

#include "type.h"

#ifdef __cplusplus
	extern "C" {
#endif  /* __cplusplus */

enum GW_WIDGET_COLOR
{
	GW_WIDGET_COLOR_BACKGROUND_A,
	GW_WIDGET_COLOR_BACKGROUND_B,
	GW_WIDGET_COLOR_BACKGROUND_A_HOT,
	GW_WIDGET_COLOR_BACKGROUND_B_HOT,
	GW_WIDGET_COLOR_BACKGROUND_A_ACTIVE,
	GW_WIDGET_COLOR_BACKGROUND_B_ACTIVE,
	
	GW_WIDGET_COLOR_FOREGROUND_A,
	GW_WIDGET_COLOR_FOREGROUND_B,
	GW_WIDGET_COLOR_FOREGROUND_A_HOT,
	GW_WIDGET_COLOR_FOREGROUND_B_HOT,
	GW_WIDGET_COLOR_FOREGROUND_A_ACTIVE,
	GW_WIDGET_COLOR_FOREGROUND_B_ACTIVE,

	GW_WIDGET_COLOR_BEVEL_A,
	GW_WIDGET_COLOR_BEVEL_B,
	GW_WIDGET_COLOR_BEVEL_A_HOT,
	GW_WIDGET_COLOR_BEVEL_B_HOT,
	GW_WIDGET_COLOR_BEVEL_A_ACTIVE,
	GW_WIDGET_COLOR_BEVEL_B_ACTIVE,
	
	GW_WIDGET_COLOR_TEXT,
	GW_WIDGET_COLOR_TEXT_HOT,
	GW_WIDGET_COLOR_TEXT_ACTIVE,
};

#define GW_WIDGET_COLOR_COUNT GW_WIDGET_COLOR_TEXT_ACTIVE+1

/* Widget */
struct GWwidget_t
{
	GWuint id;

	GWpoint2ui_t position;						/* Absolute window coordinates. */
	GWuint width;								/* Width in pixels. */
	GWuint height;								/* Height in pixels. */
	GWcolor4f_t color[GW_WIDGET_COLOR_COUNT];	/* Color palette. */
};

typedef struct GWwidget_t GWwidget_t;

void gwWidgetInit(GWwidget_t *p);

#ifdef __cplusplus
	}   /* extern "C" */
#endif /* __cplusplus */

#endif /* LIBIGW_WIDGET_H_INCLUDED */
