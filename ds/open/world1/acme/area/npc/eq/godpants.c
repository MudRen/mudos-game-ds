#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
        set_name(CYN"神武寬褲"NOR ,({ "god pants","pants" }) );
        set("long","神武教掌門人所穿著的褲子。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(14000);
//              set("rigidity",10);
//              set("material", "skin");
                set("unit","條");
                set("value",2000);
                set("armor_prop/armor", 10);
                set_temp("apply/dodge",2);
                set("limit_int",20);
                set("limit_con",20);
        }
        setup();
}
