
inherit ROOM;

void create()
{
	set("short", "東側走廊");
	set("long", @LONG
兩旁是桐紅色的牆壁，陽光從壁上的窗戶映射進些微的光芒，照在牆
壁旁的盆栽格外的耀眼。你聞到了一些香噴噴的香味。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"room12",
	    "north" : __DIR__"room14",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
