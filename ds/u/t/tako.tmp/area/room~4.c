#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "洞窟");
        set("long",@LONG
你快走到了洞窟的盡頭,你的眼皮還是不斷的在跳猛獸的的叫聲更為
劇烈,你又看到裡面好像有個人?但這次你決不靠近他。
LONG
);
   set("exits", ([ /* sizeof() == 2 */
  "south" :"/u/t/tako/area/room~3.c",
  "enter" :"/u/t/tako/area/room~5.c",
]));
    set("light",1);
set("objects", ([ /* sizeof() == 1 */
"/u/t/tako/area/sun.c" : 1,
]));        set("no_clean_up", 0);
                set("outdoors","land");

        setup();

}
