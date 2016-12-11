/* Name:        wxFrameExample.cpp
 * Purpose:     Minimal wxWidgets sample with a frame
 * Author:      Julian Smart
 * Mantainer:   Juan Francisco Cardona McCormick (jfcmacro@gmail.com)
 * ------------------------------------
 * History of modifications
 * 11.12.2016  jfcmacro  Adding wxFrame
 */

#include <wx/wx.h>
#include <iostream>

using namespace std;

const wxWindowID wxID_EndButton = wxWindow::NewControlId();
const wxWindowID wxID_EndButton2 = wxWindow::NewControlId();

// Declare the application class
class MyApp : public wxApp
{
public:
  // Called on application startup
  virtual bool OnInit();
};

// Declare our main frame class
class MyFrame : public wxFrame
{
public:
  // Constructor
  MyFrame(const wxString& title);

  // Event handlers
  void OnQuit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnQuit2(wxCommandEvent& event);
  void OnQuit3(wxCommandEvent& event);
private:
  // This class handles events
  DECLARE_EVENT_TABLE()
};

// Implements MyApp& GetApp()
DECLARE_APP(MyApp)

// Give wxWidgets the means to create a MyApp object
IMPLEMENT_APP(MyApp)

// Initialize the application
bool MyApp::OnInit()
{
  // Create the main application window
  MyFrame *frame = new MyFrame(wxT("Minimal wxWidgets App"));

  // Show it
  frame->Show(true);

  // Start the event loop
  return true;
}

// Event table for MyFrame
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_MENU(wxID_EXIT,  MyFrame::OnQuit)
EVT_BUTTON(wxID_EndButton, MyFrame::OnQuit2)
EVT_BUTTON(wxID_EndButton2, MyFrame::OnQuit3)
END_EVENT_TABLE()


void MyFrame::OnAbout(wxCommandEvent& event)
{
  wxString msg;
  msg.Printf(wxT("Hello and welcome to %s"),  
             wxVERSION_STRING);

  wxMessageBox(msg, wxT("About Minimal"),
               wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent& event)
{
  // Destroy the frame
  Close();
}

void MyFrame::OnQuit2(wxCommandEvent& event) {

  cout << event.GetInt() << " " << event.GetExtraLong() << endl;
  Close();
}

void MyFrame::OnQuit3(wxCommandEvent& event) {

  cout << "Button 2" << endl;
  Close();
}

#include "mondrian.xpm"

MyFrame::MyFrame(const wxString& title)
  : wxFrame(NULL, wxID_ANY, title)
{
  // Set the frame icon
  SetIcon(wxIcon(mondrian_xpm));

  // Create a menu bar
  wxMenu *fileMenu = new wxMenu;

  // The "About" item should be in the help menu
  wxMenu *helpMenu = new wxMenu;
  helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"),
                   wxT("Show about dialog"));

  fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"),
                   wxT("Quit this program"));

  wxPanel *panel = new wxPanel(this,
                               wxID_ANY,
                               wxDefaultPosition,
                               wxSize(500, 300));

  wxButton *button = new wxButton(panel,
                                  wxID_EndButton,
                                  wxT("This is the end!"),
                                  wxPoint(30,60),
                                  wxSize(100,100));

  wxButton *button2 = new wxButton(panel,
                                   wxID_EndButton2,
                                   wxT("This another"),
                                   wxPoint(30,200),
                                   wxSize(100,100));
  

  // Now append the freshly created menu to the menu bar...
  wxMenuBar *menuBar = new wxMenuBar();
  menuBar->Append(fileMenu, wxT("&File"));
  menuBar->Append(helpMenu, wxT("&Help"));

  // ... and attach this menu bar to the frame
  SetMenuBar(menuBar);

  // Create a status bar just for fun
  CreateStatusBar(2);
  SetStatusText(wxT("Welcome to wxWidgets!"));
}

