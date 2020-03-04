#include <weapon.h>
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
inherit FORK;
void create()
{      
        set_name(HIR"終結之槍"NOR,({"final lance","lance","fork"}) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long",HIG"這是一把終結武器。\n"NOR);
        set("value",100000);
        set("rigidity",10000);
        set("limit_str",50);
        set("limit_con",50);
        set("limit_dex",50);
        set("limit_int",50);
        set("no_drop",1);
        set("material", "blacksteel");
        set("wield_msg",HIR"$N臨空一指，天上落下一把聖槍，$N手握$n。\n"NOR);
        set("unwield_msg", RED"$N將手中的$n往天上一拋，$n無影無蹤了。\n");
        init_fork(1000);
        setup();
        }
}
void attack(object me,object victim)
{
int damage,hp,maxhp,mp,maxmp,ap,maxap;
  me=this_player();
  hp=me->query("hp");
  maxhp=me->query("max_hp");
maxmp=me->query("max_mp");
maxap=me->query("max_ap");
  mp=me->query("mp");
ap=me->query("ap");
 if ( hp < maxhp/2 )
 { 
damage=random(10) *(hp+mp+ap);
  message_vision(HIR" 終結之槍吸收了所有力量，刺向敵人的身體！！！
   造成$N"+damage+"點的傷害！！！！\n"NOR,victim); 
victim->receive_wound("body",70);
victim->receive_wound("head",40);
victim->receive_wound("left_leg",40);
victim->receive_wound("left_arm",40);
victim->receive_wound("right_leg",40);
victim->receive_wound("right_arm",40);
  victim->receive_damage("hp", damage, me );
me->receive_damage("hp",maxhp/3+maxmp/3+maxap/3);
me->receive_damage("mp",maxmp);
me->receive_damage("ap",maxap);
 return;    
 }
}
