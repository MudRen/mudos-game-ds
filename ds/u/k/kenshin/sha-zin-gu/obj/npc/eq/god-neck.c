#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HIC"����"NOR""YEL"�j�L"NOR ,({ "god-neck","neck" }) );
        set("long","�y�Ǥd�j�㦳���O������C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(6000);
             //�@ set("material", "gold");
                set("unit","��");
                set("value",4000);
                set("armor_prop/int",3);
                set("armor_prop/dex",2);
                set("armor_prop/wit",1);
                set("armor_prop/bio",1);
                set("armor_prop/armor",6+random(6));
                set("limit_int",40);
                        }
        setup();
}


