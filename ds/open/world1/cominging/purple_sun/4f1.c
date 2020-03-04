// Room: /open/world1/cominging/purple_sun/4f1.c

inherit ROOM;

void create()
{
	set("short", "紫陽山頂");
	set("long", @LONG
這裡是紫陽山的山頂上，這裡的空氣有點稀薄，令人有點呼吸困難
，在北邊有一塊小空地和山洞，空地上還有些似乎是野獸腳掌的痕跡，
不知道是什麼東西。
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"4f2.c",
  "south" : __DIR__"4fs",
  "down" : __DIR__"3f3.c",
]));
	set("no_clean_up", 0);
	set("world", "past");
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
