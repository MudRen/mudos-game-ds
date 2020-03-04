#include <weapon.h>
inherit DAGGER;
void create()
{
        set_name("鐵匕", ({ "iron dagger" ,"dagger"}) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把用鐵打造而成的武器，殺傷力不高。\n");
                set("value", 3500);
                set("material", "steel");
        }
        init_dagger(35);
        
        set("weapon_prop/str", 1);
        set("limit_str",20);
        set("limit_dex",30);
        set("limit_level",15);

        set("wield_msg", "$N從懷中摸出一把$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n藏入懷中。\n");

        setup();
}

