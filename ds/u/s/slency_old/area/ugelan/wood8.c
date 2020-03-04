// Room: /u/s/slency/area/ugelan/wood8.c

inherit ROOM;

void create()
{
	set("short", "林間小徑");
	set("long", @LONG
這裡是森林間的羊腸小徑，感覺十分清涼，不時有微風吹來，你覺
得好像進了仙境一般的舒服，蟬聲鳴鳴，實在是一個世外桃園啊。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"wood2",
  "north" : __DIR__"wood9",
]));
	set("outdoors", "forest");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
