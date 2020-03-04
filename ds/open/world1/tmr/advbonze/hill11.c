// Room: /open/world1/tmr/advbonze/hill11.c

inherit ROOM;

void create()
{
	set("short", "凌雲峰-上天梯");
	set("long", @LONG
山頂的一節一節天然石梯，你抬起了頭往山頂望了過去，似乎還
有一段不長的路得走，往東北的方向不遠處有塊小平地，似乎可
供上山的人小憩一下。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"hill12",
  "southdown" : __DIR__"hill10",
]));
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
