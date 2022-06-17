#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include
#include <wx/wxprec.h>
#include <wx/dcclient.h>
#include <wx/filedlg.h>
#include <wx/clipbrd.h>
#include <memory>
#include "ImageHolder.h"
#include "Printout.h"
#include "RDS.h"

/**
* @brief class with all GUI functionalities
* @tparam ImageHolder* pointer to object which keeps the current image
* @tparam std::shared_ptr<wxPageSetupDialogData> data used for printing
*/

/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
	protected:
		// Handlers for MyFrame1 events.
		void MyFrame1OnPaint( wxPaintEvent& event );
		void b_LoadFromFile_Click( wxCommandEvent& event );
		void b_SaveToFile_Click( wxCommandEvent& event );
		void b_Copy_Click( wxCommandEvent& event );
		void b_Print_Click( wxCommandEvent& event );
		void m_PageSettings_Click( wxCommandEvent& event );
		void m_Preview_Click( wxCommandEvent& event );
		void m_Print_Click( wxCommandEvent& event );
		void m_Quit_Click( wxCommandEvent& event );
		void m_About_Click( wxCommandEvent& event );
	public:
		/** Constructor */
		GUIMyFrame1( wxWindow* parent );
	//// end generated class members
private:
	ImageHolder* _image = nullptr;
	std::shared_ptr<wxPageSetupDialogData> _pageSetupData;
	bool _isLoaded = false;

	Stereogram* o_stereogram = nullptr;
	void show_img();


};

#endif // __GUIMyFrame1__
