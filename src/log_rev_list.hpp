/*
 * ====================================================================
 * Copyright (c) 2002-2009 The RapidSvn Group.  All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program (in the file GPL.txt.  
 * If not, see <http://www.gnu.org/licenses/>.
 *
 * This software consists of voluntary contributions made by many
 * individuals.  For exact contribution history, see the revision
 * history and logs, available at http://rapidsvn.tigris.org/.
 * ====================================================================
 */
#ifndef _LOG_REV_LIST_H_INCLUDED_
#define _LOG_REV_LIST_H_INCLUDED_

// wx
#include "wx/wx.h"

// app
#include "utils.hpp"


class LogRevList : public wxListCtrl
{
public:
  LogRevList(wxWindow * parent, const svn::LogEntries * entries)
      : wxListCtrl(parent, -1, wxDefaultPosition,
                   wxSize(365, 150), wxLC_REPORT)
  {
    InitializeList(entries);
    CentreOnParent();
  }

  virtual ~LogRevList()
  {
    DeleteAllItems();
  }

  /**
   * Returns the revision for the given @a item
   *
   * @param item
   * @return revnum
   * @retval -1 not found/error
   */
  svn_revnum_t
  GetRevisionForItem(long item) const
  {
    wxListItem info;
    info.m_itemId = item;
    info.m_col = 0;
    info.m_mask = wxLIST_MASK_TEXT;

    if (!GetItem(info))
      return -1;

    svn_revnum_t revnum=-1;
    info.m_text.ToLong(&revnum);
    return revnum;
  }

  /**
   * returns the selected revision.
   *
   * @return selected revision
   * @retval -1 if nothing was selected or the cell
   *            contains an invalid string
   */
  svn_revnum_t
  GetSelectedRevision() const
  {
    long item = GetNextItem(-1, wxLIST_NEXT_ALL,
                            wxLIST_STATE_SELECTED);
    if (item == -1)
      return -1;

    return GetRevisionForItem(item);
  }

  /**
   * returns the selected revisions.
   * Like @a GetSelectedRevision, but can return
   * more revisions at once.
   *
   * @return if nothing is selected, an empty array
   *         will be returned
   */
  RevnumArray
  GetSelectedRevisions() const
  {
    RevnumArray array;
    long item = -1;

    do
    {
      item = GetNextItem(item, wxLIST_NEXT_ALL,
                         wxLIST_STATE_SELECTED);
      if (item != -1)
      {
        svn_revnum_t revnum(GetRevisionForItem(item));

        array.Add(revnum);
      }
    }
    while (item != -1);

    return array;
  }


  void
  DeleteAllItems()
  {
    // Delete the item data before deleting the items:
    while (GetItemCount() > 0)
      DeleteItem(0);

    wxListCtrl::DeleteAllItems();
  }

private:
  void OnSelected(wxListEvent& event);

  void InitializeList(const svn::LogEntries * entries)
  {
    SetSingleStyle(wxLC_REPORT);

    InsertColumn(0, _("Revision"));
    InsertColumn(1, _("User"));
    InsertColumn(2, _("Date"));
    InsertColumn(3, _("Log Message"));

    SetColumnWidth(0, 65);
    SetColumnWidth(1, 100);
    SetColumnWidth(2, 150);
    SetColumnWidth(3, 200);

    if (entries == 0)
      return;

    long index=0;
    svn::LogEntries::const_iterator it;
    for (it=entries->begin(); it != entries->end(); it++)
    {
      const svn::LogEntry & entry = *it;
      wxString rev;
      wxString dateStr(FormatDateTime(entry.date));

      rev.Printf(wxT("%ld"), (long) entry.revision);

      InsertItem(index, rev);
      SetItem(index, 1, Utf8ToLocal(entry.author.c_str()));
      SetItem(index, 2, dateStr);
      SetItem(index, 3, NewLinesToSpaces(Utf8ToLocal(entry.message.c_str())));
      index++;
    }
  }

  wxString
  NewLinesToSpaces(const wxString& str)
  {
    /*
    wxString result = str;
    result.Replace (wxT("\n"), wxT(" "));
    return result;
    */

    wxString result;
    if (str.Length() == 0)
    {
      return result;
    }

    result.Alloc(str.Length());
    wxChar last = 0;

    for (size_t idx = 0; idx < str.Length(); idx++)
    {
      switch (str[idx])
      {
      case wxT('\r'):
      case wxT('\n'):
        if (last != wxT(' '))
        {
          result += wxT(' ');
        }
        break;

      default:
        result += str[idx];
        break;
      }
    }

    return result;
  }
};


#endif
/* -----------------------------------------------------------------
 * local variables:
 * eval: (load-file "../rapidsvn-dev.el")
 * end:
 */