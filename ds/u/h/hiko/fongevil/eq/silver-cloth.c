#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(WHT"銀璃絲衣"NOR ,({ "silver-li cloth","cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long",@LONG
這是由銀蠶絲所織成的護衣，光照上去會反射出琉璃色的燦光。
LONG
     );
        set("unit", "件");
        set("value",5000);
        set("material", "steel");
        set("armor_prop/shield",15);
        set("armor_prop/con",2);
        set("armor_prop/armor",18);        
        set("armor_prop/dex",3);          
           }
        setup();
}




