// AboutDlg.h : ヘッダー ファイル
//

#if !defined(AFX_ABOUT_DLG_H__CC6FFC61_43D5_4E40_983E_20469D9B6DE9__INCLUDED_)
#define AFX_ABOUT_DLG_H__CC6FFC61_43D5_4E40_983E_20469D9B6DE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg ダイアログ

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	~CAboutDlg();

    HCURSOR m_hCursor;
    CFont   m_cFont;

// ダイアログ データ
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnJbookletMailAddr();
	afx_msg void OnJbookletWebUrl();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CAboutDlg( CAboutDlg &dlg );
    CAboutDlg   operator = ( CAboutDlg &dlg );
};

#endif // !defined(AFX_ABOUT_DLG_H__CC6FFC61_43D5_4E40_983E_20469D9B6DE9__INCLUDED_)
