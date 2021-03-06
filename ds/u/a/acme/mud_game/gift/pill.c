#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("伸腳瞪眼丸", ({ "pill" }));
        set_weight(1);
        set("long","伸腳瞪眼丸，吃(eating)了會增加人物經驗值(exp)。\n");
        if( !clonep() ) {
                set("unit", "顆");
                set("long","伸腳瞪眼丸，吃(eating)了會增加人物經驗值(exp)。\n");
        }
        setup();
}

void init()
{
        add_action("do_eating","eating");
}

int do_eating(string arg)
{
        if( !arg ) return notify_fail("你想吃什麼？\n");
        if( arg != this_object()->query("id") )
                return notify_fail("你想吃什麼？\n");
        message_vision("$N吃下了一顆$n並增加了 "+this_object()->query("add_exp")+" 點人物經驗值(exp)。\n",this_player(),this_object());
        this_player()->add("exp",this_object()->query("add_exp"));
        destruct(this_object());
        return 1;
}
