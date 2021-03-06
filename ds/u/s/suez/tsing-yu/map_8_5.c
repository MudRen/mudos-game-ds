// Room: /u/s/suez/tsing-yu/map_8_5.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
    一個小小的台子，幾個年輕的孩子，在這裡自彈自唱的演著不知名的
戲。沒有喧囂的鑼鼓聲，也沒有華麗的服裝，麵粉和泥土是他們臉上的妝
，農家常見的鋤頭竹竿是他們手上的道具，大人們多半視而不見的走過，
只有年紀更輕的小孩和一隻帶著小狗的母狗是它們的觀眾，在這廣場的一
隅，他們仍然揮灑著汗水，在這舞台上敘述著他們的話語，不論是否有人
欣賞，有人停留。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 6 */
  "southwest" : __DIR__"map_9_4",
  "north" : __DIR__"map_7_5",
  "east" : __DIR__"map_8_6",
  "northeast" : __DIR__"map_7_6",
]));

	setup();
	replace_program(ROOM);
}
