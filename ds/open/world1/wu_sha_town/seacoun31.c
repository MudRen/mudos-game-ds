#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","石屋內");
set("long",@LONG
你看到你的面前有一位白髮蒼蒼的老人, 不經過旁人口耳
相傳, 根本不會將眼前的老人和傳奇人物林繁榮想在一起.
LONG
    );
 set("exits",([ "south":__DIR__"seacoun30",
		"north":__DIR__"seacoun32",
]));
 set("objects", ([__DIR__"../npc/lin" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}            