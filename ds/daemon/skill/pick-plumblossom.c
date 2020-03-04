// pick-plumblossom.c
// ����� -Tmr 2006/11/19

#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
void firesword(object me,object target,int damage);
mapping *action = ({
                       ([
                            "action": "$N�@�ۡu�j���ë�v�A�����A��V$n��$l",
                            "damage":                15,
                            "attact_type":  "wit", 
                            "damage_type":  "���",
                        ]),
                       ([
                              "action": "$N�I�X�u��k�����v�A�k��$n��$l�A�����V$n��$l",
                            "damage":                15,
                            "attact_type":  "wit", 
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�@�ۡu�����W�۷T�v�A���l�D�M�Ӱ_�A��V$n��$l",
                            "damage":                18,
                            "attact_type":  "wit", 
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N���⥭�|�A�@�ۡu���}��Ӫ�˼v�v���V$n$l",
                            "damage":                15,
                            "attact_type":  "wit", 
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�����̡A�k��@�O�u���C���Ѯ������v���V$n$l",
                            "damage":                10,
                            "attact_type":  "wit", 
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�@�ۡu��U�����p���áv�A�����ƵM��V$n$l",
                            "damage":                20,
                            "attact_type":  "wit", 
                            "damage_type":  "���",
                        ]),

                        });

int exert(object me, object target, string arg)
{
    object weapon;
    weapon=me->query_temp("weapon");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("unarmed") != "pick-plumblossom")
            return notify_fail("�A�S���ϥΡu�����v�C\n");
        me->map_skill("unarmed");
        me->reset_action();
        write("�ޯ�[�����]�w�����C\n");
        return 1;
    }
    if( me->query_temp("weapon") && me->query_temp("weapon")->query("skill_type")!="unarmed")
        return notify_fail("�A�⤤�����Z�������A�ä���ϥΩ�u�����v�C\n");
    
    if(me->query("ap") < 10 || me->query("hp") < 10)
        return notify_fail("�A�����骬�p�L�k�ϥΡu�����v�C\n");
    if(me->query_skill("unarmed")<5)
        return notify_fail("�A���Ť�i����¦�����L�k�ϥΡu�����v�C\n");
    if( me->query_skill_mapped("unarmed")=="pick-plumblossom")
        return notify_fail("�A�w�g�b�ϥΧ����C\n");

    me->map_skill("unarmed", "pick-plumblossom");
    me->reset_action();
      message_vision( HIG"$N"HIG"�x���M�ۡA��m���ۡA�}�l�I�i�u�����v�C\n"NOR,me);
    me->receive_damage("ap",6);
    me->start_busy(1);
    return 1;
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
    int i,j,sk,busy;
    object target;
    target = offensive_target(me);
    sk=me->query_skill("pick-plumblossom");

    //��ap
    if(me->query("ap") > 10 )
        me->receive_damage("ap", 1);

    if ( objectp(target) && sk > 50 && !target->is_busy() && !me->is_busy() && me->query("ap") > me->query("max_ap")/4*3 && sk > random(200))
    {

        i=COMBAT_D->attack_factor(me,"unarmed")*10;
        j=COMBAT_D->dodge_factor(target,"dodge")*6;
        //�]�wbusy
                busy = 1;
        message_vision(HIW "$N���������A�ϥX����⵴�ޡu��}���骽����v�A�x���I�I�G�o$n"HIW"�}��ʥX�I�I\n" NOR ,me,target);

        if( random(i) > random(j) ) {
            message_vision(GRN"($N"GRN"�@�ɤ��������D�p������I�I)\n"NOR,target,me);
            target->start_busy(busy);
            me->receive_damage("ap", busy*10);
        }
    }

    if( me->query("ap") <10 )
    {
        me->map_skill("unarmed");
        me->reset_action();
        message_vision("\n$N����I�i�u�����v�F�C\n"NOR,me);
    }

    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
    if(ob->query("int") < 30) return 90;
    else return 100;
}


