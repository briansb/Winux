#ifndef MYFRAME_H
#define MYFRAME_H

#include <wx/wx.h>


// The main window is created by deriving a class from wxFrame and giving it a menu and a status bar in its constructor. 
// Also, any class that wishes to respond to any "event" (such as mouse clicks or messages from the menu or a button) 
// must declare an event table using the macro below.
// Finally, the way to react to such events must be done in "handlers".
// In our sample, we react to three menu items, one for our custom menu command and two for the standard "Exit" and "About" commands
//  (any program should normally implement the latter two).  Notice that these handlers don't need to be virtual or public.
// start of the GUI
class MyFrame : public wxFrame {  // equal to a form
public:
	//MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	MyFrame(const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, 
		    long style = wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxRAISED_BORDER | wxRESIZE_BORDER);

	~MyFrame();

	void OnTimer(wxTimerEvent & event);

	wxDECLARE_EVENT_TABLE();

private:
	// OneLoneCoder
	wxButton *btn;
	wxTextCtrl *txt;
	wxListBox *list;
	void OnButtonClicked(wxCommandEvent &evt);

	// wxWidgets tutorial 
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

	// timer 
	wxTimer *m_timer;
	int counter = 0;
	wxTextCtrl *txt_timer;

	// for launching stressors
	wxButton *btnLaunchStressor;

};

// In order to be able to react to a menu command, it must be given a unique identifier which can be defined as a const variable or an enum element. 
// The latter is often used because typically many such constants will be needed.
// Notice that you don't need to define identifiers for the "About" and "Exit". 
// We then proceed to actually implement an event table in which the events are routed to their respective handler functions in the class MyFrame.
enum
{
	ID_Hello = 1,
	ID_VALUE_TEXTCTRL = 10001,
	ID_STATUS_TEXTCTRL,
	ID_TEST_TIMER,

};

#endif