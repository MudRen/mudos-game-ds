// Modify with AreaMaker1.0
// Room11.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�@���i�o�̥_�誺���s�ߨ�M�J��î�C�|�P��B���O�j��A���a
������M�\���A�]���o�̪��𸭿@�K�A�ҥH���Ǽ���C�A�o�{�@�Ǥ�
���������]�ͪ��󦹡C�����٤��ɶǥX���~����s�n�C
LONG
	);
	set("exits", ([
		"east": __DIR__"room12",
		"west": SHENGSAN2"aovandis/out064",
		"south": __DIR__"room21",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

