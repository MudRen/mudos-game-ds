
inherit ROOM;

void create()
{
	set("short", "後花園");
	set("long", @LONG
你發現這裡有個假山，假山上還有細細的流水流出，你感到相當的特
別，花朵在陽光的照耀下，顯得格外的光鮮動人。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room33",
	    "south": __DIR__"room30",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
