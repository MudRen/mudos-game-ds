// Room: /u/a/acme/area2/t18.c

inherit MOBROOM;

void create()
{
	set("short", "幽冥地窖[地下二層]");
	set("long", @LONG
這裡一片漆黑，四周毫無燈光，只能摸索而行，這裡的濕氣，霉
氣，沖得你混身不對勁，最好趕緊離開這個人間煉獄。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"t17",
  "northeast" : __DIR__"t19",
]));
	set("no_clean_up", 0);
set("chance",70);       
        set("mob_max",3);
        set("mob_amount",3);    //則最多出現三個怪物.
        set("mob_object",({     //設定怪物檔名.
             __DIR__"npc/man",
        }) );

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
    return ::valid_leave(me, dir);
}

