// Room: /u/a/acme/area3/p14.c

inherit ROOM;

void create()
{
	set("short", "長廊");
	set("long", @LONG
這是一條橫貫東西的長廊，長廊邊擺放了許多小盆栽，南邊是間馬房
，往東則可通往庭院。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"p13",
  "south" : __DIR__"p15",
]));
       set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
