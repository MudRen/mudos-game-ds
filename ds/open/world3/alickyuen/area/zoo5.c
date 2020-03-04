// Room: /u/a/alickyuen/area/zoo5.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Road＠CyberZoo"NOR);
	set("long", @LONG
來到這裡，你感到四周圍鳥語花香，你覺得這裡的風景跟動物園的有
很大的分別。你將所有的倦意驅走了。一直走去，你會到達花園那邊了。
而向西南便可以回到動物園的道路。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zoo11",
  "southwest" : __DIR__"zoo4",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
