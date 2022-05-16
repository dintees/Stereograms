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
_image->LoadImg();
wxImage& image = _image->GetImage();
wxBitmap bitmap(image);
dc.DrawBitmap(bitmap, 0, 0, true);


wxClientDC dc2(p_Stereogram);
if (!_out) {
	_out = new Stereogram(_image, dc2.GetSize(), _image->GetImage().GetSize(), 6);
}
_out->generateStrips();
//_out->_output.convertToImg();
//dc2.DrawBitmap(wxBitmap(_out->_output.GetImage()),0,0,true);
}


