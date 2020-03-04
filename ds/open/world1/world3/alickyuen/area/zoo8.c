// 27/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST．Shop＠Cyberzoo"NOR);
	set("long", @LONG
這裡是動物園內的一間商店，主要的是賣一些手信及小食給遊人，但
最受歡迎的要算是給動物吃的飼料了。你可以買一些來給動物吃的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"zoo7",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zseller" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
