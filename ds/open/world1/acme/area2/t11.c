// Room: /u/a/acme/area2/t11.c

inherit ROOM;

void create()
{
	set("short", "幽冥地窖[地下二層]");
	set("long", @LONG
@你正行走在這深不見低的黑暗地道，地道陰暗潮濕，令你渾身覺
得不舒服。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"t12",
  "westup" : __DIR__"t10",
]));
          set("objects",([
             __DIR__"npc/jui" : 1,
          ]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
       if( dir=="westup" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
        return ::valid_leave(me, dir);
}
