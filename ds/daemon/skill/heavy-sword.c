#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me);
void superpower(object me,object target,int z,int damage);
mapping *action = ({


                       ([
                            "action": "$N�N�⤤$w����A�@�ۡi���j�A��վU���i�סA�Φ��@�ѱj�j�ۭ��A���V$n��$l",
                            "damage":               -16,
                            "dodge" :                20,
                            "parry" :                10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "�u�I !�v���@�n�A$N���}�ަa�A�z�o�O�Q���A�@�ۡi���A�j�A$w���C�y���}�Ů�A��V$n��$l",
                            "damage":                17,
                            "dodge" :                20,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�i�L�}���B�A�ĤO�V�e���ġA�@�ۡi��A�j�A��$w����d�x�����A�A���V$n��$l",
                            "damage":               -13,
                            "dodge" :                20,
                            "parry" :                12,

                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�۰_�v���A�H$n�����ۡA��$w���}���A�@�ۡi�׼A�j�A�H�Ѧa�U�������ҡA���V$n��$l",
                            "damage":                16,
                            "dodge" :               -20,
                            "parry" :                30,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�ਭ�R�ߡA$n����𤧡A�ݦ������A�@�ۡi�ϩ�j�A$w�C���f�۪Ů�A��V$n��$l",
                            "damage":               -25,
                            "dodge" :               -25,
                            "parry" :                30,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),


                   });
int exert(object me, object target, string arg)
{
    int sk,damage;
    object weapon;
    sk=me->query_skill("heavy-sword");
    weapon=me->query_temp("weapon");
    if( me->is_ghost() ) return notify_fail("Pray luky �a . . .\n");
    if (!weapon) return notify_fail("�S�C���I�i�u���C�N�v�z?\n");
    if(weapon->query("skill_type")!="sword") return notify_fail("�S�C���I�i�u���C�N�v�z?\n");

    if(arg=="off" )
    {
        if( me->query_skill_mapped("sword")!="heavy-sword")
            return notify_fail("�A�b���ڶ�?�A�S�ϡu���C�N�v�� !\n");
        me->map_skill("sword");
        me->reset_action();
        write("�u���C�N�v�w����ϥΡC\n");
        return 1;
    }

    if(me->query_skill("heavy-sword")<2) return notify_fail("�[�o ! ! �ATrain�@���u���C�N�v�C\n");
    if(me->query("ap")<20 || me->query("hp")<50) return notify_fail("�A�����p���ΡA���ծ��n�A�ϡu���C�N�v�a�C\n");

    if(me->query_skill_mapped("sword")=="heavy-sword")
    {
        if( me->is_ghost() ) return notify_fail("Pray luky �a !\n");
        if( !target ) target = offensive_target(me);
        if (!me->is_fighting())
            return notify_fail("�A���b�ϥΡu���C�N�v�F�C\n");
        if (me->query_skill("heavy-sword") < 50)
            return notify_fail("�A�ثe��u���C�N�v�����A�|�L�k�ϥΡu���C�s���v�C\n");
        if(me->query("ap")<60)
            return notify_fail("�A��ap�����A�L�k�ϥΡu���C�s���v�C\n");

        if(!me->can_fight(target)) return me->can_fight(target);
        if(!me->is_fighting(target) ) return notify_fail("�A�èS���b�԰���C\n");
        message_vision(HIC"$N�����٦׺��^�A�⤤"+weapon->query("name")+HIB"�����P�L��A�@�D�ӤU�A�i���C�s���N�j�A�w�O�ϥX�C\n\n"NOR,me);
        me->receive_damage("ap",15+random(16));
        me->start_busy(1+random(2));
        call_out("superpower",1,me,target,1,damage);
        return 1;
    }

if(!me->skill_active( "heavy-sword",(: call_other, __FILE__, "delay", me ,5:), 10)) return notify_fail("�A���ʧ@�������C\n");

    me->map_skill("sword", "heavy-sword");
    me->reset_action();
    message_vision("\n"HIG"$N�H"+weapon->query("name")+HIW "��_�@�ۭ��A�u �� !�v���@�n�A�N�䴡�J�a�W�A�޾ɡu���C�N�v���u�͡C\n"NOR,me);
    me->receive_damage("ap",50);
    me->start_busy(2);
    //      me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
    return 1;
}
void superpower(object me,object target,int z,int damage)
{
    string msg="";
    if(!target) target = offensive_target(me);
    if(!target) return;
    if(!me) return ;
    if(!me->is_fighting()) return;
    if( environment(me) != environment(target) ) return;
    if(!me->is_fighting(target)) me->kill_ob(target);

    z=me->query_skill("heavy-sword");

    msg +=HIG"�i"HIB"���"HIG"�j"NOR"\n";
    msg +=HIG"�i"HIB"���A"HIG"�j"NOR"\n";
    msg +=HIG"�i"HIB"��A"HIG"�j"NOR"\n";
    msg +=HIG"�i"HIB"�׼A"HIG"�j"NOR"\n";
    msg +=HIG"�i"HIB"�ϩ�"HIG"�j"NOR"\n";
    msg +=HIW" �� �� �s �X �A �� �� �� �V $n �� �� �R "NOR"\n";

    message_vision(msg, me, target);

    if( z/3 + random(z) > random(target->query_skill("dodge")) )
    {
        damage = me->query_skill("sword") + random(me->query("str")) - target->query_armor()/2 - random(target->query_armor()/2) - (target->query("con"));
        if(damage>230) damage=230+((damage-230)/5);
        if(damage<30) damage=25+random(10);

        message_vision(HIR "\n�G�M . . .$n�H������O��סA����M�ߤO�����A���n�����C\n" NOR,me,target);


        damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        target->receive_damage("hp",damage,me);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
            tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
            tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
        message_vision("\n",target);
        COMBAT_D->report_status(target);
    }
    else {
        message_vision(HIC "\n$n�H������O��סA�N���C�s���A���ƥ˸ѡC\n" NOR,me,target);

    }
    if(!me->is_fighting(target)) me->kill_ob(target);
}

void delay(object me)
{
    object weapon;
    if( !me ) return;

    weapon=me->query_temp( "weapon" );

    if( !weapon || weapon->query("skill_type") != "sword" )
    {
        me->map_skill("sword");
        me->reset_action();
        return;
    }

    if( me->query_skill_mapped("sword")!="heavy-sword" )
    {
        return;
    }


    if( me->query("ap")<20 )
    {
        me->map_skill("sword");
        me->reset_action();
        message_vision("\n"HIY"$N"HIR"�����O�����~��ϥ�"HIB"�u���C�N�v�C\n"NOR,me);
        return ;
    }

    if( me->is_fighting() ) me->receive_damage("ap",10);
me->skill_active( "heavy-sword",(: call_other, __FILE__, "delay", me :), 8);
}

int valid_learn(object me) {    return 1;       }
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

