// datang3.c �j��T�i
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�j��T�i");
        set("long", @LONG
�o�̬O�j�󪺲ĤT�i�A�O���u�Ч̤lĳ�ƪ��a��C���u�Я��v��
�������u�H�̪����׷ҡA�Ф����U�Ƥ@�볣�浹�j�̤l��౨ӳB�z�C
�J���ƮɡA���u�H�K�|�l������v�̮v�f�A�]�A�T�N�̤l���������j
�̤l�Ө즹�aĳ�ơC
LONG
        );
        set("exits", ([
                "east" : __DIR__"laojundian",
                "south" : __DIR__"nairongdian",
                "west" : __DIR__"datang2",
                "north" : __DIR__"guozhendian",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/fang" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -2780);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}