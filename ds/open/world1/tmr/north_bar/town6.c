// Room: /open/world1/tmr/north_bar/town6.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－街道");
	set("long", @LONG
只見這兒有條長長的人龍，正排在古井前面等著汲水。因
為這裡是偏於較寒冷乾燥的地區，取水相當不容易，村裡的村
民就靠這全村唯一的井生活，顯少會離開村莊取水。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"town5",
  "east" : __DIR__"town13",
  "north" : __DIR__"town7",
  "west" : __DIR__"town12",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
