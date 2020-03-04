#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"奇倪峰"NOR);
 set("long",@LONG
這裡有一座青色的雕像，看起來是由青田石所刻成，從
它駭人外型來看似乎是一隻張牙舞爪的巨龍，它的雕工栩栩
如生，讓它的鱗片看起來似乎會隨著風砂顫慄，你也同時可
以看見你的西方就是那片平台，看青龍的樣子，它似乎正警
告著想要往西而入的邪惡之徒，而往東有一座似乎是神廟的
建築....
LONG
    );
 set("exits",([  "northwest":__DIR__"ten21",
              "west":__DIR__"ten7",
               "southwest":__DIR__"ten3",
                 "eastdown":__DIR__"ten42",
    ]));
 set("objects",([__DIR__"npc/sky_guard" : 2,
                 __DIR__"npc/sky_leader" : 1,
    ]));

set("no_clean_up",0);
set("outdoors","land");
 setup();
}
int valid_leave(object me,string dir)
{
        if( dir== "eastdown" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me,dir);
}



