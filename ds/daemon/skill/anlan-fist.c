#include <ansi.h>
inherit SKILL;
inherit SSERVER;
int fo=this_player()->query_skill("force")/2;
void delay(object me,int cost);
mapping *action = ({
                       ([
                            "action": "$N������W�A��k��ܸy�I�A�񥪴x�Ӧ�Aí�Y���s�A��$n��$l���h",
                            "damage":                fo,
                            "attack":                20,
                            "attact_type":  "bar",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": "$N�ߩw���ʡA�ϥ��⹺��A�r�M��V$n�����e�A�x�k�������V$n��$l",
                            "damage":                30+fo,
                            "dodge" :               -15,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "����",
                        ]),


                       ([
                            "action": "$N����y�A�ۥΥ��x�A�J����ۦp�b$n���y�ǡA�G�U�x�I��W",
                            "damage":                20+fo,
                            "dodge" :                20,
                            "attack":               -15,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N��������áA�H�J���k�W��i�}�A�ζ}�l�����V$n��$l",
                            "damage":                5+fo,
                            "dodge" :                -5,
                            "parry" :                15,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),

                       ([
                            "action": "$N�N��ߦV�~½�A���I�}�y�A�����ѥk�V���ݥh�A�@�ѫl�O��$n�e�h",
                            "damage":                30+fo,
                            "attack":                20,
                            "parry" :                20,
                            "attact_type":  "bar",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": "$N�Ԥ���@�B�A�P�ɹB�_���O�A��$n���⹺���A�H�J�����V�e���h",
                            "damage":                30+fo,
                            "dodge" :               -15,
                            "parry" :               -15,
                            "attact_type":  "bar",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": "$N��ߴ¤��A�ѤW�ӤU�A�p����Ť@��A����x�����V$n��$l",
                            "damage":                50+fo,
                            "dodge" :               -35,
                            "parry" :               -35,
                            "attact_type":  "bar",
                            "damage_type":  "����",
                        ]),


                       ([
                            "action": "$N�ϴx����M�A�����C�N�����A�A���ꤣ�ت�����V$n��$l",
                            "damage":                30+fo,
                            "dodge" :                -20,
                            "parry" :                20,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),
                       ([
                            "action": "$N�ϴx����M�A�����C�N����A�A���ꤣ�ت����V$n��$l",
                            "damage":                30+fo,
                            "dodge" :                -20,
                            "parry" :                20,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),
                       ([
                            "action": "$N�ϴx����M�A�����C�N���׼A�A���ꤣ�ت��׬�V$n��$l",
                            "damage":                30+fo,
                            "dodge" :                -20,
                            "parry" :                20,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),
                       ([
                            "action": "$N�ϴx����M�A�����C�N�����A���ꤣ�ت���V$n��$l",
                            "damage":                30+fo,
                            "dodge" :                -20,
                            "parry" :                20,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�ϴx����M�A�����C�N���ϩ�A���ꤣ�ت�ŧ�V$n��$l",
                            "damage":                30+fo,
                            "dodge" :                -20,
                            "parry" :                20,
                            "attact_type":  "bar",
                            "damage_type":  "���",
                        ]),
                   });


int exert(object me, object target, string arg)
{
    int a,c,i,j,damage,f;
    int hs,sk,force,dodge,hit,num,df;
    string msg;
    object weapon,victim;
    f=me->query_skill("force");
    df=me->query_skill("anlan-fist");
    sk=me->query_skill("unarmed");
    weapon=me->query_temp("weapon");
    if(weapon)
    {
        if(weapon->query("skill_type")!="unarmed")
            return notify_fail("�ϥΡu�f�M�P��x�v���ள�Z���C\n");
    }
    if(arg=="off" )
    {
        if( me->query_skill_mapped("unarmed")!="anlan-fist")
            return notify_fail("�A�S�b�ϥΡu�f�M�P��x�v�� ?\n");
        me->map_skill("unarmed");
        me->reset_action();
        write("�u�f�M�P��x�v�w���ΡC\n");

        return 1;
    }
    if(arg=="anlan")

    {
        if(!target)
        {
            target = offensive_target(me);
            if(!target) return notify_fail("\n�A�èS�b�԰����C\n");
        }
        if(!me->is_fighting(target))
            return notify_fail("\n�A�èS���b�԰����C\n");
        if(me->query_skill_mapped("unarmed")!="anlan-fist")
            return notify_fail("\n�A�èS���ϥΡu�f�M�P��x�v�C\n");
        if( f < 80 || sk < 90 || df < 90 )
            return notify_fail("\n�A��u�f�M�P��x�v�����A�|�ݧV�O�C\n");
        if(me->query("ap") < 300)
            return notify_fail("\n�A��ap�����C\n");
        if(me->is_busy())
            return notify_fail(HIC"\n�A�S�Ű� ~ ~ ~ �I\n"NOR);
        //num = random(sizeof(enemy));
        //enemy[num]=present(enemy[num],environment(me));
        //c=enemy[num]->query_temp("apply/armor");
        c = target->query_armor();

        hit = random(COMBAT_D->attack_factor(me,"unarmed"));
        dodge = random( - (COMBAT_D->dodge_factor(target,"dodge")));

        message_vision(HIC"$N��_���l�A��B���СA�@�������q�_���K�ߡI\n\n"NOR+
                       HIG"��    ��   $n   ��    �X    ��    ��    �I\n\n"NOR,me,target);
        damage = ((sk + f)*2) + random(me->query_damage()) + me->query_damage()/2;
        damage = damage + df + random(df);
        damage -= (random(c/2) + c/2);
        if(damage < 150) damage = 140+random(30);
        if(damage > 700) damage = 700+((damage-700)/5);
        if(hit+40 > dodge-20)
        {
            msg = HIB "$N���X�u�f�v�r�СA�����a���V$n�������I�I�I�I\n" NOR ;
            msg = HIR "            �uť��$n�j�z�@�n ~ ~ ~�I�I�I\n" NOR ;
            msg = CYN "$N���X�u�M�v�r�СA�����a���V$n���I���I�I�I�I\n" NOR ;
            msg = HIR "            �uť��$n�j�z�@�n ~ ~ ~�I�I�I\n" NOR ;
            msg = MAG "$N���X�u�P�v�r�СA�����a���V$n���ݳ��I�I�I�I\n" NOR ;
            msg = HIR "            �uť��$n�j�z�@�n ~ ~ ~�I�I�I\n" NOR ;
            msg = GRN "$N���X�u��v�r�СA�����a���V$n���Y���I�I�I�I\n" NOR ;
            msg = HIR "            �uť��$n�j�z�@�n ~ ~ ~�I�I�I\n" NOR ;
            msg = YEL "$N���X�u�x�v�r�СA�����a���V$n���y���I�I�I�I\n" NOR ;
            msg = HIR "            �uť��$n�j�z�@�n ~ ~ ~�I�I�I\n" NOR ;
            message_vision(msg, me, target);
            me->improve_skill("anlan-fist",random(2)+(me->query_int()/20));
            // �W�[�����ˮ`���v�T
            damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
            target->receive_damage("hp",damage,me);
            COMBAT_D->report_status(target);
            me->start_busy(2);
            target->start_busy(2);
            if(f > random(80) + target->query_level()) {
                message_vision(HIR""+victim->query_name(1)+"�Q���o����b�a�W�A�f���w�w�y�X�A��C\n"NOR,target);
                target->add_busy(3);

            }
        }
        else
        {
            msg = HIW"$n���G�P�������{�A�V��@���A�ϱo$N�ۦ��L�k�s�e�A�N���@�}�C\n\n"NOR;
            message_vision(msg, me, target);
            me->improve_skill("anlan-fist",1);
            target->improve_skill("dodge",3+random(2));
            me->start_busy(3);
        }
        me->receive_damage("ap",30);
        me->improve_skill("unarmed",1+(me->query_int()/10));
        me->improve_skill("force",random(2));
        return 1;
    }
    if(me->query_skill("unarmed")<60)
        return notify_fail("�ϥΡu�f�M�P��x�v�ݭn�������i���ޥ����ܴ��x�k�C\n");
    if(me->query_skill("dodge")<50)
        return notify_fail("�ϥΡu�f�M�P��x�v�ݭn�������{���ޥ��Ӳo��ĤH�C\n");
    if(me->query("ap")<50 || me->query("hp")<30)
        return notify_fail("�A���骬�p���ΡA�ϥΡu�f�M�P��x�v�|���M�I�C\n");
if(!me->skill_active( "anlan-fist",(: call_other, __FILE__, "delay", me ,5:), 5))
        return notify_fail("�A���ʧ@�٨S�����C\n");
    me->map_skill("unarmed", "anlan-fist");
    me->reset_action();

    message_vision(BLU"\n$N½�x�ܯݡA�V�e�ť��A�x�����a�ۦʯ�L�`�A�L�椤���X�F�u�f�M�P��x�v�C\n"NOR,me);
    me->receive_damage("ap",10);
    me->start_busy(2);
    return 1;
}

void delay(object me,int cost)
{
    object weapon,target,victim;
    string *limbs;
    int a,c,cs,df,force,count,num,eny,i,j,damage,hit,dodge,dex,str,lv,roll;
    lv=me->query("level");
    df=me->query_skill("anlan-fist");
    force=me->query_skill("force");
    dex=me->query("dex");
    str=me->query("str");
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
    if(me->query_skill_mapped("unarmed")!="anlan-fist")
    {
        return;
    }
    if(me->query("ap")<30)
    {
        me->map_skill("unarmed");
        me->reset_action();
        tell_object(me,"\n�A����O�����A����ϥΡu�f�M�P��x�v�F�C\n");
        return;
    }
    if( me->is_fighting() && !me->is_busy() )
    {
        roll = random(df);
        if( !target ) target = offensive_target(me);
        if( me->query_skill("force")>50 && me->query_skill("dragonfist") > 50&& me->query("ap") > 200&& roll > 30)
        {
            limbs = target->query("limbs");
            c=target->query_armor();

            hit = random(COMBAT_D->attack_factor(me,"unarmed")+df/3);
            dodge = random(- (COMBAT_D->dodge_factor(target,"dodge")));
            if(lv>50) lv=50;
            damage = (df*2/3) + ((random(me->query_damage()) + random(force*2/3))*2) + (lv*7/2);
            damage -= (c/2 +random(c/3));
            damage = damage * 5 / 6;
            if(damage < 20) damage = 18+random(5);
            if(damage > 333) damage = 333+((damage-333)/5);
            if(hit + 45> dodge)
            {
                message_vision(HIR"$N��h�ƪѯu��A�a���$N�ܴ��x�k�A�u�ݨ�"+victim->query_name(1)+"���y�I�z���@�n�A�B��������I\n"NOR,me,target);
                me->improve_skill("anlan-fist",random(1)+(me->query_int()/20)); //�S����B�~�W�[
                // �W�[�����ˮ`���v�T
                damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                target->receive_damage("hp",damage,me);
                me->receive_damage("ap",damage/10+random(5));
                COMBAT_D->report_status(target);
            }
            else
            {
                message_vision(HIW"$n�}�j������{�F�L�h�C\n"NOR,me,target);
                target->improve_skill("dodge",2);
                me->receive_damage("ap",15+random(11));

            }
            me->improve_skill("unarmed",(me->query_int()/4)+1);
        }
        if( me->query_skill("force")>80 && df > 90&& me->query("ap") > 300&& roll > 55)
        {
            limbs = target->query("limbs");
            c=target->query_armor();
            hit = random(COMBAT_D->attack_factor(me,"unarmed")+df/3);
            dodge = random(- (COMBAT_D->dodge_factor(target,"dodge")));
            if(lv>50) lv=50;
            message_vision(HIC"\n$N�[�𾮯��A������X���u��ϱo�|�g���Ů𳣵��B�I\n\n"NOR,me,target);
            message_vision(HIB"���X�F�u�f�M�P��x�v���⮩ �I\n\n"NOR,me,target);
            if(hit + 40> dodge)
            {
                for(a=0;a<7;a++)
                {
                    message_vision(HIR"�⮩�X�Ӫ��x�k�A�¤O�L��a���b$N��$l�W�I\n"NOR,target);
                    me->improve_skill("dragonfist",random(2)+(me->query_int()/40)); //�S����B�~�W�[
                    // �W�[�����ˮ`���v�T
                    damage = (df/9) + (force/9) + (random(df+force)/11) + (str/3) + (dex/3) + (random((str+dex)*3)/4) + random(lv/4);
                    damage = damage - (c/7) - random(c/7);
                    damage = damage * 6 / 7;
                    if(damage < 20) damage = 17 + random(6);

                    if(damage > 130) damage = 130 + ((damage-130)/5);
                    damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                    target->receive_damage("hp",damage,me);
                    me->receive_damage("ap",damage/10+random(5));
                    COMBAT_D->report_status(target);
                }
            }
            else
            {
                message_vision(HIW""+victim->query_name(1)+"���Ů𳣵��B�A�ߤ����G���N���СA��ĵ��������@���C\n"NOR,me,target);
                target->improve_skill("dodge",2);
                me->receive_damage("ap",25+random(16));
            }
            me->improve_skill("unarmed",(me->query_int()/4)+1);
        }
        me->receive_damage("ap",5); //luky
        me->improve_skill("unarmed",(me->query_int()/10)+1);
        me->improve_skill("dragonfist",1+(me->query_int()/10));
    }
me->skill_active( "anlan-fist",(: call_other, __FILE__, "delay", me ,cost:), 5);
}

int valid_learn(object me) {    return 1;       }


mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
    int a;
    a=ob->query_skill("unarmed");
    if(a>70) a=70;}

