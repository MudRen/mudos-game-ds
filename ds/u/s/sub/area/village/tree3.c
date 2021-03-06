// Room: /u/s/sub/area/village/tree3.c

inherit ROOM;

void create()
{
	set("short", "樹枝上");
	set("long", @LONG
陣陣的強風迎面吹襲而來，讓人覺得在這裡站穩腳步也是一種奢求。
距離地面的高度更是使人感到頭暈目眩，如果不是腳下粗壯的樹枝讓人感
到無比的安心，恐怕沒幾個人敢走過這裡。往北邊走可以到光禿禿的峭壁
上，南邊可以到神木上面。
LONG
	);
	set("outdoors", "land");
	set("current_light", 3);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tree4",
  "south" : __DIR__"tree2",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
