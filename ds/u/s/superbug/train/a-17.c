// Room: /u/s/superbug/train/a-17.c

inherit ROOM;

void create()
{
	set("short", "平價旅館");
	set("long", @LONG
這裡是貧民區唯一的一間旅館，一踏進這裡你就被這裡惡劣的環境所
驚嚇，你粉懷疑怎麼會有人想住在這種像垃圾堆的旅館，這裡唯一的好處
似乎只有價格低廉而已。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"a-1.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
