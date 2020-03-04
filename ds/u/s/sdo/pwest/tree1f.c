inherit ROOM;

void create()
{
	set("short", "樹洞內");
	set("long", @LONG
矮身進入樹洞內，發現這裡的空間遠大於之前的想像。這裡面可
以說是一間小木屋的大小了，而且看看周圍，好像是特地清出來的空
間。在牆邊還有一條樹藤編成的梯子，看來可以在往上爬。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"tree",
  "up" : __DIR__"tree2f",
]));

	setup();
	replace_program(ROOM);
}
