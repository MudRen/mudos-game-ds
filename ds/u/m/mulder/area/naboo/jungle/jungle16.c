// Room: /u/m/mulder/area/naboo/jungle/jungle16.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"森林"NOR);
	set("long", @LONG
這裡的樹木伸展到天空中，樹葉濃密，遮蓋了大部份的陽光。令到這
裡陰陰森森。你仔細一看，發覺地上佈滿大小不同的腳印。你不奇然覺得
這裡存在一些生物．．．．．
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jungle5",
  "south" : __DIR__"jungle10",
  "west" : __DIR__"jungle20",
  "east" : __DIR__"jungle15",
]));
		 set("objects",([
  __DIR__"npc/shaak":2,
__DIR__"npc/rancor":2,
 ]));

	set("world", "undefine");
	set("outdoors","forest");
	set("no_map",1);
	set("no_recall",1);
	set("no_clean_up", 0);





	setup();
	replace_program(ROOM);
}
