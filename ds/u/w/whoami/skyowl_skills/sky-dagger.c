#include <ansi.h>
inherit SKILL;
inherit SSERVER;
int BonusDamage = this_player()->query_skill("sky-force")/8;

void show_damage(object me, object target,int damage)
{
    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if(wizardp(me) && me->query("env/debug"))
        tell_object(me, HIR"  ("+damage+")\n"NOR);
}

void sp_1(object me, object target, object weapon)
{
    int damage = me->query_damage()/10, x, y;
    damage = damage * (me->query_skill("sky-force")/10);
    damage += random(me->query_skill("sky-force"));
    damage -= random(target->query_armor());
    damage = COMBAT_D->Merits_damage(me, target, damage, "bar");
    if( damage < 0 )
        damage = 0;
    x = 1+random(me->query_skill("sky-force")/25);

    if( !me->query_temp("sky-dagger/sp_hint") && (me->query_damage() + me->query_skill("sky-force")) > (target->query_armor()/random(5) + target->query_skill("dodge")) )
    {
        me->add_temp("sky-dagger/sp_hint", 1);
        message_vision(HIB"\n�H�ۤ@�n�z�ܡA$N"+HIB+"����D�_�A"+weapon->query_name()+HIB"�F�q���ŦӹL�A�b�������L�|�V���Z���A�C�D���v�A�{�p�C�D�խi�AŢ�n��$n"+HIB+"�W�B���B�U�h�B�n�`�I�I\n"NOR, me, target);
        me -> receive_damage("ap", 30);
        target -> receive_damage("hp", damage);
        show_damage(me, target, damage);
        COMBAT_D->report_status(target);
        if( me->query_skill("sky-force") > 24 && (me->query("max_ap")/2) < me->query("ap") && random(me->query_con()) > 45 )
        {
            message_vision(HIW"\n$N"+HIW+"�q�B�T�M�E�]�ߪk�A�N�������O�B�����u�A�X�շm��"+chinese_number(x)+"�ۡC\n"NOR, me);
            me -> receive_damage("ap", 30);
            for(y=1;y<(x+1);y++)
            {
                if( damage > 0 )
                    damage = damage / y;
                me -> receive_damage("ap", 8);
                target -> receive_damage("hp", damage);
                COMBAT_D->report_status(target);
                show_damage(me, target, damage);
            }
        }
    }
}

void sp_2(object me, object target, object weapon)
{
    int x = 1+random(me->query_skill("sky-dagger")/50), y;
    if( !me->query_temp("sky-dagger/sp_hint") && random(me->query_skill("sky-dagger")) > 60 && me->query("ap") > 50 )
    {
        me->add_temp("sky-dagger/sp_hint", 1);
        message_vision(CYN"$N"+CYN+"���ɫ�h�����βr�a�@�y�A�N�M�ܦ��V�e�r�Ī����աA�����m��ժ�"+weapon->query_name()+CYN"�A���ରŧ�Ī��Q���I\n"NOR, me);
        me->receive_damage("ap", 10);
        for(y=0;y<x;y++)
        {
            COMBAT_D->do_attack(me,target,weapon);
            COMBAT_D->report_status(target);
        }
    }
}

void sp_3(object me, object target, object weapon)
{
    int damage = me->query_damage()/2, x, y;
    damage = damage * (me->query_skill("sky-force")/10) + damage;
    damage += random(me->query_skill("sky-force"));
    damage -= random(target->query_armor());
    damage = COMBAT_D->Merits_damage(me, target, damage, "bar");
    if( damage < 0 )
        damage = 0;

    if( me->query_skill("sky-dagger") > random(150) && me->query("ap") > 150 && !me->query_temp("sky-dagger/sp_hint"))
    {
        me->add_temp("sky-dagger/sp_hint", 1);
        message_vision(HIW"�u��$N"+HIW+"���"+weapon->query_name()+"�@�i�A����"+HIY+"�y�ѱ������ĥդ�z"+HIW+"���a���X�A$N"+HIW+"�⤤��"+weapon->query("name")+HIW"�Ʀ��L�v���P�V$n"+HIW+"��h�I�I\n\n" NOR, me, target);
        show_damage(me, target, damage);
        target -> receive_damage("hp", damage);
        me -> receive_damage("ap", 15+random(15));
        COMBAT_D->report_status(target);
    }
}

string *parry_msg = ({
                         "�uť���u��v�@�n�M�Q$p��}�F�C\n",
                         "���G�u���v�a�@�n�Q$p�׶}�F�C\n",
                         "���O�Q$n�Τ⤤�L�b�[�}�C\n",
                         "���O$n���l�@���M�Τ⤤�L�b��}�C\n",
                     });

mapping *action = ({
                       ([
                            "action": "$N������A�u"HIW+BLK"���a����"NOR"�v�w�M�X�ۡA$w����Ӱ_�A�¦V$n���ӥh�C",
                            "damage":               2+BonusDamage,
                            "dodge" :               10,
                            "attact_type":  "bar",  // �]�w�ޯ઺��������
                            // ������ �ͪ�(bio) �~��(bar)
                            // �]�k(wit)���F(sou)���(tec)
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�ϥX�u"HIY"�����b��"NOR"�v�A���M����$n����A�⤤��$w�A�r�V$n��h�A",
                            "damage":                4+BonusDamage,
                            "dodge":                -15,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�ϥX�@�ۡu"HIW+BLK"�𭸩Ѥ�"NOR"�v�A�a�_�b�ذ��A���M��$n�����ӤU�A",
                            "damage":                6+BonusDamage,
                            "dodge" :               -10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N����@���A�@���u�븨�Q�ڡv�A�⤤$w��$n����ӥh�A",
                            "damage":                8+BonusDamage,
                            "dodge" :               -10,
                            "parry" :                15,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�V��@�D�A�u"HIY"���a�X��"NOR"�v�k��$w�浹����A���M�X�۪���$n����ʬ֥ަӥh�A",
                            "damage":                10+BonusDamage,
                            "dodge" :                20,
                            "parry" :               -20,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�ϥX�u�@�ۤG���v�A���зL�}�A����X�x�ӥk��X�P�A�X$n���j���ɡA$w�w��$n���A�ӥh�A",
                            "damage":                12+BonusDamage,
                            "dodge" :                10,
                            "parry" :               -20,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),

                       ([
                            "action": "$N��ϡu"HIW+BLK"���a����"NOR"�v���$n���A���M�S�@���u"HIC"�����ѻ�"NOR"�v�A$w�ѤU�ӤW��V$n�A",
                            "damage":                14+BonusDamage,
                            "dodge" :                10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N���Ⱚ�|, �@�ۡu"HIC"�j�P�i��"NOR"�v�⤤$w�¦V$n�����Y�F�L�h�A",
                            "damage":                16+BonusDamage,
                            "dodge" :                20,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�ϥX�u"HIR"�N���L��"NOR"�v�A���M����$n���e�A����e�N�����դ޶}�ĤH�`�N�A���M�j�ܤ@�n�A$w����ӥh�A",
                            "damage":                18+BonusDamage,
                            "dodge" :               -10,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                   });

int exert(object me, object target, string arg)
{
    int c,damage,sk,i;
    string msg;
    object weapon;
    weapon=me->query_temp("weapon");
    if(!weapon)
        return notify_fail("�ϥΤѼS�P�k�����⤤�n���P���C\n");
    if(weapon->query("skill_type")!="dagger")
        return notify_fail("�ϥΤѼS�P�k�����⤤�n���P���C\n");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("dagger")!="sky-dagger")
            return notify_fail("�A�èS���ϥΤѼS�P�k�C\n");
        me->map_skill("dagger");
        me->map_skill("parry");
        me->reset_action();
        write("�ޯ�[�ѼS�P�k]�w�����C\n");
        return 1;
    }
    if(me->query_skill("dagger")<20)
        return notify_fail("�A���P����¦�����L�k�ϥΤѼS�P�k�C\n");
    if(me->query("ap")<20 || me->query("hp")<20)
        return notify_fail("�A�����骬�p�L�k�ϥΤѼS�P�k�C\n");

    /*        //�ĤG��exert
            if(me->query_skill_mapped("dagger")=="sky-dagger")
            {
              if(!target) target = offensive_target(me);
              if(!target) return notify_fail("�A���b�ϥΡu�ѼS�P�k�v�C\n");
              if(!target) return notify_fail("��⤣���F�C\n");
              if(!me) return notify_fail("��⤣���F�C\n");
              if(!me->is_fighting()) return notify_fail("�԰�����F�C\n");
              if( environment(me) != environment(target) ) return notify_fail("�䤣����@�C\n");
              // �����ʪ��n�S�O�`�N�n�[�U�����.
              if(!me->can_fight(target)) return me->can_fight(target);
              
              c = target->query_armor();
              if(me->query_skill("sky-dagger")>40)
              {
                if(me->query("ap")>250)
                {
                 i=me->query_skill("sky-dagger");
                 if(i>90) i+=10;
                 msg = HIW "\n$N���Ѩg�S�A���ۡu"CYN"�ѱ������ĥդ�"HIW"�v�@�ۨg���V$n"HIW"�A$N�⤤��"+weapon->query("name")+HIW"�Ʀ��L�v���P�V$n��h�C\n\n" NOR;
                 if(random(i)>30)
                 {
                  damage = random(me->query_skill("sky-dagger"))*2+ random(me->query("str"))*3/2;
                  damage = damage/2 + random(damage) + me->query_damage(); 
                  damage -= random(target->query_armor()); 
                  if (damage > 160) damage = 160;
               
                  msg += HIR"$n"HIR"�]�{�פ��ΡA�ӳ�����A�����L�ƭ��@�ˡA�A�媽�y�A�ݨӨ��ˤ����C\n\n" NOR;
                   
                  damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                  target->receive_damage("hp",damage,me);
                  me->receive_daemage("ap",100);
                  target->start_busy(1);
                  me->start_busy(3);
                 }
                 else {
     
                  msg += HIB "�u��$n"HIB"�W�W�i�i���k�}$N�����ۡA�o�]�~���y��o�աC\n" NOR ;
                  me->receive_daemage("ap",20);
                  target->start_busy(2);
                  me->start_busy(2);
                 }
               if(!me->is_fighting(target)) me->kill_ob(target);
               if(!target->is_fighting(me)) target->kill_ob(me);
               message_vision(msg, me, target);
               if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                   tell_object(me,HIY"( �ˮ`: "+damage+")"NOR);
               if( target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                   tell_object(target,HIR"( �ˮ`: "+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                   if(wizardp(me) && me->query("env/debug")) 
                   tell_object(me,"(debug):  �y��"+damage+"�I�ˮ`!!\n"); 
     
               COMBAT_D->report_status(target);
               return 1;
                }
                else {
                 tell_object(me,"�A����O�L�k�t���o�ѼS�P�k���Ͼ_���O�C\n");
                }
              }
              else {
                tell_object(me,"�A���ѼS�P�k������ԡA�L�k�ϥίS�\\�C\n");
              }
            }
    */
    if(me->query_skill_mapped("dagger")=="sky-dagger")
        return notify_fail("�A���b�ϥΤѼS�P�k�C\n");
if(!me->skill_active( "sky-dagger",(: call_other, __FILE__, "delay", me, 6 :), 10))
        return notify_fail("�A���۪��ʧ@�٨S�����C\n");
    me->map_skill("dagger", "sky-dagger");
    if( me->query("class2") == "skyowl_military" )
        me->map_skill("parry", "sky-dagger");
    me->reset_action();
    message_vision("\n"HIW"$N�ⴤ"+weapon->name()+HIW"��ݫe�A�}�e�u���N�ߪK�v, �}�l�I�i�y�ѼS�P�k�z�C\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);
    return 1;
}

void delay(object me,int cost)
{
    object weapon;
    if(!me)
        return;
    weapon=me->query_temp("weapon");
    if(!weapon)
    {
        me->map_skill("dagger");
        me->map_skill("parry");
        me->reset_action();
        return;
    }
    if(weapon->query("skill_type")!="dagger")
    {
        me->map_skill("dagger");
        me->map_skill("parry");
        me->reset_action();
        return;
    }
    if(me->query_skill_mapped("dagger")!="sky-dagger")
        return;
    if(me->query_skill_mapped("parry")!="sky-dagger")
        return;

    if(me->query("ap")<7)
    {
        me->map_skill("dagger");
        me->map_skill("parry");
        me->reset_action();
        message_vision("\n"HIW"$N����O�����L�k�~��ϥΤѼS�P�k�A�u�n��Τ@��ۦ��C\n"NOR,me);
        return ;
    }
me->skill_active( "sky-dagger",(: call_other, __FILE__, "delay", me, 6 :), 10);
}

mapping query_action(object me, object target, object weapon)
{
    me->receive_damage("ap",2+random(3));
    if( me->query_skill("sky-dagger") > 50 && me->query_skill("dagger") > 40 && me->query("class2") == "skyowl_military" )
        sp_1(me, target, weapon);
    if( me->query_skill("sky-dagger") > 70 && me->query_skill("dagger") > 60 )
        sp_3(me, target, weapon);
    return action[random(sizeof(action))];
}

string query_parry_msg(object me, object target, object weapon)
{
    me->receive_damage("ap",2);
    if( me->query_skill("sky-dagger") > 90 && me->query_skill("parry") > 70 && me->query("class2") == "skyowl_military" )
        sp_2(me, target, weapon);
    return parry_msg[random(sizeof(parry_msg))];
}


int valid_learn(object me)
{
    return 1;
}
int practice_skill(object me)
{
    return 1;
}