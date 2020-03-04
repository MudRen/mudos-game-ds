// Room: /u/s/sonicct/area/road9.c

inherit ROOM;

void create()
{
	set("short", "Naboo城街道");
	set("long", @LONG
這是連接大森林的道路，由於這裡比較接近森林，所以你有
一種清新自然的感覺。往西可以通往Naboo廣場。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"gate3",
  "west" : __DIR__"road8",
]));
	set("outdoors","road");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
