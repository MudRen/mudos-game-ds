#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "洞窟");
        set("long",@LONG
這裡是洞窟的底部,你感覺愈來愈嚴熱了,熱的快要受不了了,
你往前一眺,好像是無止盡的山洞,前面好像也有人,但你心裡
有打個數,"它"決非善類
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "east" :"/u/t/tako/area/room~2.c",
  "west" :"/u/t/tako/area/room~7.c",
]));
    set("light",1);
set("objects", ([ /* sizeof() == 1 */
"/u/t/tako/area/axe man.c" : 1,
]));        set("no_clean_up", 0);
                set("outdoors","land");

        setup();
        replace_program(ROOM);
}




