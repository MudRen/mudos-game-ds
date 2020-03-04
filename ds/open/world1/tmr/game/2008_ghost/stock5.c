#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("雪花肉條(snow pork stock) [誠意 %d 份]",query("time") );
}

void create()
{
        set_name(HIW"雪花肉條"NOR,({"snow pork stock", "pork", "stock", "_GHOST_STOCK_"}) );
        set("long",@LONG
雪花肉條是以豬肋條肉為主，搭配新鮮鴿蛋及油菜葉，烹煮而成，
是一道有名的四川料理。
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

