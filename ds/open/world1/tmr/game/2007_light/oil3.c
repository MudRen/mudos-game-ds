#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("天燈燈油(lamp oil) [容量 %d 公克]",query("time") );
}

void create()
{
        set_name("天燈頂級燈油",({"super-lamp oil", "oil", "_LAMP_OIL_"}) );
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
        set("time", 100 + random(100) );
    
    setup();
        set("long", query("long") + getLong() );
}

