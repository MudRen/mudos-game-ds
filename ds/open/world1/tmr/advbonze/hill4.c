// Room: /open/world1/tmr/advbonze/hill4.c

inherit ROOM;

void create()
{
	set("short", "凌雲峰－叉路");
	set("long", @LONG
你正走在一條頗為崎嶇難走的山路，道路兩旁長滿了鮮花，林間
你正走在一條山路上，往北的道路分成二條小路，往東北方的山路路
口牌子上寫著：「往凌雲峰頂」，往西北方的道路的不遠處有間小寺
廟，遠遠望去，廟觀雖然破陋，但卻給你一種心靈平靜不少的感覺。
LONG
	);
	set("world", "past");
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"hill5",
  "northwest" : __DIR__"hill6.c",
  "south" : __DIR__"hill3.c",
]));

	setup();
	replace_program(ROOM);
}
