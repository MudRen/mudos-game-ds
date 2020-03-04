#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"奇倪峰"NOR);
 set("long",@LONG
你從山口再往內走了一些，上來了一個一望無際的平地
，只見這平地黃沙滾滾，似乎是由黃沙所組成，你在一片風
砂中，依稀可以看見北方似乎有一座高於四周的平台...
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
                return notify_fail("那裡只有玩家才能進去。\n");
        return ::valid_leave(me, dir);
}
