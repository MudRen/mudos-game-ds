inherit ROOM;

void create()
{
	set("short", "民房");
	set("long", @LONG
從牆上掛的獵弓和獸皮，很明顯這裡是一個獵戶人家。牆上還有
著不少的動物標本，一一細看，不但有公鹿頭、豹皮，竟然連熊的頭
部標本都有，可以想見這位獵人的技術精湛，可是獵弓怎麼看起來好
像有一段時間都沒有人使用的感覺。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  		"south" : __DIR__"burg4",
	]));
	set("objects",([
		__DIR__"npc/leion.c":1,
	]));

	setup();
	replace_program(ROOM);
}
