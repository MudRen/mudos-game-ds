// 30/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Road＠CyberZoo"NOR);
	set("long", @LONG
這裡正是動物園的出入口，當你想拿入場卷到入口的招待處的時候，
你才看到在那邊有一個告示牌(sign)，上面竟然寫著一些令你意想不到的
東西……
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"zoo2",
  "west" : __DIR__"zoo3",
  "out" : __DIR__"enter2",
]));
set("objects",([
__DIR__"obj/sign":1,
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
