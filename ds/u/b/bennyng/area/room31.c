// Room: /u/b/bennyng/area/room31.c

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
  "southdown" : __DIR__"room32",
  "westup" : __DIR__"room30",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
