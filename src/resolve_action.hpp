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
#ifndef _RESOLVE_ACTION_H_INCLUDED_
#define _RESOLVE_ACTION_H_INCLUDED_

// app
#include "action.hpp"

class ResolveAction:public Action
{
public:
  ResolveAction (wxWindow * parent);

  virtual bool Perform ();
  virtual bool Prepare ();
};

#endif
/* -----------------------------------------------------------------
 * local variables:
 * eval: (load-file "../rapidsvn-dev.el")
 * end:
 */