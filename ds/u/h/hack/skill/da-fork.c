  //�s�W �B�~�W�[ bagi force exp -by tmr- 2000/4/2
  //�s�W �l���S��  -by Tmr- 2000/4/3

#include <ansi.h>
  inherit SKILL;
  inherit SSERVER;

  mapping *action = ({
          ([
          "action": "$N�@���⤤$w�A�@��"+HIW"�y"+NOR"�ﶳ�g��"+HIW"�z"+NOR"�{�Y�q���p�w���a��V$n�ݤ��n�`",
          "damage":                20,
          "dodge" :                20,
          "parry" :                20,
          "attact_type":  "bar",  
          "damage_type":  "���",
          ]),

          ([
          "action": "�u��$N�⤤$w�ɵo�ƤV��l�A���M�@��"+HIW"�y"+NOR"���s�D�W"+HIW"�z"+NOR"����$n�ݡB���n�`",
          "damage":                20,
          "dodge" :                10,
          "parry" :                15,
          "attact_type":  "bar",  
          "damage_type":  "���",
          ]),

          ([
          "action": "�u��$N�L�@�����A�@��"+HIW"�y"+NOR"�����I�B"+HIW"�z"+NOR"�A�⤤$w�D�_�Ʀ��J�j�j��A�ɸn$n���e�ƳB�n�`",
          "damage":                25,
          "dodge" :                10,
          "parry" :                20,
          "attact_type":  "bar",  
          "damage_type":  "���",
          ]),

          ([
          "action": "$N�~�a�N�⤤$w��L�ѻڵe�F�Ӫ����A�@��"+HIW"�y"+NOR"���i¶��"+HIW"�z"+NOR"��$n�Y���۩I",
          "damage":                30,
          "dodge" :                10,
          "parry" :                10,
          "attact_type":  "bar",  
          "damage_type":  "�A��",
          ]),

          ([
            "action": "$N�I�i�@��"+HIW"�y"+NOR"�^�����v"+HIW"�z"NOR+"�A�j�դ@�ܡA�{�Y�D�گ�H�_������쪽��$n�I���n�`",
          "damage":                 25,
          "dodge" :                -10,
          "parry" :                -10,
          "attact_type":  "bar",  
          "damage_type":  "���",
          ]),

          ([
          "action": "$N�r�ܤ@�n�A�g�R�⤤$w�A�n�ɤۤƥX�ƹD�a����l�A�@��"+HIW"�y"+NOR"�ɱa¶�y"+HIW"�z"NOR+"����$n�U�L",
          "damage":                30,
          "dodge" :                10,
          "parry" :                10,
          "attact_type":  "bar",  
          "damage_type":  "���",
          ]),

          ([
          "action": "$N�@��"+HIW"�y"+NOR"��P�|��"+HIW"�z"+NOR"�A��W$w�ѤU���W�@�D�A�l���L��a��$n���V��h",
          "damage":                35,
          "dodge" :                20,
          "parry" :                20,
          "attact_type":  "bar",  
          "damage_type":  "���",
          ]),
  });

  int exert(object me, object target, string arg)
  {
          string msg;
          object weapon,*enemy;
                  
          weapon=me->query_temp("weapon");
          if (!weapon) 
                  return notify_fail("�A�o���K�j�~��I�i�u�j�j�Z�v�C\n");
          if(weapon->query("skill_type")!="fork") 
                  return notify_fail("�A�o���K�j�~��I�i�u�j�j�Z�v�C\n");

          if(arg=="off" )
          {
                  if( me->query_skill_mapped("fork")!="da-fork")
                          return notify_fail("�A�èS���ϥΡu�j�j�Z�v�C\n");
                  me->map_skill("fork");
                  me->reset_action();
                  write("�ޯ�u�j�j�Z�v�w�����C\n");
                  return 1;
          }
          if( me->query_skill_mapped("fork")=="da-fork")
                  return notify_fail("�A���b�ϥΡu�j�j�Z�v�C\n");
          if(me->query_skill("da-fork")<10) 
                  return notify_fail("�̧A�ثe���\\�O�A�|�����I�i�u�j�j�Z�v�C\n");
          if(me->query("ap")<10 || me->query("hp")<10) 
                  return notify_fail("�A�����骬�p�L�k�ϥΡu�j�j�Z�v�C\n");

          me->map_skill("fork", "da-fork");
          me->reset_action();
          message_vision("\n"HIW"$N�⤤"+weapon->query("name")+HIW "�~�a�@�_�A�j�j�Z��l�n�ɥ|���ӥX�I�I\n"NOR,me);
          me->receive_damage("ap",10);
          me->start_busy(1);
          return 1;
  }

  int valid_learn(object me) {    return 1;       }

  mapping query_action(object me, object weapon)
  {
          int lv,sk,fsk,i,cost,h,power;
           lv =me->query("level");
           sk =me->query_skill("da-fork");
          fsk =me->query_skill("bagi_force");
            h =me->query_skill("horse-steps");

          if(me->is_fighting() && !me->is_busy() ) { 
          
          // �B�~�W�[bagi_force exp
          if(sk > 50 && h > 50 && fsk < 80 && lv > 25 && random(3)==1     )
          {
                  i=me->query_int()+me->query_con();
                  i=i/4+random(i/3);
                  me->improve_skill("bagi_force",i);
          }

          //�l��

          if(me->query_temp("exert-da-fork")!=1
          && sk > 80  && h > 80   && me->query("hp") > 200  
          && me->query("ap") > 200  && random(100) < 20 ) {
          power=sk+h;
            power=power/2+random(power/3);
          me->add_temp("apply/damage",power);
          me->receive_damage("ap",20 );
          me->receive_damage("hp",20 );
          message_vision(HIW"$N���B�@��A�@�D�j�j��l��g�ӥX�I�I\n" NOR ,me,weapon);

          me->set_temp("exert-da-fork",1); //�]�wtemp �H�K�h���l��..
          me->attack();
          me->delete_temp("exert-da-fork");
          me->start_busy(1);
          me->add_temp("apply/damage",-power);
          }

          }

          return action[random(sizeof(action))];
  }

  int practice_skill(object me) { return 1; }

  int improve_limite(object ob)
  {
          int a;
          a=ob->query_int();
          a=70+a;
          return a;
  }

