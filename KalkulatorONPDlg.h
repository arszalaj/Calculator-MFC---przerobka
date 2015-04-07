// KalkulatorONPDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include <string>
#include "ONP.h"
#include "Stack.h"

using namespace std;


/** 
* Klasa g³ównego okna dialogowego, dziedziczy po klasie CDialog.
*/
// CKalkulatorONPDlg dialog
class CKalkulatorONPDlg : public CDialog
{
// Construction
public:
	CKalkulatorONPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_KALKULATORONP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	BOOL CKalkulatorONPDlg::PreTranslateMessage(MSG* pMsg);
	void appendTextToExp(char *text);
	void moveCursorToEnd(CEdit &edit);
	
	void OnChangeTrigGroup();


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void DrawAxis();
	afx_msg void DrawNet();
	afx_msg void DrawCurve(string infix);
	double evaluate(string infix_expr, double x);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	CONP onp;

public:
	CButton but_1;
	CButton but_2;
	CButton but_3;
	CButton but_4;
	CButton but_5;
	CButton but_6;
	CButton but_7;
	CButton but_8;
	CButton but_9;
	CButton but_plusminus;
	CButton but_0;
	CButton but_dot;
	CButton but_eq;
	CButton but_plus;
	CButton but_minus;
	CButton but_multip;
	CButton but_div;
	CButton but_lb;
	CButton but_rb;
	CButton but_ce;
	CButton but_pi;
	CEdit ed_result;
	CEdit ed_onpexp;
	CEdit ed_exp;
	CEdit ed_x;
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMult();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedPlusMinus();
	afx_msg void OnBnClickedCE();
	afx_msg void OnBnClickedLeftBracket();
	afx_msg void OnBnClickedRightBracket();
	afx_msg void OnBnClickedC();
	afx_msg void OnBnClickedEqual();
	CButton rdec;
	int rbin;
	int roct;
	int rhex;
	afx_msg void OnBnClickedX();
	CButton but_a;
	CButton but_b;
	CButton but_c;
	CButton but_d;
	CButton but_e;
	CButton but_f;
	afx_msg void OnBnClickedB();
	afx_msg void OnBnClickedCHex();
	afx_msg void OnBnClickedD();
	afx_msg void OnBnClickedE();
	afx_msg void OnBnClickedF();
	CButton deg_rad;
	CButton rad_rad;
	afx_msg void OnBnClickedDegRad();
	afx_msg void OnBnClickedRadRad();
	CButton InvCB;
	afx_msg void OnBnClickedInvCb();
	CButton but_sin;
	CButton but_cos;
	CButton but_tg;
	CButton but_exp;
	CButton but_log;
	CButton but_sqrt;
	CButton but_pow;
	afx_msg void OnBnClickedPow();
	void replaceAll(std::string& str, const std::string& from, const std::string& to);
	string CKalkulatorONPDlg::AddMultForX(string infix_expr);
	afx_msg void OnBnClickedButtonClear();
};
