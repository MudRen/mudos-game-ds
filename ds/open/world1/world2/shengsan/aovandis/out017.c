// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "郊區小路");
	set("long", @LONG
這裡的地勢平坦，有幾株棕梠樹種植在小路的兩旁，天空中的雲常常
做千變萬化的造型。這裡是奧凡迪斯的郊區，你到處走走就可以找到通往
奧凡迪斯的道路了。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out025",
	    "north": __DIR__"out014",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}