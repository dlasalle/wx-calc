/**
 * @file WxCalcWindow.cpp
 * @brief The implementation of the window class for the calculator.
 * @author Dominique LaSalle <dominique@solidlake.com>
 * Copyright 2017, Solid Lake LLC
 * @version 1
 * @date 2017-03-28
 */

#include "WxCalcWindow.hpp"
#include <stdexcept>
#include <cstdint>

namespace
{

enum event_ids {
  // important these map to the numbers
  ID_0_BUTTON = 0,
  ID_1_BUTTON = 1,
  ID_2_BUTTON = 2,
  ID_3_BUTTON = 3,
  ID_4_BUTTON = 4,
  ID_5_BUTTON = 5,
  ID_6_BUTTON = 6,
  ID_7_BUTTON = 7,
  ID_8_BUTTON = 8,
  ID_9_BUTTON = 9,
  // let these be auto assigned
  ID_DECI_BUTTON,
  ID_SIGN_BUTTON,
  ID_ADD_BUTTON,
  ID_SUB_BUTTON,
  ID_MUL_BUTTON,
  ID_DIV_BUTTON,
  ID_EQUAL_BUTTON
};

}


/******************************************************************************
* PRIVATE FUNCTIONS ***********************************************************
******************************************************************************/

double WxCalcWindow::getCurrentValue()
{
  return std::stod(std::string(m_display->GetValue().mb_str()));
}

void WxCalcWindow::updateDisplay()
{
  // this is not an efficient way to construct a number, but the user won't
  // notice a few ms here.
  std::string numStr("");
  if (!m_positive) {
    numStr += "-";
  }

  numStr += m_preDecimal;
  if (m_decimal) {
    numStr += "." + m_postDecimal;
  }

  m_display->SetValue(numStr); 
}

void WxCalcWindow::clear()
{
  m_preDecimal.assign("");
  m_postDecimal.assign("");
  m_decimal = false;
  m_positive = true;
  m_total = 0;
}

void WxCalcWindow::clearAndStore()
{
  m_total = getCurrentValue();

  // reset
  clear();

  updateDisplay();
}

void WxCalcWindow::performOp()
{
  if (m_op < 0) {
    // no op loaded -- do nothing
  } else {
    switch (m_op) {
      case ID_ADD_BUTTON: {
        m_total += getCurrentValue();
        break;
      }
      case ID_SUB_BUTTON: {
        m_total -= getCurrentValue();
        break;
      }
      case ID_MUL_BUTTON: {
        m_total *= getCurrentValue();
        break;
      }
      case ID_DIV_BUTTON: {
        const double val = getCurrentValue();
        if (val != 0) {
          m_total /= val;
        }
        // show an error some how
        break;
      }
      default:
        throw std::runtime_error("Unknown OP: " + std::to_string(m_op));
    }
    showTotal();
  }
}

void WxCalcWindow::showTotal()
{
  clear();
  m_display->SetValue(std::to_string(m_total));
}

template<int NUM>
void WxCalcWindow::onNumButton(
    wxCommandEvent&)
{
  // accumulate number
  if (!m_decimal) {
    m_preDecimal += std::to_string(NUM);
  } else { 
    m_postDecimal += std::to_string(NUM);
  }

  updateDisplay();
}

template<int OP>
void WxCalcWindow::onOpButton(
    wxCommandEvent&)
{
  switch (OP) {
    case ID_DECI_BUTTON: {
      m_decimal = true;
      updateDisplay();
      break;
    }
    case ID_SIGN_BUTTON: {
      m_positive = !m_positive;
      updateDisplay();
      break;
    }
    case ID_ADD_BUTTON:
    case ID_SUB_BUTTON:
    case ID_MUL_BUTTON:
    case ID_DIV_BUTTON: {
      performOp();
      clearAndStore();
      showTotal();
      m_op = OP;
      break;
    }
    case ID_EQUAL_BUTTON: {
      performOp();
      break;
    }
  }
}


/******************************************************************************
* EVENT TABLE *****************************************************************
******************************************************************************/

#define NUM_EVENT(id) \
  EVT_BUTTON(id, WxCalcWindow::onNumButton<id>)

#define OP_EVENT(id) \
  EVT_BUTTON(id, WxCalcWindow::onOpButton<id>)

// declare the window's event table
wxBEGIN_EVENT_TABLE(WxCalcWindow, wxFrame)
  // the numbers
  NUM_EVENT(ID_0_BUTTON)
  NUM_EVENT(ID_1_BUTTON)
  NUM_EVENT(ID_2_BUTTON)
  NUM_EVENT(ID_3_BUTTON)
  NUM_EVENT(ID_4_BUTTON)
  NUM_EVENT(ID_5_BUTTON)
  NUM_EVENT(ID_6_BUTTON)
  NUM_EVENT(ID_7_BUTTON)
  NUM_EVENT(ID_8_BUTTON)
  NUM_EVENT(ID_9_BUTTON)
  OP_EVENT(ID_DECI_BUTTON)
  OP_EVENT(ID_SIGN_BUTTON)
  OP_EVENT(ID_ADD_BUTTON)
  OP_EVENT(ID_SUB_BUTTON)
  OP_EVENT(ID_MUL_BUTTON)
  OP_EVENT(ID_DIV_BUTTON)
  OP_EVENT(ID_EQUAL_BUTTON)
wxEND_EVENT_TABLE()



/******************************************************************************
* PUBLIC FUNCTIONS ************************************************************
******************************************************************************/

WxCalcWindow::WxCalcWindow() :
  wxFrame(NULL, wxID_ANY, "Wx-Calc", wxPoint(100,100), wxDefaultSize),
  m_display(nullptr),
  m_numButtons(),
  m_deciButton(nullptr),
  m_signButton(nullptr),
  m_addButton(nullptr),
  m_subButton(nullptr),
  m_mulButton(nullptr),
  m_divButton(nullptr),
  m_equalsButton(nullptr),
  m_preDecimal(),
  m_postDecimal(),
  m_decimal(false),
  m_positive(true),
  m_total(0),
  m_op(-1)
{
  wxBoxSizer * topSizer = new wxBoxSizer(wxVERTICAL);

  m_display = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition,
      wxDefaultSize, wxTE_RIGHT); 
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
  m_numButtons.resize(10);
  for (int num = 0; num < 10; ++num) {
    m_numButtons[num] = new wxButton(this, num, std::to_string(num));
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
