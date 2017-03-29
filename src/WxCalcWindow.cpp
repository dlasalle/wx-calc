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
  wxFrame(NULL, wxID_ANY, "Wx-Calc", wxPoint(100,100), wxDefaultSize)
{
  wxBoxSizer * topSizer = new wxBoxSizer(wxVERTICAL);

  m_display = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition,
      wxDefaultSize, 0); 
  // There is a wxTE_READONLY style option, but it still allow selecting
  m_display->Disable();
  // have the text span our window horizontally
  wxBoxSizer * displaySizer = new wxBoxSizer(wxHORIZONTAL);
  displaySizer->Add(m_display, 1, wxEXPAND | wxALL, 0);

  // we don't want this to expand vertically
  topSizer->Add(displaySizer, 0, wxEXPAND, 0);

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
    buttonSizer->Add(m_numButtons[num], 1, wxEXPAND, 0);
  }
  buttonSizer->Add(m_addButton, 1, wxEXPAND, 0);

  // second row
  for (int num = 4; num <= 6; ++num) {
    buttonSizer->Add(m_numButtons[num], 1, wxEXPAND, 0);
  }
  buttonSizer->Add(m_subButton, 1, wxEXPAND, 0);

  // third row
  for (int num = 7; num <= 9; ++num) {
    buttonSizer->Add(m_numButtons[num], 1, wxEXPAND, 0);
  }
  buttonSizer->Add(m_mulButton, 1, wxEXPAND, 0);

  // fourth row
  buttonSizer->Add(m_numButtons[0], 1, wxEXPAND, 0);

  buttonSizer->Add(m_deciButton, 1, wxEXPAND, 0);
  buttonSizer->Add(m_signButton, 1, wxEXPAND, 0);

  buttonSizer->Add(m_divButton, 1, wxEXPAND, 0);

  // special equals button in the last row and column, add three spacers to get
  // it into the last column
  buttonSizer->AddStretchSpacer();
  buttonSizer->AddStretchSpacer();
  buttonSizer->AddStretchSpacer();
  buttonSizer->Add(m_equalsButton, 1, wxEXPAND, 0);

  topSizer->Add(buttonSizer, 1, wxEXPAND, 0);

  SetSizerAndFit(topSizer);
}
