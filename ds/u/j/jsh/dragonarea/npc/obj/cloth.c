#include <ansi.h> 
#include <armor.h>
inherit CLOTH;

void create() 
{
        set_name("白衣",({ "white cloth","cloth" }) );
        set("long","一件薄薄的白上衣。\n");
        set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
     set("volume",5);
         set("material","skin");
                set("unit", "件" );
       set("value",600);
                set("armor_prop/armor", 3);
                
        }
        setup();
}

