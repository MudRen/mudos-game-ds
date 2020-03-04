#include <weapon.h>
#include <ansi.h>
inherit FORK;
inherit F_UNIQUE;
void create()
{
set_name("烏蛇槍",({"blake snake pike","pike"}));

set_weight(7000);
          if( clonep() )
                      set_default_object(__FILE__);
          else {
set("long",@LONG
    一隻通體烏黑，連尖刃都泛著黑色光澤的鐵槍，槍桿上刻
有密密麻麻的刻痕，這是八極門李書文送給他的得意弟子柴子
玲的兵器。由於柴子玲身體虛弱，不論是大槍訣或是八極拳都
沒辦法展現應有的威力，所以李書文由大槍訣中變化出一套輕
巧靈動又威力十足的槍法，槍桿的刻痕據說就是以槍法刻出的
，而柴子玲就由這些刻痕中領悟出槍法的奧意。但是聽說這個
槍還有另一個武林的奧秘，那就不得而知了。
LONG);
set("unit", "隻");
set("value", 17000);
set("material","iron");
}
set("limit_int",90);
set("limit_dex",70);

set("weapon_prop/dex",7);
set("weapon_prop/hit",5);
set("weapon_prop/armor", 27);
/*
set("combat_msg", ({
     HIC"$N內力一吐，$w上的寒氣如海浪般將$n團團圍住！"NOR,
     HIY"$w在$N手上有如活物一般，以迅雷不及掩耳的速度攻向$n的$l"NOR,
    HIG"$N手中的$w突然消失！隨著$N的動作出現在$n的$l附近，接著就是狠狠一刺！"NOR,
     }) );
*/
   init_fork(70);


setup();
}     
