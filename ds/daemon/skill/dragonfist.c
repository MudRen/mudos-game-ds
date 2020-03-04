//QC: Luky 1999.8.17
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
int fo=this_player()->query_skill("force")/2;
void delay(object me,int cost);
mapping *action = ({
                       ([
                            "action": "$N�x�սL�۪Ť�, �H�u�s�ˤC���v���հj���ư饴�V$n",
                            "damage":                fo,
                            "attack":                20,
                            "attact_type":  "bar",
                            "damage_type":  "�x��",
                        ]),

                       ([
                            "action": "$N�g�q�@�n, �u�s�S�E�ѡv�H�E�D���R�E�����l���V$n",
                            "damage":                30+fo,
                            "dodge" :               -15,
                            "parry" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": "$N�ѤU�ӤW�_��, �@�ۡu�s�}�ƻa�v������$n�����W�}�h",
                            "damage":                20+fo,
                            "dodge" :                20,
                            "attack":               -15,
                            "attact_type":  "bar",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": "$N�����@�B, �b�b�Ť��ϥX�F�u�s�����ѡv�@�ۥ��V$n��$l",
                            "damage":                5+fo,
                            "dodge" :                5,
                            "parry" :                5,
                            "attact_type":  "bar",
                            "damage_type":  "�x��",
                        ]),

                       ([
                            "action": "$N�@�ۡu���s�Ѥ��v�x�l�z�o���O, �w�O��$n��$l�����A�U",
                            "damage":                30+fo,
                            "attack":                20,
                            "parry" :                20,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),

                       ([
                            "action": "$N���x�B��, �H�u���s�{�@�v���ձN���⤧�O�D���V$n",
                            "damage":                30+fo,
                            "dodge" :               -15,
                            "parry" :               -15,
                            "attact_type":  "bar",
                            "damage_type":  "����",
                        ]),

                       ([
                            "action": "$N��������, ���ۡu�g�s�S�ѡv�N�����O�q����x�W���V$n",
                            "damage":                50+fo,
                            "dodge" :               -35,
                            "parry" :               -35,
                            "attact_type":  "bar",
                            "damage_type":  "����",
                        ]),
                   });

int exert(object me, object target, string arg)
{
    int a,c,i,j,damage,f;
    int hs,sk,force,dodge,hit,num,df;
    string msg;
    object weapon;
    f=me->query_skill("force");
    df=me->query_skill("dragonfist");
    sk=me->query_skill("unarmed");
    weapon=me->query_temp("weapon");
    if(weapon)
    {
        if(weapon->query("skill_type")!="unarmed")
            return notify_fail("�A�⤤�ҫ��Z�����ள�ӨϥΡu�C���C�s�x�v?\n");
    }
    if(arg=="off" )
    {
        if( me->query_skill_mapped("unarmed")!="dragonfist")
            return notify_fail("�A�èS���b�ϥΡu�C���C�s�x�v�C\n");
        me->map_skill("unarmed");
        me->reset_action();
        write("�A����ϥΤC���C�s�x�F�C\n");
        return 1;
    }
    if(arg=="dragon-voice")
    {
        if(!target)
        {
            target = offensive_target(me);
            if(!target) return notify_fail("\n�A�n�b�԰����~����s�u��C\n");
        }
        if(!me->is_fighting(target))
            return notify_fail("\n�A�n�b�԰����~����s�u��C\n");
        if(me->query_skill_mapped("unarmed")!="dragonfist")
            return notify_fail("\n�A�{�b�S�Φb�ΤC���C�s�x��C\n");
        if( f < 80 || sk < 90 || df < 90 )
            return notify_fail("\n�A���\\�O�|������s�u��C\n");
        if(me->query("ap") < 300)
            return notify_fail("\n�A�����O�����ϥ��s�u��F�C\n");
        if(me->is_busy())
            return notify_fail(HIW"\n�A���b����L���Ʊ���I\n"NOR);
        //num = random(sizeof(enemy));
        //enemy[num]=present(enemy[num],environment(me));
        //c=enemy[num]->query_temp("apply/armor");
        c = target->query_armor(); //luky
        hit = random(COMBAT_D->attack_factor(me,"unarmed")); //luky
        dodge = random( - (COMBAT_D->dodge_factor(target,"dodge"))); //luky
        message_vision(HIY"$N�@�n�g�z�A���Ф��n�B�w�[����ĥX���G�V$n�I\n\n"NOR+
                       HIC"      $N��$n�ϥX��@���� �y�s �u ��z�I\n\n"NOR,me,target);
        damage = ((sk + f)*2) + random(me->query_damage()) + me->query_damage()/2;
        damage = damage + df + random(df);
        damage -= (random(c/2) + c/2);
        if(damage < 150) damage = 140+random(30);
        if(damage > 700) damage = 700+((damage-700)/5);
        if(hit+40 > dodge-20)
        {
            msg = HIM"    �u��$n�Q�j�j���l�Ҳo��A��o�D�g���ӳ�����I\n"NOR;
            message_vision(msg, me, target);
            me->improve_skill("dragonfist",random(2)+(me->query_int()/20));
            // �W�[�����ˮ`���v�T
            damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
            target->receive_damage("hp",damage,me);
            COMBAT_D->report_status(target);
            me->start_busy(3);
            target->start_busy(2);
            if(f > random(80) + target->query_level()) {
                message_vision(YEL"$N�Q�s�u��_�o�Y������A�@�ɵL�k��ʡC\n"NOR,target);
                target->add_busy(2);
            }
        }
        else
        {
            msg = RED"    ���L$n�ή����ܡA���}�F�o�D�P�R�ȭ��C\n\n"NOR;
            message_vision(msg, me, target);
            me->improve_skill("dragonfist",1);
            target->improve_skill("dodge",3+random(2));
            me->start_busy(3);
        }
        me->receive_damage("ap",150+damage/12+random(15));
        me->improve_skill("unarmed",1+(me->query_int()/10));
        me->improve_skill("force",random(2));
        return 1;
    }
    if(me->query_skill("unarmed")<50)
        return notify_fail("�A���{��i�����h�|�����ϥΤC���C�s�x�C\n");
    if(me->query("ap")<50 || me->query("hp")<30)
        return notify_fail("�A�����骬�p���}�A����ϥΤC���C�s�x�C\n");
if(!me->skill_active( "dragonfist",(: call_other, __FILE__, "delay", me ,5:), 5))
        return notify_fail("�A����ϥΤC���C�s�x���ʧ@�٨S�����C\n");
    me->map_skill("unarmed", "dragonfist");
    me->reset_action();
    message_vision(HIG"\n$N�M�S�@�n�A�}�l�ϥΤC���C�s�x�C\n"NOR,me);
    me->receive_damage("ap",10);
    me->start_busy(2);
    return 1;
}

void delay(object me,int cost)
{
    object weapon,target;
    string *limbs;
    int a,c,cs,df,force,count,num,eny,i,j,damage,hit,dodge,dex,str,lv,roll;
    lv=me->query("level");
    df=me->query_skill("dragonfist");
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
    if(me->query_skill_mapped("unarmed")!="dragonfist")
    {
        return;
    }
    if(me->query("ap")<30)
    {
        me->map_skill("unarmed");
        me->reset_action();
        tell_object(me,"\n�A����O�����A����A�Ρu�C���C�s�x�v�F�C\n");
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
                message_vision(RED"$N�����V$n�ӥh�A�@�x����$n�A�u��$n��"+limbs[random(sizeof(limbs))]+"�B�{�C��x�L�A$n�n�ɤf�R�A��I\n"NOR,me,target);
                me->improve_skill("dragonfist",random(1)+(me->query_int()/20)); //�S����B�~�W�[
                // �W�[�����ˮ`���v�T
                damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                target->receive_damage("hp",damage,me);
                me->receive_damage("ap",damage/10+random(5));
                COMBAT_D->report_status(target);
            }
            else
            {
                message_vision(RED"$N�����V$n�ӥh�A��$n�s�M�Ӹ��A�����{�F�}�h�C\n"NOR,me,target);
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
            message_vision(HIC"\n$N��$n�ϥX �y�s �C �C �� ���z�I\n\n"NOR,me,target);
            message_vision(CYN"�u���C�D�ܤ۲������x�k��$N���b�V$n�g��ӥh�I\n\n"NOR,me,target);
            if(hit + 40> dodge)
            {
                for(a=0;a<7;a++)
                {
                    message_vision(HIY"�@�D�Q�D�L�����x�O���b$N��"+limbs[random(sizeof(limbs))]+"�W�I\n"NOR,target);
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
                message_vision(CYN"��$n½���@�{�A�C�D�x�պɼƸ��šC\n"NOR,me,target);
                target->improve_skill("dodge",2);
                me->receive_damage("ap",25+random(16));
            }
            me->improve_skill("unarmed",(me->query_int()/4)+1);
        }
        me->receive_damage("ap",5); //luky
        me->improve_skill("unarmed",(me->query_int()/10)+1); //luky
        me->improve_skill("dragonfist",1+(me->query_int()/10)); //luky �@�ԮɺC�C�W�[
    }
me->skill_active( "dragonfist",(: call_other, __FILE__, "delay", me ,cost:), 5);
}

int valid_learn(object me) {	return 1;	}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) {	return 1; }

int improve_limite(object ob)
{
    int a;
    a=ob->query_skill("unarmed");
    if(a>70) a=70;
    if(ob->query("adv_class")==2) return 100;
    else if(ob->query("adv_class")==1) return a;
}
