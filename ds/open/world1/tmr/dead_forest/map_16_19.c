// File: /d/dead_forest/map_16_19.c
// Updated by tmr (Fri Feb 20 22:02:45 2004)

inherit ROOM;

void create()
{
	  set("short", "�j��");
	  set("long", @LONG

LONG
	  );
	  set("map_long", 1);
	  set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"map_16_18",
	"enter" : __DIR__"temple",
	"south" : __DIR__"map_17_19",
]));

	setup();
	  replace_program(ROOM);
}
