#ifndef _VSVN_FRAME_HEADER_H_INCLUDED_
#define _VSVN_FRAME_HEADER_H_INCLUDED_

#include <wx/toolbar.h>
#include <wx/splitter.h>

#include "tracer.h"

#define SPLITTER_WINDOW   100


typedef enum
{
  ACTION_TYPE_NONE,
  ACTION_TYPE_UPDATE,
  ACTION_TYPE_COMMIT,
  ACTION_TYPE_CHECKOUT,
  ACTION_TYPE_IMPORT,
  ACTION_TYPE_ADD,
  ACTION_TYPE_DEL,
  ACTION_TYPE_REVERT,
  ACTION_TYPE_RESOLVE,
  ACTION_TYPE_COPY,
  ACTION_TYPE_MKDIR,
  ACTION_TYPE_MERGE
}
ActionType;

class VSvnFrame;

/**
* Panel holding the splitter with the folder browser
* and the file list.
*/
class InfoPanel:public wxPanel
{
public:
  InfoPanel (wxWindow * parent);
};

class LogTracer:public wxTextCtrl, public Tracer
{

public:
  LogTracer (wxWindow * parent);
  void Trace (const wxString & str);
};

class VSvnFrame:public wxFrame
{
public:
  VSvnFrame (const wxString & title);
  ~VSvnFrame ();

  void OnSize (wxSizeEvent & event);

  // File menu
  void OnQuit (wxCommandEvent & event);

  // View menu
  void OnBrowse (wxCommandEvent & event);

  // Query menu
  void OnStatus (wxCommandEvent & event);
  void OnLog (wxCommandEvent & event);
  void OnInfo (wxCommandEvent & event);

  // Create menu
  void OnCheckout (wxCommandEvent & event);
  void OnImport (wxCommandEvent & event);
  void OnCopy (wxCommandEvent & event);
  void OnMkdir (wxCommandEvent & event);
  void OnMerge (wxCommandEvent & event);

  // Modify menu
  void OnUpdate (wxCommandEvent & event);
  void OnAdd (wxCommandEvent & event);
  void OnDelete (wxCommandEvent & event);
  void OnCommit (wxCommandEvent & event);
  void OnRevert (wxCommandEvent & event);
  void OnResolve (wxCommandEvent & event);

  // Help menu
  void OnContents (wxCommandEvent & event);
  void OnAbout (wxCommandEvent & event);

  // Combo box on the toolbar
  void OnCombo (wxCommandEvent & event);

  // toolbar administration
  void LayoutChildren ();
  void RecreateToolbar ();
  void AddBrowseTools ();
  void AddActionTools ();
  void AddInfoTools ();

  // menu stuff
  void InitializeMenu ();

  // toolbar events
  void OnToolEnter (wxCommandEvent & event);
  void OnToolLeftClick (wxCommandEvent & event);

  // Events from action threads
  void OnActionEvent (wxCommandEvent & event);

  // combobox
  void InitComboBrowser ();

  // list control
  void InitFileList ();

  // utility functions
  void BrowseDir ();

  void ShowStatus ();
  void ShowLog ();
  void ShowInfo ();

  void MakeUpdate ();
  void AddEntries ();
  void DelEntries ();
  void MakeCommit ();
  void MakeRevert ();
  void MakeResolve ();

  void MakeCopy ();
  void Mkdir ();
  void Merge ();
  void Contents ();

  FileListCtrl *GetFileList ()
  {
    return m_listCtrl;
  }

  FolderBrowser *GetFolderBrowser ()
  {
    return m_folder_browser;
  }

private:

  FolderBrowser * m_folder_browser;
  FileListCtrl *m_listCtrl;

  wxSplitterWindow *m_horiz_splitter;
  wxSplitterWindow *m_vert_splitter;

  InfoPanel *m_info_panel;

  wxTextCtrl *m_log;
  EventTracer *m_logTracer;

  wxComboBox *m_comboBrowse;
  wxToolBar *m_tbar;
  size_t m_toolbar_rows;        // 1 or 2 only (toolbar rows)

  ActionType lastAction;

  apr_pool_t *pool;
      /**
      * Used for allocating stuff before some actions,
      * stuff that will be used in that actions
      */
  apr_pool_t *aux_pool;

DECLARE_EVENT_TABLE ()};

const int ID_TOOLBAR = 500;

/*
 * Menu commands IDs
 */
enum
{
  ID_Quit = 1,
  ID_About,
  ID_Refresh,
  ID_Browse,
  ID_Import,
  ID_Checkout,
  ID_Copy,
  ID_Combo,
  ID_Update,
  ID_Commit,
  ID_Add,
  ID_Del,
  ID_Revert,
  ID_Status,
  ID_Log,
  ID_Info,
  ID_Resolve,
  ID_Merge,
  ID_Contents,
  ID_Mkdir,
  ID_Switch,
  ID_Preferences,

  ACTION_EVENT,                 // this one gets sent from the action threads

  LIST_CTRL = 1000
};

#endif