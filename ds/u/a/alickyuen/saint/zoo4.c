//3012
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Road＠CyberZoo"NOR);
	set("long", @LONG
走到這樣，你感到有一點累了，正好在東北面有一個小小的公園供遊
人休息一下。與此同時，你聽到在西北面有一陣陣獅子的吼叫聲，看來那
邊應該是放置獅子的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"zoo5",
  "south" : __DIR__"zoo2",
  "northwest" : __DIR__"zoo6",
]));
set("objects", ([
__DIR__"npc/zooer.c" :1,
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
