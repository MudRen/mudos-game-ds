// Room: /open/world1/tmr/area/wa2.c

inherit ROOM;

void create()
{
	set("short", "朝天湖－水裡");
	set("long", @LONG
你正在朝天湖裡，只見四週儘是青藍一片，可清晰看到不少的生物，
湖裡景色倒也不輸陸地；只是周圍景色大都一致，實不知東南西北各是通
向何方。
LONG
	);
	set("world", "past");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/fish" : 4,
  __DIR__"npc/bfish" : 1,
]));
	set("light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wa3",
  "north" : __DIR__"wa1",
  "eastup" : __DIR__"wa4",
  "east" : __DIR__"wa6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
