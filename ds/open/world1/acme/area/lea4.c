// Room: /u/a/acme/area/lea4.c

inherit ROOM;

void create()
{
	set("short", "�j���");
	set("long", @LONG
�A���B�b�@���j��줧�W�A�|�P������w���o��H���F�A�}�U���d�g
�]�ܱo�����d�סA�樫�۷��K�C�Ať�����ɱo�Ǩӭ��V���~�����s�n�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lea3",
  "north" : __DIR__"lea5",
  "west" : __DIR__"lea8",
  "east" : __DIR__"lea12",
]));
	set("no_clean_up", 0);
       set("outdoors","land");

	setup();
	replace_program(ROOM);
}
