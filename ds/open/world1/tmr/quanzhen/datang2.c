// datang2.c �j��G�i
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�j��G�i");
        set("long", @LONG
�o�̬O�j�󪺲ĤG���A�O���u�Ч̤l���\�Ҫ��Ҧb�C�{�b�٤���
�\�Үɶ��A�j��̪ſ������A�u�����u�дx�ޤW�U���ƪ��x�z�D���a
��۴X�Ӥp�D���b��z��ȡA�w���\���C
LONG
        );
        set("exits", ([
                "east" : __DIR__"datang3",
                "west" : __DIR__"datang1",
                "north" : __DIR__"cetang",
                "south" : __DIR__"piandian",
        ]));
        set("objects",([
                CLASS_D("quanzhen")+"/zhangli" : 1,
                __DIR__"npc/daotong1" : 1,
        ]));
	set("coor/x", -2790);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}