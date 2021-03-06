
// MyFinalPaintDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyFinalPaint.h"
#include "MyFinalPaintDlg.h"
#include "afxdialogex.h"
#include "SignatureDialog.h"
#include "AboutUs.h"
#include "AddCommand.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:

};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

//	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// CMyFinalPaintDlg dialog



CMyFinalPaintDlg::CMyFinalPaintDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MYFINALPAINT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyFinalPaintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}
//Connect between actions to functions
BEGIN_MESSAGE_MAP(CMyFinalPaintDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_BUTTON1, onToolBarRectangle)
	ON_BN_CLICKED(ID_BUTTON2, onToolBarLine)
	ON_BN_CLICKED(ID_BUTTON3, onToolBarEllipse)
	ON_BN_CLICKED(ID_BUTTON4, onToolBarTriangle)
	ON_BN_CLICKED(BACKGROUND1, onToolBarBackground)
	ON_BN_CLICKED(BORDERCOLOR, onToolBarBorderColor)
	ON_BN_CLICKED(ID_BUTTON_UNDO,onToolBarUndo)
	ON_BN_CLICKED(ID_BUTTON_REDO,onToolBarRedo)
	ON_COMMAND(ID_FILE_SAVE, onButtonSave)
	ON_COMMAND(ID_FILE_LOAD, onButtonLoad)
	ON_COMMAND(ID_FILE_CLEAN, onButtonClean)



ON_WM_LBUTTONDOWN()
ON_WM_MOUSEMOVE()
ON_WM_LBUTTONUP()
ON_WM_RBUTTONDOWN()
ON_WM_RBUTTONUP()

ON_COMMAND(ID_FEATURES_MAKESIGNATURE, &CMyFinalPaintDlg::OnFeaturesMakesignature)
ON_COMMAND(ID_SMALLBORDER, &CMyFinalPaintDlg::onToolBarSmallborder)
ON_COMMAND(ID_BORDERMEDIUM, &CMyFinalPaintDlg::onToolBarMediumBorder)
ON_COMMAND(ID_LARGEBORDER, &CMyFinalPaintDlg::onToolBarLargeBorder)
ON_WM_TIMER()
ON_COMMAND(ID_FEATURES_DISCOMODON, &CMyFinalPaintDlg::OnFeaturesDiscomodon)
ON_COMMAND(ID_FILE_ABOUTUS, &CMyFinalPaintDlg::OnFileAboutus)
END_MESSAGE_MAP()


// CMyFinalPaintDlg message handlers

BOOL CMyFinalPaintDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//init
	isPressed = false;
	ifChoosen = false;
	//Default line shape
	static MyLineFactory lineFactory;
	factory = &lineFactory;
	
	// Create the Toolbar and attach the resource
	m_ToolBar.Create(this);
	m_ToolBar.LoadToolBar(IDR_TOOLBAR3);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
	
	//Create the Menu and attach the resource
	menu.LoadMenu(IDR_MENU);
	SetMenu(&menu);

	//Defualt Colors
	backgroundColor = RGB(30, 100, 220);
	lineColor = RGB(20, 100, 0);
	borderSize = 3;
	//Timer
	timerValue = 0;
	SetTimer(2, 1000, NULL);
	//disco mod enable/diseable
	discoMod = false;
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyFinalPaintDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyFinalPaintDlg::OnPaint()
{
	CPaintDC dc(this);
	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//Shapes draw
		for (int i = 0; i < shapes.size(); ++i) {
			
			shapes[i]->draw(dc);
		}
		//Signature draw
		dc.SetTextColor(RGB(0, 0, 200));
		dc.TextOutW(0,650,signature);

		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyFinalPaintDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
/*
			Mouse Actions Section OPEN
											*/

//Left Btn Mouse Creating shapes 
void CMyFinalPaintDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	MyShape* s = factory->create();
	Command *command = new AddCommand(shapes, s);
	done.push(command);
	command->perform();
	s->setBackgroundColor(backgroundColor);
	s->setBorderSize(borderSize);
	s->setLineColor(lineColor);
	s->setBegin(MyPoint(point.x, point.y));
	isPressed = true;
	CDialog::OnLButtonDown(nFlags, point);
}
void CMyFinalPaintDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	isPressed = false;
	CDialog::OnLButtonUp(nFlags, point);
}
//Right Btn Mouse Moveing Shapes
void CMyFinalPaintDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	//locate which shape choosen,and delete him
	endMove = beginMove = point;
	vector<MyShape*>::iterator it;
	for (it = shapes.begin(); it != shapes.end(); ++it) {
		currentShape = *it;

		if (currentShape->pointIsIn(point)) {
			shapes.erase(it);
			ifChoosen = true;
			break;
		}

	}
	CDialog::OnRButtonDown(nFlags, point);
}
void CMyFinalPaintDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	if (point.x > 1300 && point.y > 600) {
		ifChoosen = false;
		if(!done.empty())
			done.pop();//for not show in undo
		Invalidate();
	}
	else if (ifChoosen) {

		shapes.push_back(currentShape);
		ifChoosen = false;
		Invalidate();
	}
	CDialog::OnRButtonUp(nFlags, point);
}
//Mouse Move
void CMyFinalPaintDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CPen pen;
	CBrush brush;
	dc.SetROP2(R2_NOTXORPEN);
	if (isPressed)
	{
		shapes[shapes.size() - 1]->setEnd(MyPoint(point.x, point.y));
		Invalidate();
	}
	else if (ifChoosen ) {
		MyPoint oldEndPoint, oldBeginPoint;
		int jumpX, jumpY;
		//draw the currentShpae that erase in RBclick
		currentShape->draw(dc);
		beginMove = endMove;
		endMove = point;
		//init 
		oldEndPoint = currentShape->getEnd();
		oldBeginPoint = currentShape->getBegin();
		//calculte the gap
		jumpX = endMove.x - beginMove.x;
		jumpY = endMove.y - beginMove.y;
		//UPDATE new point location
		oldBeginPoint.addX(jumpX);
		oldBeginPoint.addY(jumpY);
		oldEndPoint.addX(jumpX);
		oldEndPoint.addY(jumpY);
		//UPDATE shape points
		currentShape->setBegin(oldBeginPoint);
		currentShape->setEnd(oldEndPoint);
		//draw currentShape for momvement
		currentShape->draw(dc);
		
	}
	else if (nFlags == MK_CONTROL && discoMod) {
		//Disco mod
		int red, green, blue;
		for (int i = 0; i < shapes.size(); i++)
		{
			red = rand() % 254 + 1;
			green = rand() % 254 + 1;
			blue = rand() % 254 + 1;
			shapes[i]->setBackgroundColor(RGB(red, green, blue));
			red = rand() % 254 + 1;
			green = rand() % 254 + 1;
			blue = rand() % 254 + 1;
			shapes[i]->setLineColor(RGB(red, green, blue));
			
		}
		Invalidate();
	}
	
	CDialog::OnMouseMove(nFlags, point);
}
/*
			Mouse Actions Section CLOSE								
											*/

/*
			Tool Bar Section OPEN								
											*/
void CMyFinalPaintDlg::onToolBarRectangle()
{
	static MyRectangleFactory rectangleFactory;
	factory = &rectangleFactory;
}
void CMyFinalPaintDlg::onToolBarLine()
{
	static MyLineFactory lineFactory;
	factory = &lineFactory;
}
void CMyFinalPaintDlg::onToolBarEllipse()
{
	static MyEllipseFactory ellipseFactory;
	factory = &ellipseFactory;
}
void CMyFinalPaintDlg::onToolBarTriangle() {
	static MyTriangleFactory triangleFactory;
	factory = &triangleFactory;
}
void CMyFinalPaintDlg::onToolBarBackground() {
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		backgroundColor = dlg.GetColor();
	}

}
void CMyFinalPaintDlg::onToolBarBorderColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		lineColor = dlg.GetColor();
	}
}
void CMyFinalPaintDlg::onToolBarSmallborder()
{
	borderSize = 2;
}
void CMyFinalPaintDlg::onToolBarMediumBorder()
{
	borderSize = 4;
}
void CMyFinalPaintDlg::onToolBarLargeBorder()
{
	borderSize = 8;
}
void CMyFinalPaintDlg::onToolBarUndo()
{

	if (done.empty())
		return;
	Command *command = done.top();
	done.pop();
	undone.push(command);
	command->rollback();
	Invalidate();

}
void CMyFinalPaintDlg::onToolBarRedo()
{
	//MessageBox(_T("test2"), _T("Oryan And Naor Paint"),
	//MB_ICONASTERISK | MB_OK);
	if (undone.empty())
		return;
	Command *command = undone.top();
	undone.pop();
	done.push(command);
	command->perform();
	Invalidate();
}
/*
		Tool Bar Section CLOSE								
										*/


//Files - Save ,Load and Clean
void CMyFinalPaintDlg::onButtonSave()
{
	//create file to write,if exist write
	CFile file(L"shapes.bin", CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&file, CArchive::store);
	//enter to archive total size of shapes
	archive << shapes.size();
	for (int i = 0; i < shapes.size(); ++i)	{
		//save all shapes to archive
		archive  << shapes[i];
	}
	archive << signature;
	MessageBox(_T("File Saved."), _T("Oryan And Naor Paint"),
		MB_ICONASTERISK | MB_OK);
	archive.Close();
	file.Close();
}
void CMyFinalPaintDlg::onButtonLoad()
{
	shapes.clear();
	CFile file(L"shapes.bin", CFile::modeRead);
	CArchive archive(&file, CArchive::load);
	int size;
	archive >> size;
	for (int i = 0; i < size; i++)
	{
		//create new shape
		MyShape *s;
		archive >> s;
		shapes.push_back(s);
	}
	archive >> signature;

	archive.Close();
	file.Close();
	Invalidate();

	MessageBox(_T("File Loaded."), _T("Oryan And Naor Paint"),
		MB_ICONASTERISK | MB_OK);
}
void CMyFinalPaintDlg::onButtonClean()
{
	//clean the screen and stacks ,and init all 
	shapes.clear();
	cleanStack(undone);
	cleanStack(done);
	signature = "";
	Invalidate();
	MessageBox(_T("Screen Clean"), _T("Oryan And Naor Paint"),
		MB_ICONASTERISK | MB_OK);
	ifChoosen = false;
	isPressed = false;
	currentShape = NULL;
	


}

/*
		Features Section OPEN          
								*/	

//Signature maker
void CMyFinalPaintDlg::OnFeaturesMakesignature()
{
	//CClientDC dc(this);
	SignatureDialog signatureDialog;
	//Action only if pressed ok
	if (signatureDialog.DoModal() == IDOK) {
		signature = signatureDialog.signatureValue;
		signature_exist = true;
		signature.Format(_T("Made By:%s"), signature);
		//dc.SetTextColor(RGB(0, 0, 200));
		//dc.TextOut(0, 650, signature);
		Invalidate();
	}
	
}
//Wellcome Message timer
void CMyFinalPaintDlg::OnTimer(UINT_PTR nIDEvent)
{
	CClientDC dc(this);
	dc.SetTextColor(RGB(0, 0, 200));
	dc.TextOut(500, 300, _T("Wellcome to MyPaint"));
	timerValue++;
	if (timerValue == 6) {
		KillTimer(2);
	}

	CDialog::OnTimer(nIDEvent);
}
//Disco Mod
void CMyFinalPaintDlg::OnFeaturesDiscomodon()
{
	discoMod = !discoMod;
	if (discoMod)
		menu.CheckMenuItem(ID_FEATURES_DISCOMODON, MF_CHECKED);
	else
		menu.CheckMenuItem(ID_FEATURES_DISCOMODON, MF_UNCHECKED);

}
//About us
void CMyFinalPaintDlg::OnFileAboutus()
{
	AboutUs dlg;
	dlg.DoModal();
}

/*
			Features Section CLOSE
									*/


/*
	Helper functions OPEN
							*/

//function to clean the stacks
void CMyFinalPaintDlg::cleanStack(stack<Command*>& s)
{
	while (!s.empty()) {
		s.pop();
	}
}

/*
	Helper functions CLSOE
							*/

