#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void superpower(object me,object target,int z,int damage);
mapping *action = ({
  ([
        "action": "$N�����@�ܡA��ä@��A�N$w��b�a�O�W�ĦV$n�A�K�ɨϥX�@��"HIC"�u�e���٤ѡv"NOR"�٦V$n",
        "damage":       30,  //�o�ӬO�ˮ`�j�ƪ��ʤ��� , ���O�ˮ`�I��
        "parry":        -10,
        "attact_type":  "bar",  // �]�w�ޯ઺�������� // �ͪ�(bio) �~��(bar) �]�k(wit)���F(sou)���(tec)
        "damage_type":  "�ٶ�", 
  ]),
  ([
        "action": "$N������ۤM�`�A�}�y�@�ޡA�ֳt���b��$n�����ǡA�ޤM�j�١A�@��"HIG"�u���s�}�v"NOR"���������b$n",
        "damage":       27,
        "parry":        -2,
        "attack_type":  "bar",
        "damage_type":  "�ٶ�",
  ]),
  ([
        "action": "��w����,���l�y�ɴ�F�W�ӡA�u��$w�_�X�F�@�D�����P��,�@��"HIR"�u���K�{�v"NOR"�@���d�����a�ۯP���U�N���n�T�N�V$n",
        "damage":       35,
        "parry":        -15,
        "attack_type":  "bar",
        "damage_type":  "�N��",
  ]),
  ([
        "action": "$N��$w�M���W�@�ᶶ�ո��F�W�h�A��l�@�B�A�ϥX�@��"HIB"�u�}�Ť@�u�v"NOR"�H�M�M���G�Ƭ��@��,���@���{�q��V$n��h",
        "damage":       37,
        "parry":       -20,
        "attack_type":  "bar",
        "damage_type":  "���",
  ])
});

int cast_skill(object me,string a, object target, string arg)
{
        int sk = me->query_skill("taingin-blade"),
            
target_armor, me_damage, target_dodge, me_dex, sum_damage, penuma_damage, g,damage;

        object weapon, *attack_targets;
        
        weapon = me->query_temp("weapon");
        
       if( arg=="off" )
        {
               if( me->query_skill_mapped("blade")!="taingin-blade" ) return notify_fail("�A�èS���b�I�i�ѼC�e�M�y�I\n");
                me->reset_action();
                write("�A�N�M�V�Ǥ@�ϡA�����F�u�ѼC�e�M�y�M�k�v���C��C\n");
                return 1;
        }

        if( me->query("ap") < 30 )
                return notify_fail("�A���骺���p����A�I�i�ѼC�e�M�y�C\n");

          if( !weapon ) return notify_fail("�A������M�n���I�i�u�ѼC�e�M�y�v�H\n");

          if( weapon->query("skill_type")!="blade" )
                return notify_fail("�A������M�n���I�i�u�ѼC�e�M�y�v�H\n");

        if( arg == "?" || arg == "help" )
        {
                tell_object(me, HIC"�u"HIC"�ѼC�e�M�y"HIC"�v�����ۦ� �@�r�g����(one-chop) �Q������(overlord-chop)�C\n"NOR);
                return 1;
        }

    if( me->query_skill_mapped("blade") == "taingin-blade" )
        {
                if( !target ) target = offensive_target(me);
                if( !target ) return notify_fail("�A�٦b�I�i�ѼC�e�M�y�I\n");
                if( !me->can_fight(target) ) return me->can_fight(target);

                target_armor = target->query_armor();
                target_dodge = target->query_skill("dodge")/3 + random(target->query_dex()/4);
                me_dex = me->query_dex() * 3;
                me_damage = me_damage + random(me_damage/4);
                sum_damage = me_damage - target_armor/2 - random(target_armor/2);
                // qc section
                if(wizardp(me)) tell_object(me,sprintf("  me_damage=%-d  sum_damage=%-d\n",me_damage,sum_damage));
                // end of qc section
                if( !arg || arg == "?" )
                {
                        tell_object(me, HIC"�u"HIC"�ѼC�e�M�y"HIC"�v�����ۦ� �@�r�g����(one-chop) �Q������(overlord-chop)�C\n"NOR);
                        return 1;
                }

  if( arg == "one-chop" )
                {
                        if( !me->is_fighting(target) ) me->kill_ob(target);
                        if( !target->is_fighting(me) ) target->kill_ob(me);
                       if( me->is_busy() ) return notify_fail("�A���b���I\n");
                        if( me->query_skill("taingin-blade") < 40 )
                                return notify_fail("�A���ѼC�e�M�y�٤����¼��I\n");
                        message_vision(HIG"\n$N��" + weapon->name() + "�ΤO�����J�a�O�A��M�g���j�@�A�A���ǫ_�X�F�@�D�s�����]��F�A�V$n�p�h
                  �A���թް_�F" + weapon->name() + "��q�@�n"HIY"�u��@�r�g���١�v"NOR"�C\n\n", me, target);
                        if( random(me_dex) > random(target_dodge)
                        && sum_damage = COMBAT_D->Merits_damage(me, target, sum_damage + random(sum_damage/3), "bar") )
                        {
                                target->receive_damage("ap", sum_damage/25, me);
                                target->receive_damage("hp", sum_damage, me);
                                target->start_busy(random(3));
                                message_vision(HIR"$n�@�Ӥ��p�ߡA�Q$N��"HIY"�u��@�r�g���١�v"NOR"�p�i�F�ݤf�A���G�ݤf�A��g�Q�I�I"NOR, me, target);
                                // QC
                                if(wizardp(me)) tell_object(me,sprintf("  (damage=%-d) \n",sum_damage));
                                // End QC
                                me->improve_skill("tainginr-blade", random(me->query_int()/5) + 5);
                                me->improve_skill("blade", random(me->query_int()/6) + 5 );
                                me->add_busy(2); 
                        }
                        else
                        {
                                message_vision(HIY"$n�W�W�i�i���{�F�}�A���]�~�����u���y�C"NOR, me, target);
                                target->imporve_skill("dodge", 5);
 sum_damage = 0;
                                me->add_busy(2); 
                        }
                     
               }

                if( arg == "overlord-chop" )
             {
        if( !me->is_fighting(target) ) me->kill_ob(target);
                if( !target->is_fighting(me) ) target->kill_ob(me);
                if (me->query_skill("taingin-blade") < 70)
                if( me->is_busy() ) return notify_fail("�A���b���I\n");
                return notify_fail("�A�r���ѼC�e�M�y����O�٨S��o��j���a�B�C\n");
              if(me->query("ap")<50) 
                return notify_fail("�A�ثe�����l�����A�L�k�ϥX���q�C\n");

                //�����ʪ��n�S�O�`�N�n�[�U�����.
           if(!me->can_fight(target)) return me->can_fight(target);
           if(!me->is_fighting(target) ) return notify_fail("�A�èS���b�԰����C\n");
                message_vision(HIW"$N��}�@��..��M���F�_��.......�V�ӶV��..�V�ӶV��....

               �a���W�ƪ��Ҥ@���L��...$N���W�F����..�����M���U�e�t�U�Y..\n\n"NOR,me);
                me->receive_damage("ap",15+random(16));
            me->start_busy(3);
                call_out("superpower",1,me,target,1,damage);
                return 1;
        }
        }
}
void superpower(object me,object target,int z,int damage)
 {
      string msg;
       if(!target) target = offensive_target(me);
       if(!target) return;
       if(!me) return;
       if(!me->is_fighting()) return;
       if( environment(me) != environment(target) ) return;
      if(!me->is_fighting(target)) me->kill_ob(target);

       z=me->query_skill("taingin-blade");

       msg = "$N��M�C�}�����A��q�@�n"+HIC+"�i���q�j"+NOR+"��"+HIY+"�i"+NOR+"�Q������"+HIY+"�j"+NOR+"��A\n";
       msg += "��Ѱʦa�A���������A�M���{�{�A$w���������b$�o���F�\�W.\n";
     message_vision(msg, me, target);

       if( z/3 + random(z) > random(target->query_skill("dodge")) )
       {
         damage = me->query_skill("blade") + random(me->query("str")) - target->query_armor()/2 - random(target->query_armor()/2) - (target->query("con"));
         if(damage>405) damage=405+((damage-405)/5);
         if(damage<40) damage=40+random(8);

         message_vision(HIR "\n���G$n���W�q�Y��}�Q�A�X�@�D�����b�H���˲��A�g�Q�F�n�h��C\n" NOR,me,target);

            // �W�[�����ˮ`���v�T
            damage = COMBAT_D->Merits_damage(me,target,damage,"bar");

            target->receive_damage("hp",damage,me);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                 tell_object(me,HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                 tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            COMBAT_D->report_status(targe
t);
       }
else {
            message_vision(HIW "\n$n��W�����A�j�n�y�s�A���L�F�o�۶��q�C\n" NOR,me,target);
}

}

        if( !me->skill_active( "taingin-blade",(: call_other, __FILE__, "delay_0", me :), 6) )
                return notify_fail("�A�����ѼC�e�M�y���ʧ@�٨S�����I\n");
          
        message_vision(HIY"$N���_�⤤"+weapon->query("name")"�A�A�I�i�X�ѼC�e�M�y�I\n"NOR,me);
        me->map_skill("blade", "taingin-blade");
        me->receive_damage("ap", 10);
        me->reset_action();
        me->start_busy(1);
        return 1;
}

void delay_0(object me)
{
        object me_weapon;
        int sk = me->query_skill("taingin-blade");
 if( !me ) return;

        me_weapon=me->query_temp( "weapon" );

        if( !me_weapon || me_weapon->query("skill_type") != "blade" )
        {
                me->map_skill("blade");

                me->reset_action();
                return;
        }

        if( me->query_skill_mapped("blade")!="taingin-blade" ) return;

        if( me->query("ap") < 20 )
        {
                me->map_skill("blade");
                me->reset_action();
                tell_object(me, "�A����O�w�����~��I�i�u�ѼC�e�M�y�v�F�I\n");
                return ;
        }

        if( me->is_fighting() ) me->receive_damage("ap", 10);
me->skill_active( "taingin-blade",(: call_other, __FILE__, "delay_0", me :), 6);



}

}
int valid_learn(object me)
{
        return 1;
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return 1;
}
int improve_limite(object ob)
{
        return 100;
}
