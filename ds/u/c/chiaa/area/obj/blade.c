#include <weapon.h> 
//weapon武器
inherit BLADE;
void create()
{
        set_name("大刀", ({ "blade" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把看起來相當普通的大刀。\n");
                set("value", 1000);
                set("material", "steel");   //material材料steel鋼鐵
        }
        init_blade(10);

        set("wield_msg", "$N從背後抽出一把$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n放回入背後。\n");
      setup();
}
