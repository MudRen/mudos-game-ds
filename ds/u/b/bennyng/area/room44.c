// Room: /u/b/bennyng/area/room44.c

inherit ROOM;

void create()
{
	set("short", "�s�Ϯc�e");
	set("long", @LONG
�e���N�O�s�Ϯc�Ať���s�Ϯy�t���h�O�ﶮ��R�̩������@��A�L��
�t�C�i���O�ѤU�L���A�@�x�i���ѹ@�a�A�A�߷Q�e����������p�߹�I�D
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"room45",
  "northup" : __DIR__"room41",
]));
        set("objects", ([
  __DIR__"npc/guard.c":4,
]));
        set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
