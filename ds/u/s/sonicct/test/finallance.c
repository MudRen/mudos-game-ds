#include <weapon.h>
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
inherit FORK;
void create()
{      
        set_name(HIR"�׵����j"NOR,({"final lance","lance","fork"}) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long",HIG"�o�O�@��׵��Z���C\n"NOR);
        set("value",100000);
        set("rigidity",10000);
        set("limit_str",50);
        set("limit_con",50);
        set("limit_dex",50);
        set("limit_int",50);
        set("no_drop",1);
        set("material", "blacksteel");
        set("wield_msg",HIR"$N�{�Ť@���A�ѤW���U�@��t�j�A$N�ⴤ$n�C\n"NOR);
        set("unwield_msg", RED"$N�N�⤤��$n���ѤW�@�ߡA$n�L�v�L�ܤF�C\n");
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
  message_vision(HIR" �׵����j�l���F�Ҧ��O�q�A��V�ĤH������I�I�I
   �y��$N"+damage+"�I���ˮ`�I�I�I�I\n"NOR,victim); 
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
