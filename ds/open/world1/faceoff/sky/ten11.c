#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","村門");
 set("long",@LONG
這裡就是苗家村的村門了，在村門之外，是一片到人腰
際的劍草叢，而在村門之內，則是到處嬉戲的孩童，以及在
門口談笑的老人，看來這真是遠離世間的人間桃園....
LONG
    );
 set("exits",([   "west":__DIR__"ten12",
               "east":__DIR__"ten10",
    ]));
set("objects", ([__DIR__"npc/meo_guard" : 2,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

