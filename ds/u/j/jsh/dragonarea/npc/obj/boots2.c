#include <ansi.h> 
#include <armor.h>
inherit BOOTS;

void create() 
{
        set_name("絨布鞋",({ "rong boots","boots" }) );
        set("long","適合戶外活動所穿的鞋子。\n");
        set_weight(8000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
     set("volume",5);
         set("material","skin");
                set("unit", "件" );
       set("value",1000);
                set("armor_prop/armor", 4);
                set("armor_prop/dodge",2);
        }
        setup();
}

