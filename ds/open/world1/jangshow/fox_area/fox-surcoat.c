#include <armor.h>
#include <ansi.h>
inherit SURCOAT; 

void create()
{
        set_name(HIW"九尾銀翼"NOR,({ "nine-fox surcoat","surcoat" }) );
        set("long",HIW"九尾妖狐背部的毛皮，色呈白銀色，輕薄如紙，堅軔如鋼。\n"NOR);
        set_weight(4000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","golden");
        set("unit", "件" );
        set("value",30000); 
        }   
        set("armor_prop/armor", 10); 
        set("armor_prop/dodge",10); 
        set("armor_prop/bar",1);
        set("armor_prop/tec",1); 
        set("armor_prop/str",-3);
        setup();
}
