// Room: /open/world1/tmr/north_bar/s4.c

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
      __DIR__"npc/anthropophagi-monster" : 3,
      __DIR__"npc/horn-monster" : 3,
    __DIR__"npc/predator-monster" : 3,
    __DIR__"npc/rough-monster" : 3,
    __DIR__"npc/single-monster" : 3,

 ]));

	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"s10",
  "west" : __DIR__"s2",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
