// Room: /u/a/alickyuen/area/dr31.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Workroom");
	set("long", @LONG
這裡就是人稱「地獄女色狼」護士長的房間，看著面前這個胖胖的女
人，和她臉上的表情，都不難發現這個稱號的由來。這裡牆上面都掛著一
些「狼」裝飾，看些去就和這個護士長一樣，看來還是早些跑掉比較好…
…
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"dr28",
]));
set("objects", ([
__DIR__"npc/nurseleader.c" : 1,
]));
	set("world", "future");
set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
