/*      $Id$

        This program is free software; you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation; either version 2, or (at your option)
        any later version.

        This program is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with this program; if not, write to the Free Software
        Foundation, Inc., Inc., 51 Franklin Street, Fifth Floor, Boston,
        MA 02110-1301, USA.


        oroborus - (c) 2001 Ken Lynch
        eswm1    - (c) 2002-2011 Olivier Fourdan

 */

#ifndef INC_MYWINDOW_H
#define INC_MYWINDOW_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <X11/Xlib.h>
#include <glib.h>
#include "mypixmap.h"
#include "screen.h"

#ifdef HAVE_RENDER
#include <X11/extensions/Xrender.h>
#endif

#define MYWINDOW_XWINDOW(w) (w.window)

typedef struct _eswmWindow eswmWindow;
struct _eswmWindow
{
    ScreenInfo *screen_info;
    Visual *visual;
#ifdef HAVE_RENDER
    XRenderPictFormat *pict_format;
#endif
    gint depth;
    Window window;
    gint x, y;
    gint width, height;
    gboolean map;
};

void                     eswmWindowInit                         (eswmWindow *);
void                     eswmWindowSetCursor                    (eswmWindow *,
                                                                 Cursor);
void                     eswmWindowCreate                       (ScreenInfo *,
                                                                 Visual *,
                                                                 gint,
                                                                 Window,
                                                                 eswmWindow *,
                                                                 long,
                                                                 Cursor);
void                     eswmWindowTemp                         (ScreenInfo *,
                                                                 Visual *,
                                                                 gint,
                                                                 Window,
                                                                 eswmWindow *,
                                                                 int,
                                                                 int,
                                                                 int,
                                                                 int,
                                                                 long,
                                                                 gboolean);
void                     eswmWindowDelete                       (eswmWindow *);
void                     eswmWindowShow                         (eswmWindow *,
                                                                 int,
                                                                 int,
                                                                 int,
                                                                 int,
                                                                 gboolean);
void                     eswmWindowHide                         (eswmWindow *);
gboolean                 eswmWindowVisible                      (eswmWindow *);
gboolean                 eswmWindowDeleted                      (eswmWindow *);
void                     eswmWindowSetBG                        (eswmWindow *,
                                                                 eswmPixmap *);

#endif /* INC_MYWINDOW_H */
