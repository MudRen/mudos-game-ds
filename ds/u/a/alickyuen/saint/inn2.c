// This is a room made by roommaker.
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST．SOFT＠地下一樓"NOR);
	set("long", "這裡是酒店的地下一樓，這裡比你的想像中大得多了，在你的兩旁有
一大排一大排的房間，如果你要住進去就應該要付款了。你走著看著，都
沒有發現任何特別的東西。\n");
set("exits",([ 
"up":__DIR__"inn",
"east":__DIR__"inn5",
]));
set("objects", ([
__DIR__"npc/keeper" : 1,
]));
set("no_fight",1);
set("light",1);
	setup();
}
