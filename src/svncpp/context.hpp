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

#ifndef _SVNCPP_CONTEXT_HPP_
#define _SVNCPP_CONTEXT_HPP_ 

// stl
#include <string>

// Subversion api
#include "svn_client.h"

// svncpp
#include "pool.hpp"

// forward declarations

namespace svn
{
  /**
   * This class will hold the client context
   * and replace the old notification and baton
   * stuff
   */
  class Context
  {
  public:
    /**
     * default constructor
     */
    Context ();

    /**
     * copy constructor
     *
     * @param src 
     */
    Context (const Context &src);

    /**
     * destructor
     */
    virtual ~Context ();

    /**
     * set username/password for authentication
     */
    void setLogin (const char * username, const char * password);

    /**
     * operator to get svn_client_ctx object
     */
    operator svn_client_ctx_t * ();

    svn_client_ctx_t * ctx ();

    /**
     * set log message
     *
     * @param msg
     */
    void setLogMessage (const char * msg);

    /**
     * get log message
     *
     * @return log message
     */
    const char * 
    getLogMessage () const;
    
    /**
     * get username
     *
     * @return username
     */
    const char * 
    getUsername () const;

    /**
     * get password
     *
     * @return password
     */
    const char *
    getPassword () const;

  private:
    struct Data;
    Data * m;

    /**
     * disable assignment operator
     */
    Context & operator = (const Context &);
  };
}

#endif
/* -----------------------------------------------------------------
 * local variables:
 * eval: (load-file "../../rapidsvn-dev.el")
 * end:
 */
