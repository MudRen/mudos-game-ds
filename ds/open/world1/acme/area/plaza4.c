// Room: /u/a/acme/area/plaza4.c

inherit ROOM;

void create()
{
	set("short", "廣場");
	set("long", @LONG
這裡是天城的廣場北邊，這裡人潮洶湧，許多的遊客要一睹天池的
奇景，道路的兩旁有許多攤子，還有當街賣藝的人，熱鬧非凡，往北可
到天池。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"street6",
  "south" : __DIR__"plaza1",
]));
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
	replace_program(ROOM);
}
