#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"大廳"NOR);

 set("long",@LONG
這裡是天梟冶藥一派的北邊大廳, 你注意到這裡的遊客已
經少了很多, 可見這裡天梟並不對外開放, 很有可能天梟冶藥
一派的女眷都住在此.
LONG
    );
 set("exits",([ "southwest":__DIR__"pill5",
		"southeast":__DIR__"pill11",
		"north":__DIR__"pill9",
    ]));
 set("item_desc",([
        "柱子" : "一根大大的柱子, 從這個角度看不出有什麼異常\n", 
    ]));
 set("objects", ([__DIR__"npc/birdguard" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();                  
}
