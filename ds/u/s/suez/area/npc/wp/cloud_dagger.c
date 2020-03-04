#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
inherit F_UNIQUE;
void create()
{
set_name("千雲匕",({"cloud dagger","dagger"}));

set_weight(700);
          if( clonep() )
                      set_default_object(__FILE__);
          else {
set("long","一把白色的匕首，散發出奇異的光芒，上面的寒氣
將附近的水氣結成薄冰，有如初春的寒霜般附在刃上。\n");
set("unit", "凜");
set("value", 17000);
set("material","steel");

set("limit_con",10);
set("limit_dex",10);

set("wield_msg", "$N輕輕一揮，一道寒氣由袖中疾射而出，落入$N的手上。\n");
set("unwield_msg","$n輕輕滑入$N的袖中......那股寒意也隨之消逝了。\n");

set("weapon_prop/dex",7);
set("weapon_prop/hit",7);

set("weapon_prop/damage", 17);
set("combat_msg", ({
     HIC"$N內力一吐，$w上的寒氣如海浪般將$n團團圍住！"NOR,
     HIY"$w在$N手上有如活物一般，以迅雷不及掩耳的速度攻向$n的$l"NOR,
    HIG"$N手中的$w突然消失！隨著$N的動作出現在$n的$l附近，接著就是狠狠一刺！"NOR,
     }) );

set("replica_ob",__DIR__"stonedragon_d");
init_dagger(27);

setup();
}
}                      

void attack(object me,object victim)
{
int damage,con,dex,dodge;
dodge=me->query_skill("dodge");
if( random(100)>(100-dodge/5))
    {

dex=me->query_dex();
if( (dex)>(120))
{
   dex=(120);
}
con=victim->query_con();
damage= ((dex)/(7+random(3)))*((dex)/(3+(random(con/10))));
        victim->receive_damage("hp", damage, me );
message_vision(HIG"
              千雲匕上的寒氣突然侵入$P四肢百骸之中！
              $P趕緊以內力逼出，但寒氣過於強勁猛烈，
              $P體中熱血竟隨著寒氣由毛孔中激射而出！
              造成$P"+damage+"點的傷害！！！！\n"NOR,victim);
                             
if(damage>199)
{
   message_vision(HIR"$N只感到丹田一股劇痛，內力竟不聽使喚的在體內亂竄！！\n"NOR,victim);
   victim->receive_wound("body",(7+random(7-(dex)/20)));
}
         return;    

        }
    return;
}              


