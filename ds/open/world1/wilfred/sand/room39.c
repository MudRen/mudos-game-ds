// Room: /open/world1/wilfred/sand/room39.c

inherit ROOM;

void create()
{
	set("short", "���F��");
	set("long", @LONG
�g�~�֤몺���F�A��X�F�o�����F�C���a�A�C���W�o�󤣥͡A��
�~�����A��a�H�٤����y���F���z�A���C�����s���½Y�s���P���F�D
���n�D�A���B�A���訫�A�K�i���½Y�s������}�A��_�軷�B�i����
�ݨ�@�y���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room39s",
  "east" : __DIR__"room38",
  "westdown" : __DIR__"room40",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
