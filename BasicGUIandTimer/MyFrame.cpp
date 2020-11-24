#include "MyFrame.h"



// There are predefined macros for routing all common events, ranging from the selection of a list box entry 
// to a resize event when a user resizes a window on the screen. 
// If wxID_ANY is given as the ID, the given handler will be invoked for any event of the specified type, 
// so that you could add just one entry in the event table for all menu commands or all button commands etc.
// The origin of the event can still be distinguished in the event handler as the (only) parameter in an event handler is a reference to a wxEvent object,  
// which holds various information about the event (such as the ID of and a pointer to the class, which emitted the event).
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_BUTTON(10001, MyFrame::OnButtonClicked)
EVT_BUTTON(10010, MyFrame::OnButtonClicked)
EVT_MENU(ID_Hello, MyFrame::OnHello)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_TIMER(ID_TEST_TIMER, MyFrame::OnTimer)
wxEND_EVENT_TABLE()


// In the constructor of the main window (or later on) we create a menu with our menu items 
// as well as a status bar to be shown at the bottom of the main window. 
// Both have to be associated with the frame with respective calls.
// Notice that we don't need to specify the labels for the standard menu items wxID_ABOUT and wxID_EXIT, 
// as they will be given standard (even correctly translated) labels and also standard accelerators correct for the current platform,
// making your program behaviour more native. For this reason you should prefer reusing the standard ids (see Stock Items) if possible.
// overriding wxFrame() constructor - NULL value since this window has no parent
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style) : 
	    wxFrame(NULL, wxID_ANY, title, pos, size, style) {

	// OneLoneCoder stuff
	btn = new wxButton(this, 10001, "Click Me", wxPoint(100, 80), wxSize(150, 50));
	txt = new wxTextCtrl(this, wxID_ANY, "destination....list box", wxPoint(100, 150), wxSize(300, 30));
	list = new wxListBox(this, wxID_ANY, wxPoint(100, 210), wxSize(300, 280));

	// wxWidgets tutorial
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");

	// timer
	m_timer = new wxTimer(this, ID_TEST_TIMER);
	m_timer->Start(500);
	txt_timer = new wxTextCtrl(this, wxID_ANY, "initial value of text box", wxPoint(450, 150), wxSize(150, 30));

	// launch stressors
	btnLaunchStressor = new wxButton(this, 10010, "Launch Stressor", wxPoint(450,80), wxSize(150, 50));

}

MyFrame::~MyFrame() {
	if (m_timer) wxDELETE(m_timer);
	//wxMessageBox("Closing gracefully in destructor");
	Close(true);
}

void MyFrame::OnButtonClicked(wxCommandEvent &evt) {
	if (evt.GetId() == 10001) {
		list->AppendString(txt->GetValue());
	}
	if (evt.GetId() == 10010) {
		// ToDo:  need Winux solution
		//wxString strLaunchCommand = "./stressor";
		//wxString strLaunchCommand = "gnome-terminal -x sh -c './stressor; exec bash'";
		wxString strLaunchCommand = "stressor.exe";

		wxExecute(strLaunchCommand, wxEXEC_ASYNC | wxEXEC_SHOW_CONSOLE);
		//std::system(strLaunchCommand);
		//wxShell("ls");
	}

	
	evt.Skip();  // don't check the parents for click event. It's been handled.
}

// Here are the standard event handlers implementations. MyFrame::OnExit() closes the main window by calling Close(). 
// The parameter true indicates that other windows have no veto power such as after asking "Do you really want to close?". 
// If there is no other main window left, the application will quit.
void MyFrame::OnExit(wxCommandEvent& event)
{
	event.GetId(); /* only needed to lose compiler warnings */
	//wxMessageBox("Closing gracefully in OnExit");
	Close(true);
}

// MyFrame::OnAbout() will display a small window with some text in it. In this case a typical "About" window with information about the program.
void MyFrame::OnAbout(wxCommandEvent& event)
{
	event.GetId(); /* only needed to lose compiler warnings */
	wxMessageBox("This is a wxWidgets' Hello world sample",
		"About Hello World", wxOK | wxICON_INFORMATION);
}

// The implementation of custom menu command handler may perform whatever task your program needs to do, 
// in this case we will simply show a message from it as befits a hello world example:
void MyFrame::OnHello(wxCommandEvent& event)
{
	event.GetId(); /* only needed to lose compiler warnings */
	wxLogMessage("Hello world from wxWidgets!");
}
void MyFrame::OnTimer(wxTimerEvent & event)
{
	//wxMessageBox(_("Timer Test"));
	txt_timer->SetValue("Loop number " + std::to_string(counter));
	counter += 1;
}