/*
 * ====================================================================
 * Copyright (c) 2002, 2003 The RapidSvn Group.  All rights reserved.
 *
 * This software is licensed as described in the file LICENSE.txt,
 * which you should have received as part of this distribution.
 *
 * This software consists of voluntary contributions made by many
 * individuals.  For exact contribution history, see the revision
 * history and logs, available at http://rapidsvn.tigris.org/.
 * ====================================================================
 */
#ifndef _RAPIDSVN_UTILS_H_INCLUDED_
#define _RAPIDSVN_UTILS_H_INCLUDED_

// svn
#include "svn_wc.h"

// forward declarations
class wxString;
class Tracer;

#define DEFAULT_ARRAY_SIZE 5

#define APPLICATION_NAME _("RapidSVN")


wxString & UnixPath (wxString & path);

void GetStatusText (wxString & str, svn_wc_status_kind st);

void TrimString (wxString & str);

void *svn_cl__make_log_msg_baton (const char *message,
                                  const char *base_dir, apr_pool_t * pool);

/**
 * Recursive function to send the error strings to a Tracer
 */
void handle_svn_error (svn_error_t * err, Tracer * tracer);

svn_error_t *svn_cl__may_need_force (svn_error_t * err);

/**
 * Post a menu command event with the given ID. 
 *
 * Used for converting non-command events to command events so they'll move up
 * the GUI hierarchy.
 */
bool PostMenuEvent (wxControl *source, long id);

#endif
/* -----------------------------------------------------------------
 * local variables:
 * eval: (load-file "../rapidsvn-dev.el")
 * end:
 */
