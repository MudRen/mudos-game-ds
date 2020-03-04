#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIC "天青劍" NOR,({"sky sword","sword"}) );
        set("long",
        "一把上好青鋼打造的劍。\n"
        );
        set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("limit_str",20);
                set("value",1000);
                set("volume",2);
                set("limit_skill",20);
                set("material","steel");
         }
        set("weapon_prop/str",2);
        set("weapon_prop/con",1);
        init_sword(23);
        setup();        
}

