inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
這是一個監獄的密道，不知何人所挖，也不知通往何處，但似乎
只挖到一半就沒再繼續挖下去了，除了過來之處外，就沒有其它的通
路了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"injail",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
