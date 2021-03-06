// Room: /u/a/acme/area2/t36.c

inherit MOBROOM;

void create()
{
	set("short", "幽冥地窖[地下四層]");
	set("long", @LONG
你正走在黑暗無比的地道中，地道窄又長，好像走不完似的，越
往裡頭心裡越害怕，這股黑暗的氣流令你窒息。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"t37",
  "south" : __DIR__"t35",
]));
	set("no_clean_up", 0);
        set("chance",60);
        set("mob_amount",1);    //最多出現一個怪物
        set("mob_object",({     //設定怪物檔名.
          __DIR__"npc/devil",
        }) );

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
    return ::valid_leave(me, dir);
}

