// Room: /u/l/lestia/area/sn15.c

inherit ROOM;

void create()
{
	set("short", "北方大森林-小徑");
	set("long", @LONG
一團團的白霧向你迎面而來，你彷彿陷身在迷霧之中，低頭往下看不到
自己的腳，抬頭向上看不到天空上的白雲，你似乎已經和外面的世界脫離了
，只沉迷在這片茫茫的白霧之中，不知所措的亂走亂撞，想走出這個讓你害
怕的地方。
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"sn16",
  "west" : __DIR__"sn14",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
