#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("繡球全魚(xiuqiu fish stock) [誠意 %d 份]",query("time") );
}

void create()
{
        set_name(HIM"繡球全魚"NOR,({"xiuqiu fish stock", "fish", "stock", "_GHOST_STOCK_"}) );
        set("long",@LONG
繡球全魚是一道有名的料理，無筋無刺，五彩繽紛，口味鮮美，
嚐過者無不口頰留香，留戀忘返。
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","份");
        }
        set("value", 100);
        set("time", 1000 + random(1000) );
    
        setup();
        set("long", query("long") + getLong() );
}

