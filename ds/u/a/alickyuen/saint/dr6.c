// Room: /u/a/alickyuen/area/dr6.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Corridor");
	set("long", @LONG
沿著這條長廊向前走，就能進去找醫生診治。在這裡，你已經發覺有
一陣濃烈的藥味，可能是因為附近就是藥房的關係吧，還好是對身體沒有
害的。地上的磁磚清潔非常，避免了病人受到其他病毒感染。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dr7",
  "south" : __DIR__"dr5",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
