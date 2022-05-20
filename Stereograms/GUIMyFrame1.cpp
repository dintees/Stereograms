#include "GUIMyFrame1.h"

#include <wx/dcclient.h>

#include "ImageHolder.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent ), _image(new ImageHolder())
{

}

void GUIMyFrame1::b_LoadFromFile_Click( wxCommandEvent& event )
{
	p_OriginalImage->ClearBackground(); // remove old photo from panel
	wxClientDC dc(p_OriginalImage);
	_image->SetPanelSize(dc.GetSize());
	bool isLoaded = _image->LoadImg();
	if (isLoaded == true)
	{
		wxImage& image = _image->GetImage();
		wxBitmap bitmap(image);
		dc.DrawBitmap(bitmap, 0, 0, true);
	}
}


