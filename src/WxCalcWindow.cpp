/**
 * @file WxCalcWindow.cpp
 * @brief The implementation of the window class for the calculator.
 * @author Dominique LaSalle <dominique@solidlake.com>
 * Copyright 2017, Solid Lake LLC
 * @version 1
 * @date 2017-03-28
 */

#include "WxCalcWindow.hpp"

namespace
{

enum event_ids {
  ID_0_BUTTON,
  ID_1_BUTTON,
  ID_2_BUTTON,
  ID_3_BUTTON,
  ID_4_BUTTON,
  ID_5_BUTTON,
  ID_6_BUTTON,
  ID_7_BUTTON,
  ID_8_BUTTON,
  ID_9_BUTTON,
  ID_DECI_BUTTON,
  ID_SIGN_BUTTON,
  ID_ADD_BUTTON,
  ID_SUB_BUTTON,
  ID_MUL_BUTTON,
  ID_DIV_BUTTON,
  ID_EQUAL_BUTTON
};

const std::vector<int> ID_NUM_BUTTON{
  ID_0_BUTTON,
  ID_1_BUTTON,
  ID_2_BUTTON,
  ID_3_BUTTON,
  ID_4_BUTTON,
  ID_5_BUTTON,
  ID_6_BUTTON,
  ID_7_BUTTON,
  ID_8_BUTTON,
  ID_9_BUTTON
};

}

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
  m_display->Disable();
  topSizer->Add(m_display);

  // put a 10px spacer between the display and the buttons
  topSizer->AddSpacer(10);

  // create the button grid with no space between buttons
  wxGridSizer * buttonSizer = new wxGridSizer(4, 0, 0);
  
  // create all number buttons
  m_numButtons.resize(ID_NUM_BUTTON.size());
  for (int num = 0; num < ID_NUM_BUTTON.size(); ++num) {
    m_numButtons[num] = new wxButton(this, ID_NUM_BUTTON[num],
        std::to_string(num));
  }

  // create operation buttons
  m_addButton = new wxButton(this, ID_ADD_BUTTON, "+");
  m_subButton = new wxButton(this, ID_SUB_BUTTON, "-");
  m_mulButton = new wxButton(this, ID_MUL_BUTTON, "*");
  m_divButton = new wxButton(this, ID_DIV_BUTTON, "/");
  m_equalsButton = new wxButton(this, ID_EQUAL_BUTTON, "=");

  // create decimal and plus/minus buttons
  m_deciButton = new wxButton(this, ID_DECI_BUTTON, ".");
  m_signButton = new wxButton(this, ID_SIGN_BUTTON, "+/-");

  // the order in which we add determines the place in the grid, so add in
  // row-major order.

  // first row
  for (int num = 1; num <= 3; ++num) {
    buttonSizer->Add(m_numButtons[num], wxEXPAND);
  }
  buttonSizer->Add(m_addButton, wxEXPAND);

  // second row
  for (int num = 4; num <= 6; ++num) {
    buttonSizer->Add(m_numButtons[num], wxEXPAND);
  }
  buttonSizer->Add(m_subButton, wxEXPAND);

  // third row
  for (int num = 7; num <= 9; ++num) {
    buttonSizer->Add(m_numButtons[num], wxEXPAND);
  }
  buttonSizer->Add(m_mulButton, wxEXPAND);

  // fourth row
  buttonSizer->Add(m_numButtons[0], wxEXPAND);

  buttonSizer->Add(m_deciButton, wxEXPAND);
  buttonSizer->Add(m_signButton, wxEXPAND);

  buttonSizer->Add(m_divButton, wxEXPAND);

  // special equals button in the last row and column, add three spacers to get
  // it into the last column
  buttonSizer->AddStretchSpacer();
  buttonSizer->AddStretchSpacer();
  buttonSizer->AddStretchSpacer();
  buttonSizer->Add(m_equalsButton, wxEXPAND);

  topSizer->Add(buttonSizer);

  SetSizerAndFit(topSizer);
}
