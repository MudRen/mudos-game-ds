// Room: /open/world1/faceoff/sky/ten18.c

inherit ROOM;

void create()
{
	set("short", "村道");
	set("long", @LONG
你走在位於廣場西北角的道路上，這條道路似乎通往你東方的一座茅
屋，這座茅屋不同於一般，顯得特別的精緻，也許是因為住在裡面的人身分
不同於一般？另外這條道路往西北方接到一座龐大的森林，也就是赫赫有名
的「北方大森林」。傳說裡面住著食人肉的巨魔，還有精通黑暗幻術的靈幻
宗一派。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"ten17",
  "northwest" : "/open/world1/tmr/north_forest/sn20",
  "east" : __DIR__"ten19",
]));
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
