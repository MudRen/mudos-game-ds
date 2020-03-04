// Room: /open/world1/tmr/north_bar/f3.c

inherit ROOM;

void create()
{
	set("short", "千年古洞-洞穴");
	set("long", @LONG
這裡的地上十分凹凸不平，而且又十分狹窄，地上全是泥土
旁邊都是鐘乳石。前面的路好像有野獸活動的足跡，看著地上的
腳印，讓你猜不到到底是什麼怪物...
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"f4",
  "northwest" : __DIR__"f1",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
