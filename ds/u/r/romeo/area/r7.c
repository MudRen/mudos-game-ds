// Room: /u/k/king/area/r7.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m-���k�߸�");
	set("long", @LONG
���ۨ��ۧA���@���H�Y�A�A�~�F�@���A�@�ݬO��赹�A�ܤ����A��
�A�ߤ����K�@�}�P�n�A�߷Q�u�����]�~�i�H�ƸѲ{�b�����H���G�@�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r8",
  "northwest" : __DIR__"r6",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/dog" : 2,
  __DIR__"npc/cool" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
