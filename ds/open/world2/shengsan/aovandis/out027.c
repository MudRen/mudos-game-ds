// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
這裡是奧凡迪斯的郊區，就在道路的旁邊，如果要去奧凡迪斯，那麼
往北走就可以看到通往奧凡迪斯的重要商業道路了。這裡只有一些矮小的
植物，及一些碎石而已，並沒有什麼比較特別的地方。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out028",
	    "south": __DIR__"out035",
	    "north": __DIR__"out019",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}