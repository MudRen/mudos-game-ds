#include <armor.h>
#include <ansi.h> 
inherit WAIST;

void create()
{
        set_name(HIM"血蛟軔帶"NOR,({ "blood-snake waist","waist" }) );
        set("long","血蛟的中段皮囊，似乎沒有什麼功\用。\n");
        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","steel");
        set("unit", "件" );
        set("value",2000); 
        }
        set("armor_prop/str",1);
        set("armor_prop/con",1);
        set("armor_prop/armor", 8); 
        set("beast_armor_prop/armor", 8); 
        setup(); 
}
