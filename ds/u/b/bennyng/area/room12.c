// Room: /u/b/bennyng/area/room12.c

inherit ROOM;

void create()
{
	set("short", "�����c");
	set("long", @LONG
�|�P���G�F�����᪺�խ��D�O�A�p�J�P�ү볳�K�D�n�q�L�����c�A�N
������X�����c�u�@�̡С������y�����t���h�D
LONG
	);
    set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room15",
  "east" : __DIR__"room10",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
