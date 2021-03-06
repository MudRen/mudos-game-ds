// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "郊區小路");
	set("long", @LONG
小路的兩旁各有一條排水溝，並且種植了幾株的棕梠樹排列在這邊，
小路是以前平時農人所走的便道，不過現在已經建設成柏油路了，以方便
車輛的來來往往。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out013",
	    "south": __DIR__"out017",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}