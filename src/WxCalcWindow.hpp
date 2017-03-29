/**
 * @file WxCalcWindow.hpp
 * @brief The window class for the calculator.
 * @author Dominique LaSalle <dominique@solidlake.com>
 * Copyright 2017, Solid Lake LLC
 * @version 1
 * @date 2017-03-28
 */

#include <wx/wx.h>

class WxCalcWindow :
  public wxFrame
{
  public:
    WxCalcWindow();

    wxDECLARE_EVENT_TABLE();

    // disable copying of the class
    WxCalcWindow(
        WxCalcWindow const & rhs);
    WxCalcWindow& operator=(
        WxCalcWindow const & rhs);
};
