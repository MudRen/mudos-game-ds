#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "洞窟");
        set("long",@LONG
你愈走愈冷,想停下蹲來歇一會,但是這裡冷的你蹲不下來,你開始
想家了,你不禁流下淚來,你搓搓雙手,哈口氣的說:我一定不會
死的,於是你提起勇氣往前走,但你發現...已經沒有路了

LONG
);
        set("exits", ([ /* sizeof() == 1 */
  "east" :"/u/t/tako/area/room~8.c",
]));
    set("light",1);
set("objects", ([ /* sizeof() == 2 */
"/u/t/tako/area/angle_1.c" : 1, 
"/u/t/tako/area/angle_2.c" : 1,]));      
  set("no_clean_up", 0);
                set("outdoors","land");

        setup();
        replace_program(ROOM);
}







