// Room: /u/t/tmr/area/wa6.c

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
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wa2",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/snake" : 1,
  __DIR__"npc/fish" : 3,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
