#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�T��"NOR);

 set("long",@LONG
�A�@��i�o���T��, �ߨ�Q���Τl���������~��F, �A�L�w��
��, ���M�Q�_�Ʀ~�e�b����w�R�����f�X�W������, �ڻ��L��Ӭ�
�}�@���W�Q, �h����Q�U�j�s��, ��ӥL�N�O�h���즹�B�M�@�s��
�H����....
LONG
    );
 set("exits",([ "north":__DIR__"eastroad3",
    ]));
 set("objects", ([__DIR__"npc/tao_chaung" : 1,
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
