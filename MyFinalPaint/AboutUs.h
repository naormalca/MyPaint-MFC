#pragma once


// AboutUs dialog

class AboutUs : public CDialog
{
	DECLARE_DYNAMIC(AboutUs)

public:
	AboutUs(CWnd* pParent = NULL);   // standard constructor
	virtual ~AboutUs();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
