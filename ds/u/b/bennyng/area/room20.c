// Room: /u/b/bennyng/area/room20.c

inherit ROOM;

void create()
{
	set("short", "�_�~�c���");
	set("long", @LONG
�o�̤@�����I�A�|�P�ը~�~���A�S������ͪ��A�|�B�B�N���`�D���_
���A�N�i�H�~��A���D�ԡD
LONG
	);
    set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room19",
  "east" : __DIR__"room21",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
