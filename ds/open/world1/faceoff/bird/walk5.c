#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"北走道"NOR);
 set("long",@LONG
這裡已經接近了這條長長的北走道的盡頭了, 再往前走就
是專門提供天梟膜拜者休息的通鋪了, 但北邊並沒有傳出吵鬧
的聲音, 顯然膜拜者深知為客之道.
LONG
    );
 set("exits",([ "north":__DIR__"walk7",

            "south":__DIR__"walk3",

            "east":__DIR__"bed4",
]));
 set("objects", ([__DIR__"npc/prayer" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
