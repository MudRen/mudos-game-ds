// Room: /u/a/acme/area2/t20.c

inherit ROOM;

void create()
{
        set("short","幽冥地窖[地下二層]");
	set("long", @LONG
這裡是幽冥地窖的地下二層，四周昏暗不明，殺氣騰騰，在你身旁射來一
道冷冷的眼光，令你感到無比的壓力，不知是否繼續往前行。在你眼前隱約能
看見有左右二排的大石柱，石柱圍成一個圓圈，在石柱中央卻有個墓碑。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"t19",
]));
  set("item_desc", ([ /* sizeof() == 1 */
"墓碑" : "這是一個相當陳舊的墓碑，上頭刻著一個大字【冤】，但似乎一腳就能踢壞的樣子。\n",
  ]) );
	set("no_clean_up", 0);

	setup();
}
void init()
{ 
         add_action("do_kick","kick");
}
int do_kick(string arg)
{
          object me;
          me=this_player();
          if(arg != "墓碑")
            return 0;
          else {
            message_vision("$N用力一腳往墓碑踢去，只見墓碑應聲而毀，並顯現了個出口。\n\n",me);
            message_vision("$N的腳因為踢得太用力而受傷流血，走路一跛一跛的，站都站不穩。\n",me);
            set("exits", ([
               "east" : __DIR__"t19",
               "westdown" : __DIR__"t21",
            ]));
            me->receive_wound("left_leg",10);
            return 1;
          }
}
int valid_leave(object me, string dir)
{
       if( dir=="westdown" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
        return ::valid_leave(me, dir);
}
