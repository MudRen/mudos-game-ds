inherit ITEM;
#include <ansi.h>

void create()
{
        set_name( "獸王頭骨" , ({ "animal-king head", "head", "open-war-head" }));
        set("long", "這是一顆獸王之王的頭骨。 \n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "顆");
                set("value", 1);
        }
        setup();
}

