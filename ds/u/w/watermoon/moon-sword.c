#include <ansi.h>

#include <weapon.h>

inherit SWORD;

void create()

{

set_name( CYN "凝月劍" NOR ,({"Moon sword","sword"}));

set("long","這是一把水雲齋的師父給她的神兵利器。\n");

set_weight(11000);

        if( clonep() )

                set_default_object(__FILE__);

        else {

set("unit", "把");

set("value",5000);

set("limit_str",20);

set("limit_dex",15);

set("material","blacksteel");

        }

set("wield_msg","$N凝風鎖月步十荒 隱夢歸霜落空塵 御劍隨心縱霸氣 狂刀一舞笑英魂 $n\n");

set("unequip_msg","$N放下手中的$n,將$n插入劍鞘中。\n");

        set("weapon_prop/hit",10);

        set("weapon_prop/dex",20);

        set("weapon_prop/str",20);

init_sword(300);

setup();

();

}

