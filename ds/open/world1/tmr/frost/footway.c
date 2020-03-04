// Room: /open/world1/tmr/frost/footway.c

inherit ROOM;

void create()
{
	set("short", "棧道");
	set("long", @LONG
這是一條久經失修的棧道，延著峰腰而築，往西的道路隱沒在一片綠
林，可通往凌雲峰的上山小徑，往東順著棧道而行，可到達和凌雲峰相並
的另一座山峰。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/world1/tmr/advbonze/hill7",
  "east" : __DIR__"footway2",
]));
	set("current_light", 2);
	set("no_clean_up", 0);
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
