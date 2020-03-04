// Room: /u/k/king/area/r2.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m-���k�߸�");
	set("long", @LONG
�o�̥|�P���O�G�ꪺ����A���n���~���S�X�ѡA�q��B�������Z����
�ӡA�L�����ӳ��O�Z�̡A�ӥB�Z�\�]���٤����A�ϥΪ����O�@�ǦW�Q���Z
���A�֧��ݡA���@�w���A�X�A���Z����C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r1",
  "east" : __DIR__"r3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dog" : 3,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
