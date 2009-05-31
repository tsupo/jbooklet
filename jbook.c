/*
 *  jbook.c
 *
 * History:
 * $Log: /comm/jbooklet/jbook.c $
 * 
 * 1     09/05/14 3:52 tsupo
 * (1) �r���h���̃f�B���N�g���\���𐮗�
 * (2) VSS�T�[�o���_��ύX
 * 
 * 2     06/09/15 14:59 Tsujimura543
 * 1.3 ��
 * 
 * 1     06/09/15 14:53 Tsujimura543
 * ���܂� xmlPC.dll ���ɑ��݂��Ă����֐����O�ɏo���Ajbook.c
 * �Ƃ������O�̃t�@�C���Ɏ��[����(xmlRPC.dll������o�����[�R
 * �}�[�X�֘A�̊֐����폜�����̂ɔ����[�u)�B�]���̂��̂���
 * ���𑝂₷���ƂőΉ����Ă���B
 */

#include "xmlRPC.h"

#ifndef	lint
static char	*rcs_id =
"$Header: /comm/jbooklet/jbook.c 1     09/05/14 3:52 tsupo $";
#endif

/*
 *  JBOOK ���i��URL �� �A�t�B���G�C�g�����N(�摜��) �ϊ�
 *      (ValueCommerce�o�R)
 */

char    *
getAffiliateLinkOnJbook( const char *url, const char *sid, const char *pid )
{
    static char *affURL = NULL;
    char        targetURL[MAX_URLLENGTH];
    char        *response;
    int         sz = MAX_CONTENT_SIZE;

    if ( !url && affURL ) {
        free( affURL );
        affURL = NULL;
        return ( NULL );
    }

    if ( !affURL ) {
        affURL = (char *)malloc( MAX_CONTENT_SIZE );
        if ( !affURL )
            return ( NULL );
    }

    memset( affURL, 0x00, MAX_URLLENGTH );
    response = (char *)malloc( sz );
    if ( !response )
        return ( NULL );

    strcpy( targetURL, url );
    setUpReceiveBuffer( response, sz );
    http_get( targetURL, response );
    if ( response[0] != NUL ) {
        char    title[MAX_LOGICALLINELEN];
        char    imageURL[MAX_URLLENGTH];
        char    *p, *q, *r;

        title[0]    = NUL;
        imageURL[0] = NUL;
        p = strstr( response, "<title>" );
        if ( p ) {
            p += 7;
            q = strstr( p, "</title>" );
            if ( q ) {
                while ( (*p == ' ' ) || (*p == '\t') ||
                        (*p == '\r') || (*p == '\n')    )
                    p++;
                *q = NUL;
                strcpy( title, ((r = utf2sjis(p)) != NULL) ? r : p );
                if ( title[0] ) {
                    r = &(title[strlen(title) - 1]);
                    while ( (*r == ' ' ) || (*r == '\t') ||
                            (*r == '\r') || (*r == '\n')    ) {
                        *r = NUL;
                        r--;
                    }
                }
                p = q + 8;
            }
        }
        else
            p = response;

        q = strstr( p, "<div class=\"prodimage\">" );
        if ( q ) {
            p = strstr( q, "http://" );
            if ( p ) {
                q = strchr( p, '"' );
                if ( q ) {
                    strncpy( imageURL, p, q - p );
                    imageURL[q - p] = NUL;
                }
            }
        }

        if ( imageURL[0] == NUL ) {
            char    bookCode[MAX_NAMELEN];
            char    *p, *q;

            p = strstr( targetURL, "/p.aspx/" );
            if ( p ) {
                p += 8;
                q = strchr( p, '/' );
                if ( q ) {
                    strncpy( bookCode, p, q - p );
                    bookCode[q - p] = NUL;
                    sprintf( imageURL,
                "http://www.jbook.co.jp/member/img/product/0%.4s/M0%s-01.jpg",
                             bookCode, bookCode );
                }
            }
        }

        if ( title[0] && targetURL[0] ) {
            char        vcurl[MAX_URLLENGTH];
            char        *itemURL = NULL;

            itemURL = translateURL( targetURL );
            sprintf( vcurl,
                     "http://ck.jp.ap.valuecommerce.com/servlet/referral"
                     "?sid=%s&amp;pid=%s&amp;vc_url=",
                     sid, pid );
            sprintf( affURL, "<a href=\"%s%s\" target=\"_blank\">%s</a>\n",
                     vcurl, itemURL, title );
            if ( imageURL ) {
                sprintf( affURL + strlen( affURL ),
                         "<br />\n<a href=\"%s%s\" target=\"_blank\">"
                         "<img src=\"%s\" alt=\"%s\" border=\"0\" /></a>\n",
                         vcurl, itemURL, imageURL, title );
            }
            translateURL( NULL );   /* �̈��� */
        }
    }
    free( response );

    return ( affURL );
}
