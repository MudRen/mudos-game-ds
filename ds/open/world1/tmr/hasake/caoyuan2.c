// Room: /open/world1/tmr/hasake/caoyuan2.c

inherit ROOM;

void create()
{
	set("short", "草原");
	set("long", @LONG
你走進了這遍綿綿不絕的大草原，腳下是寸厚的青草，軟綿綿的還真
不好走，看來買匹馬來代步到是的好主意。北邊和西邊都有好多帳篷，往
東可以看見沙漠的邊緣。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"caoyuan1",
  "north" : __DIR__"caoyuan5",
  "south" : __DIR__"caoyuan9",
  "east" : __DIR__"caoyuan3",
]));

	setup();
	replace_program(ROOM);
}
