#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIR"修羅之鍊〥"NOR,({"shu lo neck","neck"}) );
        set("long",@LONG
四大塔王之一的燕非彥使用的防具。
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "條");       
                set("value",1000);          
                set("volume", 2);                       
                set("material", "cold");   
        }
        set("armor_prop/armor",5);       
        set("armor_prop/con",1);
        setup();
}

