#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIY"虎魄 "HIW"神刀"NOR, ({ "tiger blade", "blade" }));
        set("long", "採取猛虎的骨髓，再溶入千年虎魄裡，外似黃透明，可見虎骨。\n");
        set_weight(12500);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("volume",3);
                set("material", "crimsonsteel");
                set("limit_skill",40);
                set("limit_str",25);
                set("limit_dex",30);
                      set("value",15000);
                set("limit_lv", 25);
        }
        set("weapon_prop/armor", 15);
        set("weapon_prop/con",  1);
        set("weapon_prop/str",2); 
        set("weapn_prop/dex",-2);
        set("wield_msg",HIW"$N將$w拿起的那一瞬間，$N的眼神也可看出，"HIR"殺 . ...\n");
        set("unwield_msg", "$N將把$n放下。\n");

        init_blade(80);
        setup();
}

