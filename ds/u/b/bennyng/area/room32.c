// Room: /u/b/bennyng/area/room32.c

inherit ROOM;

void create()
{
	set("short", "�s�Ϯc�P�_�~�c���");
	set("long", @LONG
�ѪŬ�M�U�ۤ@���ճ��A��ū�t�U���A�A�����֤@�B�A���Ʒ|�P�_
�D���_�N�O�_�~�c���J�f�A�A�����|������Ʊ��|�o�͡D
LONG
	);
    set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room33",
  "northup" : __DIR__"room31",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
