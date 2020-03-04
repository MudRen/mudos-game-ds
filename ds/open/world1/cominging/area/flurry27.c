inherit ROOM;

void create()
{
	set("short", "走道交接口");
	set("long", @LONG
這裡是走道的互相交接口，走廊上有些人走來走去，旁邊屋子裡也
陣陣的發出一些移動東西的聲音，令人感覺有些吵，東邊就是走廊的十
字口，也是莊中來往必經之路。
LONG
	);
	set("exits", ([
  "west" : __DIR__"flurry26.c",
  "east" : __DIR__"flurry28.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
