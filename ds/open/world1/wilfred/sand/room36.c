// Room: /open/world1/wilfred/sand/room36.c

inherit ROOM;

void create()
{
	set("short", "���F��");
	set("long", @LONG
�g�~�֤몺���F�A��X�F�o�����F�C���a�A�C���W�o�󤣥͡A��
�~�����A��a�H�٤����y���F���z�A���C�����s���½Y�s���P���F�D
���n�D�A�c�W�L�����y���F���z���s��K�b�o����C
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/npc20" : 1,
    __DIR__"npc/npc20_0" : 4,
]));
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"room35",
  "south" : __DIR__"room38",
  "north" : __DIR__"room36_1",
]));
	set("current_light", 1);
	set("outdoors", "land");
	set("no_recall", 1);

	setup();
	replace_program(ROOM);
}
