// Room: /u/a/acme/area/lea5.c

inherit MOBROOM;

void create()
{
	set("short", "�j���");
	set("long", @LONG
�A���B�b�@���j��줧�W�A�|�P������w���o��H���F�A�}�U���d�g
�]�ܱo�����d�סA�樫�۷��K�C�Ať�����ɱo�Ǩӭ��V���~�����s�n�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"lea12",
  "south" : __DIR__"lea4",
  "north" : __DIR__"lea15",
  "southwest" : __DIR__"lea8",
]));
        set("chance",65);
        set("mob_amount",4);   
     set("mob_max",12);
        set("mob_object",({   
            __DIR__"npc/rabbit",
        }) );
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
}
