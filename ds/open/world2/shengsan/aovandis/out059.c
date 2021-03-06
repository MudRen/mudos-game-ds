// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "湖邊山麓");
	set("long", @LONG
這裡的地勢比平地來得高，往西看去是一片清澈的湖泊，幾塊石頭分
佈在地上，還有一些小草小樹也在這邊生長。天空中有幾朵白雲在其間做
百變的怪客，幾隻飛鳥也在其間快樂的飛翔。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out060",
	    "north": __DIR__"out055",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}