// Room: /u/l/lestia/area/sn2.c

inherit ROOM;

void create()
{
 set("short", "�_��j�˪L");
	set("long", @LONG

����o�̡A�A�o�{���a���������𸨸��A�ϩ�������´�Ӧ����a��A�A
���T�h�æۤv�b�ڹҤ��Ө�F���ܥ@�ɡC�Z�K������L���j�F�~�ɶǨӪ���
�u�A�Ȧ�������U���o�P�P�@��Y�g�����~�A�ϧA���M��ı�©]�P�ձު���
���C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
set("no_map",1);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"sn3",
  "north" : __DIR__"sn1",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
