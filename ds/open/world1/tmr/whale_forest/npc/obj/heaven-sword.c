#include <weapon.h>

inherit F_SWORD;

void create()
{
          set_name("重劍", ({ "heavy sword", "sword" }) );
         set_weight(10000);
          setup_sword(5, 7, 120, 0);

        if( !clonep() ) {
                set("wield_as",({ "sword","twohanded sword"}) );
                set("unit", "把");
                set("value", 800);
                set("rigidity", 60);
                set("long", "這是把長約一尺的重劍，光劍柄就需要兩隻手才能握得穩。\n");
        }
        setup();
}

