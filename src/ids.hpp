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
#ifndef _IDS_H_INCLUDED_
#define _IDS_H_INCLUDED_

// wxwindows
#include "wx/defs.h"

/*
 * Menu commands IDs
 */
enum
{
  // rapidsvn_frame
  ID_Quit = wxID_HIGHEST,
  ID_About,
  ID_Refresh,
  ID_Import,
  ID_Checkout,
  ID_Copy,
  ID_Rename,
  ID_Combo,
  ID_Update,
  ID_Commit,
  ID_Add,
  ID_Del,
  ID_Revert,
  ID_Log,
  ID_Info,
  ID_Resolve,
  ID_Merge,
  ID_Contents,
  ID_Mkdir,
  ID_Switch,
  ID_Preferences,
  ID_Property,
  ID_AddProject,
  ID_RemoveProject,
  ID_MoveTo,
  ID_CopyTo,
  ID_RenameHere,
  ID_CopyHere,
  ID_Cleanup,
  ID_Delete,
  ID_Default_Action,
  // Reserve space for 16 file verbs (I've never seen any files with more)
  ID_Verb_Min,
  ID_Verb_Max = ID_Verb_Min + 16,
  ID_Explore,
  ID_Column_Reset,
  ID_Column_Min,
  ID_Column_Rev,
  ID_Column_Cmt_Rev,
  ID_Column_Author,
  ID_Column_Text_Status,
  ID_Column_Prop_Status,
  ID_Column_Cmt_Date,
  ID_Column_Text_Time,
  ID_Column_Prop_Time,
  ID_Column_Url,
  ID_Column_Repos,
  ID_Column_Uuid,
  //ID_Column_Kind, we dont need this, do we?
  ID_Column_Schedule,
  ID_Column_Copied, // combination of isCopied + copyfromUrl
  ID_Column_ConflictOld,
  ID_Column_ConflictNew,
  ID_Column_ConflictWrk,
  ID_Column_Checksum,
  ID_Column_Max,

  // preferences_dlg
  ID_Preferences_GeneralPanel_StandardEditorLookup,
  ID_Preferences_GeneralPanel_StandardFileExplorerLookup,

  ACTION_EVENT,                 // this one gets sent from the action threads
// Ids used for communication events between threads and frame
  TOKEN_BASE,
  TOKEN_INFO,
  TOKEN_SVN_INTERNAL_ERROR,
  TOKEN_VSVN_INTERNAL_ERROR,
  TOKEN_ACTION_END,
  FILELIST_CTRL,
  FOLDER_BROWSER,
};

#endif
/* -----------------------------------------------------------------
 * local variables:
 * eval: (load-file "../rapidsvn-dev.el")
 * end:
 */
