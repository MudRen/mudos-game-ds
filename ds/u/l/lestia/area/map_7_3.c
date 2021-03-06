// Room: /u/l/lestia/area/map_7_3.c

inherit ROOM;

void create()
{
	set("short", "靈幻教-中央大殿");
	set("long", @LONG

你正站在一個裝潢可與上朝皇宮比擬的大殿之上，地上鋪著紅紅的大地
毯，雖然這裡沒有皇宮中那般嚴肅的氣氛，但也有著一股令人肅穆的氣息，
大殿後方恭奉著一尊不知名的神像，雕得栩栩如生，彷彿像真人一樣，神像
下方的太師椅上坐著一位神情嚴謹的老人，看起來頗有威嚴，似乎他就是現
任靈幻教的教主吧，兩旁可以通往供教徒歇息的旁廳。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_7_4",
  "north" : __DIR__"map_6_3",
  "west" : __DIR__"map_7_2",
  "south" : __DIR__"map_8_3",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
