// Modify with AreaMaker1.0
// Room37.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�o�̬O�@���������󪺤p���C�D����Ǫ�����o���õL���A����
�O�ѫp�ꪺ�d�g�ҾQ���C
LONG
	);
	set("exits", ([
		"south": __DIR__"room47",
		"west": __DIR__"room36",
		"southeast": __DIR__"room48",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/spider1" : 3,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

