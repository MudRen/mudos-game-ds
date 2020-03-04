#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
        set_name("雲母巨盾",({"mica shield","shield"}) );
        set("long",@LONG
天然雲母形成的盾牌，完全未經過人工打造，可以抵抗部份的法術威
力，雲母石的磁場力量是很強大的。
LONG
);
        set_weight(3000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",20);
                set("unit", "個");       
                set("value",1200);          
                set("volume", 4);                       
                set("material", "mica");   
        }
        set("armor_prop/armor",20);     
        set("armor_prop/shield",14);   
        setup();
}


