// Room: /u/a/acme/area3/p3.c

inherit ROOM;

void create()
{
	set("short", "蒼松下");
	set("long", @LONG
你正站在蒼松下，在蒼松右邊的大枝幹，垂吊著給孩童遊玩的鞦韆，
許多小孩在此嬉戲打鬧，在你的東邊可看見一座小拱橋。
LONG
	);
        set("light",1);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"p4",
  "east" : __DIR__"p6",
  "west" : __DIR__"p18",
  "south" : __DIR__"p2",
]));
     set("objects",([
        __DIR__"npc/child" : 3,
     ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
