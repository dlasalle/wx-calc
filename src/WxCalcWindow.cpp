/**
 * @file WxCalcWindow.cpp
 * @brief The implementation of the window class for the calculator.
 * @author Dominique LaSalle <dominique@solidlake.com>
 * Copyright 2017, Solid Lake LLC
 * @version 1
 * @date 2017-03-28
 */

#include "WxCalcWindow.hpp"

// declare the window's event table
wxBEGIN_EVENT_TABLE(WxCalcWindow, wxFrame)
wxEND_EVENT_TABLE()

WxCalcWindow::WxCalcWindow() :
  wxFrame(NULL, wxID_ANY, "Wx-Calc", wxPoint(100,100), wxSize(400, 400))
{
  wxBoxSizer * topSizer = new wxBoxSizer(wxVERTICAL);

  m_display = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition,
      wxDefaultSize, 0); 
  // make it non-editable
  m_display.Disable();

  wxGridSizer * buttonSizer = new wxBoxSizer(4, 8, 8);
  
  // create all number buttons
  for (int num = 0; num <= NUM_NUMS; ++num) {
    m_numButton[num] = new wxButton(this, ID_NUM_BUTTON[num],
        std::to_string(num));
  }

  // create decimal and plus/minus button
  m_decimalButton = new wxButton(this, ID_DECIMAL_BUTTON, ".");
  m_signButton = new wxButton(this, ID_SIGN_BUTTON, "+/-");

  // create operation buttons
  for (int opIdx = 0; opIdx < NUM_OPS; ++opIdx) {
    m_opsButton[opIdx] = new wxButton(this, ID_OPS_BUTTON[opIdx],
        OP_NAMES[opIdx]);
  }

  


}
