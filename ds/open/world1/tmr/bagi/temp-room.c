#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "半空中");
        set("long", @LONG
你正處在半空中，金色繩索仍然快速地拉著你往上急升...
四週的景物正快速在你身旁飛逝著.....
LONG
        );
        set("item_desc",([
        "金色繩索":"一條金黃色的繩索，看不出來是什麼材質做成的。\n",
        "景物":"急速飛去的景物中，你似乎發現山壁有處小山洞？！\n",
        ]) );
        set("world", "past");
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
        setup();
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me;
        me=this_player();
        if (!arg || arg!="山洞") return 0;
        message_vision("$N提一口氣，放開了金色繩索，往山壁一個洞口跳去！！。\n",me);
        me->move(__DIR__"hole");
    me->set_temp("jump-hole",1);
        return 1;
}

