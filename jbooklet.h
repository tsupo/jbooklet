// jbooklet.h : JBOOKLET �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#if !defined(AFX_JBOOKLET_H__9BD606E0_7D39_4CEE_A15F_844E4A373A9E__INCLUDED_)
#define AFX_JBOOKLET_H__9BD606E0_7D39_4CEE_A15F_844E4A373A9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Windows �w�b�_�[����w�ǎg�p����Ȃ��X�^�b�t�����O���܂��B

#include <afxwin.h>         // MFC �̃R�A����ѕW���R���|�[�l���g
#include <afxext.h>         // MFC �̊g������
#include <afxdtctl.h>		// MFC �� Internet Explorer 4 �R���� �R���g���[�� �T�|�[�g
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC �� Windows �R���� �R���g���[�� �T�|�[�g
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "resource.h"		// ���C�� �V���{��
#define NUL '\0'

/////////////////////////////////////////////////////////////////////////////
// CJbookletApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� jbooklet.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CJbookletApp : public CWinApp
{
public:
	CJbookletApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CJbookletApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
    LCID    m_langCode;

	//{{AFX_MSG(CJbookletApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_JBOOKLET_H__9BD606E0_7D39_4CEE_A15F_844E4A373A9E__INCLUDED_)
