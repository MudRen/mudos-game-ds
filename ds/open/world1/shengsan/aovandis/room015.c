// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"迪斯大道"NOR);
	set("long", @LONG
你在奧凡迪斯的迪斯大道上，走道兩旁的排水溝也是由美麗的琉璃所
砌成，排水溝蓋上的圖案是一次城裡舉辦兒童彩繪琉璃活動的參加作品，
這已經是奧凡迪斯的一大特色了這條大道是位於城裡的東半邊，往東直走
就是東城門了，往南邊就是守衛室了。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
            "east" : __DIR__"room016",
	    "west" : __DIR__"room014",
	    "south": __DIR__"room035",
            ]));

	set("light", 1);

	setup();
	replace_program(ROOM);
}