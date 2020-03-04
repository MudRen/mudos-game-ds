// Room: /open/world1/acme/area/senwu1.c

inherit ROOM;

void create()
{
	set("short", "���g�p�|");
	set("long", @LONG
�o�̬O���F���F�n�䪺���g�p�|�A���]�_�ǡA���F���j�������A
���a�o�L���A�B��F���g�A�g������A�o�o�󤣥͡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"senwu2",
  "northwest" : __DIR__"hills1",
]));
	set("world", "past");
    set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
