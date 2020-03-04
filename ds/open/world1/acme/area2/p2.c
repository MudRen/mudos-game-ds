// Room: /u/a/acme/area3/p2.c

inherit ROOM;

void create()
{
	set("short", "庭院");
	set("long", @LONG
你正站在偌大的庭院，在庭院裡有許多孩童在玩耍，在你的北方種了
一顆大松樹，而東北方則可看見一個小池子。
LONG
	);
        set("light",1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"p3",
  "south" : __DIR__"p",
]));
set("objects",([
   __DIR__"npc/general2" : 1,
]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
