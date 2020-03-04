inherit ROOM;

void create()
{
	set("short", "樓梯");
	set("long", @LONG
這是一個小小的樓梯，你遠遠看到南方有一個大門，疾風門的莊內
，通往主走道都需經過這一條，而這一個樓梯卻出乎意料之外的很乾淨
，你突然看見幾個傭人在打掃才恍然大悟。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"flurry28.c",
  "northdown" : __DIR__"flurry34.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
