// Room: /u/a/acme/area/street6.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
這裡是位於天城的北邊，這裡人潮洶湧，許多的遊客要一睹天湖的
奇景，道路的兩旁有許多攤子，還有當街賣藝的人，熱鬧非凡，往北可
到天池。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"pill",
  "south" : __DIR__"plaza4",
  "north" : __DIR__"pathway1",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/acrobat" : 1,
  __DIR__"npc/strongman_15" : 1,
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
