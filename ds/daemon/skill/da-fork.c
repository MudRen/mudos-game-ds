//�s�W �B�~�W�[ bagi force exp -by tmr- 2000/4/2
//�s�W �l���S��  -by Tmr- 2000/4/3
/* �S�� By Tmr -2002/04/01 */

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
      int damage;
    int hst,hslv;
    string *limbs=({
                       "�Y��", "�V��", "�ݤf", "���", "����", "�k��", "���u",
                       "�k�u", "����", "�k��", "�y��", "�p��", "���L", "�k�L",
                       "���}", "�k�}",
                   });
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
    {
        /* �S�� By Tmr -2002/04/01 */
        //�ĤG��exert
        if( me->query_skill_mapped("fork")=="da-fork")
        {
            if (!me->is_fighting())
                return notify_fail("�A�w���b�I�i�j�j�Z�F�C\n");
            if (me->query_skill("da-fork") < 80)
                return notify_fail("�̧A�ثe���j�j�Z���ԡA�|����I�i����\n");
            if (me->query_skill("horse-steps") < 50)
                return notify_fail("�A�ϰ��\\�O���F���ǡA�|����I�i����\n");
            if (me->query("ap") < 200)
                return notify_fail("�A�ثe�����l�����C\n");
            if (me->query("hp") < 200)
                return notify_fail("�A�ثe����O�����I�i�j�j�Z���ޡC\n");
            /* �T�w �ĤH */
            if(!target) {
                enemy = me->query_enemy();
                target=enemy[random(sizeof(enemy))];
            }
            if(!target)
                return notify_fail("�A�èS���i�H�������ﹳ�C\n");
            if( environment(me) != environment(target) )
                return notify_fail("�A�̤��O�b�P�@��C\n");
            if( !me->is_fighting(target) )
                return notify_fail("�A�S���M�o�ӤH�b�԰��C\n");

            message_vision(
                HIW "\n$N�~�a�@�}�M�S�A�����H�J����ư�A�⤤" +weapon->query("name")+HIW "���a�a�ƹD��l�V�|���K��g�h�I�I\n\n" NOR
                ,me);
            damage = me->query_damage();
            damage -=target->query_armor()/2 + random(target->query_armor()/2);
            damage = COMBAT_D->Merits_damage(me,target,damage,"bar");

            /* �L�k�y�����ˮ` */
            if(damage<1) {
                message_vision(HIG "�i�O�Q$N"HIG"í�������m�޳N�A�����a��פF��աC\n"NOR,target);
                me->start_busy(2);
                me->receive_damage("ap",100);
                me->improve_skill("da-fork",1+random(me->query_int()/5));
                me->improve_skill("fork",1+random(me->query_int()/5));
                return 1;
            }

            if( random(100) < COMBAT_D->attack_factor(me,"fork")*10/15 // �����R��
                    || random(200) > -COMBAT_D->dodge_factor(target, "dodge" ) )
            {
                /* �ϰ� �v�T��������*/
                hslv=me->query_skill("horse-steps");
                if(hslv > 90) hslv=8; // �K�U
                else hslv=4;    // �|�U

                for (hst=0;hst<hslv;hst++)
                {
                    if( damage < 1) break;
                    message_vision(
                        HIY "$N�����@�j��V$n"HIY"��"+limbs[random(sizeof(limbs))]+"("+damage+")�I�I" NOR
                        ,me,target);
                    target->receive_damage("hp",damage,me);
                    COMBAT_D->report_status(target);
                       damage -= (20+ random(30) );
                } // end for
            }
            else
                message_vision(HIG "�i�O�Q$N"HIG"�T�V�a�k�F�}�L�ƺj�l����աI�I\n"NOR,target);



                     if( random(100) < 40 ) weapon->attack(); // �Z���l��
            me->start_busy(2);
            me->receive_damage("ap",100);
            me->improve_skill("da-fork",1+random(me->query_int()/5));
            me->improve_skill("fork",1+random(me->query_int()/5));
            return 1;
        } // end if
    } // end if
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
      int lv,sk,fsk,i, h,power;
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
   return 60 + ob->query_str();
}


