#include <weapon.h>

inherit F_PIKE;

void create()
{
        set_name("生�袢u槍", ({ "short pike", "pike" }) );
        set_weight(3500);
        setup_pike( 1 , 8 , 60, 0);

        if( !clonep() ) {
                set("wield_as", ({"pike","secondhand pike"}));
                set("unit", "把");
                set("value", 400 );
                set("rigidity", 30);
                set("long" ,@LONG
　　這是一枝生鐵做的短槍，大概打鐵的功力不夠，槍頭有點鈍鈍的，如今
更因為生�蛈荍鬌蓎o沒什麼殺傷力。
LONG
			);
        }
        setup();
        // 特殊 sword
        set("name",
            ENHANCE_D->enhance_weapon(this_object(),0,"短槍") );
}

