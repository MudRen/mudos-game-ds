#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"麥梵石"NOR, ({ "mine-fan stone", "FAKE_STONE" }));
        set("long", "一個奇特的石頭, 據說可以恢復身體. \n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "顆");
                  set("value", 0);
                set("no_give", 1);
                set("no_put",1);
                set("no_sell", 1);
        }
        setup();
}

