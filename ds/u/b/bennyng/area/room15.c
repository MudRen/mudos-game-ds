// Room: /u/b/bennyng/area/room15.c

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
  "north" : __DIR__"room12",
  "east" : __DIR__"room13",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
