// Modify with AreaMaker1.0
// Room14.c

inherit ROOM;

void create()
{
	set("short","��L���");
	set("long", @LONG
�o�̥|�P���O�M�H�@�˰�����A�A�����ݨ���̦����i���C���L
�A�o�{�F�誺����G���Q�H���L������C
LONG
	);
	set("exits", ([
		"east": __DIR__"room15",
	]));
	set("hide_exits", ([
		"west": __DIR__"room13",
 	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/pig1" : 2,
		__DIR__"npc/pig0" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

