// Room: /u/a/acme/area/lea12.c

inherit ROOM;

void create()
{
	set("short", "大草原");
	set("long", @LONG
你身處在一片大草原之上，四周的野草已長得比人高了，腳下的泥土
也變得較為泥濘，行走相當不便。你聽見不時的傳來飛禽走獸的的叫聲。
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
