// Room: /u/a/acme/area3/p6.c

inherit ROOM;

void create()
{
	set("short", "池邊小徑");
	set("long", @LONG
你正走在小池旁的小徑中，你可望見池中紅鯉悠閒的游著，池中荷花
滿開，荷葉上的青蛙不時的叫著「呱∼呱∼」，東邊有一座小拱橋。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"p7",
  "west" : __DIR__"p3",
]));
        set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
