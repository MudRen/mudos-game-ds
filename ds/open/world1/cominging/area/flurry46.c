inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
這裡是一塊很乾淨的走廊，走廊上有許多的很淺的足跡，並不怎麼
明顯，走廊直走到底就是疾風門的主要走廊，你看到北邊有一間間房舍
，似乎比剛剛的房子還要好多了。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"flurry48.c",
  "southdown" : __DIR__"flurry44.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
