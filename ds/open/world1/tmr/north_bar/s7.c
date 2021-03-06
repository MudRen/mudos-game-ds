// Room: /open/world1/tmr/north_bar/s7.c

inherit ROOM;

void create()
{
	set("short", "千年古洞-地下二層");
	set("long", @LONG
這裡的地板比較不會濕滑了，但是相反的地面卻震動得更厲
害了。前面可以看到一個用石磚建造而成的小房間，不知道裡面
有什麼奇特的東西，或者是又有更危險的野獸？
LONG
	);
	set("objects", ([
	  __DIR__"npc/anthropophagi-monster" : 2,
	  __DIR__"npc/horn-monster" : 2,
//	  __DIR__"npc/predator-monster" : 1,
//	  __DIR__"npc/rough-monster" : 1,
//	  __DIR__"npc/single-monster" : 1,
 ]));

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s6",
  "east" : __DIR__"s17",
  "north" : __DIR__"s18",
  "west" : __DIR__"s16",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
