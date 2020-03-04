// Room: /open/world1/tmr/north_bar/town35.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－民房");
	set("long", @LONG
這間屋子十分簡陋老舊，連下雨時都會漏水，屋裡陣設也相
當雜亂，看樣子主人似乎沒有空整理，或是根本這就是間空屋。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"town34",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
