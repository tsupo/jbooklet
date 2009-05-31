// jbookletDlg.h : ヘッダー ファイル
//

#if !defined(AFX_JBOOKLETDLG_H__CC6FFC61_43D5_4E40_983E_20469D9B6DE9__INCLUDED_)
#define AFX_JBOOKLETDLG_H__CC6FFC61_43D5_4E40_983E_20469D9B6DE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CJbookletDlg ダイアログ

class CJbookletDlg : public CDialog
{
// 構築
public:
	CJbookletDlg(CWnd* pParent = NULL);	// 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CJbookletDlg)
	enum { IDD = IDD_JBOOKLET_DIALOG };
	CString	m_pid;
	CString	m_sid;
	CString	m_url;
	CString	m_result;
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CJbookletDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
private:
    void    saveIDs();
    void    loadIDs();
    char    filename[MAX_PATH];

protected:
	HICON m_hIcon;

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CJbookletDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreateMyLink();
	afx_msg void OnExit();
	afx_msg void OnKillfocusEditPid();
	afx_msg void OnKillfocusEditSid();
	afx_msg void OnKillfocusEditUrl();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_JBOOKLETDLG_H__CC6FFC61_43D5_4E40_983E_20469D9B6DE9__INCLUDED_)
