// 設計用來存ticket 這種重量輕，但需要大量儲存的物件。
#include <ansi.h>

inherit ITEM;
void create()
{
        set_name("牛皮紙匣", ({ "paper box","box" }) );
        set_weight(600);
        set_max_capacity(2000);
        set_max_encumbrance(2000);      // 假設一張紙只有一克
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long", @LONG
這是一個牛皮製的紙匣，裡面是近2000個的細夾層，
非常方便用來收集紙張或票券。
你可以使用size來查看目前已經放有多少樣物品。
LONG
);
                set("value", 10000);
               }
        setup();
}

void init()
{
    add_action("do_size","size");
}

int do_size()
{
    return notify_fail( sprintf("目前%s中有%3d樣物品。\n", name(), sizeof(all_inventory(this_object() ))
                               ));
}

