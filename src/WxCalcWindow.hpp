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
#include <string>

class WxCalcWindow :
  public wxFrame
{
  public:
    WxCalcWindow();

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

    // internal variables
    std::string m_preDecimal;
    std::string m_postDecimal;
    bool m_decimal;
    bool m_positive;
    double m_total;
    int m_op;

    double getCurrentValue();
    void updateDisplay();
    void clear();
    void clearAndStore();
    void performOp();
    void showTotal();

    template<int NUM>
    void onNumButton(
        wxCommandEvent&);

    template<int OP>
    void onOpButton(
        wxCommandEvent&);

    wxDECLARE_EVENT_TABLE();

    // disable copying of the class
    WxCalcWindow(
        WxCalcWindow const & rhs);
    WxCalcWindow& operator=(
        WxCalcWindow const & rhs);
};
