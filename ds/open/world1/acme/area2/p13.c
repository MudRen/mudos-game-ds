// Room: /u/a/acme/area3/p13.c

inherit ROOM;

void create()
{
	set("short", "長廊");
	set("long", @LONG
這是一條橫貫東西的長廊，長廊邊擺放了許多小盆栽。
LONG
	);
       set("light",1);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"p5",
  "west" : __DIR__"p14",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
