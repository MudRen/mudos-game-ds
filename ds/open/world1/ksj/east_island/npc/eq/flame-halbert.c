#include <ansi.h>
#include <combat.h>
#include <weapon.h>
inherit FORK;

void create()
{
  set_name(HIR"�V�R"NOR, ({ "flame halbert","halbert" }) );
  set("long",@long
�j�y�U�N�H�H���V�A�j�Y�W�O�ۤ@���������p�]�l�A���ʮɤ��D��«
�R����աC
long);      
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",3000);
    set("volume",3);
    set("material","steel");
  }
  set("limit_str",30);
  set("limit_skill",50);
  set("limit_lv",20);
  set("weapon_prop/hit",5);
  init_fork(45,TWO_HANDED);
  setup();
}

void attack(object me, object victim)
{
  int damage;
  ::attack();
  if(!me) return;
  if(!victim) return;
  if( me->query("mp") < 25 ) return;
  damage=200+random(50)+(me->query_int())-(victim->query_shield());
  if (damage<0) damage=0;

  if( (me->query("id") == "red tengu") && (!random(7)) )
  {
    message_vision(HIR"�V�R�j�y�o�X�@�}�����I\n"NOR,me,victim);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_HEAVY);
    me->start_busy(1);
  }
  else if( me->query_dex()>30 && !random(10) )
  {
    message_vision("$N"HIR"���ʿV�R�Φ��@��������V$n�I�y��$n("+damage+")���N��\n"NOR,me,victim);
    victim->receive_damage("hp", damage,me);
    me->receive_damage("mp",20);
    me->add_busy(1);  
  }
  return;
}
