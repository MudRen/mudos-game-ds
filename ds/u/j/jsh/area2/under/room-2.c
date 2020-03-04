#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
牆上冒出一陣淡青色的薄霧，在地板滑過滲入另一邊的牆中，室
頂還滴著細細小水，連接著古墓的儲水池，不時還會傳來陣陣魚兒撞
擊池底的聲響。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"room2",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/cloth-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


