// AboutDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "jbooklet.h"
#include "AboutDlg.h"
extern "C" {
#include "xmlRPC.h"
}

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#if (WINVER >= 0x0500)
//#define IDC_HAND    MAKEINTRESOURCE(32649)
#ifdef IDC_HAND
#undef IDC_HAND
#endif
#endif /* WINVER >= 0x0500 */
#define IDC_HAND    IDC_HAND2

/////////////////////////////////////////////////////////////////////////////
// �A�v���P�[�V�����̃o�[�W�������Ŏg���Ă��� CAboutDlg �_�C�A���O

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT

    m_hCursor = AfxGetApp()->LoadCursor( IDC_HAND );
}

CAboutDlg::~CAboutDlg()
{
    m_cFont.DeleteObject();
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_JBOOKLET_MAIL_ADDR, OnJbookletMailAddr)
	ON_BN_CLICKED(IDC_JBOOKLET_WEB_URL, OnJbookletWebUrl)
	ON_WM_SETCURSOR()
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



void CAboutDlg::OnJbookletMailAddr() 
{
	CString cmd;
	cmd.LoadString( IDS_JBOOKLET_MAIL_ADDR );
    ShellExecute( NULL, "open", cmd, NULL, NULL, SW_SHOWNORMAL );
}

void CAboutDlg::OnJbookletWebUrl() 
{
	CString cmd;
	cmd.LoadString( IDS_JBOOKLET_WEB_URL );
    ShellExecute( NULL, "open", cmd, NULL, NULL, SW_SHOWNORMAL );
}

BOOL CAboutDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if ( nHitTest == HTCLIENT ) {
        // Web �� URL�����[���A�h���X�Ƀ}�E�X�|�C���^��������A
        // �w�J�[�\����\������
		DWORD   dwPos = GetMessagePos();
		WORD    wX    = LOWORD( dwPos );
		WORD    wY    = HIWORD( dwPos );
		CPoint  poCursor( wX, wY );
		CRect   rcClient;

        CStatic *s = (CStatic *)GetDlgItem( IDC_JBOOKLET_MAIL_ADDR );
        s->GetWindowRect( &rcClient );
        if ( (wX >= rcClient.left) && (wX <= rcClient.right)  &&
             (wY >= rcClient.top)  && (wY <= rcClient.bottom)    ) {
			SetCursor( m_hCursor );
            return TRUE;
        }

        s = (CStatic *)GetDlgItem( IDC_JBOOKLET_WEB_URL );
        s->GetWindowRect( &rcClient );
        if ( (wX >= rcClient.left) && (wX <= rcClient.right)  &&
             (wY >= rcClient.top)  && (wY <= rcClient.bottom)    ) {
			SetCursor( m_hCursor );
            return TRUE;
        }
	}

	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void CAboutDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
    if ( bShow ) {
        // Web �� URL�ƃ��[���A�h���X�������t���ŕ\������
        LOGFONT tLogFont;
        CFont   *cWndFont;

        cWndFont = GetFont(); 
        cWndFont->GetLogFont( &tLogFont );
        tLogFont.lfUnderline = 1;
        m_cFont.CreateFontIndirect( &tLogFont );

        CStatic *s = (CStatic *)GetDlgItem( IDC_JBOOKLET_MAIL_ADDR );
        s->SetFont( &m_cFont, TRUE );

        s = (CStatic *)GetDlgItem( IDC_JBOOKLET_WEB_URL );
        s->SetFont( &m_cFont, TRUE );

        CString str;
        str.LoadString( IDS_JBOOKLET_VERSION );
        str = "JBOOKlet Version " + str;
        s = (CStatic *)GetDlgItem( IDC_JBOOKLET_VERSION );
        s->SetWindowText( str );

        // OpenSSL �Ő��\��
        char    buf[BUFSIZ];
        size_t  sz = BUFSIZ;

        s = (CStatic *)GetDlgItem( IDC_OPENSSL );
        s->SetWindowText( getOpenSSLversion( buf, sz ) );

        // iconv �Ő��\��
        s = (CStatic *)GetDlgItem( IDC_ICONV );
        s->SetWindowText( getIconvVersion( buf, sz ) );
    }
}
