// Room: /u/b/bennyng/area/room9.c

inherit ROOM;

void create()
{
	set("short", "雙魚宮後園");
	set("long", @LONG
這裡是雙魚宮的後園，四周佈滿美麗可人的玫瑰花，因為雙魚座聖鬥
士是一個愛玫瑰花的人．這裡種有各式各樣的玫瑰花，有黑有白有紅有黃
，非常燦爛，你不禁想採一朵來送給你的愛人．
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room10",
  "northup" : __DIR__"room8",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
