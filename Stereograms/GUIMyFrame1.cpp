#include "GUIMyFrame1.h"
#include "Printout.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	_image = new ImageHolder();
	_pageSetupData = std::shared_ptr<wxPageSetupDialogData>(new wxPageSetupDialogData);
}

void GUIMyFrame1::b_LoadFromFile_Click(wxCommandEvent& event)
{
	p_OriginalImage->ClearBackground(); // remove old photo from panel
	wxClientDC dc(p_OriginalImage);
	_image->SetPanelSize(dc.GetSize());
	_image->LoadImg();
	wxImage& image = _image->GetImage();
	wxBitmap bitmap(image);
	dc.DrawBitmap(bitmap, 0, 0, true);
}

void GUIMyFrame1::b_SaveToFile_Click(wxCommandEvent& event)
{
	// TODO: Implement b_SaveToFile_Click
	if (_image->GetImage().IsOk()) {
		wxFileDialog fileDialog(this, "", "", "", "PNG files (*.png)|*.png|JPG files (*.jpg)|*.jpg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
		if (fileDialog.ShowModal() == wxID_CANCEL)
			return;
		_image->GetImage().SaveFile(fileDialog.GetPath());
	}
	else {
		wxMessageBox(_("No stereogram has been generated."));
	}
}

void GUIMyFrame1::b_Copy_Click(wxCommandEvent& event)
{
	// TODO: Implement b_Copy_Click
	if (_image->GetImage().IsOk()) {
		if (wxTheClipboard->Open())
		{
			wxTheClipboard->SetData(new wxBitmapDataObject(wxBitmap(_image->GetImage())));
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
	wxPageSetupDialog PageSetupDlg(this, _pageSetupData.get());
	PageSetupDlg.ShowModal();
	*_pageSetupData = PageSetupDlg.GetPageSetupData();
}

void GUIMyFrame1::m_Preview_Click(wxCommandEvent& event)
{
	// TODO: Implement m_Preview_Click
	if (_image->GetImage().IsOk()) {
		wxPrintPreview* preview = new wxPrintPreview(new Printout(_pageSetupData, _image->GetImage()));
		wxPreviewFrame* frame = new wxPreviewFrame(preview, this, wxT("Print preview"), wxPoint(20, 20), wxSize(400, 600));
		if (!preview->IsOk()) delete preview;
		frame->Centre(wxBOTH);
		frame->Initialize();
		frame->Show();
	}
	else {
		wxMessageBox(_("No stereogram has been generated."));
	}
}

void GUIMyFrame1::m_Print_Click(wxCommandEvent& event)
{
	// TODO: Implement m_Print_Click
	if (_image->GetImage().IsOk()) {
		wxPrinter Printer;
		Printout MyPrintout(_pageSetupData, _image->GetImage());
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
