#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���g�p��");

 set("long",@LONG
�A�ש󨫨�p�������Y�F, ���e�O�@�Ӥj�j�����, �u����
�ǳ��O�@�Ǩ��ޤ������o, �ϧA�P��A���ͩR���ǦM�I, ���O�A
���M�o�{���@�ӺX�D�˦b�a�W, �A�γ\�i�H...�K�K....
LONG
    );
 set("exits",([ "enter":__DIR__"ten6", 
                "west":__DIR__"ten4",
    ]));
 set("objects", ([__DIR__"npc/leader" : 1,
    ]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}

