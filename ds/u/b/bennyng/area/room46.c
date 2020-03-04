// Room: /u/b/bennyng/area/room46.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
這裡是山羊官和射手宮的交匯處，四處荒蕪一片，兩邊長滿雜草．
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"room47",
  "westup" : __DIR__"room45",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
