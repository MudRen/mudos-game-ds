// Room: /u/a/acme/area/pathway4.c

inherit ROOM;
void create()
{
	set("short", "小徑");
	set("long", @LONG
這裡是一條小徑，因長久人湮罕至，雜草叢生，不時還聽到野狗的吠
叫聲，小徑往東邊延伸而去。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" : __DIR__"pathway5",
     "northwest" : __DIR__"pathway",
    ]));
        set("no_clean_up", 0);
      set("outdoors","land");
      setup();
      replace_program(ROOM);
}   
