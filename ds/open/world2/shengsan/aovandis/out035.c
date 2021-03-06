// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
從西方傳來一陣陣呼嘯而過的的汽車聲音，看來往西走就是通往奧凡
迪斯的道路。這裡是奧凡迪斯的郊區，沒有什麼特別的地方。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out034",
	    "south": __DIR__"out040",
	    "north": __DIR__"out027",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}