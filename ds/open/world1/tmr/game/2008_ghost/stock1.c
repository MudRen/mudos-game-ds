#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("鮮果祭品(fruit-sacrifice stock) [誠意 %d 份]",query("time") );
}

void create()
{
        set_name("鮮果祭品",({"fruit-sacrifice stock", "stock", "_GHOST_STOCK_"}) );
        set("long",@LONG
這是一份當令各式鮮果組合的祭品，包括黃澄澄的木瓜，香氣四溢的愛文芒果
， 還有讓人吃了停不下來的龍眼等。
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
        set("time", 1 + random(100) );
    
        setup();
        set("long", query("long") + getLong() );
}

