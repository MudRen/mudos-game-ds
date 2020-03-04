// Room: /u/d/darkfool/area1/4.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
這裡再往東一點便是街道的末端了，北邊是一家商店，賣些日常
用品。你從這裡遠遠地望去，街道的盡頭有塊不算小的空地，比較引
人注目的是那空地上豎立著一根約有兩個人高的圓柱體，圓柱上還有
個大紅點隱約在閃爍。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"c1",
  "north" : __DIR__"shop",
  "west" : __DIR__"3",
]));

	setup();
	replace_program(ROOM);
}
