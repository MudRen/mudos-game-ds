// Room: /u/s/suez/tsing-yu/map_7_5.c

inherit ROOM;

void create()
{
	set("short", "廣場西");
	set("long", @LONG
    這裡的西方是一條筆直的大街，你可以看見許多背著行囊的旅人以及
打扮寬鬆自在的客人。幾個挑夫坐在附近等人僱用，載貨的驢車緩緩而行
，清爽的風沿著西大道吹了過來，夾帶著些許湖泊的味道。小吃店中傳來
陣陣的香味令人不禁食指大動，一旁傳來吃吃的笑聲，幾個打扮時髦的遊
女似乎對你這外地來的旅客充滿好奇，玉石清脆的碰撞聲隨著柳枝擺盪，
一曲笛音也隨之高亢。

LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 6 */
  "east" : __DIR__"map_7_6",
  "north" : __DIR__"map_6_5",
  "west" : __DIR__"map_7_4",
  "southeast" : __DIR__"map_8_6",
  "south" : __DIR__"map_8_5",
  "northeast" : __DIR__"map_6_6",
]));

	setup();
	replace_program(ROOM);
}
