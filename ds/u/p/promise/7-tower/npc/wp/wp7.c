//code by wilfred, wp_long by wilfred...Promise@DS 2004/06/07
#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;

void speed(object me, object target);

void create()
   {
  set_name(HIW"�V��"BLK"���X�C"NOR, ({ "mix six sword", "sword" }) );
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", @LONG
���C���W�j���L�Сy���X�C�z�Ҥ����X�Ӫ��@��C�A���ݳ��A
�C�����O�A�K�¦ܷ��A�s�C�`�]�O�H�Q��s���A�رa���C�ɡA
�������o�۷������N���𮧡A���G�s�P�D�ƪ��]�ᵲ�F�C
LONG
);
    set("value",20000);
    set("material", "steel");
    set("wield_msg", HIW"$N��X���X�C��A�j�a�̶}�l���w���ʤF�_�ӡC\n"NOR);
    set("unwield_msg", HIC"$N���_�F���X�C��A�j�a���𮧶}�l���_�F�_�ӡC\n"NOR);
  }
  set("limit_skill",100);
  set("weapon_prop/dex",4);
  set("weapon_prop/str",4);
  set("weapon_prop/con",1);
  set("weapon_prop/int",-3);
  set("class_only",({"�e����","�K����"}));
  init_sword(70);
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
    message_vision(HIW"$N�⤤�����X�C�}�l��ť�ϳ�C\n"NOR,me);
    write(HIR"�{�b�����骬�p���A����a���X�C�C\n"NOR);
    me->start_busy(1);
    me->command("unwield mix six sword");
    return;
  }
  message_vision(HIW"\n\t$N�C�Y�¤ѡA�f�����X�C�A�ߩw�������q�I�V���߳Z�C\n\n"NOR,me,target);
  message_vision(HIW""BLK"���趡�A�C��w�w��«�X���X�V������!!\n"NOR,me);
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
    msg = HIW+BLK"$N����⤤���C�A���t��X�C";

    damage = random(temp_damage)+20;
    if( (me_att > ta_def * 3 && random(7)) || (me_att > ta_def * 3 / 2 && random(6)) || (me_att * 3 / 2 > ta_def && random(3)))
    {
      hit++;
      msg += HIW+BLK"�}�}�V���𮧦b$n���⤤«�X"NOR"( "HIW"�� "NOR+GRN +hit+HIW" �D�C�� )�C"NOR+HIR"(" +damage+ ")\n" NOR;
      message_vision(msg,me,target);
      target->receive_damage("hp", damage, me);
      me->start_busy(1);
      ::attack();
    }
    else
    {
      if( me_att * 2 > ta_def && random(3))
      {
        msg += HIC"�C��D�D���Q$n�Ƹ�\n"NOR;
        message_vision(msg,me,target);
      }
      else
      {
        msg += HIY"�����p�P�l��A�q�e���������}���!!\n\n"NOR;
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
      message_vision(HIG"�j�j���V���𮧦b$N��o�ӥX�A�ϱo$N����@�L�۬[���O���A�I\n"NOR,me);
      me->start_busy(2);
      return;
    }
  }
  COMBAT_D->report_status(target);

  if(again > 0)
  {
    if(me->query("ap") < 40)
    {
      message_vision(NOR+BLU"$N���餺���V�����X������p�ɡA��ռȽw�F�U��!!\n"NOR,me);
      return;
    }
    message_vision(HIG"\n\t$N�W�իݵo�A�V������`�b���X�C���A�ֳt���g�X�ƹD�C��\n\n"NOR,me,target);
    message_vision(HIR"�g�X��"+chinese_number(index)+"�D�V�����X�C��C\n"NOR,me);
    again--;
    index++;
    call_out("speed_1",1,me,target,hit,again,index);
    return;
  }
  damage = random(temp_damage) * 2 +temp_damage;
  message_vision(NOR+GRN"\n$N�A���D����C�𪺶ˮ`�A�����˦a�C"HIR"("+damage+")\n\n"NOR,target);
  target->receive_damage("hp", damage, me);
  me->receive_damage("ap", 10, me);
  COMBAT_D->report_status(target);
  return;
}

