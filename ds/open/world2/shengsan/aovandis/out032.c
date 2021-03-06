// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "郊區小路");
	set("long", @LONG
這裡是奧凡迪斯的郊區小路，這是以前平時農人所走的便道，不過現
在已經建設成柏油路了，以方便車輛的來來往往。有幾株棕梠樹種植在小
路的兩旁，天空中的雲常常做千變萬化的造型。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out033",
	    "west" : __DIR__"out031",
	    "north": __DIR__"out025",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}