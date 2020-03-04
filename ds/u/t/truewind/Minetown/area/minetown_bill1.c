// Room: /u/t/truewind/Minetown/area/minetown_bill1.c

inherit ROOM;

void create()
{
	set("short", "二樓房間");
	set("long", @LONG
本來是比爾住的地方，有時候也充當客房，但是自從比爾在礦區
賺到不少利潤買了新屋以後，這裡就變成廢物儲藏室了，到處都是蜘
蛛跟灰塵，但是你注意到角落的一個衣櫥好像曾被人搬動過的痕跡..
.。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"minetown_bill",
]));

	setup();
	replace_program(ROOM);
}
