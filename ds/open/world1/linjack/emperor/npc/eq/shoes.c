#include <armor.h>
inherit BOOTS;
void create()
{
        set_name("布鞋" ,({ "shoes" }) );
        set("long","普通人所穿的鞋子, 穿起來還算舒適。\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("value" ,30);
                set("material","cloth");
        }
        set("armor_prop/armor", 1); 
        setup();
}
