#include <ansi.h>
#include <armor.h>
inherit WRISTS;

void create()
{
        set_name(HIR"修羅護腕〥"NOR,({"shu lo hands","hands"}) );
        set("long",@LONG
四大塔王之一的燕非彥使用的防具。
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",20);
                set("unit", "雙");       
                set("value",2100);          
                set("volume", 1);                       
                set("material", "cold");   
        }
        set("armor_prop/armor",5);       
        set("armor_prop/con",1);
      
        setup();
}

