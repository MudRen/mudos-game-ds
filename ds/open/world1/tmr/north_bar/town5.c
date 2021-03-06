// Room: /open/world1/tmr/north_bar/town5.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－街道");
	set("long", @LONG
在這裡可以聽到遠方傳來的叫賣聲，應該是這附近的商店或
攤販吧。不過，這裡的空氣實在太乾燥了，讓你忍不住開始覺得
口渴，只見前面有一口大井。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"town4",
  "east" : __DIR__"town11",
  "north" : __DIR__"town6",
  "west" : __DIR__"town10",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
