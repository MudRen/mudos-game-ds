// Room: /u/k/king/area/r4.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m-���k�߸�");
	set("long", @LONG
�o�̪��Ͱ��@�ˬO�@��@�諸�A���G�@�y�s�C�@�ˡAť���u�n�@�y�G
�y�A�N�i�H�����̥����_���A����o��h�����~�A�N�p��s���O�C

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r3",
  "east" : __DIR__"r5",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/dog" : 1,
  __DIR__"npc/corpse2" : 3,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
