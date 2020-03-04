// Room: /u/a/aring/tomb/14.c

inherit ROOM;

void create()
{
	set("short", "大墓園－墳墓");
	set("long", @LONG
你正站在一座墳墓的上頭，墳墓中央有個大洞，洞裡面是一個空的
棺木，四周有許多像是抓痕的痕跡，越看越覺得發毛。
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"13.c",
  "south" : __DIR__"15.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
