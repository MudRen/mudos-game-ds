#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("生�袢u刀", ({ "short knife","knife" }) );
        set_weight(2500);
        setup_blade(1, 12, 60, 0);

        if( !clonep() ) {
			set("wield_as", ({ "blade" , "secondhand blade" }));
                set("unit", "把");
                set("value", 450);
                set("rigidity", 25);
                set("long", 
"這是一把鐵製但已經生�蛌熊u刀，由於價格便宜，一般人都能買的到。\n"
                );
        }
        setup();
        /* 殊特blade */
        set("name",
                ENHANCE_D->enhance_weapon(this_object(),0,"短刀") );
}
