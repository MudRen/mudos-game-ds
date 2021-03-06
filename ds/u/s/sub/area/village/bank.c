// Room: /u/s/sub/area/village/bank.c

inherit ROOM;

void create()
{
	set("short", "豪宅");
	set("long", @LONG
這裡是地方上的有力人士─言輕飆─的住家，裝潢相當的華麗。但是
隱隱約約卻又有一股俗氣，顯示出這裡的主人非常的沒有格調。不過由於
他有非常完善的保全設施，所以地方上的人都樂於將金錢交由他來保管。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"vi07",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/village_banker_20" : 1,
]));
	set("room_type", "bank");
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
