// Room: /u/t/truewind/Minetown/area/minetown9.c

inherit ROOM;

void create()
{
	set("short", "礦村中");
	set("long", @LONG
這是一條小小的窄巷子，角落生長了許多的花草。藤蔓也爬滿了
四周的牆壁。向南繼續走是通往礦村長住家的唯一的路。礦村裡經常
刮起的砂風在這裡幾乎感覺不到，莫名的平靜流過上空的雲層。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"minetown8",
  "south" : __DIR__"leaderroom",
]));

	setup();
	replace_program(ROOM);
}
