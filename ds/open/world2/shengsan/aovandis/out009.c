// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
這裡雜草叢生，並沒有做什麼開發，你看到有一個一個大大的石塊，
還有一些廢棄的輪胎。你發現這裡並不適合行走。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"out010",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}