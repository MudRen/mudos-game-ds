#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("鐵石",({ "iron stone","stone" }));
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","一個平凡無奇，私毫不起眼的鐵石，你不禁懷疑自己幹嘛拿著這種東西...\n");
                set("unit","個");
                set("value",100);
        }
        setup(); 
}

