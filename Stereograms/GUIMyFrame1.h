#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include
#include "ImageHolder.h"
#include "RDS.h"

/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
	protected:
		// Handlers for MyFrame1 events.
		void b_LoadFromFile_Click( wxCommandEvent& event );
	public:
		/** Constructor */
		GUIMyFrame1( wxWindow* parent );
	//// end generated class members
	private:
		ImageHolder* _image;
		Stereogram* _out;

};

#endif // __GUIMyFrame1__
