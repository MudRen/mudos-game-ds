// Room: /open/world1/moonhide/area/hotel_up.c

inherit ROOM;

void create()
{
	set("short", "寒冰客棧二樓");
	set("long", @LONG
這裡是寒冰客棧的2樓，有幾張桌子坐滿了客人，正在喝酒
吃肉，不時交談最近的江湖趣聞，好不熱鬧。
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"hotel",
]));
	set("no_clean_up", 0);
    set("objects", ([ /* sizeof() == 2 */
  "/open/world1/tmr/advthief/thief_adv_master" : 1,
]));


	setup();
	replace_program(ROOM);
}
