#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","奇倪峰");

 set("long",@LONG
這裡是奇倪峰的東北邊, 你不禁因為眼前的景像而感到自
己的渺小, 奇倪峰是由堅硬的花崗岩形成, 因此四周完全沒有
任何植物….
LONG
    );
 set("exits",([ "south":__DIR__"ten10",
		"west":__DIR__"ten14",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}
