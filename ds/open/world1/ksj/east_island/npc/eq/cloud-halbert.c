#include <ansi.h>
#include <combat.h>
#include <weapon.h>
inherit FORK;

void create()
{
  set_name(HIW"���G"NOR, ({ "cloud halbert","halbert" }) );
  set("long",@long
�j�y��¶�۲H�H�����A�j�Y�W�O�ۤ@���ǥժ��p�]�l�A���ʮɥ|�P�a
�g�p�b�����C
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
  init_fork(50,TWO_HANDED);
  setup();
}

void attack(object me, object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;

  if( (me->query("id") == "white tengu") && (!random(7)) )
  {
    me->start_busy(1);
    message_vision(HIW"���G�_�X�j�q�����A�H�Y�\\�h�j�y�q�������ӥX�I\n"NOR,me,victim);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
  }
  else if( me->query_int()>50 && !random(10) && (me->query("hp")<me->query("max_hp")*49/50) )
  {
    message_vision(HIC"���G�_�X�@�}�H�Ū����ϡA$N���W�ˤf���G���I¡�X�I\n"NOR,me,victim);
    me->receive_heal("hp", (me->query("max_hp"))*1/50);
    me->add_busy(1);
  }
  return;
}
