// Room: /u/k/king/area/49.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m������");
	set("long", @LONG
����o�̧A���|�P�n�������H�b�ݵۧA�A�@���������çL��X���
�w�F��H���q�{�]���w�g�ϧA���¡A�{�b���A�u�Q�@�ߤ@�N�����˯��l
�ӡA�N���A�׫ʦL�_�ӡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r60",
  "south" : __DIR__"48",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/vvp" : 1,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
