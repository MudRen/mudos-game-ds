// Room: /u/b/bennyng/area/room45.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
這裡是山羊官和射手宮的交匯處，四處荒蕪一片，兩邊長滿雜草．
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"room46",
  "northup" : __DIR__"room44",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
