// Room: /u/s/slency/area/ugelan/road2.c

inherit ROOM;

void create()
{
	set("short", "青石街道");
	set("long", @LONG
這是一條繁華的街道。附近有一間武器店，遠遠地看到招牌上面寫
著【武器店】，看來是賣一些防身武器的商店，身為時空旅行者的
你，有一把劍或一些防身的武器想來是絕對必要的，往北便是那家武器
店。
LONG
	);
        set("outdoors", "land");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road1",
  "east" : __DIR__"road3",
  "north" : __DIR__"weapon",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
