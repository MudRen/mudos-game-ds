// Room: /u/s/slency/area/ugelan/wood6.c

inherit ROOM;

void create()
{
	set("short", "森林深處");
	set("long", @LONG
這裡是森林中難得一見的一片廣場，樹木圍繞著這個廣場成一個圓
形，廣場上有一些兵器散落在地上，你開始覺得這裡有些不大對勁了，
隱約地你可以感覺到樹林裡有一些眼睛正注視著你
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wood7",
  "east" : __DIR__"wood5",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
