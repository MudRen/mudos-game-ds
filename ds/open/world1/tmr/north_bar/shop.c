// Room: /open/world1/tmr/north_bar/shop.c

inherit ROOM;

void create()
{
	set("short", "北蠻當舖");
	set("long", @LONG
這裡是一間當鋪，你可以看到門口的兩側立著塊竹牌，上題寫著
『公平交易，童叟無欺』八個金漆大字. 
LONG
	);
	set("no_clean_up", 0);
      set("objects", ([ __DIR__"npc/hu-mai":1, ]));
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"town18",
]));
	set("current_light", 1);
	set("light", 1);
	set("room_type", "shop");

	setup();
	replace_program(ROOM);
}
