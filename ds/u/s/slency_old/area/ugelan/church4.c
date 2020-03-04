// Room: /u/s/slency/area/ugelan/church4.c

inherit ROOM;

void create()
{
	set("short", "長型廣場");
	set("long", @LONG
這裡是教堂前一座巨大的廣場，一座古老的教堂便聳立在廣場中央
，你可以見到許多人正在教堂門口進進出出，這座教堂可以稱得上全幽
遮蘭帝國的心靈中心，幾乎所有的城民每當假日都會到此禮拜，也因此
廣場上總有大群人民來來往往，由此往東便是那做教堂，往西是一個廣
場。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"church3",
  "east" : __DIR__"god1",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
