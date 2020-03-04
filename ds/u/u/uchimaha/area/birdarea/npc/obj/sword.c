#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name(HIC"陰"HIR"陽"NOR"劍",({"negative positive sword","sword"}));
set("long","這是一把由獨臂老人所打造出來的最佳傑作，劍刃的地方有著絲絲的冷氣，
冷氣的外圍卻又包圍了一層暖氣，入手之後，令人為之一震。\n");
set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("limit_str",25);
set("limit_dex",20);
set("value",15000);
set("material","blacksteel");
        }
set("wield_msg","$N從背後抽出一把$n，只見$N身旁圍繞著一股陰陽調和之氣。\n");
set("unwield_msg","$N放下手中的$n，將$n插入背後的劍鞘中。\n");
        set("weapon_prop/sou",-2);
        set("weapon_prop/bar",1);
        set("weapon_prop/wit",1);
        set("weapon_prop/int",2);
init_sword(55);
setup();
}

