// jbooklet.h : JBOOKLET アプリケーションのメイン ヘッダー ファイルです。
//

#if !defined(AFX_JBOOKLET_H__9BD606E0_7D39_4CEE_A15F_844E4A373A9E__INCLUDED_)
#define AFX_JBOOKLET_H__9BD606E0_7D39_4CEE_A15F_844E4A373A9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Windows ヘッダーから殆ど使用されないスタッフを除外します。

#include <afxwin.h>         // MFC のコアおよび標準コンポーネント
#include <afxext.h>         // MFC の拡張部分
#include <afxdtctl.h>		// MFC の Internet Explorer 4 コモン コントロール サポート
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC の Windows コモン コントロール サポート
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "resource.h"		// メイン シンボル
#define NUL '\0'

/////////////////////////////////////////////////////////////////////////////
// CJbookletApp:
// このクラスの動作の定義に関しては jbooklet.cpp ファイルを参照してください。
//

class CJbookletApp : public CWinApp
{
public:
	CJbookletApp();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CJbookletApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション
    LCID    m_langCode;

	//{{AFX_MSG(CJbookletApp)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_JBOOKLET_H__9BD606E0_7D39_4CEE_A15F_844E4A373A9E__INCLUDED_)
