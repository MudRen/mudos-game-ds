// Room: /u/k/king/area/r21.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[1;37m-[1;35m����[2;37;0m");
	set("long", @LONG
�o�̴N�O�԰�ӳ��Ĥ@�h�F�A�A�i�H��o�̨Ӥw�g�N��A���Z�\�׬��w
�g���@�w���{�פF�A�A�U�h�A�]�u�������@���A�|�P�]���u���@��諸�u�\
�Y�A�����D�h�֥j�N�����⦺�b�o�̡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r22",
  "down" : __DIR__"r20",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
