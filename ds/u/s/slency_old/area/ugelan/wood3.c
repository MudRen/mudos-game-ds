// Room: /u/s/slency/area/ugelan/wood3.c

inherit ROOM;

void create()
{
	set("short", "森林暗處");
	set("long", @LONG
你愈往裡面走，樹木愈是高大濃密，你不時可以看到一些動物的屍
骨殘骸，不可否認的是這裡一定有一些毒禽猛獸之屬，只不過在這寧靜
異常的森林裡，實在很難相信會出現什麼猛獸。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"wood4",
  "north" : __DIR__"wood2",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
       	setup();
	replace_program(ROOM);
}
