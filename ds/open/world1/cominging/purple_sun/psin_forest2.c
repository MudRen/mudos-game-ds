// 紫陽山第一層

inherit ROOM;

void create()
{
	set("short", "紫陽山下森林");
	set("long", @LONG
這裡是紫陽山下的一座小森林，森林附近並沒有什麼很明顯的東西
，北邊是往山壁的地方走，不過好像不能再走過去的樣子，往南邊是森
林的小路。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"psin_forest1.c",
  "south" : __DIR__"psin2.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}