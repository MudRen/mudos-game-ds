// Room: /u/m/matlab/area/r2-1ne.c

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
  "north" : __DIR__"r2-1nen.c",
  "southwest" : __DIR__"r2-1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
