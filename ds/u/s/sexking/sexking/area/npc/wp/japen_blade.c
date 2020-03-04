#include <weapon.h>
inherit BLADE;

void create()
{
set_name("日本武士刀",({"japen blade","blade"}));
        set_weight(10000);   
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
這是一把日本出產的武士刀，通常都是浪人劍客慣用的兵器，
十分銳利，但很重。
LONG);
                set("unit", "把");
                set("material","blade");
        }
        init_blade(35,TWO_HANDED);
        set("value",3500);
set("limit_str",15);
set("limit_dex",20);
set("armor_prop/dex",-2);
set("wield_msg","$N從腰間拔出一把$n，感覺十分沉重，。\n");
set("unequip_msg", "$N將$n「唰」的一聲插入刀鞘之中，。\n");
setup();
}

