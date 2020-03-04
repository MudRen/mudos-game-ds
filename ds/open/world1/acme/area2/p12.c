// Room: /u/a/acme/area3/p12.c

inherit ROOM;

void create()
{
	set("short", "長廊");
	set("long", @LONG
這是一條橫貫東西的長廊，長廊邊擺放了許多小盆栽。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"p16",
  "west" : __DIR__"p5",
]));
       set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
