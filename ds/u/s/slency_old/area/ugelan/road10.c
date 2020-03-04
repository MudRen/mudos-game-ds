// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "青石街道");
	set("long", @LONG
這裡是一條由青石所鋪成的街道，除了來來往往的人群，並沒有什
麼特別的，牆角上有個小洞不停地流出水來，有很多的流浪動物在那裡
喝水解渴。
LONG);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road9",
  "north" : __DIR__"road11",
]));
	set("item_desc",([
	"小洞" : "一個牆角泥磚碎裂所造成的小洞, 洞裡不斷流出水來。\n" ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
