/************************************************/
/* SK NAME: �ܻR�C���C�Z         EDIT TIME: 6/29*/ 
/* EDIT BY: Promise@DS           FOR: NPC�ϥ�   */
/* SK �C�۱ԭz: �_�Z �i���s�šj               */
/*              �L�Z �i�_�b����j               */
/*              �ѳZ �i���Ƶ���j               */
/*              �v�Z �i�����]�j               */
/*              ��Z �i�������j               */
/*              ���Z �i�������j               */
/*              �׳Z �i���[�L���j               */
/* �̲�SUPER:�K��C�� [�H�ݩʤ��������B����B����*/
/*                               �ߨ��BHP�BAP�BMP*/
/*                               �Լ��BSOU�BBIO  */
/*                       �ޯत��Sword�Bdodge    */
/*                               Combat���D      */
/************************************************/

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
inherit F_UNIQUE;
#define SKILL_NAME "�ܻR�C���C�Z"

void delay(object me);
void speed(object me, object target);
void speed_1(object me, object target, int hit, int again, int index);

mapping *action = ({
        ([
        "action": "$N���B�������R�X"HIC"�_�Z"NOR" �i���s�šj�A�u��$n��M�����ұ��A�@�L���Ƥ��O�C",
        "damage":                10,
        "dodge" :               10,
        "parry" :               10,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),
        ([
        "action": "$N�_�����t���b�V$n�A�R�X"HIY"�L�Z"NOR" �i�_�b����j�A�u��$n��M�����ұ��A�@�L���Ƥ��O�C",
        "damage":                20,
        "dodge":                 -10,
        "parry" :                -6,
        "attact_type":  "bar",
        "damage_type":  "�h�B�A��",
        ]),

        ([
        "action": "�u��$N������K�P�몺���Ҥ��w�A�R�X"HIG"�ѳZ"NOR" �i���Ƶ���j�A�u��$n��M�����ұ��A�@�L���Ƥ��O�C",
        "damage":                30,
        "dodge" :                -5,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "�ٶ�",
        ]),

        ([
        "action": "$N��w�������R�X"HIR"�v�Z"NOR" �i�����]�j�A�u��$n��M�����ұ��A�@�L���Ƥ��O�C",
        "damage":                40,
        "dodge" :                10,
        "parry" :               15,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�����y�A�R�X"HIM"��Z"NOR" �i�������j�A���C�H�������A�I�V$n���ݸ��n�ޡI ",
        "damage":                50,
        "dodge" :               -20,
        "parry" :                30,
        "attact_type":  "bar",
        "damage_type":  "����",
        ]),

        ([
        "action": "$N�I�X"HIB"���Z"NOR" �i�������j�A���C��⭸�X�A�p�C�s�뿬���C�t�A�}�Ůg�V$n���ݤf�I",
        "damage":                60,
        "dodge" :               -10,
        "parry" :                15,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�I�X"HIW"�׳Z"NOR" �i���[�L���j�A�C�W�����A�C�զp���A�@������r��$n�����V���I",
        "damage":                70,
        "dodge" :                20,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "�A��",
        ]),

       });

int exert(object me, object target, string arg)
{
        int sk,damage;
        object weapon;
        mapping type;
        sk=me->query_skill("dance-sword");
        weapon=me->query_temp("weapon");
        if( me->is_ghost() ) return notify_fail("�����H...?\n");
        if (!weapon) return notify_fail("�A�n��@��C�~��I�i�ܻR�C���C�Z�C\n");
        if(weapon->query("skill_type")!="sword") return notify_fail("�A�⤤�������C�~��I�i�ܻR�C���C�Z�C\n");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("sword")!="dance-sword")
                        return notify_fail(HIR"�A�S�B��ܻR�C���C�Z�C\n"NOR);
                me->map_skill("sword");
                me->reset_action();
                write(HIW"�A�w�����ϥΩܻR�C���C�Z�F�C\n"NOR);
                return 1;
        }

        if(me->query_skill("dance-sword")<5) return notify_fail("�A�ثe��ܻR�C���C�Z�@�L�����C\n");
        if(me->query("ap")<100 || me->query("hp")<100) return notify_fail("�A�����骬�p�L�k�ϥΩܻR�C���C�Z�C\n");


        //�ĤG��exert
        if(me->query_skill_mapped("sword")=="dance-sword")
        {
        if( me->is_ghost() ) return notify_fail("�����H...?\n");
                if( !target ) target = offensive_target(me);
                if (!me->is_fighting()) 
                return notify_fail("�A�w�B��F�ܻR�C���C�Z�C\n");
                if (me->query_skill("dance-sword") < 90)
                return notify_fail("�ثe�A�ٵL�k�ϥΥP���E�K��C���C\n");
              if(me->query("ap")<100) 
                return notify_fail("�A�ثe�����l�����A�L�k�ϥΥP���E�K��C���C\n");
              if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("�A�S���b�԰����C\n");
                message_vision(HIY"$N�K�N�ޥ͡A�}�l�B�_�P���E�K��C���C\n\n"NOR,me);
                me->receive_damage("ap",200+random(50));
                me->start_busy(2);
                call_out("speed",1,me,target,1,damage);
                return 1;
        }
        
        if(!me->skill_active( "dance-sword",(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("�A�ϥX�ܻR�C���C�Z���ʧ@�٨S�����C\n");
        me->map_skill("sword", "dance-sword");
        me->reset_action();
        message_vision("\n"HIW"$N���_�⤤��"+weapon->query("name")+HIW "�A�}�l�B��ܻR�C���C�Z�C\n"NOR,me);
        me->receive_damage("ap",20);
        me->start_busy(2);
//      me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
        return 1;
}

void speed(object me, object target)
{
  int again = me->query_dex() / 60 ;
  int index = 2;
  if(!me->is_fighting()) return;

  if(me->query("ap") < 40)
  {
    message_vision(HIW"$N�⤤���C�}�l��ť�ϳ�C\n"NOR,me);
    write(HIR"�{�b�����骬�p���A�X�ϥX�K��C��\n"NOR);
    me->start_busy(1);
    me->command("unwield mix six sword");
    return;
  }
  message_vision(HIW"\n\t$N����K�P�R�B�A�H�X�n�����������B��P�����𬰪�A�٨����A�ϥX "HIY"�P��"HIW"�i"NOR+GRN"�K��C��"HIW"�j�I�I\n\n"NOR,me,target);
  message_vision(HIW+BLK"�o�@��D�D�C��Ƭ���A����ͬ��C��A��D�V�X�A���H�����g���C\n"NOR,me);
  call_out("speed_1",1,me,target,0,again,index);
  return;
}
void speed_1(object me, object target, int hit, int again, int index)
{
  string msg;
  int mcexp,tacexp,bio,sou,mhp,map,maxhit, temp_damage, damage,tar_damage ,i;
  if(!me) return;
  if(!target || !me->is_fighting())
  {
    message_vision("$N�N�ʧ@�����F�C\n",me);
    return;
  }

  mcexp = me->query("combat_exp");
  tacexp = target->query("combat_exp");
  mhp = me->query("max_hp") /100;
  map = me->query("max_ap") /100;
  bio = me->query("Merits/bio") *10;
  sou = me->query("Merits/sou") *10;
  again ? maxhit = me->query_dex() / 7 : maxhit = me->query_dex() / 12;
  temp_damage = me->query_damage() /10 + mhp + map + bio + sou;
  tar_damage = target->query_damage();
  if(environment(me) != environment(target))
  {
    message_vision("$N�]����⤣�b�����F��աC\n",me);
    return;
  }
  for(i=1;i<maxhit;i++)
  {
    msg = HIW+BLK"$N����⤤���C�A���t��X�C";

    damage = random(temp_damage)+20;
    if( (mcexp > tacexp * 3 && random(7)) || (mcexp > tacexp * 3 / 2 && random(6)) || (mcexp * 3 / 2 > tacexp && random(3)))
    {
      hit++;
      msg += HIW+BLK"�}�}�K�N�𮧦b$n"BLK"���⤤«�X"NOR"( "HIW"�� "NOR+GRN +hit+HIW" �D�C�� )�C"NOR+HIR"(" +damage+ ")\n" NOR;
      message_vision(msg,me,target);
      target->receive_damage("hp", damage, me);
      me->start_busy(1);
          }
    else
    {
      if( mcexp * 3 > tacexp && random(3))
      {
        msg += HIC"�C���D�D���Q$n�Ƹ�\n"NOR;
        message_vision(msg,me,target);
      }
      else
      {
        msg += HIY"$n�����p�P�l��A�q�e���������}���!!\n\n"NOR;
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
      message_vision(HIG"�j�j���K�N�𮧦b$N��o�ӥX�A�ϱo$N����@�L�۬[���O���A�I\n"NOR,me);
      me->start_busy(2);
      return;
    }
  }
  COMBAT_D->report_status(target);

  if(again > 0)
  {
    if(me->query("ap") < 40)
    {
      message_vision(NOR+BLU"$N���餺���K�N�𮧮����p�ɡA��ռȽw�F�U��!!\n"NOR,me);
      return;
    }
    message_vision(HIG"\n\t$N�W�իݵo�A�K�N����`�b�C���A�ֳt���g�X�ƹD�C��\n\n"NOR,me,target);
    message_vision(HIR"�g�X��"+chinese_number(index)+"�D�K��C���C\n"NOR,me);
    again--;
    index++;
    call_out("speed_1",1,me,target,hit,again,index);
    return;
  }
  damage = random(temp_damage) * 2 +temp_damage;
  message_vision(NOR+GRN"\n$N�A���D����C�����ˮ`�A�����˦a�C"HIR"("+damage+")\n\n"NOR,target);
  target->receive_damage("hp", damage, me);
  me->receive_damage("ap", 10, me);
  COMBAT_D->report_status(target);
  return;
}


void delay(object me)
{
        object weapon;
        if( !me ) return;
        
        weapon=me->query_temp( "weapon" );

        if( !weapon || weapon->query("skill_type") != "sword" )
        {
                me->map_skill("sword");
                me->reset_action();
                return;
        }

        if( me->query_skill_mapped("sword")!="dance-sword" )
        {
                return;
        }

        if( me->query("ap")<20 )
        {
                me->map_skill("sword");
                me->reset_action();
                message_vision("\n"HIW"$N"HIR"��O�����w�w�����F�U�ӡC\n"NOR,me);
                return ;
        }

        if( me->is_fighting() ) me->receive_damage("ap",5);
        me->skill_active( "dance-sword",(: call_other, __FILE__, "delay", me :), 8);
}
int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
