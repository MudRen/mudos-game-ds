// Room: /u/a/acme/area3/p16.c

inherit ROOM;

void create()
{
	set("short", "長廊");
	set("long", @LONG
這是一條橫貫東西的長廊，長廊邊擺放了許多小盆栽，北邊是個廚房
，傳來陣陣的香味，往西可通往庭院。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"p17",
  "west" : __DIR__"p12",
]));
       set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
