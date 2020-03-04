// Room: /u/s/slency/area/ugelan/farm3.c

inherit ROOM;

void create()
{
	set("short", "幽遮蘭城外的莊園");
	set("long", "這裡是幽遮蘭城外較偏遠的莊園，你發現這裡的土壤似乎太過乾燥\n"", 也因為並沒有多少莊農在此耕種，這裡不管往哪兒看都是一片大平原\n""，沒有任何丘陵或高山的屏障，假如其他族群從此處進進入幽遮蘭城，\n""只怕將是一場浩劫。\n"
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"farm6",
  "east" : __DIR__"farm1",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
