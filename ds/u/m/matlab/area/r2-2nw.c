// Room: /u/m/matlab/area/r2-2nw.c

inherit ROOM;

void create()
{
	set("short", "�·t�j�Y");
	set("long", @LONG
�|�P�@�����I�A���D�W�H�إi���t������{�^�O�b���骺�۬W�W
��{����[���F!!!!
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"r2-2.c",
  "north" : __DIR__"r2-2nwn.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
