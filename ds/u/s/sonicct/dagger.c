#include <weapon.h>
inherit DAGGER;

void create()
{
     set_name("千雲匕",({"cloud dagger","dagger"}));
     set("long","一把白色的匕首，散發出奇異的光芒，上面的寒氣
     將附近的水氣結成薄冰，有如初春的寒霜般附在刃上。\n");
     set_weight(700);
          if( clonep() )
                      set_default_object(__FILE__);
          else {
set("unit", "把");
set("value", 1700);
set("material","iron");
set("limit_con",10);

set("wield_msg", "$N輕輕一揮，一道寒氣由袖中疾射而出，落入$N的手上。\n");
set("unwield_msg","$n輕輕滑入$N的袖中......那股寒意也隨之消逝了。\n");
set("weapon_prop/dex",7);
set("weapon_prop/hit",50);

set("weapon_prop/damage", 17);
set("combat_msg", ({
"$N內力一吐，$w上的寒氣如海浪般將$n團團圍住！",
"$w在$N手上有如活物一般，以迅雷不及掩耳的速度攻向$n的$l",
"$w突然消失！隨著$N的動作出現在$n的$l附近，接著就是狠狠一刺！",
}) );

setup();
}
}
