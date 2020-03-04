#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIW"虎紋披風"NOR,({ "tiger cloak","cloak" }) );
        set("long","這件披風全部是用白額虎的毛皮所編逢而成的,\n"
                   "十分美觀性，而且穿起來有王者之風。\n");
        set_weight(7500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "fur");
        set("volume",3);
        set("unit", "件" );
        set("value",2800);
        set("limit_lv",15);
        set("limit_con",18);
}        
        set("armor_prop/armor",10);
        set("armor_prop/con",1);
        set("armor_prop/combat",5);
        setup();
}

