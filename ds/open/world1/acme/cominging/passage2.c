inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
這是大門外的長廊，橫貫東西向，長廊旁擺放了二排盆栽，作為
裝飾，北邊矗立著衙門的大門，十分的威嚴、莊重。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"passage3",
  "west" : __DIR__"passage1",
  "north" : __DIR__"bigdoor",
]));
        set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
