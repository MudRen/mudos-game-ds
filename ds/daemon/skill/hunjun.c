#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
mapping *action = ({
                       ([
                            "action": "$N�����@�ߡA��}��e�}�A�@�ۡu������v,\n  �r�a�V$n���e�����h",
                            "damage":                10,
                            "dodge" :                15,
                            "attact_type":  "bar",	// �]�w�ޯ઺��������
                            // ������ �ͪ�(bio) �~��(bar)
                            // �]�k(wit)���F(sou)���(tec)
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": "$N�ϥX�@�ۡu�C����v�A��}��í�A\n ���_�@���A ��V$n���e�A",
                            "damage":                17,
                            "dodge" :                12,
                            "parry" :               -20,
                            "attact_type":  "bar",
                            "damage_type":  " ���",
                        ]),

                       ([
                            "action": "$N�������@���A��⼵�b�a�W�A\n �@�ۡu�C�ž�v��L�V$n�U�b�����h�A",
                            "damage":                10,
                            "dodge" :                -15,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N��M�@�ਭ�A�@�ۡu�j�Ÿ}�v�A��}��V$n��h",
                            "damage":                14,
                            "dodge" :                5,
                            "parry" :                -20,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N���e��i�A�@�U��۱a�L�A�ϦӰj����$n���}��A\n���O�@�ۡu�U�q�^��v",
                            "damage":                12,
                            "dodge" :                15,
                            "parry" :                25,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N��M�ۤU�A�׶}$n��������A��}�@�ޥ����ް_�A\n���O�@��"+ HIG "�u�P�����v" NOR + "�A�Ⱖ�}�@����$n���C�����h�A",
                            "damage":                17,
                            "dodge" :                -10,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�ƭ��ਭ�A�w�������������$n����A�@�ۡu��M�^�ॴ�v�A�V$n�ḣ",
                            "damage":                15,
                            "dodge" :                10,
                            "parry" :                20,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),

                       ([
                            "action": "$N�@�ۡu����v�A�@�}��t��_�A�b����Z�������V$n�U�y",
                            "damage":                13,
                            "dodge" :                -5,
                            "parry" :                25,
                            "attact_type":  "bar",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": "$N�ϥX�u�^�����v�A���N$n�@�o�A���$n�I��A�ΤO���U�@�x�I",
                            "damage":                18,
                            "dodge" :                10,
                            "parry" :                -10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�h��@�B�A�b��⾮�E�O�q�A�r�M�@�ۡu�z���s���v�A\n ���ծ��a�l���p�ɭ��B�븨�b$n���W�I",
                            "damage":                25,
                            "dodge" :                -20,
                            "parry" :                -20,
                            "attact_type":  "bar",
                            "damage_type":  "����",
                        ]),
                   });

int exert(object me, object target, string arg)
{
    int a,c,i,j,damage;
    string msg;
    object weapon;
    mapping type;

    weapon=me->query_temp("weapon");
    if(weapon)
    {
        if(weapon->query("skill_type")!="unarmed") return notify_fail("�A�⤤���۪Z���A����Ρu�꥿�y�v�Ť�D�H\n");
    }
    if(arg=="off" )
    {
        if( me->query_skill_mapped("unarmed")!="hunjun")
            return notify_fail("�A�èS���ϥΡu�꥿�y�v�Ť�D�C\n");
        me->map_skill("unarmed");
        me->reset_action();
        write("�A�w�g����ϥΡu�꥿�y�v�Ť�D�C\n");
        return 1;
    }

    if(me->query_skill("unarmed")<15) return notify_fail("�A���Ť�i��(unarmed)���Ť����A�L�k�ϥΪ꥿�y���k�C\n");
    if(me->query("mp")<20 || me->query("hp")<15) return notify_fail("�A�����骬�p�����\�A�Ϊ꥿�y���k�C\n");
    //�ĤG��exert
    if(me->query_skill_mapped("unarmed")=="hunjun")
    {
        if( !target ) target = offensive_target(me);
        if(!target) 	return notify_fail("�A�w�g�b�ϥΡu�꥿�y�v���Ť�D�C\n");

        //�����ʪ��n�S�O�`�N�n�[�U�����.
        if(!me->can_fight(target))
            return me->can_fight(target);

        c = target->query_armor();

        if(me->query_skill("hunjun") > random(200) && me->query_skill("hunjun") > 49 )
        {
            msg = HIY "\n$N�B���k���A�n�W�F�������O�q�A��M�z�ܤ@�n�A �ϥX�����ޡu�P���E������v�A���ɥ��O���V$n���ݤf�I�I\n\n" NOR ;
            damage = me->query_skill("hunjun") ;
            damage =  damage/2 + random(damage) + me->query_damage();
            damage -= random(target->query_armor());
            if(damage<60) damage=60+random(me->query_str());
            me->start_busy(2);
            if(random(me->query_skill("hunjun")) > 25 )
            {
                msg += HIR "���G$n���ݤf�Q$N���������A�n���A��g�Q�T\n" NOR;
                target->start_busy(4);
                // �W�[�����ˮ`���v�T
                damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                target->receive_damage("hp",damage,me);
                COMBAT_D->report_status(target);
            }
            else
            {
                msg += HIW"�i�O�Q$n�T�V�a���k�F�}�h�A��$n�]�~�a���y�����C\n" NOR;
            }
            if(!me->is_fighting(target)) me->kill_ob(target);
            if(!target->is_fighting(me)) target->kill_ob(me);
            message_vision(msg, me, target);
            me->receive_daemage("mp",30);
            return 1;
        }
        else
        {
            i=random(me->query_skill("hunjun")/20)+1;
            if(i>5) i=5;
            if(i<1) i=1;

            for( a=0; a<i; a++ )
            {
                if(a>0) message_vision(HIC"\n�X��$n���j���ɡA$N���۾l�¤S�X���ۡI\n"NOR,me,target);
                j=random(sizeof(action));
                type=action[j];
                msg = type["action"]+NOR+", ";
                damage = (me->query_damage()+me->query_skill("hunjun")/2)-random(c*3)/2;
                damage += type["damage"];
                if( damage < 1 ) damage = random(20);
                if( random(me->query_dex()*2+me->query_skill("hunjun")/2) > random(target->query_dex()*2+target->query_skill("dodge")/2)+type["dodge"]
                        && damage>0)
                {
                    msg += HIC"���G�y��$n"HIC"�@�B"+type["damage_type"]+"!!\n"NOR;
                    message_vision(msg, me, target);
                    me->improve_skill("hunjun",target->query("level")/3);
                    // �W�[�����ˮ`���v�T
                    damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                    target->receive_damage("hp",damage,me);
                    COMBAT_D->report_status(target);
                }
                else
                {
                    msg += "�i�O�Q$n���{�F�}�h�C\n";
                    message_vision(msg, me, target);
                    target->improve_skill("dodge",1);
                }
            }
            me->receive_damage("mp",i*7);
            me->start_busy(1);
        }
        if(!me->is_fighting(target)) me->kill_ob(target);
        if(!target->is_fighting(me)) target->kill_ob(me);
        me->improve_skill("hunjun",1+random(me->query_int()/2));
        me->improve_skill("unarmed",1+random(me->query_int()/2));
        return 1;
    }

    me->map_skill("unarmed", "hunjun");
    me->reset_action();
    message_vision("\n"HIC"$N�N������í�A�����������B��ݦu�ʡA�}�l�B�_�u�꥿�y�v�ߪk�w���ʳZ�C\n"NOR,me);
    me->receive_damage("mp",7);
    me->start_busy(1);
me->start_call_out( (: call_other, __FILE__, "delay", me ,7:), 14);
    return 1;
}

void delay(object me,int cost)
{
    object weapon;
    if(!me) return;
    weapon=me->query_temp("weapon");
    if(weapon)
    {
        if(weapon->query("skill_type")!="unarmed")
        {
            me->map_skill("unarmed");
            me->reset_action();
            return;
        }
    }

    if(me->query_skill_mapped("unarmed")!="hunjun")
    {
        return;
    }

    if(me->query("mp")<5)
    {
        me->map_skill("unarmed");
        me->reset_action();
        tell_object(me,"\n�A����O�����A�L�k�~��ϥΪ꥿�y�Ť�D�C\n");
        return ;
    }
    if( me->is_fighting() ) me->receive_damage("mp",5); //luky
me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
}

int valid_learn(object me) {	return 1;	}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) {	return 1; }
