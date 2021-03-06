// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "郊區小路");
	set("long", @LONG
郊區的小路總是不會比大路來得寬敞，兩旁有排水溝以及一些植物，
。這是以前平時農人所走的便道，不過現在已經建設成柏油路了，使得要
從這邊經過的車子比較好駕駛。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out034",
	    "west" : __DIR__"out032",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}