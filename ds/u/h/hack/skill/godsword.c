//1999.10.3  By DS-Acme
//Update 2000/4/7 -By Tmr-

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
void firesword(object me,object target,int damage);
mapping *action = ({
        ([
        "action": "$N�C���s���A�ۤ��M�ۡA�@�C���ۤ@�C�A\n\t�@�ۡu��魸�r�v�A�ⴤ$w��$n��������h",
        "damage":                15,
        "dodge" :                10,
        "parry" :                -8,
        "attact_type":  "bio",  // �]�w�ޯ઺��������
                                // ������ �ͪ�(bio) �~��(bar)
                                // �]�k(wit)���F(sou)���(tec)
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�@���u½���ЫB�v�A�ڦp�s���A�B�p��R�A�ⴤ$w�s��$n���ܡB�e�áB���y�A�C�B�j��",
        "damage":                10,
        "dodge":                 -5,
        "parry" :                14,
        "attact_type":  "bio",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�C�լ�S�@�ܡA�ѻ��F���֡A�ର�I�p�����A\n\t�@���u�g���Ѫe�v�A�ⴤ$w��$n��A�ӥh",
        "damage":                17,
        "dodge" :               -10,
        "parry" :                10,
        "attact_type":  "bio",
        "damage_type":  "�A��",
        ]),

        ([
        "action": "$N�@�ۡu�M������v�����R��A�ت`�C�y�A���x�}�����C�Z�A\n\t�⤤$w���a��$n�ߺ۱��h",
        "damage":                13,
        "dodge" :                20,
        "parry" :                -10,
        "attact_type":  "bio",
        "damage_type":  "�C��",
        ]),

        ([
        "action": "$N�ⴤ$w�ݤ��X�@�ۡu�}�H��šv�A�C�y�T�I�A\n\t���I$n�����ءy�t���z�B�y�Ůڡz�A�y�����z�A�T�B�j��",
        "damage":                10,
        "dodge" :               -10,
        "parry" :                15,
        "attact_type":  "bio",
        "damage_type":  "���",
        ]),
});

int exert(object me, object target, string arg)
{
        object weapon;
        weapon=me->query_temp("weapon");

        if(arg=="off" )
        {
                if( me->query_skill_mapped("sword")!="godsword")
                        return notify_fail("�A�èS���ϥί��Z�C�Z�C\n");
                me->map_skill("sword");
                me->reset_action();
                write("�ޯ�[���Z�C�Z]�w�����C\n");
                return 1;
        }

        if(!weapon) 
                return notify_fail("�ϥί��Z�C�Z�����⤤�n���C�C\n");
        if(weapon->query("skill_type")!="sword") 
                return notify_fail("�ϥί��Z�C�Z�����⤤�n���C�C\n");
        if(me->query_skill("sword")<10) 
                return notify_fail("�A���C�k��¦�����L�k�ϥί��Z�C�Z�C\n");
        if(me->query("ap") < 10 || me->query("hp") < 10) 
                return notify_fail("�A�����骬�p�L�k�ϥί��Z�C�Z�C\n");
        if( me->query_skill_mapped("sword")=="godsword")
                return notify_fail("�A�w�g�b�ϥί��Z�C�Z�C\n");

        me->map_skill("sword", "godsword");
        me->reset_action();
        message_vision("\n"HIW" $N���|��W��"+weapon->name()+", �}�l�I�i�y���Z�C�Z�z�C\n"NOR,me);
        me->receive_damage("ap",6); //luky
        me->start_busy(1);
        return 1;
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
        int i,j,sk,busy;
        object target;  
        target = offensive_target(me);
        sk=me->query_skill("godsword");

        //��ap 
        if(me->query("ap") > 10 )
                me->receive_damage("ap",1+random(2));

        //�o����� 4
        if (objectp(target) && sk > 60 && !me->is_busy()
        && me->query("ap") > 100 && (random(sk/2)+random(sk/5)) > random(200) )        {

        i=COMBAT_D->attack_factor(me,"sword")*10/15;
        j=-COMBAT_D->dodge_factor(target,"dodge")*10/15;
        //�]�wbusy
        if(sk > 95 ) busy =3;
        else if( sk > 80 ) busy =2;
        else busy=1;
        message_vision(HIW "$N�C�����F�A�F�@�ۡB��@�۪�����$n"HIW"���ͯ}��I�I\n" NOR ,me,target);

        if( random(i) > random(j) ) {
        message_vision(GRN"(�n��$N"GRN"�߯����w�A�}�l�S�X�}��I�I)\n"NOR,target,me);
        target->start_busy(busy);
        me->receive_damage("ap",busy*10);
        }

        }

        return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
        if(ob->query("int") < 30) return 90;
        else return 100;        
}

