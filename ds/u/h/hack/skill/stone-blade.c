//�Y�ۤM�k(stone-blade) by Acme Sat Jan 1 2000

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void superpower(object me);
mapping *action = ({
        ([
        "action": "$N�@�ۡu���p�j���`�v�N�⤤��$w���A�V$n��$l�A�M�դ@��A�A�V$n��$l",
        "damage":                12,
        "dodge" :                12,
        "parry" :                18,
        "attact_type":  "bio",  
        "damage_type":  "�M��",
        ]),
        ([
        "action": "$N�⤤$w�o�X�@�}�H���A�@�ۡu�H�k���ŪL�v�A���_��������V$n",
        "damage":                15,
        "dodge" :                 5,
        "parry" :                25,
        "attact_type":  "bio",  
        "damage_type":  "�M��",
        ]),
        ([
        "action": "$N�@���u�[��V�ӲM�v�A�g�R�⤤$w�A�@�����ۤ@������V$n",
        "damage":                20,
        "dodge" :                10,
        "parry" :                20,
        "attact_type":  "bio",  
        "damage_type":  "���",
        ]),
        ([
        "action": "$N�M�շ��w�A���l�O�o�p�j����L�k���סA�@���u�ѴH�ڿA�`�v�A�V$n",
        "damage":                18,
        "dodge" :                17,
        "parry" :                13,
        "attact_type":  "bio",  
        "damage_type":  "�A��",
        ]),

        ([
        "action": "$N���ʤ⤤$w����$n$l�A�M�լ�M�@��A�@�ۡu�`�˷t�B�ϡv���A$n��$l",
        "damage":                10,
        "dodge" :                15,
        "parry" :                15,
        "attact_type":  "bio",  
        "damage_type":  "�A��",
        ]),

        ([
        "action": "$N�@���u���A����v�A���R�ۤ��⪺$w�A�M�զ������b����A����V$n��$l",
        "damage":                15,
        "dodge" :                10,
        "parry" :                20,
        "attact_type":  "bio",  
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�⤤$w����$n��$l�A�@���u�t�O�H�ӫB�v�A�p�å۱Y�������V$n",
        "damage":                12,
        "dodge" :                20,
        "parry" :                10,
        "attact_type":  "bio",  
        "damage_type":  "�A��",
        ]),

});
mapping *s_action = ({
        ([
        "action": 
          "$N�ϥX�Y�ۤM�k�������q"HIB"�u�ݶ��k�ӵءv"NOR"�A��M�m��A�����D��$n����\n"NOR
         +    "\t$N�M�զp�g��������A�V$n��$l"NOR,
        "damage":                80,
        "dodge" :                30,
        "parry" :                30,
        "hit" :                  45,
        "attact_type":  "bio",  
        "damage_type":  "���",
        ]),
});

int exert(object me, object target, string arg)
{
        string msg;
        object weapon;
        
        weapon=me->query_temp("weapon");
        if(arg=="off" )
        {
                if( me->query_skill_mapped("blade")!="stone-blade")
                        return notify_fail("�A�èS���I�i�Y�ۤM�k\n");
                me->map_skill("blade");
                me->reset_action();
                write("�ޯ�Y�ۤM�k�w�����C\n");
                return 1;
        }
    if ( !weapon )  return notify_fail("�⤤�n���M�~��νY�ۤM�k�C\n");
          if( weapon->query("skill_type")!="blade")
                return notify_fail("�⤤�n���M�~��νY�ۤM�k�C\n");

        if(me->query_skill_mapped("blade")=="stone-blade") 
                return notify_fail("�A�w�g�b�I�i�Y�ۤM�k�F�C\n");
        if(me->query("ap")<10 || me->query("hp")<10 )
                 return notify_fail("�A�����骬�p�L�k�ϥνY�ۤM�k�C\n");
        me->map_skill("blade", "stone-blade");
        me->reset_action();
        message_vision(HIW "$N����⤤��"+weapon->query("name")+"�R�F�@�M�Y�ۤM�k���u�_�M���v�C\n"NOR,me);
        me->receive_damage("ap",5);
        me->start_busy(1);
 
        return 1;
}
mapping query_action(object me, object weapon)
{
    if (me->query_temp("stone-blade/superpower") ) return action[random(sizeof(action))];
    if ( me->query_skill("stone-blade") >=90 && me->query("ap") > 100 && random(200)>=185 )
    {
        me->start_busy(2);
        me->skill_active( "stone-blade",(: call_other, __FILE__, "superpower",me:), 3);
    }
    if ( me->query_skill("stone-blade") >= 50  && me->query("ap") > 50 && random(200)>=170 )
    {
        me->receive_damage("ap",10);
        me->start_busy(1);
        return s_action[0];
    }
    return action[random(sizeof(action))];
}

void superpower(object me)
{
     int i,damage;
     object target,weapon;
     string *limbs;
     weapon=me->query_temp("weapon");

     if( !target ) target = offensive_target(me);

    if( environment(me) != environment(target) ) return;
     if(!me->is_fighting()) return;

message_vision(HIW"$N�j�ܤ@�n�A�ϥX�m�֤M�����n�A�⤤"+weapon->query("name")+"�R�X�@���ե��C\n"NOR,me);
     for (i=0;i<=4;i++)
     {
       damage=30+random(20);
       limbs = target->query("limbs");
       message_vision("$N�N�⤤"+weapon->query("name")+"�򴤡A��V$n��"+limbs[random(sizeof(limbs))]+"�C"NOR,me,target);
           switch( random(20) ) {
           case 0:
               message_vision("���G�O�D�Ӥp�èS���y���ˮ`�C\n",me,target);
               break;
           case 1:
               message_vision("���O�Q$n��}�F�C\n",me,target);
               break;
           case 2:
               message_vision("���O�Q$n���F�a���}�F�C\n",me,target);
               break;
           case 3:
               message_vision("���O�Q$n�ή��׶}�C\n",me,target);
               break;
           default:
               message_vision("$n�G�I�@�n�A�Q�o�@�M���A���F�I�I",me,target);
               target->receive_damage("hp",damage);
             if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                     tell_object(me,HIY"("+damage+")"NOR"\n");
             COMBAT_D->report_status(target);         //���target���A
             if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                     tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp") +")");
            if(wizardp(me) && me->query("env/debug")) 
                     tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n"); 
               me->receive_damage("ap",15+random(6));
               break;
           }
     }
     me->delete_temp("stone-blade/superpower");
}

int practice_skill(object me) { return 1; }
int valid_learn(object me)    { return 1; }

