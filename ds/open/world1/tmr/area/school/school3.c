#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�s��ЫǤG��"NOR);

 set("long",@LONG


[44m                                                        [m
[30;44m       ��                           �l��        ��      [m
[30;44m                    ��           �� �l�i��              [m
[1;33;44m      ��[0;30;44m                       ���i �l�i�i              [m
[30;44m                             ���i�i �l�i�i              [m
[30;44m                           ���f�f�i�i�i�f�f�h��         [m
[1;34;44m�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i�i[m

  �A�V�W��, �A�@���岧��o�ӱЫǬ[�b�Ť������򯫤u, �A�o�{�A
���|�P�O�@�Ǥ��, �䤤���@�ӤW���K�F�@�i�x�����ϥ֯� (paper)
, �A�P�ɤ]�o�{�o�̪��������n, �Ʀܥi�H�ݨ��b�l��, �¤Ѵ򵥦W
�Ӵ��[ , ���ޫ���, �٬O���ݬݯȤW�g�F����a! 

LONG
    );
 set("exits",([ "north":__DIR__"wood1.c",
 		"down":__DIR__"school2.c",
    ]));
 set("item_desc",([
	"paper":@PAPER
	
  �o�i�ȤW�g��: �b�o�ӥ@�ɤ�, ���Ǧa��R���۰g�c, �g�c�@���
�������@�w�����k, �p: ���_���X�B, ���訫�X�B��....�U�@�u����
���X�h, �]�i�H��< [1;33mrecall start[0m >�^��ڤۮ��]....�ڭ̬��F�ϧA
�i�H����x�p����W��, �����b�o�̩��_�N���@�Ӱg�c, �Ʊ�A��
����x�p����W��!

[ ��: ����recall���Ϊk, �Х� help recall �ݬ�. �����T�س�!! ]

PAPER
,
    ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
