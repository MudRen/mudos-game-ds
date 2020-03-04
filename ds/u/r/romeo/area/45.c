// Room: /u/k/king/area/45.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m�C�P�L");
	set("long", @LONG
�o�̬O��~�M�]�ЬP���ݬ��b���]�۪��A�o�H�@�ĥ|�������ѡA����
�h�����򩳥j�ӡA�|�P�u���@��諸����A�M��o�@�I����]�S���A�ӳ�
������]�������ӫI�ǡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"44",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/blademan" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
