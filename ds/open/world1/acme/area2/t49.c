// Room: /u/a/acme/area2/t49.c

inherit MOBROOM;

void create()
{
        set("short","幽冥地窖[地下四層]");
	set("long", @LONG
這裡四周煙霧迷漫，阻擋了你的視線，伸手不見五指，似乎怎麼
走都還是在原地，且不時有一道冷冷的眼光盯著你瞧，你不禁心中發
毛。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"t48",
  "east" : __DIR__"t48",
  "west" : __DIR__"t48",
  "south" : __DIR__"t48",
]));
        set("no_map",1);
	set("no_clean_up", 0);
        set("chance",70);
        set("mob_amount",2);    //則最多出現二個怪物.
        set("mob_object",({     //設定怪物檔名.
        __DIR__"npc/mo",
        }) );

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
    return ::valid_leave(me, dir);
}

