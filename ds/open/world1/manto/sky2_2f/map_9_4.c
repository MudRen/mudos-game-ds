// Room: /open/world1/manto/sky2_2f/map_9_4.c

inherit ROOM;

void create()
{
	set("short", "�����@�k��");
	set("long", @LONG

LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"map_7_6",
]));

	setup();
      call_other( "/open/world1/manto/sky2_2f/board/sky_secret_b", "???" );
        set("stroom", 1);
}
