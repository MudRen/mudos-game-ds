//�L�ۤM�k(stone-blade) by Acme Sat Jan 1 2000

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void superpower(object me);
mapping *action = ({
        ([
        "action": "$N�@�ۡu���p�j���`�v�A",
        "damage":                12,
        "dodge" :                12,
        "parry" :                18,
        "attact_type":  "bio",  
        "damage_type":  "�M��",
        ]),
        ([
        "action": "$N�@�ۡu�H�k���ŪL�v",
        "damage":                15,
        "dodge" :                 5,
        "parry" :                25,
        "attact_type":  "bio",  
        "damage_type":  "�M��",
        ]),
        ([
        "action": "$N�@���u�[��V�ӲM�v",
        "damage":                20,
        "dodge" :                10,
        "parry" :                20,
        "attact_type":  "bio",  
        "damage_type":  "���",
        ]),
        ([
        "action": "$N�@���u�ѴH�ڿA�`�v",
        "damage":                18,
        "dodge" :                17,
        "parry" :                13,
        "attact_type":  "bio",  
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�@�ۡu�`�˷t�B�ϡv",
        "damage":                10,
        "dodge" :                15,
        "parry" :                15,
        "attact_type":  "bio",  
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�@���u���A����v",
        "damage":                15,
        "dodge" :                10,
        "parry" :                20,
        "attact_type":  "bio",  
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�@���u�t�O�H�ӫB�v",
        "damage":                12,
        "dodge" :                20,
        "parry" :                10,
        "attact_type":  "bio",  
        "damage_type":  "���",
        ]),

});
mapping *s_action = ({
        ([
        "action": HIB "$N�ϥX�L�ۯS��u�ݶ��k�ӵءv"NOR,
        "damage":                90,
        "dodge" :                20,
        "parry" :                40,
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
                        return notify_fail("�A�èS���I�i�L�ۤM�k\n");
                me->map_skill("unarmed");
                me->reset_action();
                write("�ޯ�L�ۤM�k�w�����C\n");
                return 1;
        }
    if ( !weapon )  return notify_fail("�⤤�n���M�~��νL�ۤM�k�C\n");
          if( weapon->query("skill_type")!="blade")
                return notify_fail("�⤤�n���M�~��νL�ۤM�k�C\n");

        if(me->query_skill_mapped("blade")=="stone-blade") 
                return notify_fail("�A�w�g�b�I�i�L�ۤM�k�F�C\n");
        if(me->query("ap")<10 || me->query("hp")<10 )
                 return notify_fail("�A�����骬�p�L�k�ϥνL�ۤM�k�C\n");
        me->map_skill("blade", "stone-blade");
        me->reset_action();
        message_vision(HIW "$N����⤤��"+weapon->query("name")+"�R�F�@�M�L�ۤM�k���u�_�M���v�C\n"NOR,me);
//        me->receive_damage("ap",5);
        me->start_busy(1);
 
        return 1;
}
  mapping query_action(object me, object weapon)
{
   if (me->query_temp("stone-blade/superpower") ) return action[random(sizeof(action))];
    if ( me->query_skill("stone-blade") >= 70  && me->query("ap") > 100 && random(100)>=79 )
    {
//        me->receive_damage("ap",50);
//        me->start_busy(1);
          return s_action[0];
    }
    if ( me->query_skill("stone-blade") >=90 && me->query("ap") > 200 && random(100)>=30 )
    {
//        me->receive_damage("ap",80);
          me->start_busy(2);
     me->skill_active( "stone-blade",(: call_other, __FILE__, "superpower",this_player():), 3);
    }
    return action[random(sizeof(action))];
}

void superpower(object me)
{
     int i;
     object target,weapon;
     string *limbs;
     me=this_player();
     weapon=me->query_temp("weapon");

     if( !target ) target = offensive_target(me);
     if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return;

     if(!me->is_fighting()) return;
     if( environment(me) != environment(target) ) return;

     if(me->query_temp("stone-blade/superpower") ) return;
     message_vision(HIW"$N�j�ܤ@�n�A�ϥX�����S�\\�C"NOR,me);
     for (i=0;i<=5;i++)
     {
       limbs = target->query("limbs");
       message_vision("$N�N�⤤"+weapon->query("name")+"�򴤡A��V$n��"+limbs[random(sizeof(limbs))]+"�C"NOR,me,target);
       if(me->query_skill("stone-blade") > random(30) )
       {
          COMBAT_D->report_status(target);         //���target���A
          target->receive_damage("hp",30+random(20));
       }
       else {
          message_vision("���O�Q$n�ή��׶}�C\n",me,target);
       }
     }
     me->delete_temp("active/superpower");
}

int practice_skill(object me) { return 1; }
int valid_learn(object me)    { return 1; }

