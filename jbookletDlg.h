// jbookletDlg.h : �w�b�_�[ �t�@�C��
//

#if !defined(AFX_JBOOKLETDLG_H__CC6FFC61_43D5_4E40_983E_20469D9B6DE9__INCLUDED_)
#define AFX_JBOOKLETDLG_H__CC6FFC61_43D5_4E40_983E_20469D9B6DE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CJbookletDlg �_�C�A���O

class CJbookletDlg : public CDialog
{
// �\�z
public:
	CJbookletDlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CJbookletDlg)
	enum { IDD = IDD_JBOOKLET_DIALOG };
	CString	m_pid;
	CString	m_sid;
	CString	m_url;
	CString	m_result;
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CJbookletDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
private:
    void    saveIDs();
    void    loadIDs();
    char    filename[MAX_PATH];

protected:
	HICON m_hIcon;

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
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
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_JBOOKLETDLG_H__CC6FFC61_43D5_4E40_983E_20469D9B6DE9__INCLUDED_)
