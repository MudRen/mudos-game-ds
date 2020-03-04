#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("北京烤鴨(beijing-duck stock) [誠意 %d 份]",query("time") );
}

void create()
{
        set_name(HIR"北京烤鴨"NOR,({"beijing-duck stock", "duck", "stock", "_GHOST_STOCK_"}) );
        set("long",@LONG
北京烤鴨是具有世界聲譽的北京著名菜式，用料為優質肉食鴨北京鴨，果木炭火烤制
，色澤紅潤，肉質肥而不膩，用來普渡孤魂野鬼，最見誠意。
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

