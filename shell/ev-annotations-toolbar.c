/* ev-annotations-toolbar.c
 *  this file is part of evince, a gnome document viewer
 *
 * Copyright (C) 2015 Carlos Garcia Campos  <carlosgc@gnome.org>
 *
 * Evince is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Evince is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 */

#include "config.h"

#include "ev-annotations-toolbar.h"
#include "ev-annotations-marshal.h"
#include <evince-document.h>
#include <glib/gi18n.h>

enum {
        BEGIN_ADD_ANNOT,
        CANCEL_ADD_ANNOT,
        N_SIGNALS
};

struct _EvAnnotationsToolbar {
        GtkToolbar base_instance;

        GtkWidget *text_button;
        GtkWidget *highlight_button_yellow;
        GtkWidget *highlight_button_cyan;
        GtkWidget *highlight_button_green;
        GtkWidget *highlight_button_magenta;
        GtkWidget *underline_button;
        GtkWidget *strikethrough_button;
        GtkWidget *squiggly_button;
};

struct _EvAnnotationsToolbarClass {
	GtkToolbarClass base_class;

};

static guint signals[N_SIGNALS];

G_DEFINE_TYPE (EvAnnotationsToolbar, ev_annotations_toolbar, GTK_TYPE_TOOLBAR)

static void
ev_annotations_toolbar_annot_button_toggled (GtkWidget            *button,
                                             EvAnnotationsToolbar *toolbar)
{
        EvAnnotationType annot_type;
        EvAnnotationTextMarkupType annot_markup_type;
        EvAnnotationColor annot_color;

        if (!gtk_toggle_tool_button_get_active (GTK_TOGGLE_TOOL_BUTTON (button))) {
                g_signal_emit (toolbar, signals[CANCEL_ADD_ANNOT], 0, NULL);
                return;
        }

        if (button == toolbar->text_button) {
                      annot_type = EV_ANNOTATION_TYPE_TEXT;
                      annot_markup_type = EV_ANNOTATION_TEXT_MARKUP_NONE;
                      annot_color = EV_ANNOTATION_COLOR_YELLOW;
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_yellow), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_cyan), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_green), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_magenta), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->underline_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->strikethrough_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->squiggly_button), FALSE);

        } else if (button == toolbar->highlight_button_yellow) {
                      annot_type = EV_ANNOTATION_TYPE_TEXT_MARKUP;
                      annot_markup_type = EV_ANNOTATION_TEXT_MARKUP_HIGHLIGHT;
                      annot_color = EV_ANNOTATION_COLOR_YELLOW;
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->text_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_cyan), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_green), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_magenta), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->underline_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->strikethrough_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->squiggly_button), FALSE);

        } else if (button == toolbar->highlight_button_cyan) {
                      annot_type = EV_ANNOTATION_TYPE_TEXT_MARKUP;
                      annot_markup_type = EV_ANNOTATION_TEXT_MARKUP_HIGHLIGHT;
                      annot_color = EV_ANNOTATION_COLOR_CYAN;
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->text_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_yellow), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_green), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_magenta), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->underline_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->strikethrough_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->squiggly_button), FALSE);

        } else if (button == toolbar->highlight_button_green) {
                      annot_type = EV_ANNOTATION_TYPE_TEXT_MARKUP;
                      annot_markup_type = EV_ANNOTATION_TEXT_MARKUP_HIGHLIGHT;
                      annot_color = EV_ANNOTATION_COLOR_GREEN;
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->text_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_cyan), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_yellow), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_magenta), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->underline_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->strikethrough_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->squiggly_button), FALSE);

        } else if (button == toolbar->highlight_button_magenta) {
                      annot_type = EV_ANNOTATION_TYPE_TEXT_MARKUP;
                      annot_markup_type = EV_ANNOTATION_TEXT_MARKUP_HIGHLIGHT;
                      annot_color = EV_ANNOTATION_COLOR_MAGENTA;
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->text_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_cyan), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_green), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_yellow), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->underline_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->strikethrough_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->squiggly_button), FALSE);

        } else if (button == toolbar->underline_button) {
                      annot_type = EV_ANNOTATION_TYPE_TEXT_MARKUP;
                      annot_markup_type =  EV_ANNOTATION_TEXT_MARKUP_UNDERLINE;
                      annot_color = EV_ANNOTATION_COLOR_NONE;
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->text_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_cyan), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_green), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_yellow), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_magenta), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->strikethrough_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->squiggly_button), FALSE);

        } else if (button == toolbar->strikethrough_button) {
                      annot_type = EV_ANNOTATION_TYPE_TEXT_MARKUP;
                      annot_markup_type =  EV_ANNOTATION_TEXT_MARKUP_STRIKE_OUT;
                      annot_color = EV_ANNOTATION_COLOR_NONE;
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->text_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_cyan), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_green), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_yellow), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_magenta), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->underline_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->squiggly_button), FALSE);

        } else if (button == toolbar->squiggly_button) {
                      annot_type = EV_ANNOTATION_TYPE_TEXT_MARKUP;
                      annot_markup_type =  EV_ANNOTATION_TEXT_MARKUP_SQUIGGLY;
                      annot_color = EV_ANNOTATION_COLOR_NONE;
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->text_button), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_cyan), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_green), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_yellow), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_magenta), FALSE);
                      gtk_toggle_tool_button_set_active (GTK_TOGGLE_TOOL_BUTTON (toolbar->underline_button), FALSE);

        } else {
                      g_assert_not_reached ();
        }

        g_signal_emit (toolbar, signals[BEGIN_ADD_ANNOT], 0, annot_type, annot_markup_type, annot_color);
}

static gboolean
ev_annotations_toolbar_toggle_button_if_active (EvAnnotationsToolbar *toolbar,
                                                GtkToggleToolButton  *button)
{
        if (!gtk_toggle_tool_button_get_active (button))
                return FALSE;

        g_signal_handlers_block_by_func (button,
                                         ev_annotations_toolbar_annot_button_toggled,
                                         toolbar);
        gtk_toggle_tool_button_set_active (button, FALSE);
        g_signal_handlers_unblock_by_func (button,
                                           ev_annotations_toolbar_annot_button_toggled,
                                           toolbar);

        return TRUE;
}

static GtkWidget *
ev_annotations_toolbar_create_toggle_button (EvAnnotationsToolbar *toolbar,
                                             const gchar          *label,
                                             const gchar          *icon_name,
                                             const gchar          *tooltip)
{
        GtkWidget *button = GTK_WIDGET (gtk_toggle_tool_button_new ());

        gtk_widget_set_tooltip_text (button, tooltip);

        if (label) {
                gtk_tool_button_set_label (GTK_TOOL_BUTTON (button), label);
                atk_object_set_name (gtk_widget_get_accessible (button), label);
        }

        if (icon_name)
                gtk_tool_button_set_icon_name (GTK_TOOL_BUTTON (button), icon_name);

        /* For some reason adding text-button class to the GtkToogleButton makes the button smaller */
        gtk_style_context_add_class (gtk_widget_get_style_context (gtk_bin_get_child (GTK_BIN (button))), "text-button");
        g_signal_connect (button, "toggled",
                          G_CALLBACK (ev_annotations_toolbar_annot_button_toggled),
                          toolbar);

        return button;
}

static void
ev_custom_icon_to_builtin_theme (const gchar *icon_file_path,
         const gchar *custom_icon_name)
{
        GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file(icon_file_path, NULL);
        int width, height;
        gdk_pixbuf_get_file_info (icon_file_path, &width, &height);
        gtk_icon_theme_add_builtin_icon (custom_icon_name, width, pixbuf);
        g_object_unref (G_OBJECT(pixbuf));


}

static void
ev_annotations_toolbar_init (EvAnnotationsToolbar *toolbar)
{
        gtk_orientable_set_orientation (GTK_ORIENTABLE (toolbar), GTK_ORIENTATION_HORIZONTAL);

        gtk_toolbar_set_icon_size (GTK_TOOLBAR (toolbar), GTK_ICON_SIZE_MENU);
        gtk_style_context_add_class (gtk_widget_get_style_context (GTK_WIDGET (toolbar)),
                                     GTK_STYLE_CLASS_INLINE_TOOLBAR);

        /* Use Text label until we have:
         *   1. More buttons in the toolbar (lack of space)
         *   2. Clear icons for an action.
         */
          /* Text highlight button */
          ev_custom_icon_to_builtin_theme("../data/icons/22x22/actions/evince-comment-annotation.png", "evince-comment-annotation");

          toolbar->text_button = ev_annotations_toolbar_create_toggle_button (toolbar,
                                                                                    NULL,
                                                                                    "evince-comment-annotation",
                                                                                    _("Add text annotation"));
          gtk_container_add (GTK_CONTAINER(toolbar), toolbar->text_button);
          gtk_widget_show (toolbar->text_button);

          ev_custom_icon_to_builtin_theme("../data/icons/22x22/actions/evince-yellow-highlight-annotation.png", "evince-yellow-highlight-annotation");

          /* Yellow highlight button */
          toolbar->highlight_button_yellow = ev_annotations_toolbar_create_toggle_button (toolbar,
                                                                                   NULL,
                                                                                   "evince-yellow-highlight-annotation",
                                                                                   _("Yellow highlighter"));
          gtk_container_add (GTK_CONTAINER (toolbar), toolbar->highlight_button_yellow);
          gtk_widget_show (toolbar->highlight_button_yellow);

          ev_custom_icon_to_builtin_theme("../data/icons/22x22/actions/evince-cyan-highlight-annotation.png", "evince-cyan-highlight-annotation");

          /* Blue highlight button */
          toolbar->highlight_button_cyan = ev_annotations_toolbar_create_toggle_button (toolbar,
                                                                                   NULL,
                                                                                   "evince-cyan-highlight-annotation",
                                                                                   _("Blue highlighter"));
          gtk_container_add (GTK_CONTAINER (toolbar), toolbar->highlight_button_cyan);
          gtk_widget_show (toolbar->highlight_button_cyan);


          ev_custom_icon_to_builtin_theme("../data/icons/22x22/actions/evince-magenta-highlight-annotation.png", "evince-magenta-highlight-annotation");

          /* Pink highlight button */
          toolbar->highlight_button_magenta = ev_annotations_toolbar_create_toggle_button (toolbar,
                                                                                  NULL,
                                                                                  "evince-magenta-highlight-annotation",
                                                                                   _("Pink highligher"));
          gtk_container_add (GTK_CONTAINER (toolbar), toolbar->highlight_button_magenta);
          gtk_widget_show (toolbar->highlight_button_magenta);

          ev_custom_icon_to_builtin_theme("../data/icons/22x22/actions/evince-green-highlight-annotation.png", "evince-green-highlight-annotation");

          /* Green highlight button */
          toolbar->highlight_button_green = ev_annotations_toolbar_create_toggle_button (toolbar,
                                                                                   NULL,
                                                                                   "evince-green-highlight-annotation",
                                                                                   _("Green highlighter"));
          gtk_container_add (GTK_CONTAINER (toolbar), toolbar->highlight_button_green);
          gtk_widget_show (toolbar->highlight_button_green);

          /* Underline button */
          ev_custom_icon_to_builtin_theme("../data/icons/22x22/actions/evince-format-text-underline.png", "evince-format-text-underline");

          toolbar->underline_button = ev_annotations_toolbar_create_toggle_button (toolbar,
                                                                                        NULL,
                                                                                        "evince-format-text-underline",
                                                                                         _("Underline"));
          gtk_container_add (GTK_CONTAINER (toolbar), toolbar->underline_button);
          gtk_widget_show (toolbar->underline_button);

          /* Strikethrough button */
          ev_custom_icon_to_builtin_theme("../data/icons/22x22/actions/evince-format-text-strikethrough.png", "evince-format-text-strikethrough");

          toolbar->strikethrough_button = ev_annotations_toolbar_create_toggle_button (toolbar,
                                                                                        NULL,
                                                                                        "evince-format-text-strikethrough",
                                                                                         _("Underline"));
          gtk_container_add (GTK_CONTAINER (toolbar), toolbar->strikethrough_button);
          gtk_widget_show (toolbar->strikethrough_button);

          /* Squiggly button */
          ev_custom_icon_to_builtin_theme("../data/icons/22x22/actions/evince-format-text-squiggly.png", "evince-format-text-squiggly");

          toolbar->squiggly_button = ev_annotations_toolbar_create_toggle_button (toolbar,
                                                                                        NULL,
                                                                                        "evince-format-text-squiggly",
                                                                                         _("Squiggly"));
          gtk_container_add (GTK_CONTAINER (toolbar), toolbar->squiggly_button);
          gtk_widget_show (toolbar->squiggly_button);
}

static void
ev_annotations_toolbar_class_init (EvAnnotationsToolbarClass *klass)
{
        GObjectClass *g_object_class = G_OBJECT_CLASS (klass);

        signals[BEGIN_ADD_ANNOT] =
                g_signal_new ("begin-add-annot",
                              G_TYPE_FROM_CLASS (g_object_class),
                              G_SIGNAL_RUN_LAST,
                              0,
                              NULL, NULL,
                              g_cclosure_user_marshal_VOID__ENUM_ENUM_ENUM,
                              G_TYPE_NONE, 3,
                              EV_TYPE_ANNOTATION_TYPE,
                              EV_TYPE_ANNOTATION_TEXT_MARKUP_TYPE,
                              EV_TYPE_ANNOTATION_COLOR);

        signals[CANCEL_ADD_ANNOT] =
                g_signal_new ("cancel-add-annot",
                              G_TYPE_FROM_CLASS (g_object_class),
                              G_SIGNAL_RUN_LAST,
                              0,
                              NULL, NULL,
                              g_cclosure_marshal_VOID__VOID,
                              G_TYPE_NONE, 0,
                              G_TYPE_NONE);
}

GtkWidget *
ev_annotations_toolbar_new (void)
{
	return GTK_WIDGET (g_object_new (EV_TYPE_ANNOTATIONS_TOOLBAR, NULL));
}

void
ev_annotations_toolbar_add_annot_finished (EvAnnotationsToolbar *toolbar)
{
        g_return_if_fail (EV_IS_ANNOTATIONS_TOOLBAR (toolbar));

        if (ev_annotations_toolbar_toggle_button_if_active (toolbar, GTK_TOGGLE_TOOL_BUTTON (toolbar->text_button))) {
			return;
		}

        ev_annotations_toolbar_toggle_button_if_active (toolbar, GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_yellow));
        ev_annotations_toolbar_toggle_button_if_active (toolbar, GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_cyan));
        ev_annotations_toolbar_toggle_button_if_active (toolbar, GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_green));
        ev_annotations_toolbar_toggle_button_if_active (toolbar, GTK_TOGGLE_TOOL_BUTTON (toolbar->highlight_button_magenta));
        ev_annotations_toolbar_toggle_button_if_active (toolbar, GTK_TOGGLE_TOOL_BUTTON (toolbar->underline_button));
        ev_annotations_toolbar_toggle_button_if_active (toolbar, GTK_TOGGLE_TOOL_BUTTON (toolbar->strikethrough_button));
        ev_annotations_toolbar_toggle_button_if_active (toolbar, GTK_TOGGLE_TOOL_BUTTON (toolbar->squiggly_button));
}
