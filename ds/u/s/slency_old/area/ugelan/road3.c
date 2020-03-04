// Room: /u/s/slency/area/ugelan/road3.c

inherit ROOM;

void create()
{
	set("short", "青石街道");
	set("long", @LONG
這是一條繁華的街道。往北邊一看有一個大大的招牌上寫著【防具
店】，很明顯的是一間專賣防具的商店，街道中央有一棵百年神木，樹
皮上的層層皺摺紀錄了歲月的痕跡，很多人舒服地在樹蔭下陳涼，一副
相當悠閒的樣子。
LONG
	);
	set("outdoors", "land");	
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road2",
  "east" : __DIR__"road17",
  "north" : __DIR__"defense",
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
