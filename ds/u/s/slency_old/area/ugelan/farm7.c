// Room: /u/s/slency/area/ugelan/farm7.c

inherit ROOM;

void create()
{
	set("short", "小茅屋");
	set("long", @LONG
這間茅屋的牆上及牆邊掛滿了很多的農耕工具，一看就知道是這裡
莊農們的住所，裡面樸素的生活用品，令人感覺到鄉村的樸實氣息。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"farm6",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
