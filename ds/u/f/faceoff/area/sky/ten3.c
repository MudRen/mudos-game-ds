#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"奇倪峰"NOR);
 set("long",@LONG
你從這裡可以看見你的東北方有一座青色的雕像，風砂
依然如一把利刃般切向你的臉，甚至透過你的衣物刺激著你
的身體，你開始懷疑，這樣的天然環境，似乎是不歡迎你往
這裡走....
LONG
    );
 set("exits",([   "northeast":__DIR__"ten5",
               "southwest":__DIR__"ten2",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

