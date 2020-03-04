// Room: /u/a/acme/area3/p5.c

inherit ROOM;

void create()
{
	set("short", "長廊");
	set("long", @LONG
這是一條橫貫東西的長廊，長廊邊擺放了許多小盆栽，在北邊是間大
廳，往南則通往庭院。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"p12.c",
  "north" : __DIR__"p10",
  "west" : __DIR__"p13.c",
  "south" : __DIR__"p4",
]));
       set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
