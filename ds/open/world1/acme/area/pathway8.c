// Room: /u/a/acme/area/pathway8.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
這裡是銜接著天山和黃沙陵之間的小路，一陣風吹來，揚起了一片黃
沙，沙子乘風飛舞向你捲襲而來，身上被黃沙割得隱隱作痛，口鼻卻也吸
進了不少的沙，令人作嘔。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"pass10",
  "southeast" : __DIR__"pathway9",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
