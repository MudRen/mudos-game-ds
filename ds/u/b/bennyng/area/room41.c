// Room: /u/b/bennyng/area/room41.c

inherit ROOM;

void create()
{
	set("short", "�s�Ϯc");
	set("long", @LONG
�o�̫K�O�s�Ϯc�A�����򤴤����s�Ϯy�����t���h�H�H�O���O�`�ȧA
�̦ӧ�a����_�ӡH�H�K�K�I�I�K�K�I�I
LONG
	);
        set("exits", ([ /* sizeof() == 3 */
  "southdown" : __DIR__"room44",
  "north" : __DIR__"room42",
  "east" : __DIR__"room40",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
