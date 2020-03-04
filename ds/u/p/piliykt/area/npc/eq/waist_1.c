#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
        set_name("虎皮腰帶",({"tiger-skin waist","waist"}) );
        set("long",@LONG
南山白額虎的虎皮所製,繫在腰間上讓你有一種威風的感覺.
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",20);
                set("unit", "條");       
                set("value",2000);          
                set("volume", 3);                       
                set("material", "fur");   
        }
        set("armor_prop/armor",5);       
        set("armor_prop/con",1);
        set("armor_prop/str",1);         
setup();
}

