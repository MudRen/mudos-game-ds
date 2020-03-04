inherit ROOM;

void create()
{
	set("short", "左使之房");
	set("long", @LONG
這裡是疾風門左使的專門房間，你一進到這裡就感覺到有些冷氣襲
來，大概是因為這裡四周的窗戶都是打開的，而且很少關過，不過難道
不怕小偷嗎？疾風門的左使游機子就是住在這個房間，似乎現在不太快
樂的樣子，東邊是主要的走道，走道上打掃的一塵不染。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"flurry48.c",
]));
	set("light",1);
	set("objects",([
  __DIR__"npc/left-escort.c":1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
