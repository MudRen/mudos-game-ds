// Modify with AreaMaker1.0
// Room63.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b�@�j������L�̡C���ǳ��O�@�Ǳ`������M��A�S����
��S�O���F��C�L�����ɶǨӳ��~�D���ҵo�X���������n���C
LONG
	);
	set("exits", ([
		"north": __DIR__"room53",
		"south": __DIR__"room73",
		"west": __DIR__"room62",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

