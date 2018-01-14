// SignatureDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MyFinalPaint.h"
#include "SignatureDialog.h"
#include "afxdialogex.h"


// SignatureDialog dialog

IMPLEMENT_DYNAMIC(SignatureDialog, CDialog)

SignatureDialog::SignatureDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
	, signatureValue(_T(""))
{

}

SignatureDialog::~SignatureDialog()
{
}

void SignatureDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SigantureValue, signatureValue);
}



BEGIN_MESSAGE_MAP(SignatureDialog, CDialog)
END_MESSAGE_MAP()


// SignatureDialog message handlers
