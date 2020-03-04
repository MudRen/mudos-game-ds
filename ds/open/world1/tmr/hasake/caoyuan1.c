// Room: /open/world1/tmr/hasake/caoyuan1.c

inherit ROOM;

void create()
{
	set("short", "草原");
	set("long", @LONG
你走進了這遍綿綿不絕的大草原，腳下是寸厚的青草，軟綿綿的還真
不好走，看來買匹馬來代步到是的好主意。南邊和西邊都有好多帳篷，往
東可以看見沙漠的邊緣。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/sheep" : 2,
  __DIR__"npc/hasake" : 1,
]));
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"caoyuan",
  "east" : __DIR__"caoyuan2",
]));

	setup();
	replace_program(ROOM);
}
