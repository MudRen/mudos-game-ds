// Room: /open/world1/tmr/hasake/room-che.c

inherit ROOM;

void create()
{
	set("short", "�����w���a");
	set("long", @LONG
�����w���b�������B�o�ܾ��A�@�i�i´�۬����󪺦Ϥ�౾�b�|
�P�C�G��W��۴X�Ӥj�s�J�A�@�Ө����]�����k�Ĥl���F�s�ߥX�ӯ��H�H
�a�ݵۧA�C
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/aman" : 1,
]));
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"caoyuan8",
]));

	setup();
	replace_program(ROOM);
}
