#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;

void speed(object me, object target);

void create()
{
  set_name(CYN"�ֳ��C"NOR, ({ "sho-in sword", "sword" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", @LONG
���C���W�j���L�Сy�ӷ��C�z�Ҥ����X�Ӫ��@��C�A���ݳ��A
�C�����O�A�K�¦ܷ��A�s�C�`�]�O�H�Q��s���A�رa���C�ɡA
�������o�۷������N���𮧡A���G�s�P�D�ƪ��]�ᵲ�F�C
LONG
);
    set("value",20000);
    set("material", "steel");
    set("wield_msg", "$N�ޥX$n�A�C���z�X�@�p�®�A�P�򪺪Ů�]�̰ʤF�_�ӡC\n"NOR);
    set("unwield_msg", "$N�N$n���^�C�T���C\n"NOR);
  }
  set("limit_skill",70);
  set("weapon_prop/dex",4);
  set("class_only",({"�e����","���Z��"}));
  init_sword(60);
  setup();
}

void attack(object me,object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(random(6)) return;
  speed(me, victim);
  return;
}

void speed(object me, object target)
{
  int again = me->query_dex() / 60 ;
  int index = 2;
  if(!me->is_fighting()) return;

  if(me->query("ap") < 40)
  {
    message_vision("$N���C����L��A���G�Q�@����C\n"NOR,me);
    write(WHT"[�A�����骬�p�L�k�ϥίS��]\n"NOR);
    me->start_busy(1);
    return;
  }
  message_vision(HIW"\n\t$N��M���èI�y�A�f���ֳ��C�A�µ�$n�ĤF�L�h�C\n\n"NOR,me,target);
  message_vision(HIW""BLK"�C���ɵo�@�ѿ@�p�����P�[��!!\n"NOR,me);
  call_out("speed_1",1,me,target,0,again,index);
  return;
}

void speed_1(object me, object target, int hit, int again, int index)
{
  string msg;
  int me_att, ta_def, maxhit, temp_damage, damage, i;

  if(!me) return;
  if(!target || !me->is_fighting())
  {
    message_vision("$N�N�ʧ@�����F�C\n",me);
    return;
  }

  me_att = me->query("combat_exp");
  ta_def = target->query("combat_exp");
  again ? maxhit = me->query_dex() / 7 : maxhit = me->query_dex() / 12;
  temp_damage = me->query_damage() / 3;

  if(environment(me) != environment(target))
  {
    message_vision("$N�]����⤣�b�����F��աC\n",me);
    return;
  }

  // �S�𳡥�
  for(i=1;i<maxhit;i++)
  {
    msg = "$N�ֳt����X�@�C�I";
    damage = random(temp_damage)+20;
    if( (me_att > ta_def * 3 && random(7)) || (me_att > ta_def * 3 / 2 && random(6)) || (me_att * 3 / 2 > ta_def && random(3)))
    {
      hit++;
      msg += HIW""BLK"�®�b$n"HIW""BLK"�����W�������z�}!! "NOR""WHT"(RUSH "HIW +hit+ NOR""WHT" HIT)�C"HIR"(" +damage+ ")\n" NOR;
      message_vision(msg,me,target);
      target->receive_damage("hp", damage, me);
      me->start_busy(1);
      ::attack();
    }
    else
    {
      if( me_att * 2 > ta_def && random(3))
      {
        msg += HIW"�i���Q$n"HIW"���L�F�C\n"NOR;
        message_vision(msg,me,target);
      }
      else
      {
        msg += HIR"�y��!�z���@�n�A�®�ϦӳQ$n"HIR"�_�}�F!!\n\n"NOR;
        message_vision(msg,me,target);
        COMBAT_D->report_status(target);
        me->start_busy(3);
        target->start_busy(0);
        return;
      }
    }
    target->start_busy(2);
    me->start_busy(2);
    me->receive_damage("ap", 10, me);
    if(me->query("ap") < 40)
    {
      message_vision(HIG"$N�����l���ӹL�d�A�����@�n�A���˦b�a�W�I\n"NOR,me);
      me->start_busy(2);
      return;
    }
  }
  COMBAT_D->report_status(target);

  if(again > 0)
  {
    if(me->query("ap") < 40)
    {
      message_vision(HIR"$N�Ķդ����A����������F�U�ӡC\n"NOR,me);
      return;
    }
    message_vision(HIG"\n\t$N�e�h�T�j�B�A������a���꼳���աA�S�µ�$n�ĤF�L�h�C\n\n"NOR,me,target);
    message_vision(WHT"�ϥX��"+chinese_number(index)+"��"HIW"���P�[��!!\n"NOR,me);
    again--;
    index++;
    call_out("speed_1",1,me,target,hit,again,index);
    return;
  }
  damage = random(temp_damage) * 2 +temp_damage;
  message_vision(HIW"\n�ݯd�b$N"HIW"�餺���¦��l��M�z�o�}�ӡI�K�ɦ��|�q�I�I "HIR"("+damage+")\n\n"NOR,target);
  target->receive_damage("hp", damage, me);
  me->receive_damage("ap", 10, me);
  COMBAT_D->report_status(target);
  return;
}

