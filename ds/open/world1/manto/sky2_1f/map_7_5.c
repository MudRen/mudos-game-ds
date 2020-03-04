// Room: /open/world1/manto/sky2_1f/map_7_5.c

inherit ROOM;

void create()
{
	set("short", "�x�|");
	set("long", @LONG

LONG
	);
	set("light", 1);
	set("ourdoors", "land");
	set("current_light", 1);
	set("map_long", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"map_7_3",
]));
	set("no_clean_up", 0);

        set("objects",([
    __DIR__"npc/goldman9" :1,
    __DIR__"npc/goldman8" :1,
    __DIR__"npc/goldman5" :8,
    __DIR__"obj/melamine_manto" :1,
]));
	setup();
	replace_program(ROOM);
}
