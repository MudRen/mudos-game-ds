#include <weapon.h>

inherit F_SWORD;

void create()
{
        set_name("生�袢u劍", ({ "short sword", "sword" }) );
        set_weight(2000);
        setup_sword(1, 12, 75, 0);

        if( !clonep() ) {
                set("wield_as", ({"sword","secondhand sword"}));
                set("unit", "把");
                set("value", 150);
                set("rigidity", 5 );
                set("long", "一把鐵製的短劍，是一般常見的基本防身武器，但已經生�蚳嚓H時都會斷掉的感覺。\n");
        }
        setup();
        // 特殊 sword
        set("name",
            ENHANCE_D->enhance_weapon(this_object(),0,"短劍") );
}

