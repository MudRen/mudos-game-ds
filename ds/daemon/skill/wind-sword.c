#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void superpower(object me);
mapping *action = ({

                       ([
                            "action": "$N�A�@���u�M��ŧ��v�A�C�W�����A�C�զp���A�@������r��$n�����V���I�I",
                            "damage":                12,
                            "dodge" :                12,
                            "parry" :                18,
                            "attact_type":  "bio",
                            "damage_type":  "�C��",
                        ]),
                       ([
                            "action": "�A�V�e�D�W�@�B�A����C�Z�A�k����C�ϥX�@���u�Ƴ��ﶳ�v����$n����ߡI ",
                            "damage":                15,
                            "dodge" :                 5,
                            "parry" :                25,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$n�A�C�׫��a�ѡA�@���u�d�p�v�q�v�A�ƥX�L�ƭӼC�y�A�q�V$n�����}�I ",
                            "damage":                20,
                            "dodge" :                10,
                            "parry" :                20,
                            "attact_type":  "bio",
                            "damage_type":  "�L�ƼC��",
                        ]),
                       ([
                            "action": "$N�A�@���u�U�y�k�v�v�A���C�ۤW�ӤU�w�w���X�@�Ӥj���A��M�q���V$n��X�I",
                            "damage":                18,
                            "dodge" :                17,
                            "parry" :                13,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$�����y�A�@���u�Q�s�ͬW�v�A���C�H�������A�I�V$n���ݸ��n�ޡI ",
                            "damage":                10,
                            "dodge" :                15,
                            "parry" :                15,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�@���u�j���ڨF�v�A�����K�a�����A���C�X�@�A�{�q���V$n�����L�I ",
                            "damage":                15,
                            "dodge" :                10,
                            "parry" :                20,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�I�X�u�i�h�s�C�v�A���C��⭸�X�A�p�C�s�뿬���C�t�A�}�Ůg�V$n���ݤf�I",
                            "damage":                12,
                            "dodge" :                20,
                            "parry" :                10,
                            "attact_type":  "bio",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N���S�@�n�A�@���u�Ѧa�b���v�A�˪ŭ��_�A�����n�X�L�ƹD���G�C�~�A��ģ�ѻڡI ",
                            "damage":                12,
                            "dodge" :                20,
                            "parry" :                10,
                            "attact_type":  "bio",
                            "damage_type":  "�C��",
                        ]),
                   });
mapping *s_action = ({
                         ([
                              "action":
                              HIR"$N�⤤���C�C�~�D�ʡM�C���ɪ��M�ۥX���`����m�M�C�y���v�Ƭ��@�C�����H�e�ݡM�ֱ��L�ۡM�u���@�C�T
                              ��H�ڥ��S�k���סM�@���u�j���جh�C�v������"HIY"�u"HIB"���C"HIY"�v"HIR"�ݺݥ������i�b$n�ݤf�T��H�@�C�Y�M�ݪ��C�ۯݤf�ޥX�T",NOR

                              "damage":                80,
                              "dodge" :                30,
                              "parry" :                30,
                              "hit" :                  45,
                              "attact_type":  "bio",
                              "damage_type":  "�C��",
                          ]),
                     });

int exert(object me, object target, string arg)
{
    string msg;
    object weapon;

    weapon=me->query_temp("weapon");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("sword")!="wind-sword")
            return notify_fail("�A�S�I�i�^���جh�C !!\n");
        me->map_skill("sword");
        me->reset_action();
        write("�A���b�ϥΦ^���جh�C !!\n");
        return 1;
    }
    if ( !weapon )  return notify_fail("�⤤�n���C�~��ϥX�^���جh�C �C\n");
    if( weapon->query("skill_type")!="sword")
        return notify_fail("�⤤�n���C�~��ϥX�^���جh�C �C\n");

    if(me->query_skill_mapped("sword")=="wind-sword")
        return notify_fail("�A���b�I�i�^���جh�C �F�C\n");
    if(me->query("ap")<15 || me->query("hp")<15 )
        return notify_fail("�A�����骬�p�L�k�ϥΦ^���جh�C �C\n");
    me->map_skill("sword", "wind-sword");
    me->reset_action();
    message_vision(HIR"$N����@��"+weapon->query("name")+HIR"�K�}�l�ϥX�^���جh�C �C\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);

    return 1;
}
mapping query_action(object me, object weapon)
{
    if (me->query_temp("wind-sword/five-hit") ) return action[random(sizeof(action))];
    if ( me->query_skill("wind-sword") >=90 && me->query("ap") > 150 && random(200)>=190 )
    {
        me->start_busy(2);
me->skill_active( "wind-sword",(: call_other, __FILE__, "five-hit",me:), 3);
    }
    if ( me->query_skill("wind-sword") >= 51  && me->query("ap") > 51 && random(200)>=171 )
    {
        me->receive_damage("ap",10);
        me->start_busy(1);
        return s_action[0];
    }
    return action[random(sizeof(action))];
}

void superpower(object me)
{
    int i,damage;
    object target,weapon;
    string *limbs;
    weapon=me->query_temp("weapon");

    if( !target ) target = offensive_target(me);

    if( environment(me) != environment(target) ) return;
    if(!me->is_fighting()) return;

    message_vision(HIG"$N�j�ܤ@�n�A�ϥX�^�h�μC�����A�⤤"+weapon->query("name")+HIG"������X�F�{�{������C\n"NOR,me);
    for (i=0;i<=4;i++)
    {
        damage=30+random(20);
        limbs = target->query("limbs");
        message_vision(HIW"$N�N�⤤"+weapon->query("name")+"���A�C���V$n��"+limbs[random(sizeof(limbs))]+"�C"NOR,me,target);
        switch( random(20) ) {
        case 0:
            message_vision(HIW"$n���P�@�D�A���}�F����!!�C\n"NOR,me,target);
            break;
        case 1:
            message_vision(HIW"$n���ߧA�������A�ɤF�U��\n"NOR,me,target);
            break;
        case 2:
            message_vision(HIW"$n���P�@�{�A�׶}�F�����C\n"NOR,me,target);
            break;
        case 3:
            message_vision(HIW"$n���P�@���A�{�}�F�����C\n"NOR,me,target);
            break;
        default:
            message_vision("$n�Q�C��뤤�A����Q��I�I",me,target);
            target->receive_damage("hp",damage);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR"\n");
            COMBAT_D->report_status(target);         //���target���A
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp") +")");
            if(wizardp(me) && me->query("env/debug"))
                tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n");
            me->receive_damage("ap",15+random(6));
            break;
        }
    }
    me->delete_temp("wind-sword/five-hit");
}

int practice_skill(object me) { return 1; }
int valid_learn(object me)    { return 1; }


