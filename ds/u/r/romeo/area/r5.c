// Room: /u/k/king/area/r5.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m-���k�߸�");
	set("long", @LONG
��F�o�̡A�A�ݨ�@�������Ǫ��A���ٻk�ۭ��~�n���Ī��Z�̡A�@
�ӭӳ��O�Z�L��˳˳�̡A�p�����ܦ��F�����A�ݨӧA�]�t���h�P�C

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r6",
  "west" : __DIR__"r4",
]));
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/dog" : 1,
  __DIR__"npc/bat" : 1,
  __DIR__"npc/corpse" : 1,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
