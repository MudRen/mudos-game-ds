// 奧凡迪斯
// LV 1~50
#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"奧凡迪斯市中心"NOR);
	set("long", @LONG
這裡是奧凡迪斯的中心地帶，你看到四周的牆上都是精美的雕飾所刻
劃，壯碩的石柱就在廣場的四周屹立著，每一個石柱就有如通了天那樣的
高大，這似乎象徵著某種的意義。你在這裡感覺到城市的偉大及壯麗....
從這往北直直走去可以看到金碧輝煌的巨大建築物，東西方各為城市的東
西側門，直直往南走即可到達這座城市的正門了。

     往下走是 [Magic-Card]的專賣店 －星空彩繪。

LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room010",
	    "west" : __DIR__"room017",
	    "south": __DIR__"room002",
	    "north": __DIR__"room042",
      "down" : WD_NOW+"magic-card/room1",
            ]));
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/lamuza" : 1,
        ]));
	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
