#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FIST;

void create()
{
    set_name(HIR"九狐爪"NOR,({"nine-fox claw","claw"}) );
    set("long","九尾的爪子，殺傷力非常大，傳說只要配上這雙爪子，
連不會武功\的平常人也可以變成英雄。\n");
        set_weight(7000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","對");
        set("limit_level",15);
        set("limit_str",25);
        set("value",50000);
        set("wield_msg",
         HIW "$N雙手套上$n"HIW+"，登時$N眼中射出血紅色的殺氣，令人不由的退了二步。\n"
         NOR);
        }
        set("weapon_prop/dex", 4);
        set("weapon_prop/int", -2);
        set("weapon_prop/str", 2);
        set("weapon_prop/bar", 2);
        set("weapon_prop/wit", -1);
        set("weapon_prop/sou", -1);
        set("weapon_prop/parry", 10);
        init_fist(70);
        setup();
}
