// Room: /u/d/darkfool/area1/l3.c

inherit ROOM;

void create()
{
	set("short", "圖書館前");
	set("long", @LONG
在你面前聳立的這座建築物就是鎮上的圖書館了，造型古樸典雅
，頗有美感。比起冰冷的速成屋它的確更令人著迷，你不禁陷入沉思
，想像著建造者究竟是什麼模樣。推開臺階上的大門就可以進到裡面
去了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"l2",
]));

	setup();
	replace_program(ROOM);
}
