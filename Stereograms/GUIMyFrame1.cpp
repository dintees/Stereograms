#include "GUIMyFrame1.h"
//#include <cassert>

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	_image = new ImageHolder();
	_pageSetupData = std::shared_ptr<wxPageSetupDialogData>(new wxPageSetupDialogData);
}

void GUIMyFrame1::MyFrame1OnPaint(wxPaintEvent& event)
{
	show_img();
}

void GUIMyFrame1::b_LoadFromFile_Click(wxCommandEvent& event)
{
	_isLoaded = _image->LoadImg();
	if (_isLoaded)
	{
		if (o_stereogram != nullptr) {
			delete o_stereogram;
			o_stereogram = nullptr;
		}

		o_stereogram = new Stereogram(_image, wxSize(800,600), 8);
		//assert(("Wrong size", o_stereogram->GetSize().x == 800));
		//assert(("Wrong size", o_stereogram->GetSize().y == 600));
		o_stereogram->generateStrips(color_checkbox->IsChecked());
	}

	show_img();
}

void GUIMyFrame1::b_SaveToFile_Click(wxCommandEvent& event)
{
	// TODO: Implement b_SaveToFile_Click
	if (o_stereogram && o_stereogram->GetImg().IsOk()) {
		wxFileDialog fileDialog(this, "", "", "", "BMP files (*.bmp)|*.bmp", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
		if (fileDialog.ShowModal() == wxID_CANCEL)
			return;
		o_stereogram->GetImg().SaveFile(fileDialog.GetPath());
	}
	else {
		wxMessageBox(_("No stereogram has been generated."));
	}
}

void GUIMyFrame1::b_Copy_Click(wxCommandEvent& event)
{
	// TODO: Implement b_Copy_Click
	if (o_stereogram && o_stereogram->GetImg().IsOk()) {
		if (wxTheClipboard->Open())
		{
			wxTheClipboard->SetData(new wxBitmapDataObject(wxBitmap(o_stereogram->GetImg())));
			wxTheClipboard->Close();
		}
	}
	else {
		wxMessageBox(_("No stereogram has been generated."));
	}
}

void GUIMyFrame1::b_Print_Click(wxCommandEvent& event)
{
	// TODO: Implement b_Print_Click
	m_Print_Click(event);
}

void GUIMyFrame1::color_checkboxOnCheckBox(wxCommandEvent& event)
{
	// TODO: Implement color_checkboxOnCheckBox
	if (o_stereogram) {
		o_stereogram->generateStrips(color_checkbox->IsChecked());
		show_img();
	}
}

void GUIMyFrame1::m_PageSettings_Click(wxCommandEvent& event)
{
	// TODO: Implement m_PageSettings_Click
	if (DefaultPrinterAvailable()) {
		wxPageSetupDialog PageSetupDlg(this, _pageSetupData.get());
		PageSetupDlg.ShowModal();
		*_pageSetupData = PageSetupDlg.GetPageSetupData();
	}
	else {
		show_img();
		wxMessageBox(_("No default printer found."));
	}

}

void GUIMyFrame1::m_Preview_Click(wxCommandEvent& event)
{
	// TODO: Implement m_Preview_Click
	if (o_stereogram && o_stereogram->GetImg().IsOk()) {
		if (DefaultPrinterAvailable()) {
			wxPrintPreview* preview = new wxPrintPreview(new Printout(_pageSetupData, o_stereogram->GetImg()));
			wxPreviewFrame* frame = new wxPreviewFrame(preview, this, wxT("Print preview"), wxPoint(20, 20), wxSize(400, 600));
			if (!preview->IsOk()) delete preview;
			frame->Centre(wxBOTH);
			frame->Initialize();
			frame->Show();
		}
		else {
			show_img();
			wxMessageBox(_("No default printer found."));
		}
	}
	else {
		wxMessageBox(_("No stereogram has been generated."));
	}
}

void GUIMyFrame1::m_Print_Click(wxCommandEvent& event)
{
	// TODO: Implement m_Print_Click
	if (o_stereogram && o_stereogram->GetImg().IsOk()) {
		wxPrinter Printer;
		Printout MyPrintout(_pageSetupData, o_stereogram->GetImg());
		Printer.Print(this, &MyPrintout, true);
	}
	else {
		wxMessageBox(_("No stereogram has been generated."));
	}
}

void GUIMyFrame1::m_Quit_Click(wxCommandEvent& event)
{
	// TODO: Implement m_Quit_Click
	Destroy();
}

void GUIMyFrame1::m_About_Click(wxCommandEvent& event)
{
	// TODO: Implement m_About_Click
	wxMessageBox(L"Program that creates a stereogram from a given image. The image should be 800x600 pixels in size.\n \nViewing the stereogram, the recommended distance from the monitor is 40-60 cm. Keep looking until you see the three squares at the top of the picture. \n \nAuthors: Damian \x141yszczarz, Bart\x142omiej Wypart, Piotr G\x119\x62\x61lski\nVersion 2.1", _("About"), wxICON_INFORMATION);
}


void GUIMyFrame1::show_img()
{
	wxClientDC dc2(p_Stereogram);

	if (o_stereogram) {
		p_Stereogram->ClearBackground();
		wxImage& image = o_stereogram->GetImg();
		wxImage tmpImage = image;

		float marginLeft = p_Stereogram->GetSize().x / 2 - image.GetSize().x / 2;
		float marginTop = p_Stereogram->GetSize().y / 2 - image.GetSize().y / 2;

		wxBitmap bitmap(tmpImage);
		dc2.DrawBitmap(bitmap, marginLeft, marginTop, true);
	}
}