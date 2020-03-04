#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit WHIP;
void berserk(object me, object target);
void create()
{
  set_name(MAG"�����@"NOR, ({ "strange whip", "whip" }) );
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", @LONG
���@�D�O��~���k�P�L�b��æ�T���ɡA�b�@�ӦW���i�U�r�]�j�B�o�{��
�@�������W���q�ۡA�[�W��w��  �@�����̪��i�Q�����@�j�V�����k�P
�L�o�ѤH�a�ʦ~�����z�����A�Ҧ@�P�Ҧ������@���@�C
LONG
);
    set("value",20000);
    set("material", "steel");
	set("replica_ob", __DIR__"whip5");
    set("wield_msg", "$N�p���l�l���q�y����X�@��$n�A���񪺰��y�n�����V�A�E�ӤF�C\n"NOR);
    set("unwield_msg", "$N���_$n�@�ݡA$n���O���ͩR�@�몺��^�y�W�h�F�C\n"NOR);
  }
  set("replica_ob", __DIR__"whip5.c");
  set("limit_skill",60);
  set("weapon_prop/dex",2);
  set("weapon_prop/con",2);
  set("weapon_prop/str",2);
  set("weapon_prop/int",3);
  set("class_only",({"������"}));
  init_whip(75);
  setup();
}

void attack(object me,object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(random(5)) return;   //��Alick���n�D, ����v����
  berserk(me, victim);
  return;
}
void berserk(object me, object target)
{
  int atts = me->query("dex") / 60 ;
  int time = 2;
  if(!me->is_fighting()) return;
  if(me->query("ap") < 40)
  {
    message_vision("$N���_���䪺�@�l�A���G�Q�ϥ�ԣ���ۡC\n"NOR,me);
    write(WHT"[�A�ثe�����p�伵���F�����@������]\n"NOR);
    me->start_busy(1);
    return;
  }
  message_vision(HIW"\n\t$N��M�@���⤤�����@�A�l���Ѧa�������y�I\n"NOR,me,target);
  call_out("berserk_1",1,me,target,0,atts,time);
  return;
}

void berserk_1(object me, object target, int hit, int atts, int time)
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
  atts ? maxhit = me->query_dex() / 7 : maxhit = me->query_dex() / 12;
  temp_damage = me->query_damage() / 3;

  if(environment(me) != environment(target))
  {
    message_vision("$N�]����⤣�b�����F��աC\n",me);
    return;
  }

  for(i=1;i<maxhit;i++)
  {
    msg = "$N�������@�W�z�X�@���^�y�S�R�I";
    damage = random(temp_damage)+17;
    if( (me_att > ta_def * 3 && random(7)) || (me_att > ta_def * 3 / 2 && random(6)) || (me_att * 3 / 2 > ta_def && random(3)))
    {
      hit++;
      msg += MAG"�^�y�S�R�e��F$n������H�I "NOR""WHT"(��"HIW +chinese_number(hit)+ WHT"��������)�C"HIR"(" +damage+ ")\n" NOR;
      message_vision(msg,me,target);
      target->receive_damage("hp", damage, me);
      me->start_busy(1);
      ::attack();
    }
    else
    {
      if( me_att * 2 > ta_def && random(2))  //���@�{���v
      {
        msg += HIW"�i���Q$n"HIW"���L�F�C\n"NOR;
        message_vision(msg,me,target);
      }
      else
      {
        msg += HIR"�y��!�z���@�n�A�^�y�S�R�Q$n"HIR"����������_���F!!\n\n"NOR;
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
      message_vision(HIG"$N�����𤣨��A�����@�n�A���˦b�a�W�I"HIR"(�������J�]���i��)\n"NOR,me);
      me->start_busy(5);
      return;
    }
  }
  COMBAT_D->report_status(target);

  if(atts > 0)
  {
    if(me->query("ap") < 40)
    {
      message_vision(MAG"$N���񪺰��y�����A����������F�U�ӡC\n"NOR,me);
      return;
    }
    message_vision(HIG"\n\t$N�Q�F�@�f�A��A�չϧl�ާ�h���y��ӡA�S�µ�$n�ĤF�L�h�C\n\n"NOR,me,target);
    message_vision(WHT"�ϥX��"+time+"��"HIW"���^�y�S�R!!\n"NOR,me);
    atts--;
    time++;
    call_out("berserk_1",1,me,target,hit,atts,time);
    return;
  }
  damage = random(temp_damage) * 2 +temp_damage;
  message_vision(HIR"\n�l�d�b$N"HIR"�餺��"MAG"����"HIR"��M�z�o�}�ӡI�K�ɦ��|�q�I�I "HIR"("+damage+")\n\n"NOR,target);
  target->receive_damage("hp", damage, me);
  me->receive_damage("ap", 30, me);
  COMBAT_D->report_status(target);
  return;
}

