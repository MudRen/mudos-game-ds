// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "道路");
	set("long", @LONG
這個由柏油鋪成的道路每兩到三年就要修路一次，可說是相當的堅實
。路旁有些小花小草在生長，往遠處看，可以看到幾間的民房聚集的地方
。這裡是奧凡迪斯的郊區。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "west" : __DIR__"out007",
	    "south": __DIR__"out011",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}