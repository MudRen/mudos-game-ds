// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "青石街道");
	set("long", @LONG
一條人來人往的街道，附近的房舍大多門戶緊閉，此地並沒有什麼
商店，路面上有著明顯的溝痕，看來是來往頻繁的馬車所造成的，往北
不遠處便到護城河畔了，往南是一條大街。
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road15",
  "south" : __DIR__"road7",
]));
 	set("outdoors", "land");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
