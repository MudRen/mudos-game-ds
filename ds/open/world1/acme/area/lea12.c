// Room: /u/a/acme/area/lea12.c

inherit ROOM;

void create()
{
	set("short", "�j���");
	set("long", @LONG
�A���B�b�@���j��줧�W�A�|�P������w���o��H���F�A�}�U���d�g
�]�ܱo�����d�סA�樫�۷��K�C�Ať�����ɪ��Ǩӭ��V���~�����s�n�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"lea11",
  "south" : __DIR__"lea10",
  "west" : __DIR__"lea4",
  "northwest" : __DIR__"lea5",
]));
	set("no_clean_up", 0);
      set("outdoors","land");
    set("objects", ([
       __DIR__"npc/sciurine" : 4,
    ]));

	setup();
	replace_program(ROOM);
}
