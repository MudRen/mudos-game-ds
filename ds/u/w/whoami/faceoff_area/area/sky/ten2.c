#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�_�ٮp"NOR);
 set("long",@LONG
�A�q�s�f�A�������F�@�ǡA�W�ӤF�@�Ӥ@��L�ڪ����a
�A�u���o���a���F�u�u�A���G�O�Ѷ��F�Ҳզ��A�A�b�@����
�⤤�A�̵}�i�H�ݨ��_����G���@�y����|�P�����x...
LONG
    );
 set("exits",([   "northeast":__DIR__"ten3",
             "northwest":__DIR__"ten4",
              "south":__DIR__"ten1",
    ]));
 set("objects", ([__DIR__"npc/sky_guard" : 1,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

int valid_leave(object me, string dir)
{
        if( dir== "enter" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}
