// 30/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Road＠CyberZoo"NOR);
	set("long", @LONG
聽到獅子的吼叫聲，你已經知道這裡是放置獅子的地方。在牠們叫的
同時，有些小朋友很興奮地跟著牠們叫，但也有一些小朋友因為害怕而大
哭起來。往東南便可回到動物園的道路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"zoo4",
"north" : __DIR__"zoo19",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
