// Room: /u/k/king/area/r32.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m�C�P�L");
	set("long", @LONG
�o�̬O������´�T���_���ĤG�ھڦa�A�W��G�������A��~�鸨�s�@
�Ы�A�������򯳩l�ӭq�U���w�A�������t�d�u�ìӳ��A�M�᯳�l�ӫO��
���������w���A�ҥH���l�Ӫ����U�]���q���������H�T���C
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "west" : __DIR__"r35",
  "north" : __DIR__"r34",
  "south" : __DIR__"r37",
  "east" : __DIR__"r33",
  "northwest" : __DIR__"r36",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
