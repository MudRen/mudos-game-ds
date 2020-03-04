// Room: /u/k/king/area/r8.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m-���k�߸�");
	set("long", @LONG
�o�̤w�g�֨찭�������f�F�A�|�P�����H���ʪ��n���A�����D�O�Ԥ�
�٬O�ĤH�A�٬O�p�ߪ��e������n�C���M�H�ɳ����@��Ǫ��ӱ��A�C

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r7.c",
  "east" : __DIR__"r9",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/ccoo" : 1,
  __DIR__"npc/bat" : 2,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
