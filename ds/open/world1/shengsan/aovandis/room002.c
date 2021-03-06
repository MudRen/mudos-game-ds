// 奧凡迪斯
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"寬廣的走道"NOR);
	set("long", @LONG
你在一個南北走向的寬廣走道上，走道兩旁的排水溝也是由美麗的琉
璃所砌成，排水溝蓋上的圖案是一次城裡舉辦兒童彩繪琉璃活動的參加作
品，這已經是奧凡迪斯的一大特色了，往北可到達城市的中心地帶。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	    "south": __DIR__"room023",
	    "north": __DIR__"room001",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}