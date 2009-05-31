// jbookletDlg.cpp : インプリメンテーション ファイル
//

#include "jbooklet.h"
#include "jbookletDlg.h"
#include "AboutDlg.h"
extern "C" {
#include "xmlRPC.h"

char    *
getAffiliateLinkOnJbook( const char *url, const char *sid, const char *pid );
}

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJbookletDlg ダイアログ

CJbookletDlg::CJbookletDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJbookletDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJbookletDlg)
	m_pid = _T("");
	m_sid = _T("");
	m_url = _T("");
	m_result = _T("");
	//}}AFX_DATA_INIT
	// メモ: LoadIcon は Win32 の DestroyIcon のサブシーケンスを要求しません。
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    strcpy( filename, "./setting.inf" );
    loadIDs();
}

void CJbookletDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJbookletDlg)
	DDX_Text(pDX, IDC_EDIT_PID, m_pid);
	DDV_MaxChars(pDX, m_pid, 32);
	DDX_Text(pDX, IDC_EDIT_SID, m_sid);
	DDV_MaxChars(pDX, m_sid, 32);
	DDX_Text(pDX, IDC_EDIT_URL, m_url);
	DDV_MaxChars(pDX, m_url, 384);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_result);
	DDV_MaxChars(pDX, m_result, 2048);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CJbookletDlg, CDialog)
	//{{AFX_MSG_MAP(CJbookletDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, OnCreateMyLink)
	ON_BN_CLICKED(IDCANCEL, OnExit)
	ON_EN_KILLFOCUS(IDC_EDIT_PID, OnKillfocusEditPid)
	ON_EN_KILLFOCUS(IDC_EDIT_SID, OnKillfocusEditSid)
	ON_EN_KILLFOCUS(IDC_EDIT_URL, OnKillfocusEditUrl)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJbookletDlg 独自追加メソッド

void    CJbookletDlg::saveIDs()
{
    FILE    *fp;

    if ( (m_sid.GetLength() > 0) || (m_pid.GetLength() > 0) ) {
        if ( ( fp = fopen( filename, "w" ) ) != NULL ) {
            if ( m_sid.GetLength() > 0 )
                fprintf( fp, "SID: %s\n", m_sid );
            if ( m_pid.GetLength() > 0 )
                fprintf( fp, "PID: %s\n", m_pid );
            fclose( fp );
        }
    }
}

void    CJbookletDlg::loadIDs()
{
    FILE    *fp;

    if ( ( fp = fopen( filename, "r" ) ) != NULL ) {
        char    *p, buf[BUFSIZ];

        while ( ( p = fgets( buf, BUFSIZ - 1, fp ) ) != NULL ) {
            if ( !strncmp( p, "SID: ", 5 ) ) {
                while ( (p[strlen(p) - 1] == '\r') ||
                        (p[strlen(p) - 1] == '\n')    )
                    p[strlen(p) - 1] = NUL;
                p += 5;
                m_sid = p;
            }
            if ( !strncmp( p, "PID: ", 5 ) ) {
                while ( (p[strlen(p) - 1] == '\r') ||
                        (p[strlen(p) - 1] == '\n')    )
                    p[strlen(p) - 1] = NUL;
                p += 5;
                m_pid = p;
            }
        }

        fclose( fp );
    }
}


/////////////////////////////////////////////////////////////////////////////
// CJbookletDlg メッセージ ハンドラ

BOOL CJbookletDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	// このダイアログ用のアイコンを設定します。フレームワークはアプリケーションのメイン
	// ウィンドウがダイアログでない時は自動的に設定しません。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンを設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンを設定
	
    if ( m_sid.GetLength() > 0 ) {
        CEdit   *p = (CEdit *)GetDlgItem( IDC_EDIT_SID );
        p->SetWindowText( m_sid );
    }
    if ( m_pid.GetLength() > 0 ) {
        CEdit   *p = (CEdit *)GetDlgItem( IDC_EDIT_PID );
        p->SetWindowText( m_pid );
    }

	return TRUE;  // TRUE を返すとコントロールに設定したフォーカスは失われません。
}

void CJbookletDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CJbookletDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画用のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// クライアントの矩形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンを描画します。
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// システムは、ユーザーが最小化ウィンドウをドラッグしている間、
// カーソルを表示するためにここを呼び出します。
HCURSOR CJbookletDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CJbookletDlg::OnCreateMyLink() 
{
    if ( (m_sid.GetLength() == 0) || (m_pid.GetLength() == 0) )
        return;

    if ( m_url.GetLength() > 0 ) {
        CWaitCursor cur;    // マウスカーソルを砂時計表示

        setUseProxy( isUsedProxy() );
    	m_result = getAffiliateLinkOnJbook( m_url, m_sid, m_pid );

        CEdit   *p = (CEdit *)GetDlgItem( IDC_EDIT_RESULT );
        p->SetWindowText( m_result );
    }
}

void CJbookletDlg::OnExit() 
{
    saveIDs();
	OnOK();
}

void CJbookletDlg::OnKillfocusEditPid() 
{
    CEdit   *p = (CEdit *)GetDlgItem( IDC_EDIT_PID );
    p->GetWindowText( m_pid );
}

void CJbookletDlg::OnKillfocusEditSid() 
{
    CEdit   *p = (CEdit *)GetDlgItem( IDC_EDIT_SID );
    p->GetWindowText( m_sid );
}

void CJbookletDlg::OnKillfocusEditUrl() 
{
    CEdit   *p = (CEdit *)GetDlgItem( IDC_EDIT_URL );
    p->GetWindowText( m_url );
}
