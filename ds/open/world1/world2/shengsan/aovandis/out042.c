// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
密集高大的樹木生長在這裡，陽光只能從樹葉與樹葉之間穿過，一條
一條細細長長的光線射到地上好不美麗阿。地上的枯葉也很多，偶而你會
聽到昆蟲或動物經過枯葉沙沙的聲音。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out043",
	    "west" : __DIR__"out041",
	    "north": __DIR__"out038",
            ]));

	set("outdoors","forest");	// 樹林
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}