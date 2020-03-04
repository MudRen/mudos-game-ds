#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "奇怪的巷口");
        set("long", @LONG
    你正在一個奇怪的巷口上，牆壁上似乎有洞口能進去
LONG
        );
      set("item_desc", (
        "牆壁" : "一個奇怪的洞口, 但是不曉得怎麼進去。\n",
        "洞口" :"一個奇怪的洞口, 但是不曉得怎麼進去。\n",
        ]));

        set("no_clean_up", 0);
        set("outdoors","land");

        setup();
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me;
        me=this_player();

        if (arg != "洞口" && arg !="hole" )
                return 0;
        else 
        {
        message_vision("$N竅開了牆壁，走了進去。\n",me);
        me->move(__DIR__"workroom");
      tell_room(environment(me),me->query("name")+"竅開了牆壁，走了進去\n",me);
        return 1;

}

