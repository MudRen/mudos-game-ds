// Room: /u/a/acme/area/lea15.c

inherit ROOM;

void create()
{
	set("short", "�j���");
	set("long", @LONG
�A���B�b�@���j��줧�W�A�|�P������w���o��H���F�A�}�U���d�g
�]�ܱo�����d�סA�樫�۷��K�C�Ať�����ɱo�Ǩӭ��V���~�����s�n�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lea5",
  "east" : __DIR__"lea16",
//��bug ���� "north" : __DIR__"gosky",
  "northeast" : __DIR__"pass",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
