//u/c/chiaa/world2/blackly_forest/den.c

#include <ansi.h>
inherit ROOM;

void create ()
{
  set("short", "密室");
  set("long", @LONG
一個黑暗的密室,原來這裡是忍者村的逃生出口,
要是有敵人來襲,而入口又被封住,就可以由此通往外面的
黑暗森林!!
LONG
        );
  set("exits", ([ /* sizeof() == 1 */
 "up"    : __DIR__"road8", //森林外處
  
]));


 setup();
  replace_program(ROOM);
}
