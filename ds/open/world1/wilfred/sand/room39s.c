// Room: /open/world1/wilfred/sand/room39s.c

inherit ROOM;

void create()
{
	set("short", "���F��");
	set("long", @LONG
�g�~�֤몺���F�A��X�F�o�����F�C���a�A�C���W�o�󤣥͡A��
�~�����A��a�H�٤����y���F���z�A���C�����s���½Y�s���P���F�D
���n�D�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room39",
]));
	set("outdoors", "land");
	set("current_light", 1);
	set("no_clean_up", 0);
    set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/npc10" : 1,
    ]));

	setup();
	replace_program(ROOM);
}
