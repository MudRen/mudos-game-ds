// Room: /u/s/slency/area/ugelan/god10.c
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ж�");
	set("long", @LONG
�o���ж��̪��G�m�۷���, �@�~�а��v�R����, ��W���F�\�h
�C�q������e��, ���M�O�B�b�@���˹�²�檺�ж���, �o�O�H�Pı��P
���󬰱���F�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"god9",
]));
	create_door("south", "���", "north", DOOR_CLOSED);
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
