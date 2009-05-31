// jbooklet.cpp : �A�v���P�[�V�����p�N���X�̒�`���s���܂��B
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
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJbookletApp �N���X�̍\�z

CJbookletApp::CJbookletApp()
{
	// TODO: ���̈ʒu�ɍ\�z�p�̃R�[�h��ǉ����Ă��������B
	// ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
    m_langCode = GetThreadLocale();
    if ( m_langCode != 0x0411 )
        m_langCode = 0x0409;  // �u���{��v�ȊO�̏ꍇ�͋����I�Ɂu�p��v�ɂ���
    SetThreadLocale( m_langCode );
}

/////////////////////////////////////////////////////////////////////////////
// �B��� CJbookletApp �I�u�W�F�N�g

CJbookletApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CJbookletApp �N���X�̏�����

BOOL CJbookletApp::InitInstance()
{
	// �W���I�ȏ���������
	// ���������̋@�\���g�p�����A���s�t�@�C���̃T�C�Y��������������
	//  ��Έȉ��̓���̏��������[�`���̒�����s�K�v�Ȃ��̂��폜����
	//  ���������B

#if _MSC_VER < 1400
#ifdef _AFXDLL
	Enable3dControls();			// ���L DLL ���� MFC ���g���ꍇ�͂������R�[�����Ă��������B
#else
	Enable3dControlsStatic();	// MFC �ƐÓI�Ƀ����N����ꍇ�͂������R�[�����Ă��������B
#endif
#endif

	CJbookletDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �_�C�A���O�� <OK> �ŏ����ꂽ���̃R�[�h��
		//       �L�q���Ă��������B
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �_�C�A���O�� <��ݾ�> �ŏ����ꂽ���̃R�[�h��
		//       �L�q���Ă��������B
	}

	// �_�C�A���O�������Ă���A�v���P�[�V�����̃��b�Z�[�W �|���v���J�n������́A
	// �A�v���P�[�V�������I�����邽�߂� FALSE ��Ԃ��Ă��������B
	return FALSE;
}
