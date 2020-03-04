// Room: /u/a/acme/area/pass5.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
這是一條上山的小徑，地上到處可見片片枯黃的落葉，四周生長了高
大的樹，濃蔭參天，高聳入雲，隱天蔽日，蔚為奇觀。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"pass4",
  "westdown" : __DIR__"pass6",
  "northwest" : __DIR__"f1",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
