// Room: /u/a/alickyuen/area/inn5.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST．SOFT＠Corridor"NOR);
	set("long", @LONG
這裡是這間旅館的地下二樓的走廊，二旁都是一些給客人的設施，就
像北邊那間休閒室，天天也有很多人在享用。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"inn2",
    "north" : __DIR__"inn7",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
