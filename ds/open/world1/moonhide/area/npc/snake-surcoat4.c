#include <armor.h>
#include <ansi.h>
inherit SURCOAT; 

void create()
{
        set_name(HBK"迴疾披天地"NOR,({ "tan-di surcoat","surcoat" }) );
        set("long","百年大蛇 迴地 的不知名體皮，有股淡淡的香味，帶給你心靈上的慰藉。\n");
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
        set("armor_prop/bio",-1);
        set("armor_prop/sou", 1);
        set("armor_prop/str",-1);
        set("armor_prop/dodge",20);        
        setup();
}

