#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("一公斤的燈油",({"kilogram lamp oil", "oil", "_LAMP_OIL_"}) );
        set("long",@LONG
這是一個造型精巧的瓷瓶，裡頭裝著點燃天燈用的燈油。
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","瓶");
        }
        set("value", 1);
        set("time", 1000 );
        setup();
}


