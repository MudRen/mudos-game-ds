// Room: /open/world3/tmr/hunter_forest/forest1.c

inherit ROOM;

void create()
{
	set("short", "尼可骨森林入口");
	set("long", @LONG
你正站著尼可骨森林的入口，往北濃密深綠的一座森林，就是尼可骨
森林。這座森林為獵人公會的產物，以保有完整的自然生態而聞名，森林
常有不知名的動、植物，目前森林中只開放一小區，供作獵人試驗的場所
，其餘地方為獵人公會下令封閉，避免外界打擾。
LONG
	);
	set("world", "future");
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/open/world3/tmr/basic/digging_road6",
  "north" : __DIR__"forest2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
