#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name( HIC "陰"HIR"陽"NOR"劍" ,({"moon-sun sword","sword"}));
set("long","這是一把由獨臂老人所打造出來的最佳傑作。\n");
set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("limit_str",25);
set("limit_dex",20);
set("material","blacksteel");
        }
set("wield_msg","$N從背後抽出一把$n，只見$N身旁圍繞著一股陰氣和一股陽氣。\n");
set("unwield_msg","$N放下手中的$n，將$n插入背後的劍鞘中。\n");
        set("weapon_prop/sou",-1);
        set("weapon_prop/bar",1);
        set("weapon_prop/int",1);
init_sword(55);
setup();
}

