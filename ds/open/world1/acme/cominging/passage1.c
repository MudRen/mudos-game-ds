// Room: /u/a/acme/area/passage1.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
這是大門外的長廊，橫貫東西向，長廊旁擺放了二排盆栽，作為
裝飾，牆上還掛了幾幅名家畫作，給人一種舒服的感覺。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"passage2",
  "west" : __DIR__"room1",
  "south" : __DIR__"door1",
]));
	set("no_clean_up", 0);
        set("light",1);

	setup();
	replace_program(ROOM);
}
