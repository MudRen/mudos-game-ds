// Room: /open/world1/acme/bonze/b12.c

inherit ROOM;

void create()
{
	set("short", "凌雲寺");
	set("long", @LONG
你抬頭一望，上面有一塊木匾，上面寫著「凌雲寺」三個大字，
筆走龍蛇，蒼勁有力，寺門前有兩隻石獅子，一左一右蹲在寺院的兩
旁，虎虎生風，令人望而卻步。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"b13",
  "southwest" : __DIR__"b11",
]));
        set("light",1);

	setup();
	replace_program(ROOM);
}
