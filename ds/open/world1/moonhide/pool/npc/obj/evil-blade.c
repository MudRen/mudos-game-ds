#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(HIR"魔　刀"NOR,({"evil-blade","blade","evil"}));

        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long",HIC"\n\t\t上古神兵石製造，加上惡魔血液打造出的魔性之作。\n"NOR);
                set("volume",2);
                set("unit", "把");
                set("value",10000);
                set("material","silver");
        }
                set("limit_skill",50);
                set("limit_lv",25);
                set("limit_str",30);
                set("limit_dex",30);
        init_blade(50);
                       setup();
}

