#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ѱ��p��"NOR);

 set("long",@LONG 
�A�@��i�o�өж�, �ߨ�Q���Ҵ��o�X���W�S�����ҧl��, 
���b�A���o�ӭ����g�Ĥ��w����, ��������A�Q�_�F�ѱ��̤l
����, �A�@���, �C��! �ѱ��s�ɾQ���n���s�������믫, ���L
�̸Ӥ��|�Y����Χa ?! �A�Q�ܦ��B, ��~�Q�ް_���������M��
���L��....
LONG
    );
 set("exits",([ "south":__DIR__"bird7",
    ]));
set("objects", ([__DIR__"npc/cooker" : 1,
    ]));

set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

