#include <ansi.h>
#include <armor.h>
inherit WRISTS;

void create()
{
        set_name(HIC"玉蟾護腕"NOR,({"jade-toad wrists","wrists"}) );
        set("long",@LONG
一雙用藍色鹿皮製成的手套，看起來蠻好看的。
LONG
);
        set_weight(600); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "雙");       
                set("value",5000);          
                set("volume", 2);                       
                set("material", "fur");   
        }
        set("armor_prop/armor",2);       
        set("armor_prop/int",2);
        set("armor_prop/shield",4);
        setup();
}
