//updated
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Door＠CyberZoo"NOR);
		set("long", @LONG
通過這個入口，就可以入去動物園了。但入去之前，當然就是要買票
啦。由於這裡才是剛剛開放，所以現在的票會便宜一點，可以說是入去玩
的好時機啊！
LONG
	);
 set("exits",([ 
"in":__DIR__"zoo.c",
"out":__DIR__"enter.c"
]));
set("objects",([
__DIR__"npc/zoosr":1,
]));
set("outdoors","land");
	setup();
	replace_program(ROOM);
}
