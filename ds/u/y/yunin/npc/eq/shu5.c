#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
        set_name(HIR"修羅護面〥"NOR,({"shu lou mask","mask"}) );
        set("long",@LONG
四大塔王之一的燕非彥使用的防具。
LONG
);
        set_weight(299); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",20);
                set("unit", "個");       
                set("value",3400);          
                set("volume", 2);   
                set("material","cold");   
        }
        set("armor_prop/armor",4);       
        set("armor_prop/con",1);
 setup();
}

