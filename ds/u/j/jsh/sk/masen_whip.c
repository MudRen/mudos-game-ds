/***�����@�k(Masen_whip)    Update By Kkeenn**********/
// update by Tmr 2006/06/07
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
mapping *action = ({
                       ([
                            "action": "$N�@���⤤���@�l�A�����@�k�Ĥ@���y"HIM"���@�ٱ���"NOR"�z\n�@�l���e���᪺�V$n���ߺۥϥh",
                            "damage": 12,
                            "dodge" : 25,
                            "attact_type":  "bio",
                            "damage_type":  "�@��",
                        ]),
                       ([
                            "action": "$N�ϥX�����@�k�ĤG���y"HIR"�������߯�"NOR"�z�A����V�e��̤@�ۡA\n�k���@�l�ߨ�X$n���`�N�����@�V$n���Y��",
                            "damage":                15,
                            "dodge" :                20,
                            "parry" :               -10,
                            "attact_type":  "bio",
                            "damage_type":  "�@��",
                        ]),

                       ([
                            "action": "$N�@���ਭ�R�X�����@�k�ĤT���y"HIC"�C���L�ҥ�"NOR"�z�A\n  �⤤���@�l�b�������{���ڦV$n���������h",
                            "damage":                10,
                            "dodge" :                20,
                            "parry" :                20,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N���Ѥ@�n�����A�����@�k�ĥ|���y"HIB"���ߦӫ��"NOR"�z�A\n�⤤�@�l�ۥX�@�ӭӪ���l�V$n�������h",
                            "damage":                25,
                            "dodge" :                10,
                            "parry" :                -15,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�R���@�_�A�����@�k�Ĥ����y"HIW"�C�i�Ȫe�E"NOR"�z�A�⤤�@�l�a�ۤ@�Ѵ��p�����l�V�������V$n�@�h�A\n  �����a���V$n�p��",
                            "damage":                30,
                            "dodge" :                -10,
                            "parry" :                -20,
                            "attact_type":  "bio",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": "$N�V$n�ĥh�I��X�����@�k�Ĥ����y"HIY"�����s���N"NOR"�z\n  �@�l���M�q�������l�u���V$n��h",
                            "damage":                27,
                            "dodge" :                20,
                            "parry" :                -30,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�j�B�h��A�⤤���@�l�o�V�e���ֽĥX�A�����@�k�ĤC���y"MAG"���i�ǹq��"NOR"�z�@�l�H�B���{�q���t�g�V$n���ӻH",
                            "damage":                22,
                            "dodge" :                30,
                            "parry" :                -15,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�㥸�@�n�A�����@�k�ĤK���y"WHT"�ߦǳభ��"NOR"�z�A���H�@��B�@�H$n�ʡA\n�b$n�Q�઺���Ἲ�ä��ɡA�V$n�U�L�B��h",
                            "damage":                18,
                            "dodge" :                20,
                            "parry" :                -15,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),
                   });

int exert(object me, object target, string arg)
{
    string msg;
    object weapon, wp;
    mapping type;

    weapon=me->query_temp("weapon");
    if( !weapon || weapon->query("skill_type")!="whip")
        return notify_fail("�A�����������@�����Z���~��ϥη����@�k�C\n");

    if(arg=="off" ) {
        if( me->query_skill_mapped("whip")!="masen_whip")
            return notify_fail("�A�èS���ϥΡu�����@�k�v�C\n");
            me->map_skill("whip");
            me->reset_action();
            write("�@�k�u�����@�v�w�����C\n");
            return 1;
        }

        if(me->query_skill("whip")< 5)
        return notify_fail("�A�����@�Z�����Ѥ����H�ϥΡu�����@�k�v�C\n");
        if(me->query("ap")<10 || me->query("hp")<20)
                return notify_fail("�A�����骬�p�L�k�ϥη����@�k�C\n");

        //�ĤG��exert
        if( me->query_skill_mapped("whip") == "masen_whip")
        {
                int times, sk, damage, target_d,i;
            if( !target )
                target = offensive_target(me);
            if(!target)
                return notify_fail("�A�w�g�b�ϥΡu�����@�k�v�F�C\n");

            //�����ʪ��n�S�O�`�N�n�[�U�����.
            if( !weapon || weapon->query("skill_type")!="whip")
                return notify_fail("�A�����n���@�����Z���~��I�i�C\n");
            if(!me->can_fight(target))
                return notify_fail("�A�L�k����o�;԰��C\n");
            if( !me->is_fighting(target) )
                return notify_fail("�A�èS������԰��C\n");
            if(target->is_corpse())
                return notify_fail("�A�������u�O�@�����....\n");

            sk = me->query_skill("masen_whip");
                if( userp(me) && me->query_temp("masen") )
                        return notify_fail("�A�u�ɶ����L�k�A�I�i�u�K��X�L���@�v�F�C\n");

            if( sk < 30 )
                return notify_fail("�A�������@�k���F��30�šA�L�k�o�X�u�K��X�L���@�v�C\n");
            if(me->query_skill("whip") < 50)
                return notify_fail("�A����¦�@�k���F��50�šA�L�k�o�X�u�K��X�L���@�v�C\n");
            if(me->query_skill("force") < 30)
                return notify_fail("�A�����\\���ť��F��30�šA�L�k�o�X�u�K��X�L���@�v�C\n");

                // ���� 
                times = sk/10;
                if( times < 2) times = 2;
                if( times > 8) times = 8;

        
            message_vision(HIG"\n$N"HIG"�@�n�M�S���Ķ��d�A�@�դ@�ܡA�I�i�X�ǻ����������@�k�ĤE���i�K��X�L���@�j�I�I�I\n"NOR,me);
                for(i=0;i<times;i++) {
      damage = (me->query_damage()*me->query_Merits("bio")*2/5 - random(target->query_armor()))*6/15;
                        damage = COMBAT_D->Merits_damage(me, target, damage, "bio");
     if( damage >50 ) damage = 50+random(70);
                    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
                    if( random(sk) > random(target_d) ) {

                                switch(i) {
                                case 0:
                                    message_vision(HIR"$N"HIR"�s��V$n"HIR"���X�ĳ����y"HIM"���@�ٱ���"HIR"�z�A�y��$n"HIR"����@�B�@��("+damage+")�I\n"NOR,me,target);
                                break;
                                case 1:
                                    message_vision(HIR"$N"HIR"�s��V$n"HIR"���X�ĶL���y"HIR"�������߯�"HIR"�z�A�y��$n"HIR"�k��@�B�@��("+damage+")�I\n"NOR,me,target);
                                break;
                                case 2:
                                  message_vision(HIR"$N"HIR"�s��V$n"HIR"���X�İ����y"HIC"�C���L�ҥ�"HIR"�z�A�y��$n"HIR"���}�@�B�@��("+damage+")�I\n"NOR,me,target);
                                break;
                                case 3:
                                  message_vision(HIR"$N"HIR"�s��V$n"HIR"���X�ĸv���y"HIB"���ߦӫ��"HIR"�z�A�y��$n"HIR"�k�}�@�B�@��("+damage+")�I\n"NOR,me,target);
                                break;
                                case 4:
                                 message_vision(HIR"$N"HIR"�s��V$n"HIR"���X�ĥ����y"HIW"�C�i�Ȫe�E"HIR"�z�A�y��$n"HIR"�Y���@�B�@��("+damage+")�I\n"NOR,me,target);
                                break;
                                case 5:
                                message_vision(HIR"$N"HIR"�s��V$n"HIR"���X�ĳ����y"HIY"�����s���N"HIR"�z�A�y��$n"HIR"�����@�B�@��("+damage+")�I\n"NOR,me,target);
                                break;
                                case 6:
                                message_vision(HIR"$N"HIR"�s��V$n"HIR"���X�Ĭm���y"MAG"���i�ǹq��"HIR"�z�A�y��$n"HIR"�y���@�B�@��("+damage+")�I\n"NOR,me,target);
                                break;
                                case 7:
                                        message_vision(HIR"$N"HIR"�s��V$n"HIR"���X�Į����y"WHT"�ߦǳభ��"HIR"�z�A�y��$n"HIR"�I���@�B�@��("+damage+")�I\n"NOR,me,target);
                                break;
                                }
                            target->receive_damage("hp",damage, me);
                        COMBAT_D->report_status(target);
                        } else {
                                        message_vision(CYN"�i��$N"CYN"�߯����w�A�o�@�@����F�ųB...\n"NOR, me, target);
                        }
                }
            target->start_busy(1);
            me->set_temp("masen",1);
            call_out("stop_masen", 12, me);
            me->start_busy(1);
            me->receive_damage("ap", 50);
            return 1;
        }

        if(!me->skill_active( "masen_whip",(: call_other, __FILE__, "delay", me ,5:), 10))
            return notify_fail("�A�������@�k�٨S�����C\n");
        me->map_skill("whip", "masen_whip");
        me->reset_action();
        message_vision("\n"HIC"$N�@���⤤���@�l�A�R�F�����֦a�@��A�}�l�I�i�_���`�N�@���y�����@�k�z�F�I\n"NOR,me);
        me->receive_damage("ap",10);
        me->start_busy(1);
        return 1;
}

int valid_learn(object me)
{
    return 1;
}


void stop_masen(object me)
{
        if( !me ) return;
        me->delete_temp("masen");
        tell_object(me,"�A���e�I�i�u�K��X�L���@�k�v�ҿ�d�����ˤw�g��_�����F�C\n");
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
    return ob->query_int() + 75;
}

