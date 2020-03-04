// Room: /u/s/superbug/train/a-6.c

inherit ROOM;

void create()
{
	set("short", "貧民區[東街]");
	set("long", @LONG
這裡是貧民區的東街，這裡仍充滿著令你感到嘔心的氣味，在你的南
方有一間不起眼的小屋，屋頂上豎立著一個小小的十字架，看來似乎是間
教堂，也許這是這裡唯一安靜的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"a-5.c",
  "south" : __DIR__"a-22.c",
  "east" : __DIR__"a-7.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
