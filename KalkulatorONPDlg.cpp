// KalkulatorONPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KalkulatorONP.h"
#include "KalkulatorONPDlg.h"
#include "WPoint.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

/* deklaracja zmiennych globalnych */
CString expr;///< przechowuje aktualne wyra¿enie arytmetyczne do obliczenia
CString onp_expr;///< przechowuje aktualne wyra¿enie w ONP
CString result;///< przechowuje ³añcuch zawieraj¹cy wynik obliczeñ wyra¿enia
CString mem;///< ³añcuch pomocniczy

long double ld_result;///< przechowuje numeryczny wynik obliczenia wyra¿enia


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CKalkulatorONPDlg dialog




CKalkulatorONPDlg::CKalkulatorONPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKalkulatorONPDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKalkulatorONPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_1, but_1);
	DDX_Control(pDX, IDC_2, but_2);
	DDX_Control(pDX, IDC_3, but_3);
	DDX_Control(pDX, IDC_4, but_4);
	DDX_Control(pDX, IDC_5, but_5);
	DDX_Control(pDX, IDC_6, but_6);
	DDX_Control(pDX, IDC_7, but_7);
	DDX_Control(pDX, IDC_8, but_8);
	DDX_Control(pDX, IDC_9, but_9);
	DDX_Control(pDX, IDC_PM, but_plusminus);
	DDX_Control(pDX, IDC_0, but_0);
	DDX_Control(pDX, IDC_DOT, but_dot);
	DDX_Control(pDX, IDC_EQUAL, but_eq);
	DDX_Control(pDX, IDC_PLUS, but_plus);
	DDX_Control(pDX, IDC_MINUS, but_minus);
	DDX_Control(pDX, IDC_MULT, but_multip);
	DDX_Control(pDX, IDC_DIV, but_div);
	DDX_Control(pDX, IDC_LB, but_lb);
	DDX_Control(pDX, IDC_RB, but_rb);
	DDX_Control(pDX, IDC_CE, but_ce);
	DDX_Control(pDX, IDC_EDIT3, ed_result);
	DDX_Control(pDX, IDC_EDIT1, ed_onpexp);
	DDX_Control(pDX, IDC_EDIT2, ed_exp);
	DDX_Control(pDX, IDC_EDIT4, ed_x);
}

BEGIN_MESSAGE_MAP(CKalkulatorONPDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_1, &CKalkulatorONPDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CKalkulatorONPDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CKalkulatorONPDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CKalkulatorONPDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CKalkulatorONPDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CKalkulatorONPDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CKalkulatorONPDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CKalkulatorONPDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CKalkulatorONPDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_0, &CKalkulatorONPDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_DOT, &CKalkulatorONPDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_PLUS, &CKalkulatorONPDlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_MINUS, &CKalkulatorONPDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_7, &CKalkulatorONPDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_MULT, &CKalkulatorONPDlg::OnBnClickedMult)
	ON_BN_CLICKED(IDC_DIV, &CKalkulatorONPDlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_PM, &CKalkulatorONPDlg::OnBnClickedPlusMinus)
	ON_BN_CLICKED(IDC_CE, &CKalkulatorONPDlg::OnBnClickedCE)
	ON_BN_CLICKED(IDC_LB, &CKalkulatorONPDlg::OnBnClickedLeftBracket)
	ON_BN_CLICKED(IDC_RB, &CKalkulatorONPDlg::OnBnClickedRightBracket)
	ON_BN_CLICKED(IDC_C, &CKalkulatorONPDlg::OnBnClickedC)
	ON_BN_CLICKED(IDC_EQUAL, &CKalkulatorONPDlg::OnBnClickedEqual)
	ON_BN_CLICKED(IDC_X, &CKalkulatorONPDlg::OnBnClickedX)
	ON_BN_CLICKED(IDC_POW, &CKalkulatorONPDlg::OnBnClickedPow)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CKalkulatorONPDlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// CKalkulatorONPDlg message handlers

BOOL CKalkulatorONPDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	ed_exp.SetFocus();
	//Make sure this is here so you can use XP Styles
	InitCommonControls();
	
	DrawAxis();

	return FALSE;  // return TRUE  unless you set the focus to a control
}

void CKalkulatorONPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CKalkulatorONPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

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
		CDialog::OnPaint();
		DrawAxis();
	}
}

void CKalkulatorONPDlg::DrawAxis()
{
	CDC* pDC = GetDC();
	pDC->Rectangle(0,0,700,700);
	int width = 20;
	
	CString bufferX;
	ed_x.GetWindowTextA(bufferX);
	string x_expr = bufferX.GetString();
	if(x_expr.length() > 0)
		sscanf(x_expr.c_str(), "%d", &width);

	DrawNet(width);

	COLORREF qLineColor = RGB(0,0,0);
	CPen qLinePen(PS_SOLID, 2, qLineColor); 
	pDC->SelectObject(&qLinePen);
	
	pDC->SetPixel(200, 200, qLineColor);

	pDC->MoveTo(WPoint(0,-width, width));
	pDC->LineTo(WPoint(0,width, width));
	CString xString = CString("x");
	CString yString = CString("y");

	pDC->MoveTo(WPoint(-width,0, width));
	pDC->LineTo(WPoint(width,0, width));

	pDC->MoveTo(WPoint(-width*0.04,width*0.96, width));
	pDC->LineTo(WPoint(0,width, width));
	pDC->LineTo(WPoint(width*0.04,width*0.96, width));

	WPoint wPoint;
	pDC->TextOut(wPoint.GetX(-width*0.04, width),wPoint.GetY(width*0.96, width),yString);

	pDC->MoveTo(WPoint(-width*0.96,width*0.04, width));
	pDC->LineTo(WPoint(-width,0, width));
	pDC->LineTo(WPoint(-width*0.96,-width*0.04, width));
	pDC->TextOut(wPoint.GetX(-width*0.96, width),wPoint.GetY(-width*0.04, width),xString);
	
	for(int i = -width; i<width; i+=width/5)
	{
		pDC->MoveTo(WPoint(i,-width*0.02, width));
		pDC->LineTo(WPoint(i,width*0.02, width));
		pDC->TextOut(wPoint.GetX(-(i+width*0.01), width),wPoint.GetY(-width*0.04, width),to_string(i).c_str());
	}

	for(int i = -width; i<width; i+=width/5)
	{
		pDC->MoveTo(WPoint(-width*0.02,i, width));
		pDC->LineTo(WPoint(width*0.02,i, width));
		if(i)
		{
			pDC->TextOut(wPoint.GetX(-(width*0.04), width),wPoint.GetY(i+width*0.01, width),to_string(i).c_str());
		}
	}

}

void CKalkulatorONPDlg::DrawNet(int width)
{
	CDC* pDC = GetDC();
	COLORREF qLineColor = RGB(200,200,200);
	CPen qLinePen(PS_SOLID, 0.05, qLineColor); 
	pDC->SelectObject(&qLinePen);
	

	for(float i = -width; i<width; i+=(float)width/20)
	{
		pDC->MoveTo(WPoint(i,-width, width));
		pDC->LineTo(WPoint(i,width, width));
	}

	for(float j = -width; j<width; j+=(float)width/20)
	{
		pDC->MoveTo(WPoint(-width,j, width));
		pDC->LineTo(WPoint(width,j, width));
	}
}


// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKalkulatorONPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CKalkulatorONPDlg::PreTranslateMessage(MSG* pMsg)

{
	int x = pMsg->wParam;
	if(pMsg->message == WM_KEYDOWN)
	{
		ed_exp.SetFocus(); // ustaw aktywny wyswietlacz
		if(x == VK_RETURN) // jezeli byl to ENTER
		{
			OnBnClickedEqual(); // zasymuluj wcisniecie =
			pMsg->wParam = 0; // wyzeruj komunikat aby nie mial dalszych skutkow
		}
		if(x == VK_DELETE) // jezeli byl to CE
		{
			OnBnClickedCE(); // zasymuluj wcisniecie =
			pMsg->wParam = 0; // wyzeruj komunikat aby nie mial dalszych skutkow
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

/** 
* Do³¹cza podany tekst do wyra¿enia i wyœwietla go w odpowiedniej kontrolce.
* @param *text ³añcuch do do³¹czenia
*/
void CKalkulatorONPDlg::appendTextToExp(char *text)
{
	CString buffer;
	string s;
	int start,end;
	ed_exp.GetSel(start,end);
	ed_exp.GetWindowTextA(buffer); 
	s = buffer;
	if(start == end)
	{
		s.insert(start,text);
	}
	else
	{
		s.replace(start,end-start,text);
	}
	expr.Empty(); 
	expr.Append(s.c_str()); 
	ed_exp.SetWindowTextA(expr); 
	ed_exp.SetSel(start+(int)strlen(text),start+(int)strlen(text));
	ed_exp.SetFocus();
}


	
/** 
* Przenosi kuror na koniec kontrolki CEdit.
* @param edit kontrolka, której kursor chcemy umieœciæ na koñcu.
*/
void CKalkulatorONPDlg::moveCursorToEnd(CEdit &edit)
{
	CString buffer;
	edit.GetWindowTextA(buffer);
	edit.SetSel(buffer.GetLength(),buffer.GetLength(),0); // ustawienie pozycji kursora na koniec
	edit.SetFocus();
}

/**
* Obs³uga przycisku "1"
*/
void CKalkulatorONPDlg::OnBnClicked1()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("1");
	
}



/**
* Obs³uga przycisku "2"
*/
void CKalkulatorONPDlg::OnBnClicked2()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("2");
}


/**
* Obs³uga przycisku "3"
*/
void CKalkulatorONPDlg::OnBnClicked3()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("3");
}

/**
* Obs³uga przycisku "4"
*/
void CKalkulatorONPDlg::OnBnClicked4()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("4");
}

/**
* Obs³uga przycisku "5"
*/
void CKalkulatorONPDlg::OnBnClicked5()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("5");
}

/**
* Obs³uga przycisku "6"
*/
void CKalkulatorONPDlg::OnBnClicked6()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("6");
}

/**
* Obs³uga przycisku "7"
*/
void CKalkulatorONPDlg::OnBnClicked7()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("7");
}

/**
* Obs³uga przycisku "8"
*/
void CKalkulatorONPDlg::OnBnClicked8()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("8");
}

/**
* Obs³uga przycisku "9"
*/
void CKalkulatorONPDlg::OnBnClicked9()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("9");
}

/**
* Obs³uga przycisku "0"
*/
void CKalkulatorONPDlg::OnBnClicked0()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("0");
}

/**
* Obs³uga przycisku "."
*/
void CKalkulatorONPDlg::OnBnClickedDot()
{
	// TODO: Add your control notification handler code here
	appendTextToExp(".");
}

/**
* Obs³uga przycisku "+"
*/
void CKalkulatorONPDlg::OnBnClickedPlus()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("+");
}

/**
* Obs³uga przycisku "-"
*/
void CKalkulatorONPDlg::OnBnClickedMinus()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("-");
}

/**
* Obs³uga przycisku "*"
*/
void CKalkulatorONPDlg::OnBnClickedMult()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("*");
}

/**
* Obs³uga przycisku "/"
*/
void CKalkulatorONPDlg::OnBnClickedDiv()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("/");
}

/**
* Obs³uga przycisku "+/-"
*/
void CKalkulatorONPDlg::OnBnClickedPlusMinus()
{
	// TODO: Add your control notification handler code here
	if(expr[0] == '-') // jezeli na poczatku stoi minus
		expr = expr.Mid(1,expr.GetLength()-1); // to obcinamy go
	else
	{
		string buffer;
		buffer = expr.GetString();
		buffer = '-' + buffer;
		expr = buffer.c_str();
	}
	ed_exp.SetWindowTextA(expr);
	moveCursorToEnd(ed_exp);
}

/**
* Obs³uga przycisku "CE"
*/
void CKalkulatorONPDlg::OnBnClickedCE()
{
	// TODO: Add your control notification handler code here
	expr.Empty();
	onp_expr.Empty();
	result.Empty();
	ed_onpexp.SetWindowTextA("");
	ed_exp.SetWindowTextA("");
	ed_result.SetWindowTextA("");
}

/**
* Obs³uga przycisku "("
*/
void CKalkulatorONPDlg::OnBnClickedLeftBracket()
{
	// TODO: Add your control notification handler code here
	appendTextToExp("(");
}

/**
* Obs³uga przycisku ")"
*/
void CKalkulatorONPDlg::OnBnClickedRightBracket()
{
	// TODO: Add your control notification handler code here
	appendTextToExp(")");
}

/**
* Obs³uga przycisku "C"
*/
void CKalkulatorONPDlg::OnBnClickedC()
{
	// TODO: Add your control notification handler code here
	expr = expr.Mid(0,expr.GetLength()-1);
	ed_exp.SetWindowTextA(expr);
	moveCursorToEnd(ed_exp);
}
/**
* Obs³uga przycisku "="
*/
void CKalkulatorONPDlg::OnBnClickedEqual()
{
	CString buffer, bufferX;
	string wyn;
	ed_exp.GetWindowTextA(buffer);
	ed_x.GetWindowTextA(bufferX);

	string infix_expr = buffer.GetString(), infix_exprTmp = infix_expr;
	string x_expr = bufferX.GetString();
	string onp_ex;
	char buf[256];
	infix_expr = AddMultForX(infix_expr);
	replaceAll(infix_expr,"x", "(" + x_expr + ")");
	if(onp.infixToONP(infix_expr,onp_ex) == -1)
	{
		buffer = "Nieprawidlowe lub nieobslugiwane wyrazenie";
		ed_result.SetWindowTextA(buffer);
		ed_onpexp.SetWindowTextA(buffer);
		return ;
	}
	else
	{
		ed_onpexp.SetWindowTextA(onp_ex.c_str());
		if(onp.evaluateONP(onp_ex,ld_result) == -1)
		{
			ed_result.SetWindowTextA("Nie mozna obliczyc wyrazenia");
		return ;
		}
		else
		{
			sprintf(buf,"%.15Lf",ld_result);
			wyn = buf;
			ed_result.SetWindowTextA(wyn.c_str());

			DrawAxis();
			DrawCurve(infix_exprTmp);
		}
	}
	moveCursorToEnd(ed_exp);
}

void CKalkulatorONPDlg::DrawCurve(string infix_expr)
{
	string onp_ex, infixTmp = AddMultForX(infix_expr);
	CDC* pDC = GetDC();
	COLORREF qLineColor = RGB(255,0,0);
	CPen qLinePen(PS_SOLID, 2, qLineColor); 
	pDC->SelectObject(&qLinePen);
	
	int width = 20;

	CString bufferX;
	ed_x.GetWindowTextA(bufferX);
	string x_expr = bufferX.GetString();
	if(x_expr.length() > 0)
		sscanf(x_expr.c_str(), "%d", &width);

	long double fY;

	for (float fX = - width; fX < width; fX += (float)width/20)
	{
		infix_expr = infixTmp;
		replaceAll(infix_expr,"x", "(" + to_string(fX) + ")");
		onp.infixToONP(infix_expr,onp_ex);
		onp.evaluateONP(onp_ex,fY);
		//fY = evaluate(onp_ex,fX);
		if(fX == - width)
		{	
			pDC->MoveTo(WPoint(-fX,fY, width));
		}
		else
		{
			pDC->LineTo(WPoint(-fX,fY, width));
		}
	}
}

string CKalkulatorONPDlg::AddMultForX(string infix_expr)
{
	int i = 0;
	while(i < infix_expr.length())
	{	
		if(isdigit(infix_expr[i]) && infix_expr[i+1] == 'x')
		{
			infix_expr = infix_expr.substr(0,i+1) + '*' + infix_expr.substr(i+1);
		}
		i++;
	}
	return infix_expr;
}

void CKalkulatorONPDlg::replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}
/**
* Obs³uga przycisku 'x'
*/
void CKalkulatorONPDlg::OnBnClickedX()
{
	// TODO: Add your control notification handler code here
	this->appendTextToExp("x");
	
}


void CKalkulatorONPDlg::OnBnClickedPow()
{
	// TODO: Add your control notification handler code here
	this->appendTextToExp("^");
}


void CKalkulatorONPDlg::OnBnClickedButtonClear()
{
	OnPaint();
}
