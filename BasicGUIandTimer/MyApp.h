#ifndef MYAPP_H
#define MYAPP_H

// Content from :
// https://www.youtube.com/watch?v=FOIbK4bJKS8
//   the program structure and button, text box, and list box
// https://docs.wxwidgets.org/stable/overview_helloworld.html
//   the menu and status bar

// Visual Studio
//   File -> New -> Project
//      Installed -> Visual C++ -> Other -> Empty Project

// System environment variable:  WXWIN = C:\Program Files\wxWidgets_3.1.3
// Configuration Properties/
//     General/Character Set:  Use Unicode Character Set
//     C/C++/General/Additional include directories:  $(WXWIN)\include;$(WXWIN)\include\msvc
//     C/C++/Precompiled headers/Precompiled Header: Not using precompiled headers
//     Linker/General/Additional library directories:  $(WXWIN)\lib\vc_lib

#include "wx/wx.h"
#include "MyFrame.h"

// int main() is masked by wxWidgets
// our new starting point is a class
// this is the application class...just a starting point... the launcher
// Practically every app should define a new class derived from wxApp. 
// By overriding wxApp's OnInit() virtual method the program can be initialized, 
//  e.g. by creating a new main window.
class MyApp : public wxApp {
public:
	MyApp();
	~MyApp();

	// tells launcher to display window
private:
	MyFrame* frame;

public:
	virtual bool OnInit();
};

#endif