// Room: /future/area/digging_road2.c

inherit ROOM;

void create()
{
	set("short", "�q�ϹD��");
	set("long", @LONG
�A���b�q�Ϫ��@�����W�A���n���h�O�����j���u�t�A���u�D���v����
�M�q�o���q�Ϫ��j�p�Ʃy�A�]�O���a�ߤ@��u�@���a��A���F���h�O��a
�q�u�~���ЫΡC
LONG
	);
	set("world", "future");
	set("outdoors","desert");
	set("exits", ([ /* sizeof() == 3 */
	  "south" : __DIR__"stihy",
	  "west" : __DIR__"digging_road1",
	  "east" : __DIR__"digging_road3",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
