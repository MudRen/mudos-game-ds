//u/c/chiaa/world2/blackly_forest/vacancy1.c

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "林間空地");
        set("long", @LONG
這是林間的一小片空地,方圓不過數尺,兩旁除了青草綠樹,
不時可看見螻蟻之類的小昆蟲，也可聽得鳥叫蟲嗚,
可以讓行走在森林的人,在這裡暫時得到休息!!
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
     "southeast"  : __DIR__"path2",           //小徑2
     "northwest"  : __DIR__"road1",          //森林外處
]));
       
        setup();
replace_program(ROOM);
}
