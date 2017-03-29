/**
 * @file WxCalcWindow.hpp
 * @brief The window class for the calculator.
 * @author Dominique LaSalle <dominique@solidlake.com>
 * Copyright 2017, Solid Lake LLC
 * @version 1
 * @date 2017-03-28
 */

#include <wx/wx.h>
#include <vector>

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

  private:
    // display
    wxTextCtrl * m_display;

    // buttons
    std::vector<wxButton*> m_numButtons;
    wxButton * m_deciButton;
    wxButton * m_signButton;
    wxButton * m_addButton;
    wxButton * m_subButton;
    wxButton * m_mulButton;
    wxButton * m_divButton;
    wxButton * m_equalsButton;
};
