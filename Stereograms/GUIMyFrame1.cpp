#include "GUIMyFrame1.h"

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
	wxClientDC dc(p_OriginalImage);
	_image->SetPanelSize(dc.GetSize());

	_isLoaded = _image->LoadImg();
	if (_isLoaded)
	{
		if (o_stereogram != nullptr) {
			delete o_stereogram;
			o_stereogram = nullptr;
		}

		o_stereogram = new Stereogram(_image, _image->GetSize(), 10);
		o_stereogram->generateStrips();
	}

	show_img();
}

void GUIMyFrame1::b_SaveToFile_Click(wxCommandEvent& event)
{
	// TODO: Implement b_SaveToFile_Click
	if (o_stereogram && o_stereogram->GetImg().IsOk()) {
		wxFileDialog fileDialog(this, "", "", "", "PNG files (*.png)|*.png|JPG files (*.jpg)|*.jpg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
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
	wxMessageBox(_("Maybe some modal Window with the description of this program..."));
}


void GUIMyFrame1::show_img()
{
	wxClientDC dc(p_OriginalImage);
	if (_isLoaded)
	{
		p_OriginalImage->ClearBackground(); // remove old photo from panel
		wxImage& image = _image->GetImage();
		wxBitmap bitmap(image);
		dc.DrawBitmap(bitmap, 0, 0, true);
	}

	wxClientDC dc2(p_Stereogram);

	if (o_stereogram) {
		p_Stereogram->ClearBackground();

		/*wxImage im(o_stereogram->GetSize(), o_stereogram->getBitmap());
		unsigned char* test = o_stereogram->getBitmap();*/
		wxBitmap bmp(o_stereogram->GetImg());
		dc2.DrawBitmap(bmp, 0, 0, true);
	}
}