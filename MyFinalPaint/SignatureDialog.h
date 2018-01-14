#pragma once


// SignatureDialog dialog

class SignatureDialog : public CDialog
{
	DECLARE_DYNAMIC(SignatureDialog)

public:
	SignatureDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~SignatureDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString signatureValue;
};
