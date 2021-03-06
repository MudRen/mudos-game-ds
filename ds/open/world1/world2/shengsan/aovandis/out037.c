// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
這裡有一些高大的樹木在這邊分佈，樹上的松鼠不時的在林間跳躍飛
翔，活潑的蝴蝶也在這邊聚集，因為地上長滿了鮮豔美麗的花朵。你可以
看到東西向有人走過的痕跡。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out038",
	    "west" : __DIR__"out036",
	    "south": __DIR__"out041",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}
