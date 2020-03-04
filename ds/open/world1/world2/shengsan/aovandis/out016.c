// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "奧凡迪斯郊區");
	set("long", @LONG
這裡到處都是平鋪在地上的石子，以及廢棄在一旁的輪胎，只有幾株
鬼針草生長在石子堆中，不過這裡並不會太悶熱，不時間也會有青青的微
風吹過你的身旁。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out024",
	    "north": __DIR__"out013",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
	replace_program(ROOM);
}