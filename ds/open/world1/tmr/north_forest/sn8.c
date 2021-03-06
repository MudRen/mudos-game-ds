// Room: /u/l/lestia/area/sn8.c

inherit ROOM;

void create()
{
	set("short", "北方大森林");
	set("long", @LONG
靜寂的森林裡並無任何異樣，但這出奇的寧靜反顯得不尋常，死寂的林
裡連風都停止了流動，不見任何人影及動物的蹤跡反顯得殺機重重，你已被
這沉重的氣氛壓迫的差點無法喘息，如今的你只想快步離去。
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("objects", ([ 
	__DIR__"npc/bear":2,
	__DIR__"npc/troll":2,
	]));

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sn9",
  "north" : __DIR__"sn7",
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
