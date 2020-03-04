// Room: /u/a/acme/area/pill.c

inherit ROOM;

void create()
{
	set("short", "清心藥舖");
     set("light",1);
	set("long", @LONG
你一踏進這裡便覺藥氣撲鼻，在門邊有個招牌，上面寫著『清心』
二個大字，老舊的櫃檯後面陣列著一列藥櫃，藥櫃的每個抽屜按藥鋪的
規矩沒有任何的標籤，西面牆上正燒著檀香。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"street6",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/herbalist" : 1,
]));
set("room_type","sell");        //商店(只能買東西)
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
