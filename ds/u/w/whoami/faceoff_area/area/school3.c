#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�˪ŮѰ|�G��"NOR);

 set("long",@LONG
�A�V�W��, �A�@���岧��o�ӮѰ|�[�b�Ť������򯫤u, �A�o�{�A���|�P�O�@��
���, �䤤���@�ӤW���K�F�@�i�x�����ϥ֯�(paper), �A�P�ɤ]�o�{�o�̪�������
�n, �Ʀܥi�H�ݨ��b�l��,�¤Ѵ򵥦W�Ӵ��[ , ���ޫ���, �٬O���ݬݯȤW�g�F��
��a! 
LONG
    );
 set("exits",([ "north":"/u/f/faceoff/wood1.c",  
    ]));
 set("item_desc",([
        "paper":"�o�i�ȤW�g��:�b�o�ӥ@�ɤ�, ���Ǧa��R���۰g�c,
�g�c�@��ӻ������@�w�����k, �p:���_���X�B, ���訫�X�B��....�U�@ 
�u�������X�h, �]�i�H��recall�^��¤Ѽөιڤۮ��]��....�ڭ̬��F
�ϧA�i�H����x�p����W��, �����b�o�̩��_�N���@�Ӱg�c, �Ʊ�A��
����x�p����W��! .\n",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}