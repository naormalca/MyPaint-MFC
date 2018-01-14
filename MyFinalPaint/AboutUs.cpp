// AboutUs.cpp : implementation file
//

#include "stdafx.h"
#include "MyFinalPaint.h"
#include "AboutUs.h"
#include "afxdialogex.h"


// AboutUs dialog

IMPLEMENT_DYNAMIC(AboutUs, CDialog)

AboutUs::AboutUs(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG2, pParent)
{

}

AboutUs::~AboutUs()
{
}

void AboutUs::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AboutUs, CDialog)
	ON_BN_CLICKED(IDOK, &AboutUs::OnBnClickedOk)
END_MESSAGE_MAP()


// AboutUs message handlers


void AboutUs::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
