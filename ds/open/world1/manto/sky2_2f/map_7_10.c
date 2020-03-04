// Room: /open/world1/manto/sky2_2f/map_7_10.c

inherit ROOM;

void create()
{
	set("short", "�����@�k��-�Z����");
	set("long", @LONG

LONG
	);
	set("current_light", 2);
	set("light", 1);
	set("map_long", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/heaven_wp_box" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"map_5_8",
  "southeast" : __DIR__"map_9_12",
]));
	set("no_clean_up", 0);

	setup();
        set("stroom", 1);
}
