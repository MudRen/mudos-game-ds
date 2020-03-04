#include <ansi.h>
#include <combat.h>
#include <weapon.h>
inherit FORK;

void create()
{
  set_name(HIC"��ϩ"NOR, ({ "ice halbert","halbert" }) );
  set("long",@long
�j�y���ۤ@�h���ƪ������A�j�Y�W�O�ۤ@�����ժ��p�]�l�A���ʮɥ|
�P���|���G�H��C
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
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;

  if( (me->query("id") == "blue tengu") && (!random(7)) )
  {
    me->start_busy(1);
    message_vision(HIW"��ϩ�j�y�o�X�@�}�ե��I\n"NOR,me,victim);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
    COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),TYPE_BERSERK);
    return;
  }
  else if( me->query_dex()>30 && !random(10) )
  {
    message_vision("$N"HIW"������ϩ�N$nŢ�n�b�H�𤧤��A�@�ɦ�ʿ�w�I\n"NOR,me,victim);
    victim->add_busy(2);
  }
  return;
}
