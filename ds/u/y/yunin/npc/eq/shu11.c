#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
        set_name(HIR"修羅披風〥"NOR,({"shu lo cloak","cloak"}) );
        set("long",@LONG
四大塔王之一的燕非彥使用的防具。
LONG
);
        set_weight(900); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",20);
                set("unit", "頂");       
                set("value",2100);          
                set("volume", 2);                       
                set("material", "cold");   
        }
        set("armor_prop/armor",10);       
        set("armor_prop/con",1);
setup();
}

