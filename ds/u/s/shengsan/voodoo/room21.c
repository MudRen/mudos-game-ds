
inherit ROOM;

void create()
{
	set("short", "西側走廊");
	set("long", @LONG
這是東側走廊，你看到北邊有一個住人的房間，而東邊是一座花園，
如果往西邊的走廊走去可以到巫毒教的前廳。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room30",
	    "west" : __DIR__"room20",
	    "north": __DIR__"room29",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
