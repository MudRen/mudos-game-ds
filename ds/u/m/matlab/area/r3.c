// Room: /u/m/matlab/area/r3.c

inherit ROOM;

void create()
{
	set("short", "�·t�j�Y");
	set("long", @LONG
�|�P�@�����I�A���D�W�H�إi���t������{�^�O�b���骺�۬W�W
��{����[���F!!!!�_�誺�����Q���_�F�A��������o�Q�����ƥO
�A�n�_�߹y�_�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"r4.c",
  "west" : __DIR__"r2-2nwnnne.c",
  "east" : __DIR__"r2-1nennnw.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
