// Room: /u/b/bennyng/area/room38.c

inherit ROOM;

void create()
{
	set("short", "�s�Ϯc");
	set("long", @LONG
�o�̫K�O�s�Ϯc���X�f�A�����򤴤����s�Ϯy�����t���h�H�H�O���O
�`�ȧA�̦ӧ�a����_�ӡH�H�K�K�I�I�K�K�I�I
LONG
	);
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room43",
  "south" : __DIR__"room39",
  "east" : __DIR__"room37",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
