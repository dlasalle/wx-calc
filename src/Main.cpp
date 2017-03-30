/**
 * @file Main.cpp
 * @brief The main function. 
 * @author Dominique LaSalle <dominique@solidlake.com>
 * Copyright 2017, Solid Lake LLC
 * @version 1
 * @date 2017-03-13
 */

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/display.h>
#include "WxCalcWindow.hpp"

class App:
  public wxApp
{
  public:
    virtual bool OnInit()
		{
				wxDisplay disp;

				WxCalcWindow * win = new WxCalcWindow();
				win->Show(true);

				return true;
		}
};

wxIMPLEMENT_APP(App);
