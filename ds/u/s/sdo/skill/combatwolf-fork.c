//�ԯT�j�k(combatwolf-fork.c) 
//�S��⦡�G�_��ѯT�}(skywolf)�A�������O
//          �B�T�߫ʳZ(icewolf)�A�o���
//���q�����G�D�A��A�I�A�ۡA��
//          �ƭȦX�p�G20
//�ثe����u��mob�ϥ�
//                         2001.11.19 sdo@DS
//���}��Ѫ��a�ǲߡA�]����j�װ��ץ�
//damage<15�Aattack<20
//                         2002.04.30 sdo@DS
#include <ansi2.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
  ([
        "action": "$N�N�⤤$w���j�y���I�a�W�A���M�ֳt���ϤF�@��"HIC"�D"NOR"�A�j�y�Ѧa�W�u�_�A���V$n",
        "damage": 5,  //�o�ӬO�ˮ`�j�ƪ��ʤ��� , ���O�ˮ`�I��
        "attack": 15,
        "attact_type":  "bar",  // �]�w�ޯ઺�������� �ͪ�(bio) �~��(bar) �]�k(wit)���F(sou)���(tec)
        "damage_type":  "���", 
  ]),
  ([
        "action": "$N�|�_�⤤��$w�A�B�_"HIC"��"NOR"�r�Z�A�������V$n���|��s��T��",
        "damage": 15,
        "attack": -5,
        "parry": -10,
        "dodge": -10,       
        "attack_type":  "bar",
        "damage_type":  "���",
  ]),
  ([
        "action": "$N�N�⤤��$w�b���e�ꮾ�F���j��A�а_"HIC"�I"NOR"�A���$n�P���U�j�n�`",
        "damage": 10,
        "attack": 10,
        "dodge": 10,
        "parry": -10,
        "attack_type":  "bar",
        "damage_type":  "�W��",
  ]),
  ([
        "action": "$N�j�ܤF�@�n�y"HIC"��"NOR"�z�A���֪��R�ʤ�W��$w�A�H�d�x�U�����զV$n��ӥh",
        "damage": 5,
        "attack": 20,
        "parry": -5,
        "attack_type":  "bar",
        "damage_type":  "����",
  ]),
  ([
        "action": "$N�q�B"HIC"��"NOR"�A�Ϥⴤ��$w�����B�A�񨭻P$n�۷i",
        "damage": 5,
        "attack": 5,
        "parry":10,
        "dodge":10,
        "attack_type":  "bar",
        "damage_type":  "���",
  ])
});

int exert(object me, object target, string arg)
{
        int sk = me->query_skill("combatwolf-fork"),
        f_sk = me->query_skill("fork"),
        force = me->query_skill("force");
        int target_armor,target_dex,me_dex,me_damage,sum_damage;
        
    	object weapon,wp;
        weapon = me->query_temp("weapon");
        
        if( arg=="off" )
        {
                if( me->query_skill_mapped("fork")!="combatwolf-fork" )
                        return notify_fail("�A�èS���ϥξԯT�j�k�C\n");
                me->map_skill("fork");
                me->reset_action();
                write("�A����ϥξԯT�j�k�F�C\n");
                return 1;
        }

        if( me->query("ap") < 50 )
                return notify_fail("�A�ثe�����鱡�Ψä����\\�ϥξԯT�j�k�C\n");

        if( !weapon ) return notify_fail("�A�n���j�~��γ�C\n");

        if( f_sk < 25 ) return notify_fail("�A���j���Z�������٤�����C\n");

        if( weapon->query("skill_type")!="fork" )
                return notify_fail("�A�Q�γo�تZ���ϥκj�k�H\n");

        if( arg == "?" || arg == "help" )
        {
                tell_object(me,"�ثe���_��ѯT�}(skywolf)�B�B�T�߫ʳZ(icewolf)�i�H�ϥΡC\n"NOR);
                return 1;
        }


        if( me->query_skill_mapped("fork") == "combatwolf-fork" )
        {
                if( !target ) target = offensive_target(me);
                if( !target ) return notify_fail("�A�èS���ؼХi�H�����I\n");
                if( !me->can_fight(target) ) return me->can_fight(target);

                target_armor = target->query_armor();
                target_dex = target->query_dex();
                me_dex = me->query_dex() + random(me->query_dex()/2)*2;
                me_damage = me->query_damage() + force/4 + sk/3 + f_sk/4;
                me_damage = me_damage + random(me_damage/4);
                sum_damage = me_damage - target_armor/4 - random(target_armor*1/4);
                
                // qc section
                //if(wizardp(me)) tell_object(me,sprintf("  me_damage=%-d  sum_damage=%-d\n",me_damage,sum_damage));
                // end of qc section
                
                if( !arg || arg == "?" )
                {
                        tell_object(me,"�ثe���_��ѯT�}(skywolf)�B�B�T�߫ʳZ(icewolf)�i�H�ϥΡC\n"NOR);
                        return 1;
                }
                if( arg == "skywolf" )
                {
                        if( !me->is_fighting(target) ) me->kill_ob(target);
                        if( !target->is_fighting(me) ) target->kill_ob(me);
                        if( me->is_busy() ) return notify_fail("�A���b���I\n");
                        if( me->query_skill("combatwolf-fork") < 85 )
                                return notify_fail("�A���ԯT�j�k�٨S�����Z�O�I\n");
                        message_vision(
                        "\n\n"HIW"$N"HIW"�����q���A�@�ѱ���ѩP�����o�}�ӡA���ۤj�ܤ@�n�A�򴤤⤤��"+weapon->name()+HIW"�A�V$n"HIW"�ϥX"HIY"�y�_��ѯT�}�I�z\n\n"NOR, me, target);
                        if( random(me_dex) > random(target_dex)&& sum_damage = COMBAT_D->Merits_damage(me, target, sum_damage + random(sum_damage/3), "bar") )
                        {
                                target->receive_damage("ap", sum_damage/10, me);
                                target->receive_damage("hp", sum_damage, me);
                                message_vision(
                                HIR"$n"HIR"�G�s�@�n�A�Q$N"HIR"��"HIY"�_��ѯT�}"HIR"�����ݤf�A����V�ᥭ���ӥX�I"NOR, me, target);
                                // QC
                                //if(wizardp(me)) tell_object(me,sprintf("  (damage=%-d) \n",sum_damage));
                                // End QC
                                me->improve_skill("combatwolf-fork", random(me->query_int()/5) + 5);
                                me->improve_skill("fork", random(me->query_int()/6) + 5 );
                                me->add_busy(1);
  				if( objectp(wp = me->query_temp("weapon")) ) wp->attack(); // wp �l�a�v
                        }
                        else
                        {
                                message_vision(
                                HIC"$n"HIC"�榣�ϥX�F�y�K�O���z�A�b�d�v�@�v���ڰ{�L�F�o�P�R���@�ۡC"NOR, me, target);
                                target->imporve_skill("dodge", 5);
                                sum_damage = 0;
                                me->add_busy(2+random(2));
                        }
                        if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                                message_vision(HIY" ("+ HIR + sum_damage + HIY")"NOR" \n\n"NOR, me);
                        else message_vision("\n\n", me);
                        COMBAT_D->report_status(target);
                        me->receive_damage("ap", 20 + sum_damage/10 );
                        return 1;
                }

                if( arg == "icewolf" )
                {
                        if( !me->is_fighting(target) ) me->kill_ob(target);
                        if( !target->is_fighting(me) ) target->kill_ob(me);
                        message_vision(
                        "$N�N�⤤���j���j�y����$n�A���b�I�I���ڡA$N���M�B�_"HIC"�B�T�ʤ߳Z"NOR"�A�j�y�V$n�g�X�@�D�H��"NOR, me, target);
                        if( random(target->query_dex()) < random(me->query_dex()*3/2) )
                        {
                                message_vision(HIW"��$N�p���ȦB�����A�ʼu���o�I\n"NOR, target);
  				if( objectp(wp = me->query_temp("weapon")) ) wp->attack(); // wp �l�a�v
                                target->start_busy(2+random(2));
                                //if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                                //  	message_vision(HIY" ("+ HIR + me->query_damage()/3 + HIY")"NOR" \n"NOR, me);
                                //else message_vision("\n", me);
                                COMBAT_D->report_status(target);
                        }
                        else
                        {
                                message_vision("$N�榣�{���A���L�F���D�L�δH��C\n"NOR,target);
                                me->add_busy(random(2));
                        }
                        me->receive_damage("ap", 30 - sk/20);
                        return 1;
                }
        }
          
        message_vision(HIY"$N��j�@�ߡA��B�P���A�@�ӯT�������X�{�b����C\n"NOR,me);
        me->map_skill("fork", "combatwolf-fork");
        me->receive_damage("ap",30);
        me->reset_action();
        me->start_busy(1);
        return 1;
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
        return 80;
}
