// Room: /u/s/sonicct/area/road15.c

inherit ROOM;

void create()
{
	set("short", "Naboo����D");
	set("long", @LONG
�o�O�@���Q�����q����D�E���_�i�H�q�����C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shop6",
  "south" : __DIR__"road11",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
