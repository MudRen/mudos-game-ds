// Room: /u/k/king/area/r16.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[1;37m-[1;35m����[2;37;0m");
	set("long", @LONG
�o�̴N�O�����p�СA���䳣���L�z���O���A�o�̪����n�����H�H��
���D�A�C�@�Ӯɨ����|���@�Z�u�èӨ��ޡA�Q�b�o�̥��V�O���i�઺�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"r15",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard3" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
