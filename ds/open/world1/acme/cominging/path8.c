inherit ROOM;

void create()
{
	set("short", "走道");
	set("long", @LONG
你正走在走道上，在這邊有許許多多的人群，似乎是有些的事情，
東邊是改名字的好所在，戶政房，在那有一個廉潔的戶政官在執勤。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"house5",
  "west" : __DIR__"path2",
  "north" : __DIR__"path7",
  "south" : __DIR__"path9",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
