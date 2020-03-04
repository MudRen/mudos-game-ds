// Room: /u/k/king/area/r3.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m-���k�߸�");
	set("long", @LONG
�@��諸���餣�T�S���A�R�F�n�[�A�M�ӳo�ǫ���o�O���~�̳��w��
�����F�A�A�n�O�S���������\�O�A�A�ܧִN�|�ܦ��@�D���~�����a�F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r2",
  "south" : __DIR__"r4",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/corpse" : 2,
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
