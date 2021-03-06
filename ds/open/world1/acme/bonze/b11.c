// Room: /open/world1/acme/bonze/b11.c

#include <path.h>
inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
你走在頗為破舊的山道上，腳下的石板路搖搖晃晃的建構在山壁
之中，需得小心翼翼的行走，以防不慎摔至山谷中。往西北方的山道
是通往凌雲峰的唯一道路。往東北方可通往凌雲寺寺廟。
LONG
	);
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"b20",
  "northeast" : __DIR__"b12",
  "south" : __DIR__"b10",
 "northwest" :TMR_PAST"advbonze/hill1.c",
]));

	setup();
	replace_program(ROOM);
}
