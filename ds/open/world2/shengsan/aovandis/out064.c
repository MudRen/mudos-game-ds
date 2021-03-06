// 奧凡迪斯郊區
// LV 1~50
#include <path.h>
inherit ROOM;

void create()
{
	set("short", "荒涼的草地");
	set("long", @LONG
這裡雜草叢生，並沒有做什麼開發，你的西邊有一大片茂盛的樹
林。看起來似乎是個很原始的森林，單獨進入可能會有點危險。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "east" : LUKY_NOW"area_1/room11",
	    "west" : __DIR__"out063",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}