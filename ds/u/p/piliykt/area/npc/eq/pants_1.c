#include <ansi.h>
#include <armor.h>
inherit PANTS;

void create()
{
        set_name("長裙",({"long skirt","skirt"}) );
        set("long",@LONG
用絲布做的長裙子,散發著高貴的氣質。
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("female_only",1);
                set("unit", "件");       
                set("value",1000);          
                set("volume", 4);                       
                set("material", "silk");   
        }
        set("armor_prop/armor",5);       
        setup();
}

