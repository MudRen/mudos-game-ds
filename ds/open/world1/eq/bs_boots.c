#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("獸皮靴",({"beast boots","boots"}) );
        set("long",@LONG
獸皮做的靴子，穿起來軟軟的很舒服。
LONG
);
        set_weight(1000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "雙");       
                set("value",600);          
                set("volume", 4);                       
                set("material", "skin");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/dex",1);
        setup();
}


