// Modify with AreaMaker1.0
// Room52.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�o�̬O��L���@���C���ǳ��O�@�Ǳ`������M��A�S������S�O
���F��A�A�Ҽ{�F�@�U�٬O�M�w�~�򻰸��A�S���n�b�o�̮��O�ɶ��C
LONG
	);
	set("exits", ([
		"north": __DIR__"room42",
		"east": __DIR__"room53",
		"south": __DIR__"room62",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird1" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

