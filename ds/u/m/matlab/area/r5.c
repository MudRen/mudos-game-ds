// Room: /u/m/matlab/area/r5.c

inherit ROOM;

void create()
{
	set("short", "�e�x");
	set("long", @LONG
�e��@���O���q���A�@�����e����LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r4.c",
  "north" : __DIR__"r6.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
