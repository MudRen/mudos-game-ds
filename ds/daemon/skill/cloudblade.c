//update by linjack 99.10.19
//QC : Luky [10.21.1999]
#include <ansi.h>
#define DELAY 
inherit SKILL;
inherit SSERVER;
string *adv_attack = ({
                          "$N���ⴤ��M�`�A�O�e�M�W���@�ۡy"HIC"�}���}��"NOR"�z�w�������A�X�@�D�M����V$n�A\n",
                          "$N�[�ָ}�B�A�H���֪��t�ױ�¶$n�A�H�X�_���N���@���y"HIR"�T���G��"NOR"�z��V$n�A\n",
                      });
mapping *action = ({
                       ([
                            "action": "$N�H�u�@���}�����v�@�ۡA���$w�D�ܪŤ��A��$n���B�Y�A�h",
                            "damage":                12,
                            "dodge" :               -10,
                            "attact_type":  "bar",
                            "damage_type":  "�A��"
                        ]),
                       ([
                            "action":"$N���Ϋ���A�@���u���R�����i�v�A�⤤$w�n�̤��w����V$n",
                            "damage":     6,
                            "dodge" :    20,
                            "attact_type":  "bar",
                            "damage_type":  "�A��"
                        ]),
                       ([
                            "action":"$N�ϥX�u�M�j���Ѷ}�v�A$w¶$N�@��A�@�ӽb�B�ĦV$n��A�ӥh",
                            "damage": 10,
                            "attack": 10,
                            "attact_type":  "bar",
                            "damage_type":  "���"
                        ]),
                       ([
                            "action":"$N���W�Ť��A�@�ۡu�C���ѻڵ��v�A�ѤW�ӤU���R��$w��V$n",
                            "damage": 15,
                            "dodge" : -20,
                            "attact_type":  "bar",
                            "damage_type":  "���"
                        ]),
                       ([
                            "action":"$N�B�l��$w���W�A���M�O���ۡu�����i�ܾ_�v�A�⤤$w�a�ʱj�j�l�O��V$n",
                            "damage":  20,
                            "parry":  -20,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),
                       ([
                            "action":"$N���$w�A���ηn�\\��\�w�A�u���v�H����v�@�ۥH�맮���۪�����V$n",
                            "damage":   5,
                            "dodge":   20,
                            "parry":   20,
                            "attack":  20,
                            "attact_type":  "bar",
                            "damage_type":  "�A��",
                        ]),
                   });
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
    int a,c,i,j,damage,cb,bd,b,d,e,da,cf,roll;
    string msg,aa;
    object weapon;
    mapping type;
    weapon=me->query_temp("weapon");
    da = me->query_damage();
    cb = me->query_skill("cloudblade");
    bd = me->query_skill("blade");
    cf = me->query_skill("cloudforce");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("blade")!="cloudblade")
            return notify_fail("�A�S���b�ϥΦV���M�k�a�C\n");
        me->map_skill("blade");
        me->reset_action();
        write(CYN"�A���_�M�աA�ݤF�f��A���ϥΦV���M�k�F�C\n"NOR);
        return 1;
    }
    if(!weapon || weapon->query("skill_type")!="blade")
        return notify_fail("���ΤM�A�p��ϥX�M�k�H�A�H���A�j��i�H�{��o�X�M��ڡH\n");
    if(bd < 5)
        return notify_fail("����t�l���򥻤M�k�A�p���e�q�V���M�k��䤤�O�H\n");
    if(me->query("ap")<15 || me->query("hp")<10)
        return notify_fail("�A�����O�F�a�C\n");
    //�ĤG��exert
    if(me->query_skill_mapped("blade")=="cloudblade")
    {
        if( cb < 25 || bd < 25 )
            return notify_fail("�A���ޥ��٤��¼��A����ΦV���M�k�����ޡC\n");
        if( me->query("hp") < 20 || me->query("ap") < 30 )
            return notify_fail("�A�����骬�p�w�g�Ӯt�F�A����ΦV���M�k�����ޡC\n");
        if( !target ) target = offensive_target(me);
        if( !target )	return notify_fail("�A�w�g�b�ϥΦV���M�k�F�C\n");
        //�����ʪ��n�S�O�`�N�n�[�U�����.
        if( !me->can_fight(target)) return me->can_fight(target);
        if( !me->is_fighting(target)) me->kill_ob(target);
        if( !target->is_fighting(me)) target->kill_ob(me);
        c = target->query_armor();
        d = random(sizeof(adv_attack));
        msg = adv_attack[d];
        //�ίS�𪺱ԭzsizeof���X���P���G
        if( d == 0 )
        {
            damage = (da/2) + (cb/2) + (cf/2) + random(16);
            damage = damage - (c/2) - random(c/2);
            if( damage > 180 ) damage = 180 + random((damage-180)/4);
            if( damage <  20 ) damage = 17 + random(8);
            if(random(COMBAT_D->attack_factor(me,"blade")) + cb/3 > random( - (COMBAT_D->dodge_factor(target,"dodge"))))
            {
                roll = random(100);
                msg += HIY"\n���G$n ---- "HIC"���ۤF"HIY"�I\n\n"NOR;
                message_vision(msg, me, target);
                me->improve_skill("cloudblade",2 + (me->query_int()/8) + random(2));
                me->improve_skill("blade",2 + random(2));
                // �W�[�����ˮ`���v�T
                damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                target->receive_damage("hp",damage,me);
                COMBAT_D->report_status(target);
                if( cb > 50 && bd > 55 && roll > 60 )
                {
                    message_vision(HIM"$N��$n�Q�@�}������äF�}�}�A�X�զA�l�ɤ@�M�I\n"NOR,me,target);
                    me->improve_skill("cloudblade",2 + (me->query_int()/10));
                    me->improve_skill("blade",2 + random(2));
                    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),2);
                    COMBAT_D->report_status(target);
                    if( cb > 80 && bd > 90 && roll > 72)
                    {
                        message_vision(HIM"$N��$n�Q�@�}������äF�}�}�A�X�զA�l�ɤ@�M�I\n"NOR,me,target);
                        me->improve_skill("cloudblade",3+(me->query("lv")/5));
                        me->improve_skill("blade",(me->query("lv")/4));
                        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
                        COMBAT_D->report_status(target);
                    }
                }
                target->start_busy(1);
                me->start_busy(2);
            }
            else
            {
                msg += HIY"\n���G$n ---- "CYN"�S����"HIY"��\n\n"NOR;
                message_vision(msg, me, target);
                target->improve_skill("dodge",1);
                me->start_busy(2);
                me->improve_skill("blade",1);
            }
            if(!me->is_fighting(target)) me->kill_ob(target);
            if(!target->is_fighting(me)) target->kill_ob(me);
            me->receive_damage("ap",14+random(7));
            me->improve_skill("blade",1);
            return 1;
        }
        else if( d == 1 )
        {
            damage = (da/3) + random(cb/4) + (cb/4) + (cf/2) + random(11);
            damage = damage - (c/3) - random(c*2/3);
            if( damage > 130 ) damage = 130 + random((damage-130)/3);
            if( damage <  15 ) damage = 14 + random(5);
            if(random(me->query_dex()*2+cb/3)+25 > random(target->query_dex()*2+target->query_skill("dodge")/2))
            {
                roll = random(100);
                msg += HIC"\n$n�{���F�@�Ӥ��A���ۤF�I\n\n"NOR;
                message_vision(msg, me, target);
                me->improve_skill("cloudblade",2 + (me->query_int()/8) + random(2));
                me->improve_skill("blade",1+random(2));
                // �W�[�����ˮ`���v�T
                damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                target->receive_damage("hp",damage,me);
                COMBAT_D->report_status(target);
                if( cb > 60 && bd > 70 && roll > 65)
                {
                    message_vision(HIR"$N��$n���εy�������A���W�S�A�X��F���@�M�I\n"NOR,me,target);
                    me->improve_skill("cloudblade",2 + (me->query_int()/10));
                    me->improve_skill("blade",2 + random(2));
                    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
                    COMBAT_D->report_status(target);
                }
                me->start_busy(1);
            }
            else
            {
                msg += CYN"\n�i�O���Q$n�s�}�����A�{�}�F�o�ۡC\n\n" NOR;
                message_vision(msg, me, target);
                target->improve_skill("dodge",1);
                me->start_busy(2);
                target->start_busy(1);
            }
            if(!me->is_fighting(target)) me->kill_ob(target);
            if(!target->is_fighting(me)) target->kill_ob(me);
            me->receive_damage("ap",12+random(9));
            me->improve_skill("blade",2);
            return 1;
        }
    }
    //fix by luky
if(!me->skill_active( "cloudblade",(: call_other, __FILE__, "delay", me ,5:), 5))
        return notify_fail("�A�٦b�ΦV���M�k���O�C\n");
    me->map_skill("blade","cloudblade");
    me->reset_action();
    message_vision("\n$N���_�⤤��"+weapon->query("name")+NOR+"���ʴX�U�A�ϰ_"HIG"�V���M�k"NOR"�C\n",me);
    me->receive_damage("ap",10);
    me->start_busy(2);
    return 1;
}
void delay(object me,int cost)
{
    object weapon,target;
    int roll;
    if(!me) return;
    weapon=me->query_temp("weapon");
    if(!weapon)
    {
        me->map_skill("blade");
        me->reset_action();
        return;
    }
    if(weapon->query("skill_type")!="blade")
    {
        me->map_skill("blade");
        me->reset_action();
        return;
    }
    if(me->query_skill_mapped("blade")!="cloudblade")
    {
        return;
    }
    if(me->query("ap")<15)
    {
        me->map_skill("blade");
        me->reset_action();
        tell_object(me,"\n�A�����O�w�g�A���A�L�k�A�ϥΦV���M�k�C\n\n");
        return ;
    }
    if( me->is_fighting() )
    {
        roll = random(100);
        if( !target ) target = offensive_target(me);
        if( me->query_skill("cloudblade")>30 && me->query_skill("blade") > 35 && roll > 50 && !me->is_busy() && !me->is_block())
        {
            message_vision(CYN"$N���Τ@��A��M��$n�o�X��"+YEL+"�G"+CYN+"�M�����I\n"NOR,me,target);
            me->improve_skill("cloudblade",1 + (me->query_int()/10));
            me->improve_skill("blade",1 + random(2));
            COMBAT_D->do_attack(me,target,me->query_temp("weapon"),3);
            COMBAT_D->report_status(target);
            if( me->query_skill("cloudblade")>50 && me->query_skill("blade") > 60 && roll > 68)
            {
                message_vision(HIC"$N���Τ@��A��M��$n�o�X��"+HIY+"�T"+HIC+"�M�����I\n"NOR,me,target);
                me->improve_skill("cloudblade",2 + (me->query_int()/10));
                me->improve_skill("blade",2 + random(2));
                COMBAT_D->do_attack(me,target,me->query_temp("weapon"),2);
                COMBAT_D->report_status(target);
                if( me->query_skill("cloudblade")>75 && me->query_skill("blade") > 90 && roll > 80)
                {
                    message_vision(HIG"$N���Τ@��A������$n�o�X�̰��q����"+HIR+"�|"+HIG+"�M�����I\n"NOR,me,target);
                    me->improve_skill("cloudblade",3 + (me->query_int()/5));
                    me->improve_skill("blade",4 + random(4));
                    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),4);
                    COMBAT_D->report_status(target);
                    me->receive_damage("ap",25);
                }
                me->receive_damage("ap",15);
            }
            me->receive_damage("ap",7);
        }
        me->receive_damage("ap",4); //luky
    }
me->skill_active( "cloudblade",(: call_other, __FILE__, "delay", me ,cost:), 5);
}
int valid_learn(object me) {	return 1;	}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) {	return 1; }

int improve_limite(object ob)
{
    int a,b;
    if( ob->query("class1")!="�V����" ) return 15;  //�t�X�J����quest��
    else if( ob->query("adv_class")==1 ) return 85;   //�S���@�ध�e�u��m��85
    else return 95;  //�̰��m��95
}
