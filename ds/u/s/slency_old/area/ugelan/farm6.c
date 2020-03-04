// Room: /u/s/slency/area/ugelan/farm6.c

inherit ROOM;

void create()
{
	set("short", "城牆外");
	set("long", @LONG
走到這裡，你可以很清楚的看到整座豎立在丘陵上的幽遮蘭城堡，
看著高聳的堡塔，你不禁驚嘆如此的鬼斧神工，由此往西有一間小茅屋
，看來是附近的莊農所居住的地方。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"farm7",
  "south" : __DIR__"farm3",
  "east" : __DIR__"farm5",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
