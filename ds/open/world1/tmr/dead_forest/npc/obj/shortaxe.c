#include <weapon.h>

inherit F_AXE;

void create()
{
        set_name("生�袢u斧", ({ "short axe", "axe" }) );
        set_weight(3500);
        setup_axe( 4 , 4 , 80, 0);
        if( !clonep() ) {
                set("wield_as", ({"axe","secondhand axe"}));
                set("unit", "把");
                set("value", 300 );
                set("rigidity", 30);
                set("long",@LONG
這是一把生�蚺w久的短斧，斧面上盡是鐵鏽，感覺已經不夠銳利了。
LONG
                );
        }
        setup();
        // 特殊 sword
        set("name",
            ENHANCE_D->enhance_weapon(this_object(),0,"短斧") );
}

