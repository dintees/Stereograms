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
	this->SetSizeHints( wxSize( 600,550 ), wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	b_LoadFromFile = new wxButton( this, wxID_ANY, wxT("Load from file"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( b_LoadFromFile, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer2->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	b_CreateStereogram = new wxButton( this, wxID_ANY, wxT("Create stereogram"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( b_CreateStereogram, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	b_SaveToFile = new wxButton( this, wxID_ANY, wxT("Save to File"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( b_SaveToFile, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	b_Copy = new wxButton( this, wxID_ANY, wxT("Copy"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( b_Copy, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	b_Print = new wxButton( this, wxID_ANY, wxT("Print"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( b_Print, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	p_OriginalImage = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	p_OriginalImage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );

	bSizer3->Add( p_OriginalImage, 1, wxEXPAND | wxALL, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	p_Stereogram = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	p_Stereogram->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );

	bSizer3->Add( p_Stereogram, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

MyFrame1::~MyFrame1()
{
}
