// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
這裡有一些的雜草，以及一些的碎石和枯木，還有一些廢棄的輪胎，
你發現北方有一條平坦的道路。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out009",
	    "south": __DIR__"out013",
	    "north": __DIR__"out004",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}