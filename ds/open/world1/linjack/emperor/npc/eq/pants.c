#include <armor.h>
inherit PANTS;
void create()
{
        set_name("粗布長褲" ,({ "pants" }) );
        set("long","一般農家人才會去穿的長褲。\n");
        set_weight(400);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("value" ,50);
                set("material","linen");
        }
        set("armor_prop/armor", 2);
        set("armor_prop/shield", 1); 
        setup();
}
