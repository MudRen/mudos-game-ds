#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("頂級鹹蛋黃(egg yolk) [淨重 %d 公克]",query("time") );
}

void create()
{
        set_name(HIY "頂級鹹蛋黃" NOR,({"egg yolk", "yolk", "_MOON_YOLK_"}) );
        set("long",@LONG
這是一顆圓圓的鹹蛋黃，是做月餅的重要材料之一。
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","顆");
        }
          set("value", 100);
        set("time", 100 + random(100) );
    
    setup();
        set("long", query("long") + getLong() );
}


