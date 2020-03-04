// Room: /u/k/king/area/44.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m�C�P�L");
	set("long", @LONG
�o�̬O�a���٥@�Ю˩w������ҡA�ݰ_�ӨèS������F��A�u�O�b�|
�P���@�j�M���b�ΰ����į�C���l�ӷ�~���D���ͤ��Ѥ��įS�O��˩w��
�Ш�o�̨ӡA�u�O�Ĥ����S���Ҧn�A�u���C�C���F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"45",
  "east" : __DIR__"r35",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/fgf" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
