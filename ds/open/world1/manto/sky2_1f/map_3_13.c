// Room: /open/world1/manto/sky2_1f/map_3_13.c

inherit ROOM;

void create()
{
	set("short", "���Юi���]");
	set("long", @LONG

LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"map_3_11",
  "south" : __DIR__"map_5_13",
]));
        set("objects",([
    __DIR__"npc/goldman4" :1,
    __DIR__"obj/ming_platform" :1,
    __DIR__"obj/ming_mark" :1,
]));

	setup();
}
