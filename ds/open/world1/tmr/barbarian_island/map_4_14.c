// File: /d/barbarian_island/map_4_14.c
// Updated by tmr (Wed May  8 23:23:58 2002)

inherit ROOM;

void create()
{
          set("short", "石壁前");
          set("long", @LONG
出現在你面前的是一面大石壁，壁上似乎有道人工開拓而成的石門。
LONG
          );
          set("map_long", 1);
          set("outdoors", "forest");
          set("exits", ([ /* 1 element(s) */
        "south" : __DIR__"map_5_14",
]));
        set("detail", ([  // 是detail 不是detial , debug by -Acme-
        "石門":"一道看起來沈重的石門，不知是否能憑你的力量推開它(push)。\n",
        ]));
        setup();
}
void init()
{
        add_action("do_push","push");
}
int do_push(string arg)
{
        object me=this_player();
        int str=me->query_strength("attack")
		+me->query_stat("nina")*me->query_attr("strength")*10;
        if(!arg || arg!="石門")
                return notify_fail("你要推動什麼？\n");
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("你正忙著，請先停下手邊的事吧。\n");
        if(str<100000) {
                message_vision("$N使出渾身的力量使勁的要推開石門，但是石門紋風不動.....\n",me);
        } else {
                message_vision("$N輕鬆地推開了石門，隨即走了進去......\n",me);
                me->move(__DIR__"statue_room");
                tell_room(environment(me),me->query("name")+"推開了石門，走了過來。\n",me);
        }
        return 1;
}

