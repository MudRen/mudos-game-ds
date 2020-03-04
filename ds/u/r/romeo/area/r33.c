// Room: /u/k/king/area/r33.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m�C�P�L");
	set("long", @LONG
�o�̬O�Q�j���⤧�@�����f�C������ҡA���l�Ӭݤ��L���Z�\�A�N�N
�L����ۤv�����̡A�C���f�C���Q���a�l���ɡA���l�ӳ��|�X�����L
�\���A��O���f�C���]���~��b�o�̡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r32",
  "east" : __DIR__"42",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pkman" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
