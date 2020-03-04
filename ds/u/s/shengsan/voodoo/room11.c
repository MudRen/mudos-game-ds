
inherit ROOM;

void create()
{
	set("short", "東側走廊");
	set("long", @LONG
你看到兩旁的牆壁粉刷上桐紅色系的塗料，沿著走廊的兩側，每隔一
段距離就有一個盆栽放著，在這進出的人並不會很多。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room12",
	    "west" : __DIR__"room10",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
