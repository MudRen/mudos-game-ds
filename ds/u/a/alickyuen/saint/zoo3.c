// Room: /u/a/alickyuen/area/zoo3.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Road＠CyberZoo"NOR);
	set("long", @LONG
這邊的是比較兇惡的動物，有豹、老虎等，但唯獨是沒有獅子。聽了
管理員的說話後才知道獅子因為跟其他動物不和而被他們隔離了。往西就
可以去到商店及水族館等的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zoo7",
  "east" : __DIR__"zoo",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
