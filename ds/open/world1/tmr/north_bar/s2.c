// Room: /open/world1/tmr/north_bar/s2.c

inherit ROOM;

void create()
{
	set("short", "千年古洞-地下二層");
	set("long", @LONG
你走著走著，突然，你覺得地上黏黏的、軟軟的，似乎會凹
陷下去。原來，這地上有一大片的泥巴，反而讓你走起路來更不
方便了。
LONG
	);
	set("objects", ([
//	  __DIR__"npc/anthropophagi-monster" : 1,
//	  __DIR__"npc/horn-monster" : 1,
	  __DIR__"npc/predator-monster" : 1,
	  __DIR__"npc/rough-monster" : 1,
	  __DIR__"npc/single-monster" : 1,
 ]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s1",
  "east" : __DIR__"s4",
  "north" : __DIR__"s5",
  "west" : __DIR__"s3",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
