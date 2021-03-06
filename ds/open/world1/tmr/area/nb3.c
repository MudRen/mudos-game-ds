// Room: /u/t/tmr/area/nb3.c

inherit ROOM;

void create()
{
	set("short", "鶴子橋上");
	set("long", @LONG
你正走在一段離湖心不遠的橋上，往南走去可到達岸邊，往北細看，
可約略看見五座竹房立在湖心的一塊小島上，只是再往北過去，鶴子橋
端似乎沒有連接到房舍。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nb4",
  "south" : __DIR__"nb2",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
