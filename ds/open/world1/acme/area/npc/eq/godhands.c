#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(CYN"���Z�@��"NOR ,({ "god hands","hands" }) );
        set("long","���Z�дx���H�Ҩرa���@��C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(12000);
//              set("rigidity",10);
//              set("material", "skin");
                set("unit","��");
                set("value",3000);
                set("volume",1);
                set("armor_prop/armor", 8);
                set_temp("apply/shield",5);
                set("limit_int",25);
        }
        setup();
}
