#include <room.h>
inherit ROOM;
void create()
{
        set("short", "十二人旅店");
        set("long", @LONG
這是地下城中的十二人客棧，在這裡有大群的來客，似乎可以比主
城的小客棧的小很多，十二人客棧是最近老口碑的客棧，所以來客湧湧
而入，可能是有歷史兼氣氛溫馨的關係，在這裡的旅客都不會大聲說話
，好像有幾位不禮貌的客人被旅館主人轟出去變成第十三人了，樓上是
來客的休息房，在每桌桌上都放了一個菜單。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "north":__DIR__"sec6.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/boss.c"     :1,
"/open/world3/tmr/basic/npc/hotelrobot.c"  :1,
]));

        setup();
        replace_program(ROOM);

}
