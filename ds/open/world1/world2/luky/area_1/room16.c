// Modify with AreaMaker1.0
// Room16.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�@���i�o�̥_�誺���s�ߨ�w�J��î�C�|�P��B���O�j��A���a
������M�\���A�]���o�̪��𸭿@�K�A�ҥH���Ǽ���C���䪺�����
����H�ٰ��A�H�ܩ�A�L�k�ݲM���䦳����F��C
LONG
	);
	set("exits", ([
		"east": __DIR__"room17",
		"south": __DIR__"room26",
	]));
	set("hide_exits", ([
		"west": __DIR__"room15",
 	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

