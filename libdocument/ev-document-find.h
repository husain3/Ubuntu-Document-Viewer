/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8; c-indent-level: 8 -*- */
/*
 *  Copyright (C) 2004 Red Hat, Inc.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#pragma once

#if !defined (__EV_EVINCE_DOCUMENT_H_INSIDE__) && !defined (EVINCE_COMPILATION)
#error "Only <evince-document.h> can be included directly."
#endif

#include <glib-object.h>
#include <glib.h>

#include "ev-macros.h"
#include "ev-document.h"

G_BEGIN_DECLS

#define EV_TYPE_DOCUMENT_FIND	    (ev_document_find_get_type ())
#define EV_DOCUMENT_FIND(o)		    (G_TYPE_CHECK_INSTANCE_CAST ((o), EV_TYPE_DOCUMENT_FIND, EvDocumentFind))
#define EV_DOCUMENT_FIND_IFACE(k)	    (G_TYPE_CHECK_CLASS_CAST((k), EV_TYPE_DOCUMENT_FIND, EvDocumentFindInterface))
#define EV_IS_DOCUMENT_FIND(o)	    (G_TYPE_CHECK_INSTANCE_TYPE ((o), EV_TYPE_DOCUMENT_FIND))
#define EV_IS_DOCUMENT_FIND_IFACE(k)	    (G_TYPE_CHECK_CLASS_TYPE ((k), EV_TYPE_DOCUMENT_FIND))
#define EV_DOCUMENT_FIND_GET_IFACE(inst) (G_TYPE_INSTANCE_GET_INTERFACE ((inst), EV_TYPE_DOCUMENT_FIND, EvDocumentFindInterface))

typedef struct _EvDocumentFind	        EvDocumentFind;
typedef struct _EvDocumentFindInterface EvDocumentFindInterface;

typedef enum {
	EV_FIND_DEFAULT          = 0,
	EV_FIND_CASE_SENSITIVE   = 1 << 0,
	EV_FIND_WHOLE_WORDS_ONLY = 1 << 1
} EvFindOptions;

struct _EvDocumentFindInterface
{
	GTypeInterface base_iface;

        /* Methods */
	GList 	     *(* find_text)              (EvDocumentFind *document_find,
						  EvPage         *page,
						  const gchar    *text,
						  gboolean        case_sensitive);
	GList        *(* find_text_with_options) (EvDocumentFind *document_find,
						  EvPage         *page,
						  const gchar    *text,
						  EvFindOptions   options);
	EvFindOptions (*get_supported_options)   (EvDocumentFind *document_find);
};

EV_PUBLIC
GType         ev_document_find_get_type               (void) G_GNUC_CONST;
EV_PUBLIC
GList        *ev_document_find_find_text              (EvDocumentFind *document_find,
						       EvPage         *page,
						       const gchar    *text,
						       gboolean        case_sensitive);
EV_PUBLIC
GList        *ev_document_find_find_text_with_options (EvDocumentFind *document_find,
						       EvPage         *page,
						       const gchar    *text,
						       EvFindOptions   options);
EV_PUBLIC
EvFindOptions ev_document_find_get_supported_options  (EvDocumentFind *document_find);

G_END_DECLS
