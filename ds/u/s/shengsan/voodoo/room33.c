
inherit ROOM;

void create()
{
	set("short", "後花園");
	set("long", @LONG
美麗的花朵在這個花園裡燦爛的綻放著，又有美麗的小昆蟲陪襯，你
覺得很特別。從這往北走是通往教壇的走廊。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
            "west" : __DIR__"room32",
	    "south": __DIR__"room31",
	    "north": __DIR__"room34",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
