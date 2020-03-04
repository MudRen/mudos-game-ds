#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
走到這邊是一個空間寬廣的墓室，你勉強壓抑心中的不安，慢慢
地審視四周四周呈現圓形的牆上空無一物，但不知為何，你心中一直
覺得不舒服，周圍樹根，土紋，甚至石塊的分佈都會讓你覺得像是妖
魔正向著你直撲而來。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"room1",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/helmet-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

