///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 1000,700 ), wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	b_LoadFromFile = new wxButton( this, wxID_ANY, wxT("Load from file"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( b_LoadFromFile, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer2->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	b_SaveToFile = new wxButton( this, wxID_ANY, wxT("Save to File"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( b_SaveToFile, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	b_Copy = new wxButton( this, wxID_ANY, wxT("Copy"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( b_Copy, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	b_Print = new wxButton( this, wxID_ANY, wxT("Print"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( b_Print, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticline11 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer2->Add( m_staticline11, 0, wxEXPAND | wxALL, 5 );

	color_checkbox = new wxCheckBox( this, wxID_ANY, wxT("Colour"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( color_checkbox, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	bSizer3->SetMinSize( wxSize( 800,600 ) );
	p_Stereogram = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	p_Stereogram->SetBackgroundColour( wxColour( 202, 202, 202 ) );
	p_Stereogram->SetMinSize( wxSize( 800,600 ) );

	bSizer3->Add( p_Stereogram, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	m_Menu1 = new wxMenu();
	wxMenuItem* m_PageSettings;
	m_PageSettings = new wxMenuItem( m_Menu1, wxID_ANY, wxString( wxT("Page &settings") ) , wxEmptyString, wxITEM_NORMAL );
	m_Menu1->Append( m_PageSettings );

	wxMenuItem* m_Preview;
	m_Preview = new wxMenuItem( m_Menu1, wxID_ANY, wxString( wxT("Print pre&view") ) , wxEmptyString, wxITEM_NORMAL );
	m_Menu1->Append( m_Preview );

	wxMenuItem* m_Print;
	m_Print = new wxMenuItem( m_Menu1, wxID_ANY, wxString( wxT("&Print") ) , wxEmptyString, wxITEM_NORMAL );
	m_Menu1->Append( m_Print );

	m_Menu1->AppendSeparator();

	wxMenuItem* m_Quit;
	m_Quit = new wxMenuItem( m_Menu1, wxID_ANY, wxString( wxT("&Quit") ) , wxEmptyString, wxITEM_NORMAL );
	m_Menu1->Append( m_Quit );

	m_menubar1->Append( m_Menu1, wxT("&File") );

	m_Menu2 = new wxMenu();
	wxMenuItem* m_About;
	m_About = new wxMenuItem( m_Menu2, wxID_ANY, wxString( wxT("&About") ) , wxEmptyString, wxITEM_NORMAL );
	m_Menu2->Append( m_About );

	m_menubar1->Append( m_Menu2, wxT("&Help") );

	this->SetMenuBar( m_menubar1 );


	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::MyFrame1OnPaint ) );
	b_LoadFromFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::b_LoadFromFile_Click ), NULL, this );
	b_SaveToFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::b_SaveToFile_Click ), NULL, this );
	b_Copy->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::b_Copy_Click ), NULL, this );
	b_Print->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::b_Print_Click ), NULL, this );
	color_checkbox->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::color_checkboxOnCheckBox ), NULL, this );
	m_Menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame1::m_PageSettings_Click ), this, m_PageSettings->GetId());
	m_Menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame1::m_Preview_Click ), this, m_Preview->GetId());
	m_Menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame1::m_Print_Click ), this, m_Print->GetId());
	m_Menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame1::m_Quit_Click ), this, m_Quit->GetId());
	m_Menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame1::m_About_Click ), this, m_About->GetId());
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::MyFrame1OnPaint ) );
	b_LoadFromFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::b_LoadFromFile_Click ), NULL, this );
	b_SaveToFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::b_SaveToFile_Click ), NULL, this );
	b_Copy->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::b_Copy_Click ), NULL, this );
	b_Print->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::b_Print_Click ), NULL, this );
	color_checkbox->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::color_checkboxOnCheckBox ), NULL, this );

}
