// 27/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Fish＠CyberZoo"NOR);
	set("long", @LONG
上到來，你的眼前一亮，因為你看到了很多魚類，有熱帶魚，鯊魚等
等‥‥‥看得你眼花撩亂。突然你看到有人潛進了魚缸內，原來牠們要用
餐了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zoo10",
  "down" : __DIR__"zoo7",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
