// Room: /open/world1/tmr/north_bar/town19.c

inherit ROOM;

void create()
{
	set("short", "�_�Z�����ľQ");
	set("long", @LONG
�o�̬O���̰ߤ@���@�a�ĩ��A�����N�i�D��@�@���į��
�ľQ�j�ҴN���b�e���i���į��C
LONG
	);
	set("light", 1);
	set("objects", ([ 
	__DIR__"npc/herbalist" : 1, ]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"town18",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
