#include <ansi.h>
inherit SKILL;
inherit SSERVER;
string *adv_attack = ({
                          HIY"$N��ܤ@�n�A���s�Z�����y��z�r�Z�����]���j�j�C��g�V$n,"NOR,
                          HIY"$N���X�|�D�C��A�H�޲����y�ܡz�r�Z�q���P����V$n,"NOR,
                          HIY"$N�N�C��e�`��a�A�H�y�ʡz�r�Z���a�N�C��D�_���V$n,"NOR,
                          HIY"$N���D�Ť��A�ޥαj�j���O�R�ʡy�p�z�r�Z�A�V$n,"NOR,
                          HIW"$N�^���r�a�@��A�H��B��A�@�ۡy�H�z�r�Z���V$n,"NOR,
                          HIW"$N�j�ܤ@�n�A�l�������A�@�f��b�C�W���E�y�V�z�r�Z���V$n,"NOR,
                          HIW"$N�|���C��A���������A�@���y�~�z�r�Z���V$n,"NOR,
                          HIW"$N�׻E�Q���\\�O\�A�y�١z�r�Z�w�������A�V$n,"NOR,
                      });
mapping *action = ({
                       ([
                            "action": "$N�ϥX�@���u"HIM"���E�{�@��"NOR"�v,��$w���ѦӤU,��$n�A�h",
                            "damage":                30,
                            "dodge" :               -20,
                            "attact_type":  "bar",	// �]�w�ޯ઺��������
                            // ������ �ͪ�(bio) �~��(bar)
                            // �]�k(wit)���F(sou)���(tec)
                            "damage_type":  "�A��"
                        ]),
                       ([
                            "action":"$N�����, �@�ۡu"HIW"���P����"NOR"�v,$w�����Ʀ��|�D�C��,
                            �|�D�C�𪽮g�V$n",
                            "damage":    20,
                            "dodge" :    20,
                            "attact_type":  "bar",
                            "damage_type":  "���"
                        ]),
                       ([
                            "action":"$N�ϥX�u"HIY"�@�C�ʪe�s"NOR"�v,�⤤����$w, �o�X�j�j�C��g�V$n",
                            "damage": 25,
                            "attact_type":  "bar",
                            "damage_type":  "���"
                        ]),
                       ([
                            "action":"$N�R�ƼC��, �@�����ۡy"HIW"�F�p�u�_��"NOR"�z,$w���C�b�W�UŸ��,�Φ��@���q��
                            �ʦ�$n���h��,�L�ƪ��C���V$n���U�j�n��",
                            "damage": 45,
                            "dodge" : -20,
                            "attact_type":  "bar",
                            "damage_type":  "���"
                        ]),
                       ([
                            "action":"$N�B�X�u"HIC"�B�������H"NOR"�v�@��, $w�C�~�������z�H�H�H��ŧ�V$n",
                            "damage":  30,
                            "dodge":   10,
                            "attact_type":  "bar",
                            "damage_type":  "���"
                        ]),
                       ([
                            "action":"$N�ϥX�@�ۡu"HIR"�����P�p�K"NOR"�v,$N�N�P���������$w����, �A½$w�j��,
                            ���X�����C���V$n"+NOR,
                            "damage":  35,
                            "dodge":  -15,
                            "attact_type":  "bar",
                            "damage_type":  "�N��"
                        ]),
                       ([
                            "action":"$N�ϥX�u"HIG"��~���i�s"NOR"�v,$N�⤤$w�J�M�@��, �j���V�e���X
                            �j�j��~, ����V$n",
                            "damage":  30,
                            "attact_type":  "bar",
                            "damage_type":  "���"
                        ]),
                       ([
                            "action":"$N�����ݰ�, �\\�O\����$w����, ���ۡy"HIM"�g"HIC"��"HIR"�}"HIG"�s"HIW"��"NOR"�z�@���o�X�j�j�C��,
                            ��������$n�g�A�ӥh",
                            "damage": 60,
                            "dodge":  -10,
                            "attact_type":  "bar",
                            "damage_type":  "�Y�����"
                        ]),
                   });
void delay(object me,int cost);
int exert(object me, object target, string arg)
{
    int a,c,i,j,damage,th,sd,b,d,e,da;
    string msg,aa;
    object weapon;
    mapping type;
    weapon=me->query_temp("weapon");
    da = me->query_damage();
    th = me->query_skill("thundersword");
    sd = me->query_skill("sword");
    if(arg=="off" )
    {
        if( me->query_skill_mapped("sword")!="thundersword")
            return notify_fail(HIG"�A�{�b�èS���b�ϥ�"HIR"���s�Z.\n"NOR);
        me->map_skill("sword");
        me->reset_action();
        write(HIB"�A�`�l�@�f��, �վ��餺½�骺����, ����ϥ�"HIR"���s�Z.\n"NOR);
        return 1;
    }
    if(!weapon || weapon->query("skill_type")!="sword")
        return notify_fail(RED"���s�Z"GRN"�����μC���ϥX.\n"NOR);
    if(me->query_skill("sword")<45)
        return notify_fail(GRN"�A���򥻼C�N�٤Ӯt�l, �����"RED"���s�Z.\n"NOR);
    if(me->query("ap")<60 || me->query("hp")<30)
        return notify_fail(GRN"�A�{�b�����p�Ӯt�F, �����"RED"���s�Z.\n"NOR);
    //�ĤG��exert
    if(me->query_skill_mapped("sword")=="thundersword")
    {
        if( !target ) target = offensive_target(me);
        if(!target) 	return notify_fail(GRN"�A�w�g�B����s�Z�F.\n"NOR);
        //�����ʪ��n�S�O�`�N�n�[�U�����.
        if(!me->can_fight(target)) return me->can_fight(target);
        if( !me->is_fighting(target)) me->kill_ob(target);
        if( !target->is_fighting(me)) target->kill_ob(me);
        c = target->query_armor();
        if(th > random(300) && sd > 60 && me->query("ap")>100 )
        {
            b = th/10;
            b = (b/2) + (random(b)/2) + 1;
            if(b>8) b=8;
            if(b<1) b=1;
            for( e=0;e<b;e++)
            {
                if(e<1) message_vision(HIC"\n$N�B�_���s�Z���ۡy�ʹp�K�r�Z�z�q�g�V$n�ӥh!!!\n\n"NOR,me,target);
                d = random(sizeof(adv_attack));
                msg = adv_attack[d];
                damage = th + sd;
                damage =  (damage/3) + ((da*3)/2);
                damage -= (c/2) + (random(c)/2);
                if(damage<40) damage=30+random(20);
                if(damage>120) damage=80+random(40);
                if(random(me->query_dex()*2+th/3) > random(target->query_dex()*2+target->query_skill("dodge")/2) && damage>0 )
                {
                    msg += HIG"���G�y��$n�@�B�Y�����ˮ`!!\n"NOR;
                    message_vision(msg, me, target);
                    me->improve_skill("thundersword",random(3));
                    // �W�[�����ˮ`���v�T
                    damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                    target->receive_damage("hp",damage,me);
                    COMBAT_D->report_status(target);
                }
                else
                {
                    msg += GRN"���O�o�Q$n�{�}�F�C\n" NOR;
                    message_vision(msg, me, target);
                    target->improve_skill("dodge",1);
                }
            }
            if(!me->is_fighting(target)) me->kill_ob(target);
            if(!target->is_fighting(me)) target->kill_ob(me);
            me->receive_damage("ap",8*b);
            me->improve_skill("sword",1);
            return 1;
        }
        else
        {
            message_vision(CYN"$N�����R�ʲ��Ἲ�ê��C�ۥ]��F$n!\n"NOR,me,target);
            damage = (th/5) + (sd/5) + (da/5);
            damage = (random(damage)/2) + damage/2;
            damage -= (random(c)/2);
            if( damage < 5 ) damage = random(10);
            if( random(me->query_dex()*2+sd/3) > random(target->query_dex()*2+target->query_skill("dodge")/2) && damage>0)
            {
                msg = HIC"���G�y��$n���W�h�B�ζ�, �åB�Z�äF$n�����!!\n"NOR;
                message_vision(msg, me, target);
                me->improve_skill("thundersword",target->query("level")/5);
                // �W�[�����ˮ`���v�T
                damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                target->receive_damage("hp",damage,me);
                COMBAT_D->report_status(target);
                target->start_busy(2);
            }
            else
            {
                msg = CYN"�i�O��$n�ѯ}$N���}��, �������פF�}�h�C\n";
                message_vision(msg, me, target);
                target->improve_skill("dodge",1);
                target->start_busy(1);
                me->start_busy(2);
            }
            me->receive_damage("ap",15);
            me->start_busy(1);
            if(!me->is_fighting(target)) me->kill_ob(target);
            if(!target->is_fighting(me)) target->kill_ob(me);
            me->improve_skill("thundersword",1+random(me->query_int()/4));
            me->improve_skill("sword",1+random(me->query_int()/4));
            return 1;
        }
    }

    //fix by luky
if(!me->skill_active( "thundersword",(: call_other, __FILE__, "delay", me ,6:), 10))
        return notify_fail("�A���\\���ʧ@�٨S�����C\n");

    me->map_skill("sword","thundersword");
    me->reset_action();
    message_vision("\n"HIW"$N�`�l�F�@�f��, �l�B�_"HIR"���s�Z�C\n"NOR,me);
    me->receive_damage("ap",10);
    me->start_busy(1);
    //me->start_call_out( (: call_other, __FILE__, "delay", me ,6:), 10);
    return 1;
}
void delay(object me,int cost)
{
    object weapon;
    if(!me) return;
    weapon=me->query_temp("weapon");
    if(!weapon)
    {
        me->map_skill("sword");
        me->reset_action();
        return;
    }
    if(weapon->query("skill_type")!="sword")
    {
        me->map_skill("sword");
        me->reset_action();
        return;
    }
    if(me->query_skill_mapped("sword")!="thundersword")
    {
        return;
    }
    if(me->query("ap")<40)
    {
        me->map_skill("sword");
        me->reset_action();
        tell_object(me,HIW"\n�A����O�w�g�����I�i"HIR"���s�Z"HIW"�F�C\n"NOR);
        return ;
    }
    if( me->is_fighting() ) me->receive_damage("ap",8); //luky
    //me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
me->skill_active( "thundersword",(: call_other, __FILE__, "delay", me ,cost:), 10);
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
    a=ob->query_int();
    a=40+a;
    return a;
}
