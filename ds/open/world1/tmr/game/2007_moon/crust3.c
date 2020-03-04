#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("頂級起酥皮(pastry crust) [淨重 %d 公克]",query("time") );
}

void create()
{
        set_name("頂級起酥皮",({"pastry crust", "crust", "_MOON_CRUST_"}) );
        set("long",@LONG
起酥皮，又稱千層酥皮，是由麵粉加水搓成的麵糰，在麵糰中間需包上
牛油，重覆的對疊，由於麵皮有牛油隔離而產生許多層次。
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","份");
        }
        set("value", 1);
        set("time", 100 + random(100) );
    
    setup();
        set("long", query("long") + getLong() );
}


