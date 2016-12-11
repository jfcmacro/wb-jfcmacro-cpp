// Name:        minimal.cpp
// Purpose:     Minimal wxWidgets sample
// Author:      Julian Smart

#include <wx/wx.h>
#include <wx/notebook.h>

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

#include "mondrian.xpm"
#include "copy.xpm"
#include "cut.xpm"
#include "paste.xpm"

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

    // Now append the freshly created menu to the menu bar...
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, wxT("&File"));
    menuBar->Append(helpMenu, wxT("&Help"));

    // ... and attach this menu bar to the frame
    SetMenuBar(menuBar);

    // Create a status bar just for fun
    CreateStatusBar(2);
    SetStatusText(wxT("Welcome to wxWidgets!"));

    // Frame
    wxPanel *clientArea = new wxPanel(this, wxID_ANY,
                                      wxDefaultPosition,
                                      wxSize(500, 300));

    wxNotebook* notebook = new wxNotebook(clientArea, wxID_ANY,
                                          wxDefaultPosition, wxSize(300, 200));
    // Create the image list
    wxImageList* imageList = new wxImageList(16, 16, true, 3);
    imageList->Add(wxIcon(copy_xpm));
    imageList->Add(wxIcon(paste_xpm));
    imageList->Add(wxIcon(cut_xpm));

    notebook->SetImageList(imageList);
    
    // Create and add panel the pages
    wxPanel* window1 = new wxPanel(notebook, wxID_ANY);
    wxPanel* window2 = new wxPanel(notebook, wxID_ANY);
    wxPanel* window3 = new wxPanel(notebook, wxID_ANY);
                                      
    notebook->AddPage(window1, wxT("Tab one"), true, 0);
    notebook->AddPage(window2, wxT("Tab two"), false, 1);
    notebook->AddPage(window3, wxT("Tab three"), false, 2);
}

