// Modify with AreaMaker1.0
// Room13.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b��L���C�����j���������ۡA�ը˦b�j�۵M�����Pı�O
�H���M�@�s�C�F����O���G���@���p���A���L�]������Ӫ��F������
�M���C
LONG
	);
	set("exits", ([
		"north": __DIR__"room3",
		"south": __DIR__"room23",
		"west": __DIR__"room12",
	]));
	set("hide_exits", ([
		"east": __DIR__"room14",
 	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

