#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
        set_name(CYN"���Z�e��"NOR ,({ "god pants","pants" }) );
        set("long","���Z�дx���H�Ҭ�۪��Ǥl�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(14000);
//              set("rigidity",10);
//              set("material", "skin");
                set("unit","��");
                set("value",2000);
                set("armor_prop/armor", 10);
                set_temp("apply/dodge",2);
                set("limit_int",20);
                set("limit_con",20);
        }
        setup();
}
