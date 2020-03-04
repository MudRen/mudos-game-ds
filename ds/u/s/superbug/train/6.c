// Room: /u/s/superbug/train/6.c

inherit ROOM;

void create()
{
	set("short", "男廁所");
	set("long", @LONG
這裡是一間男廁所，一踏進這裡你就聞到一股臭味，從滿地垃圾看來
，已有一陣子沒人來清掃了，牆上的玻璃也碎落在地上，你得小心翼翼的
以免踩到，你只想趕快離開這裡。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"4.c",
]));
        set("world", "future");
        set("light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
