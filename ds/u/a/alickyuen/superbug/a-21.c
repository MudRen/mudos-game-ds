// Room: /u/s/superbug/train/a-21.c

inherit ROOM;

void create()
{
	set("short", "末日武器店");
	set("long", @LONG
這裡是一間武器店，牆上掛著各式各樣的武器，令你感到一陣眼花撩
亂，聽說這裡專賣些市面上買不到的武器，也許你可以找到一些強力的武
器，櫃檯前坐著一個賊頭賊腦的男子，似乎是這的老闆。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"a-14.c",
]));
set("objects", ([
__DIR__"npc/seller5.c" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
