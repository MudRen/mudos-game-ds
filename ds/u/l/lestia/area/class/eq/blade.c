#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("狂塵刀", ({ "crazy sword", "crazy" , "sword" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把剛鑄造成的一把刀。\n");
                set("volume",3);
                set("value", 400);
        set("material","iron");
                set("sword",41);
        }
        set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n插入腰間的刀鞘。\n");
        init_blade(15);
        setup();
}

