// Room: /open/world1/tmr/bagi/ghat3.c

inherit ROOM;

void create()
{
	set("short", "山道叉口");
	set("long", @LONG
你正處在一處山道叉口，山道往東北、西北分了二條路，路口處矗立
了一塊至腰身的青石碑，附近積雪綿綿無盡的樣子，望著這一片白茫茫的
雪地，心中起了蕭瑟的感覺。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "石碑" : "你撥開了石碑上頭的積雪，出現了一行字：「東通冷月，西往寒日。」
",
]));
	set("outdoors", "snow");
	set("current_light", 1);
	set("no_clean_up", 0);
	set("world", "past");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"ghat2",
  "northwest" : __DIR__"ghat5",
  "northeast" : __DIR__"ghat4",
]));

	setup();
	replace_program(ROOM);
}
