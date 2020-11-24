#include "MyApp.h"

// defines starting point main or WinMain, which is the Windows-compliant main
// As in all programs there must be a "main" function. 
// Under wxWidgets main is implemented using this macro, which creates an application instance and starts the program.
//wxDECLARE_APP(MyApp)
wxIMPLEMENT_APP(MyApp);

MyApp::MyApp() {}
MyApp::~MyApp() {}

// wxApp::OnInit() is called upon startup and should be used to initialize the program, 
// maybe showing a "splash screen" and creating the main window (or several). 
// The frame should get a title bar text ("Hello World") and a position and start-up size. 
// One frame can also be declared to be the top window. Returning true indicates a successful initialization.
bool MyApp::OnInit() {
	// create new instance of MyFrame(a window) and show it
	frame = new MyFrame("GUI example with running loop", wxPoint(50, 50), wxSize(800, 600));
	// not required, but nice to have
	//SetTopWindow(frame);
	//frame->Centre();
	frame->Show();
	return true;
}