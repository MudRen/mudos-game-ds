#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("銀製長劍", ({ "silver long sword", "sword" , "long" }) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把銀製的長劍，以特殊技巧鑄成，在與不死系生物戰鬥時
能有特殊的效用，此外，很好看...\n");
                set("volume",3);
                set("value", 1400);
        set("material","silver");
                set("sword",41);
        }
        set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
        init_sword(15);
        setup();
}

