#include <armor.h>
#include <ansi.h>
inherit CLOTH; 

void create()
{
        set_name(HIW"王子的新衣"NOR,({ "prince cloth","cloth" }) );
        set("long","蕭敬騰所穿的王子的新衣。\n");
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","golden");
        set("unit", "件" );
        set("value",20000);
        }  
       setup();
}

