// jbooklet.cpp : アプリケーション用クラスの定義を行います。
//

#include "jbooklet.h"
#include "jbookletDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJbookletApp

BEGIN_MESSAGE_MAP(CJbookletApp, CWinApp)
	//{{AFX_MSG_MAP(CJbookletApp)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJbookletApp クラスの構築

CJbookletApp::CJbookletApp()
{
	// TODO: この位置に構築用のコードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
    m_langCode = GetThreadLocale();
    if ( m_langCode != 0x0411 )
        m_langCode = 0x0409;  // 「日本語」以外の場合は強制的に「英語」にする
    SetThreadLocale( m_langCode );
}

/////////////////////////////////////////////////////////////////////////////
// 唯一の CJbookletApp オブジェクト

CJbookletApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CJbookletApp クラスの初期化

BOOL CJbookletApp::InitInstance()
{
	// 標準的な初期化処理
	// もしこれらの機能を使用せず、実行ファイルのサイズを小さくしたけ
	//  れば以下の特定の初期化ルーチンの中から不必要なものを削除して
	//  ください。

#if _MSC_VER < 1400
#ifdef _AFXDLL
	Enable3dControls();			// 共有 DLL 内で MFC を使う場合はここをコールしてください。
#else
	Enable3dControlsStatic();	// MFC と静的にリンクする場合はここをコールしてください。
#endif
#endif

	CJbookletDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: ダイアログが <OK> で消された時のコードを
		//       記述してください。
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: ダイアログが <ｷｬﾝｾﾙ> で消された時のコードを
		//       記述してください。
	}

	// ダイアログが閉じられてからアプリケーションのメッセージ ポンプを開始するよりは、
	// アプリケーションを終了するために FALSE を返してください。
	return FALSE;
}
