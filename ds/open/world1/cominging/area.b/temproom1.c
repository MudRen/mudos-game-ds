inherit ROOM;
void create()
{
	set("short", "黑色小房間");
	set("long", @LONG

一個不知名的房間，裡面充滿了不知名的氣息，令人有些覺得可怕
，往外是一條黑色的小路，這裡有一些人群往來，在這有一個小販在販
賣物品。
LONG
	);
	set("exits", ([
  "out"   : __DIR__"outroad4.c",
  "north" : __DIR__"temproom1.c",
]));
	set("objects",([
  __DIR__"npc/shopman.c": 1,
]));
	set("no_fight",1);
	set("no_cast",1);
	set("light",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
