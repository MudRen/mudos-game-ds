#include <armor.h>
#include <ansi.h>
inherit SURCOAT; 

void create()
{
        set_name(HIW"迴疾披天"NOR,({ "hua-tai surcoat","surcoat" }) );
        set("long","百年大蛇  迴天  的體皮，具有高度迴避率與殺傷力。\n");
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","golden");
        set("unit", "件" );
        set("value",15000);
        }  
        set("armor_prop/armor", 13); 
        set("armor_prop/bar",1);
// 2003.4.11  加 bar 1 所以減 wit 1   by ksj
        set("armor_prop/wit",-1);
        set("armor_prop/con",-1);
        set("armor_prop/dodge",20);        
        setup();
}

