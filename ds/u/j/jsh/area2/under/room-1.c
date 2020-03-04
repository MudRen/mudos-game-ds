#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
似乎所有的密室都有一位神秘的人，不時還會說有怪獸出沒，但
，就要看你相不相信了。此室吹著微微的涼風，讓人覺得清爽，涼快
，沉重的心情，一掃而空。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"room1",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/mask-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

