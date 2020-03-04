// Room: /u/a/acme/area3/p4.c

inherit ROOM;

void create()
{
	set("short", "庭院");
	set("long", @LONG
你正站在偌大的庭院，在庭院裡有許多孩童在玩耍，在你的北方有一
個大廳，南邊則有一顆大榕樹。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"p5",
  "south" : __DIR__"p3",
]));
       set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
