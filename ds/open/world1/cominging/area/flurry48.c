inherit ROOM;

void create()
{
	set("short", "主走廊");
	set("long", @LONG
這裡是疾風門之中最主要的走廊，在這裡有許多的房間，而各個房
間都是疾風門之中聲望極高的人，尤其是在你面前的掌門之房和左右邊
的護使的房間，這裡的地板很乾淨，似乎經常清洗。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"flurry46.c",
  "north" : __DIR__"flurry50.c",
  "west" : __DIR__"flurry47.c",
  "east" : __DIR__"flurry49.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
