// Room2.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b�@�K����L�̡A�o�̪������A�����\�o�򰪡C�A���_
��M�����O�~�k���s���A�L�����ɶǨӳ��~�D���ҵo�X���������n
���C
LONG
	);
	set("exits", ([
		"east": __DIR__"room3",
		"south": __DIR__"room12",
	]));
 	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird0" : 3,
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

