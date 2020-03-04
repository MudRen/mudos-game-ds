// Room: /open/world1/manto/sky2_2f/map_5_8.c

inherit ROOM;

void create()
{
	set("short", "�����@�k��-���㶡");
	set("long", @LONG

LONG
	);
	set("current_light", 2);
	set("light", 1);
	set("map_long", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/heaven_eq_box" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"map_3_8",
  "southeast" : __DIR__"map_7_10",
  "southwest" : __DIR__"map_7_6",
  "down" : "/open/world1/manto/sky2_1f/map_3_7.c",
]));
	set("no_clean_up", 0);

	setup();
        set("stroom", 1);
}
