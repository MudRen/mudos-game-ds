// 鯨魚森林 裡的 樹枝 weapon

#include <weapon.h>

inherit F_SWORD;

void create()
{
        set_name("枯樹枝", ({ "branche", "branche" }) );
        set_weight(2000);
        setup_sword(1, 8, 20, 0);
        if( !clonep() ) {
                set("wield_as", 
                ({"sword","secondhand sword"})
                );
                set("unit", "把");
                set("value", 50);
                set("rigidity", 10);
                set("long", "這是一根已枯的樹枝，拿來當成木劍，倒也可行。\n");
        }
        setup();
}

