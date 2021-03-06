// Room: /open/world1/tmr/xiangyang/guangchang.c

inherit ROOM;

void create()
{
	set("short", "中央廣場");
	set("long", @LONG
這裡是襄陽的中央廣場，鋪著青石地面。東面通向青龍門，
西面通向白虎門，南面直達朱雀門，遠遠地你可看到北面是襄
陽安撫使衙門。近年來蒙古大軍屢次攻打襄陽，官府為防止蒙
古奸細混雜進來，已經不允許人們在此聚集。只見一隊官兵在
此往來巡邏，你還是快離開吧。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/pian" : 1,
  __DIR__"npc/bing" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"westjie1_e2",
  "east" : __DIR__"eastjie1_w1",
  "south" : __DIR__"southjie1",
  "north" : __DIR__"anfupailou",
]));
	set("current_light", 2);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");
	set("item_desc", ([ /* sizeof() == 1 */
  "dong" : "
",
]));

	setup();
	replace_program(ROOM);
}
