// Room: /u/b/bennyng/area/room21.c

inherit ROOM;

void create()
{
	set("short", "�_�~�c");
	set("long", @LONG
�o�̫K�O�_�~�c�����Y�A�o�̪������L�a���٭�A�u���\�O�d��
�A�L�j�j���p�t�z�A�ϧA������E����C�A����}�l���w�_�ӡA�A�߷Q��
���I�ѨM�L�A���w�ϧA���v���𤧤��D
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room22",
  "west" : __DIR__"room20",
]));
        set("objects", ([
  __DIR__"npc/Aquarius.c":1,
]));
        set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
