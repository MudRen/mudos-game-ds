// Room: /open/world1/tmr/frost/depositary3f.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "藏經閣五樓");
        set("long", @LONG
多數道教宮觀的建築為傳統的木結構建築，即以木架為骨幹，牆壁用
磚砌，用瓦蓋屋頂，而牆壁隔扇僅作為內外間隔之用，不負屋頂重量。而
藏經閣則是屬於這類建築，樓高七層，藏書萬卷，為觀內的主要建築之一
，平常是不准外人任意進出。而這兒是藏經閣的五樓。
LONG
        );
        set("current_light", 3);
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/dragon-tiger" : 1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"depositary4f",
  "up" : __DIR__"depositary6f",
]));

        set("objects", ([ /* sizeof() == 1 */
		  __DIR__"npc/dragon-elephant" : 1,
		  __DIR__"npc/bird-elephant" : 1,
		  __DIR__"npc/turtle-elephant" : 1,
		  __DIR__"npc/tiger-elephant" : 1,
		]));

        setup();
}


int valid_leave(object me, string dir)
{
		object g;
        ::valid_leave();
   
        if( dir == "up" ) {
				g = present("5f_guard", this_object());
				if( objectp(g) )  {
    	            message_vision( "$N"NOR"擋在樓梯口前，不讓$n"NOR"上樓去。\n", g, me);
	    	        return 0;
    			}
        }
        return ::valid_leave(me,dir);
}

