#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
        set_name("金縷\腰帶",({"gold-silk waist","waist"}) );
        set("long",@LONG
金縷絲織成的腰帶，閃閃發光炫人耳目。
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",15);
                set("unit", "條");       
                set("value",1500);          
                set("volume", 3);                       
                set("material", "gold");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/con",2);
        setup();
}
