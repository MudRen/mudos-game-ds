// Room: /open/world1/tmr/wujian/snake-room6d.c

inherit ROOM;

void create()
{
	set("short", "無間小道");
	set("long", @LONG
霧茫茫的一片，在此黑暗的洞穴內，似乎有種極為恐怖的生物，
沙沙的聲響不斷的發出。你注意到這邊的霧氣更濃，還帶著嘔心的血
腥味，沉重的寂靜聲中，越加凸顯出你內心的恐懼。
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"jian3",
  "east" : __DIR__"jian1",
  "up" : "/open/world1/moonhide/area/snake-room6",
  "west" : __DIR__"jian2",
  "south" : __DIR__"room1",
]));
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
