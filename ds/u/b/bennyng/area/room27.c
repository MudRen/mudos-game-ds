// Room: /u/b/bennyng/area/room27.c

inherit ROOM;

void create()
{
	set("short", "�_�~�c�c��");
	set("long", @LONG
�o�̥i�ݨ�t�쪺�[�P�ӡA�A�i�H���D�A����[�P�Ө���O���V�D
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"room24",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
