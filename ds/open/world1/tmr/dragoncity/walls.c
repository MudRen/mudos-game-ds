// Room: /open/world1/dragoncity/walln1.c

inherit ROOM;

void create()
{
	set("short", "南城頭");
	set("long", @LONG
這裡是磐龍城的南城頭。一些少帥軍子弟兵正在城頭巡邏，
一個牙將正在這兒負責接受各種守城材料，一些弓箭手正撚弓
搭箭緊盯著城下的動靜。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "down" : __DIR__"walls1",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 2);
	set("objects", ([
		__DIR__"npc/guard2" : 1,
		]));
	setup();
	replace_program(ROOM);
}
