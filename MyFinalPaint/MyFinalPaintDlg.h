
// MyFinalPaintDlg.h : header file
//

#pragma once

#include <vector>
#include<stack>
#include "MyShape.h"
#include "MyEllipseFactory.h"
#include "MyLineFactory.h"
#include "MyRectangleFactory.h"
#include "MyTriangleFactory.h"
#include "Command.h"


#define FILENAME "Shapes.bin"
using namespace std;

// CMyFinalPaintDlg dialog
class CMyFinalPaintDlg : public CDialog
{
// Construction
public:
	CMyFinalPaintDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYFINALPAINT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


private:
	//Toolbar
	CToolBar m_ToolBar;
	//Menu
	CMenu menu;
	//vector that contain all shapes on screen
	vector<MyShape*> shapes;
	//redo and undo stacks
	stack<Command*> done, undone;
	MyShape *currentShape;
	//booleans for actions
	bool isPressed;
	bool ifChoosen;
	bool discoMod;
	//Pointer hold the current shape, generated from factory class
	MyFactory* factory;
	CPoint beginMove, endMove;
	//Signature dialog value
	CString signature;
	bool signature_exist;
	//Colors and size
	COLORREF backgroundColor, lineColor;
	int borderSize;
	//timer
	int timerValue;
	
	
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void onButtonLoad();
	afx_msg void onButtonClean();
	afx_msg void onButtonSave();
	afx_msg void OnFeaturesMakesignature();
	afx_msg void onToolBarBackground();
	afx_msg void onToolBarBorderColor();
	afx_msg void onToolBarSmallborder();
	afx_msg void onToolBarMediumBorder();
	afx_msg void onToolBarLargeBorder();
	afx_msg void onToolBarRectangle();
	afx_msg void onToolBarLine();
	afx_msg void onToolBarEllipse();
	afx_msg void onToolBarTriangle();
	afx_msg void onToolBarUndo();
	afx_msg void onToolBarRedo();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnFeaturesDiscomodon();
	afx_msg void OnFileAboutus();

	void cleanStack(stack<Command*>& s);
	
	
};
