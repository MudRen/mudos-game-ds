#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([
        "action": "$N�ϥX�y���мC�k�z�Ĥ@���i���L�j�j�A�|�_$w�V$n���h�C",
        "damage":                20,
        "dodge" :               -10,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "�C��",
        ]),

        ([
        "action": "$N�@���y���мC�k�z�ĤG���i��L�ߡj�A��$w���o$n���ߺۡC",
        "damage":                15,
        "dodge":                 10,
        "parry" :                10,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�@�ۡy���мC�k�z�ĤT���i�ٵL���j�A���ʵ�$w�ٸ�$n�����Y�C",
        "damage":                15,
        "dodge" :                -5,
        "parry" :               -10,
        "attact_type":  "bar",
        "damage_type":  "�ٶ�",
        ]),

        ([
        "action": "$N�ϥX�y���мC�k�z�ĥ|���i���L�Ρj�A���C��ۡA�Ѱ_�L�μC��A��$n��h�C",
        "damage":                16,
        "dodge" :                10,
        "parry" :               -15,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�@���y���мC�k�z�Ĥ����i�h�L���j�A�ݵM��X��F���@�C�C",
        "damage":                18,
        "dodge" :                20,
        "parry" :               -30,
        "attact_type":  "bar",
        "damage_type":  "�C��",
        ]),

        ([
        "action": "$N�@���y���мC�k�z�Ĥ����i�A�L���j�A���C�d�y�V$n���A�ӥh�C",
        "damage":                15,
        "dodge" :               -10,
        "parry" :                 5,
        "attact_type":  "bar",
        "damage_type":  "�A��",
        ]),

        ([
        "action": "$N�@���y���мC�k�z�ĤC���i���p���j�A�C�է֦p���A�@�۱��@�ۦV$n��h�C",
        "damage":                12,
        "dodge" :                20,
        "parry" :               -20,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�@���y���мC�k�z�ĤK���i�r�p��j�A���C�r���A�ݦ��ûR�A�o�O��r�C",
        "damage":                23,
        "dodge" :               -10,
        "parry" :               -15,
        "attact_type":  "bar",
        "damage_type":  "�C��",
        ]),
        ([
        "action": "$N�@���y���мC�k�z�ĤE���i���p�ѡj�A�uť$w�o�X�u�����v���T�A�l�O�Q���C",
        "damage":                18,
        "dodge" :               -14,
        "parry" :               -11,
        "attact_type":  "bar",
        "damage_type":  "�C��",
        ]),
        ([
        "action": "$N�@���y���мC�k�z�ĤQ���i�ڦp�s�j�A�C�۳s�������A�@�����@���C",
        "damage":                13,
        "dodge" :                10,
        "parry" :                10,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),
        ([
        "action": "$N�@���y���мC�k�z�ĤQ�@���i�w�p�s�j�A�w�𾮯��A���C�ݵM�@���A��䤣�ơC",
        "damage":                10,
        "dodge" :               -20,
        "parry" :                30,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),
        ([
        "action": "$N�@���y���мC�k�z�ĤQ�G���i�X�p���j�A�C�ۿ�w�A���X�����C",
        "damage":                10,
        "dodge" :                25,
        "parry" :                25,
        "attact_type":  "bar",
        "damage_type":  "���",
        ]),

});

int exert(object me, object target, string arg)
{
        int i,str,c,damage;
        string msg;
        object weapon;
        mapping type;
       
        weapon=me->query_temp("weapon");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("sword")!="hungchen-sword")
                        return notify_fail("�A�èS���ϥ�[���мC�k]�C\n");
                me->map_skill("sword");
                me->reset_action();
                write("�ޯ�[���мC�k]�w�����C\n");
                return 1;
        }
        if(!weapon) return notify_fail("�ϥ�[���мC�k]�����⤤�n���C�C\n");
        if(weapon->query("skill_type")!="sword") return notify_fail("�ϥί��Z�C�Z�����⤤�n���C�C\n");
        if(me->query_skill("sword")<20) return notify_fail("�A���C�k��¦�����L�k�ϥ�[���мC�k]�C\n");

        //�ĤG��exert
        if(me->query_skill_mapped("sword")=="hungchen-sword")
        {     
          if( !target ) target = offensive_target(me);
          if(!target)   return notify_fail("�A�w�g�b�ϥ�[���мC�k]�C\n");

          //�����ʪ��n�S�O�`�N�n�[�U�����.
          if(!target->can_fight(me))
             return target->can_fight(me);
          c = target->query_armor();
          if(me->query_skill("hungchen-sword")>80 && me->query("mp")>me->query("max_mp")/3)
          {
             msg = HIC "\n�u��$N�����Q���A�q�Ĥ@�����ܲĤQ�T���A�@��ܦ��A�涳�y���A�̫���ۡy���мC�k�z\n";
             msg += HIC "�̲צ��i�C�P�����šj�A$N���C�V$n��ݨ��A�C���{�{�A�o�X��䤧�n�A�w�n��F$n�ݤf\n";
             msg += HIC "�u�褤�v�B�u���áv�B�u�F�V�v�B�u���ʡv�B�u�B�Y�v�B�u�ժ��v�B�u�q���v�C�B�j�ޡC\n" NOR;
            if( random(100)>30)
            {
             str=me->query("str");
             damage = random(me->query_skill("hungchen-sword")) + me->query_damage() + random(str*2);
             damage -= random(target->query_armor());
             me->start_busy(2);
             msg += HIR "\n���G$n���ݤf�n�޳s���C�C�A���l�E�F�X�U�A�g�Q�A��A��M���ˤ����C\n" NOR;
             target->start_busy(3);
             damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
             target->receive_damage("hp",damage,me);
             COMBAT_D->report_status(target);
             message_vision(msg, me, target);
             i=(damage/10)+(str/2);
             me->receive_damage("mp",i);
            }
            else
            {
             me->start_busy(2);
             msg += HIW "\n$n�j�奢��A�a�n�j�s�A����k��A�T�V���u�}�F�A�o�]�~�o�y���K�C�C\n" NOR;
             message_vision(msg, me, target);
            }
          }
          else
          {
            msg = HIW "\n�A��[���мC�k]��������A����ϥίS��C\n"NOR;
            message_vision(msg, me, target);
          }     
       }
        if(me->query("mp")<10 || me->query("hp")<10) return notify_fail("�A�����骬�p�L�k�ϥ�[���мC�k]�C\n");
        me->map_skill("sword", "hungchen-sword");
        me->reset_action();
        message_vision("\n"HIW" $N���_��W��"+weapon->name()+"�A����}�����F�ӼC�Z�A�}�l�I�i[���мC�k]�C\n"NOR,me);
        me->receive_damage("mp",4);
        me->start_busy(1);
me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
        call_out("delay",10,me);
        return 1;
}

void delay(object me)
{
        object weapon;
        if(!me) return;
        weapon=me->query_temp("weapon");
        if(!weapon)
        {
                me->map_skill("sword");
                me->reset_action();
                remove_call_out("delay");
                return;
        }
        if(weapon->query("skill_type")!="sword")
        {
                me->map_skill("sword");
                me->reset_action();
                remove_call_out("delay");
                return;
        }
        if(me->query_skill_mapped("sword")!="hungchen-sword");
        {
         remove_call_out("delay");
         return;
        }
        if(me->query("mp")<4)
        {
                me->map_skill("sword");
                me->reset_action();
                message_vision("\n"HIW"$N����O�����L�k�~��ϥ�[���мC�k], �u�n��Τ@��C�ۡC\n"NOR,me);
                remove_call_out("delay");
                return ;
        }
        me->add("mp",-4);
        call_out("delay",10,me);
}

int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }
