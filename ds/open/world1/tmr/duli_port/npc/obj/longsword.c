
#include <weapon.h>

inherit F_SWORD;

void create()
{
        set_name("長劍", ({ "long sword", "sword" }) );
          set_weight(7000);
        setup_sword(2, 10, 40, 2);

        if( !clonep() ) {
                set("wield_as", "sword");
                set("unit", "把");
                set("value", 500);
                set("rigidity", 20);
                set("long", "這是一把鐵打造的長劍，比起短劍來，更具有殺傷力。\n");
        }
        setup();
}

