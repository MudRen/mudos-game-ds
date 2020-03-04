#include <armor.h>
#include <ansi.h>
inherit MASK;

void create()
{
        set_name( "月影烏瞳面" ,({ "moon-shadow mask","mask" }) );
        set("long",@LONG
這是一面刻有金絲紋路的面具，紋路的走向跟一般的虎紋恰好相反，
平添了幾分詭異的氛圍。
LONG
);
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
	        set("material","fur");
	        set("unit","面");
	        set("value",3000);
	        set("limit_int",50);
        }
        set("armor_prop/str", 1);
        set("armor_prop/int", 1);
        set("armor_prop/armor",5);
        setup();
}
