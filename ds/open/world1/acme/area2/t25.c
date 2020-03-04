// Room: /u/a/acme/area2/t25.c

inherit MOBROOM;

void create()
{
	set("short", "幽冥地窖[地下三層]");
	set("long", @LONG
你再前行數丈，地道突然收窄，必須弓身而行，越向前行，彎腰
越低。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"t26",
  "west" : __DIR__"t24",
]));
	set("no_clean_up", 0);
set("chance",70);       
        set("mob_max",3);
        set("mob_amount",3);    //則最多出現三個怪物.
        set("mob_object",({     //設定怪物檔名.
            __DIR__"npc/ghost2",
        }) );

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
    return ::valid_leave(me, dir);
}

