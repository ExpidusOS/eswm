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


        device.h - (c) 2017 Viktor Odintsev

 */

#ifndef INC_DEVICE_H
#define INC_DEVICE_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <X11/Xlib.h>
#include <gdk/gdk.h>

typedef enum
{
    ESWM_EVENT_XEVENT,
    ESWM_EVENT_KEY,
    ESWM_EVENT_BUTTON,
    ESWM_EVENT_MOTION,
    ESWM_EVENT_CROSSING
} EswmEventType;

typedef struct
{
    EswmEventType type;
    Window window;
    gint device;
    XEvent *xevent;
} EswmEventMeta;

typedef struct
{
    EswmEventMeta meta;

    Window root;
    gboolean pressed;
    guint keycode;
    guint state;
    Time time;
} EswmEventKey;

typedef struct
{
    EswmEventMeta meta;

    Window root;
    Window subwindow;
    gboolean pressed;
    guint button;
    guint state;
    gint x;
    gint y;
    gint x_root;
    gint y_root;
    Time time;
} EswmEventButton;

typedef struct
{
    EswmEventMeta meta;

    gint x;
    gint y;
    gint x_root;
    gint y_root;
    Time time;
} EswmEventMotion;

typedef struct
{
    EswmEventMeta meta;

    Window root;
    gboolean enter;
    gint mode;
    gint detail;
    gint x_root;
    gint y_root;
    Time time;
} EswmEventCrossing;

typedef union
{
    EswmEventMeta meta;
    EswmEventKey key;
    EswmEventButton button;
    EswmEventMotion motion;
    EswmEventCrossing crossing;
} EswmEvent;

typedef struct
{
    gboolean keyboard;
    gint xi2_device;
} EswmDevice;

typedef struct {
    EswmDevice pointer;
    EswmDevice keyboard;

    gboolean xi2_available;
    gint xi2_opcode;
} EswmDevices;

EswmEvent               *eswm_device_translate_event            (EswmDevices *,
                                                                 XEvent *,
                                                                 EswmEvent *);
void                     eswm_device_free_event                 (EswmEvent *);
void                     eswm_device_button_update_window       (EswmEventButton *,
                                                                 Window);
#ifdef HAVE_XI2
void                     eswm_device_configure_xi2_event_mask   (EswmDevices *,
                                                                 Display *,
                                                                 Window,
                                                                 gulong);
#endif
gboolean                 eswm_device_grab                       (EswmDevices *,
                                                                 EswmDevice *,
                                                                 Display *,
                                                                 Window,
                                                                 gboolean,
                                                                 guint,
                                                                 gint,
                                                                 Window,
                                                                 Cursor,
                                                                 Time);
void                     eswm_device_ungrab                     (EswmDevices *,
                                                                 EswmDevice *,
                                                                 Display *,
                                                                 Time);
gboolean                 eswm_device_grab_button                (EswmDevices *,
                                                                 Display *,
                                                                 guint,
                                                                 guint,
                                                                 Window,
                                                                 gboolean,
                                                                 guint,
                                                                 gint,
                                                                 gint,
                                                                 Window,
                                                                 Cursor);
void                     eswm_device_ungrab_button              (EswmDevices *,
                                                                 Display *,
                                                                 guint,
                                                                 guint,
                                                                 Window);
gboolean                 eswm_device_grab_keycode               (EswmDevices *,
                                                                 Display *,
                                                                 gint,
                                                                 guint,
                                                                 Window,
                                                                 gboolean,
                                                                 guint,
                                                                 gint,
                                                                 gint);
void                     eswm_device_ungrab_keycode             (EswmDevices *,
                                                                 Display *,
                                                                 gint,
                                                                 guint,
                                                                 Window);
gboolean                 eswm_device_check_mask_event           (EswmDevices *,
                                                                 Display *,
                                                                 guint,
                                                                 EswmEvent *);
EswmDevices             *eswm_devices_new                       (GdkDisplay *);

#endif /* INC_DEVICE_H */
