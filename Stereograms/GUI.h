///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxButton* b_LoadFromFile;
		wxStaticLine* m_staticline1;
		wxButton* b_CreateStereogram;
		wxButton* b_SaveToFile;
		wxButton* b_Copy;
		wxButton* b_Print;
		wxPanel* p_OriginalImage;
		wxStaticLine* m_staticline2;
		wxPanel* p_Stereogram;
		wxMenuBar* m_menubar1;
		wxMenu* m_Menu1;
		wxMenu* m_Menu2;

		// Virtual event handlers, override them in your derived class
		virtual void b_LoadFromFile_Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void b_SaveToFile_Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void b_Copy_Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void b_Print_Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_PageSettings_Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_Preview_Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_Print_Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_Quit_Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_About_Click( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Stereograms"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 740,690 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

