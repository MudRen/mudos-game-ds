#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(HBK"寒澈護手"NOR ,({ "frost hands","hands" }) );
        set("long","寒澈派觀主所佩帶的護手。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(12000);
//              set("rigidity",10);
//              set("material", "skin");
                set("unit","雙");
                set("value",3000);
                set("volume",1);
                set("armor_prop/armor", 8);
                set_temp("apply/shield",5);
                set("limit_int",25);
        }
        setup();
}
