#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"黃金雕像"NOR,({ "goud statue","statue" }));
        set_weight(30000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","一座雕像,看似一條虎,上面坐了一個面貌非常猙獰的人。\n");
                set("no_get",1);
                set("no_drop",1);
                set("no_dest",1); 
                set("value", 100000);
                set("unit","匹");
        }
        setup();
}


