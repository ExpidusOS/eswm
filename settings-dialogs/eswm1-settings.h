/* vi:set sw=2 sts=2 ts=2 et ai: */
/*-
 * Copyright (c) 2008 Jannis Pohlmann <jannis@expidus.org>.
 *
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 2 of the License, or (at 
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#ifndef __ESWM_SETTINGS_H__
#define __ESWM_SETTINGS_H__

#include <glib-object.h>

G_BEGIN_DECLS;

typedef struct _EswmSettingsPrivate EswmSettingsPrivate;
typedef struct _EswmSettingsClass   EswmSettingsClass;
typedef struct _EswmSettings        EswmSettings;

#define ESWM_TYPE_SETTINGS            (eswm_settings_get_type ())
#define ESWM_SETTINGS(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), ESWM_TYPE_SETTINGS, EswmSettings))
#define ESWM_SETTINGS_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), ESWM_TYPE_SETTINGS, EswmSettingsClass))
#define ESWM_IS_SETTINGS(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ESWM_TYPE_SETTINGS))
#define ESWM_IS_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ESWM_TYPE_SETTINGS)
#define ESWM_SETTINGS_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), ESWM_TYPE_SETTINGS, EswmSettingsClass))

GType         eswm_settings_get_type (void) G_GNUC_CONST;

EswmSettings *eswm_settings_new      (void) G_GNUC_MALLOC;



struct _EswmSettingsClass
{
  GObjectClass __parent__;
};

struct _EswmSettings
{
  GObject __parent__;

  EswmSettingsPrivate *priv;
};

G_END_DECLS;

#endif /* !__ESWM_SETTINGS_H__ */
