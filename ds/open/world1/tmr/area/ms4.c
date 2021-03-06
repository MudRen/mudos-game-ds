// Room: /u/t/tmr/area/ms4.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set("long", @LONG
你正走在一條道路上，路的兩旁遍植了柳樹，一些村民正坐在樹蔭底
下暫避酷暑，有棵較大樹下放置著一個「奉水茶桶」，給路過的人飲用。
往東方過去就是孟村的農田，往西可到達村子裡。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"vroad1",
  "east" : __DIR__"ms2",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
