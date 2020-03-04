// Room: /u/s/superbug/train/2.c

inherit ROOM;

void create()
{
	set("short", "候車間");
	set("long", @LONG
這是一間給旅客等待火車的地方，擺放著許多張長條椅，可是卻空盪
盪的沒有幾個人，只有幾個流浪漢躺在椅子上睡覺，在佈告欄上似乎貼著
某些東西，牆角還有一台販賣機。
LONG
	);
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"1.c",
  "enter" : __DIR__"4.c",
]));
set("objects", ([
__DIR__"npc/seller1.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
