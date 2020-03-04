#include <armor.h>
#include <ansi.h>
inherit SURCOAT; 

void create()
{
        set_name("逐日者披風",({ "sun-follow surcoat","surcoat" }) );
        set("long","這是片用像純綿材質做成的披風，絲質柔軟，摸起來比較舒服。\n");
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","silk");
                set("unit", "件" );
                set("value",500);
        }  
        set("armor_prop/armor", 5); 
        set("armor_prop/dex", 1);
        setup();
}

