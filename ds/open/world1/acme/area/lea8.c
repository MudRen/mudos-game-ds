// Room: /u/a/acme/area/lea8.c

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
  "northeast" : __DIR__"lea5",
  "south" : __DIR__"lea6",
  "east" : __DIR__"lea4",
  "southwest" : __DIR__"lea7",
]));
	set("no_clean_up", 0);
     set("outdoors","land");
    set("objects", ([
       __DIR__"npc/pig" : 4,
    ]));

	setup();
	replace_program(ROOM);
}
