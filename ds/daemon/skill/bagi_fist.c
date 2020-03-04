//New bagi_fist by Tmr  1999/10/15 18:30
// QC: Luky 1999.10.16 14:39
// Update By Tmr 2000/5/7
// Last Update By Tmr 2006/06/06

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me,int cost);

mapping *action = ({
    ([
    "action": "$N���}��X���b�}���B�A�ܥ������x�A�@���u����v,\n  �V$n���y�����h",
    "damage":                10,
    "dodge" :                20,
    "attact_type":  "bar",  // �]�w�ޯ઺��������
        // ������ �ͪ�(bio) �~��(bar)
        // �]�k(wit)���F(sou)���(tec)
    "damage_type":  "�A��",
    ]),

    ([
    "action": "$N�@���u�����v�A�����j�B�e�i�A\n  �G�i$n���e�A���k�x�ΤO���V$n���ݤf",
    "damage":                15,
    "dodge" :                10,
    "parry" :               -20,
    "attact_type":  "bar",
    "damage_type":  "����",
    ]),

    ([
    "action": "$N�ϥX�@���u�ĺO�ĩաv�k�x�e����½�A\n  ���x�V�׫e�詵�����V$n",
    "damage":                8,
    "dodge" :                -10,
    "parry" :                20,
    "attact_type":  "bar",
    "damage_type":  "�A��",
    ]),

    ([
    "action": "$N�r�a��a�޽��A�@���u�s���}�v�A���}�e���V$n",
    "damage":                13,
    "dodge" :                10,
    "parry" :                -25,
    "attact_type":  "bar",
    "damage_type":  "���",
    ]),

    ([
    "action": "$N���B�@���A�@���u�ϯ{�v�A�����ۤW�詹�e�פ�e�@�j���A\n  �����a���V$n�ӻH",
    "damage":                10,
    "dodge" :                10,
    "parry" :                20,
    "attact_type":  "bar",
    "damage_type":  "����",
    ]),

    ([
    "action": "$N�@�s�V�e�j��T�B�A�@��"+ HIY "�u�K�s�a�v" NOR + "��y�ਭ�A\n  ��B��I�ĤO�V$n���h",
    "damage":                17,
    "dodge" :                10,
    "parry" :                -10,
    "attact_type":  "bar",
    "damage_type":  "����",
    ]),

    ([
    "action": "$N���y�I���A���}���e����@�B�A�@���u�D�����y�v�צp�j�����V$n�ݤf",
    "damage":                12,
    "dodge" :                -10,
    "parry" :                20,
    "attact_type":  "bar",
    "damage_type":  "����",
    ]),

    ([
    "action": "$N�@���u����v�A���x���B�~��̴X��A�k�x�n�ɦV�׫e�U�襴�V$n�U�y�L",
    "damage":                12,
    "dodge" :                -10,
    "parry" :                20,
    "attact_type":  "bar",
    "damage_type":  "����",
    ]),

    ([
    "action": "$N�ϥX�u�j�񵷡v�A���⥪�B�k�����a�o�޵�$n�צp�h�h���j",
    "damage":                10,
    "dodge" :                -10,
    "parry" :                10,
    "attact_type":  "bar",
    "damage_type":  "���",
    ]),

    ([
    "action": "$N���B�e��A�k���ťѨ��᩹�e�e�@�j��A�@���u���B�{�v�A\n  �{�V$n�W�L�G�j�n�`",
    "damage":                14,
    "dodge" :                -20,
    "parry" :                -10,
    "attact_type":  "bar",
    "damage_type":  "����",
    ]),
});



void improve_skill(object me) {
    me->improve_skill("bagi_fist",1 + random(me->query_int()/2));
    me->improve_skill("unarmed",1 + random(me->query_int()/2));
}

/* �Z���l�� */
void damage_weapon(object me) {
    if ( objectp(me->query_temp("weapon")) )
        me->query_temp("weapon")->attack(); // wp �l�a�v add by wilfred
}

/* �P�_�O�_�ݭn�ܶˮ`�Ʀr */
void show_damage(object me, object target,int damage) {
    if (me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
        tell_object(me,HIY"("+damage+")"NOR);
    if (target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
    if (wizardp(me) && me->query("env/debug"))
        tell_object(me, HIR"  ("+damage+")\n"NOR);
}
/* �P�_�O�_�٥��޵o�԰� */
void check_combat(object me, object target) {
    if ( !objectp(me) ) return;
    if ( !objectp(target) ) return;
    if (!me->is_fighting(target)) me->kill_ob(target);
    if (!target->is_fighting(me)) target->kill_ob(me);


}


int get_tiger_damage(object me, object target)
{
    int damage, power;
    damage = me->query_skill("bagi_fist") + me->query_damage();
    damage = damage + random(damage/2);
    damage = damage - target->query_armor()/3 - random(target->query_armor()/3);

    power = me->query_temp("exert_mark/bagi-power"); //�Ȯɩʪ��F�賣�u�� temp ,quit�ɷ|�M��
    if (power > 5)
    {
        if (power < 20)  {
            damage = damage+damage* 1/6;
            me->add_temp("exert_mark/bagi-power",-5);
        } else if (power < 40) {
            damage = damage+damage* 2/6;
            me->add_temp("exert_mark/bagi-power",-10);
        } //5��
        else if (power < 60) {
            damage = damage+damage* 3/6;
            me->add_temp("exert_mark/bagi-power",-15);
        } //4��
        else if (power < 80) {
            damage = damage+damage* 4/6;
            me->add_temp("exert_mark/bagi-power",-20);
        } //3��
        else  {
            damage = damage + damage*5/6;
            me->add_temp("exert_mark/bagi-power",-30);
        } //2��
    }

    return COMBAT_D->Merits_damage(me, target, damage, "bar");
}

/* �r��w���s �S�� */
void do_tiger_attack(object me, object target) {

    int damage, target_d,sk;
    string msg;

    if ( userp(me) && userp(target) ) me->start_busy(2);
    else me->start_busy(1);

    me->receive_daemage("ap", 50);

    if ( userp(me) )
        msg = HIC "$N��ܤ@�n�A��B���x, �ϥX���ޡu�r��w���s�v�A�����a���V$n�I�I\n\n" NOR ;
    else
        msg = HIC "$N��ܤ@�n�A��B���x, �ϥX���ޡu"HIY"�r��w���s"HIC"�v�A�����a���V$n�I�I\n\n" NOR ;

    damage = get_tiger_damage(me, target);
    if ( damage <= 0 ) {
        msg += HIW "�i�O�o�@���o�O�n�z�L�O�A�L�k��$n" HIW "�y������ˮ`...\n" NOR;
        message_vision(msg, me, target);
        check_combat(me, target);
        return;
    }

    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
    sk = me->query_skill("bagi_fist");
    if ( sk + random(sk/2) > random(target_d) ) {
        target->add_busy(1+random(2));
        target->receive_damage("hp",damage,me);

        msg += HIR "$n"HIR"�Q$N���������A�n�ɨg�Q�@�f�A��T�I" NOR;
        message_vision(msg, me, target);
        damage_weapon(me);                      // �Z���l��
        show_damage(me, target, damage);        // ��ܶˮ`�Ʀr

        message_vision("\n", me);

        // ���j�}�S��G�F���T�I��
        // added by tmr 2006/10/18
        if ( ( !userp(me) && me->id("_BAGI_MASTER_WU_") && random(100) < 70 )           // �d��
                || (me->query_temp("SIX_OPEN_DAMAGE") && me->query("ap") > 200 && random(100) < 30 )
           ) {
            // ���j�}�N�o�ɶ�
            msg = HIG "\n$N"HIG"�⨭���v���Y���E�A�߰ʦp���ϡA�x�ʦp����A�Ͱʦp�p�T�A�ʵǺ�۳s�A\n"NOR;
            msg += HIG "$N"HIG"��Ѥߥ͡A�_��y�����СA�@�i�B�@��x�A�ϥX�K�������Ǥ����y"HIR"�F���T�I��"HIG"�z�I�I\n" NOR;
            msg += HIG "$n"HIG"�����L�k���m�A�ݤf���ۡA�S�h�g�Q�@�f�A��T�I" NOR;
            target->add_busy( 1 );          // �hbusy 1
            target->receive_damage("hp", damage/2 ,me);
            me->receive_damage("ap",50);
            message_vision(msg, me, target);
            show_damage(me, target, damage/2);        // ��ܶˮ`�Ʀr
            message_vision("\n", me);
        }



        COMBAT_D->report_status(target);
        improve_skill(me);
    } else {
        msg += HIW"�i�O�Q$n" HIW "�T�V�a���k�F�}�h.....\n" NOR;
        message_vision(msg, me, target);
    }
}

/* �s���������O */
int get_continue_attack_damage(object me, object target) {

    int basicd, damage, power,sk, pcost;
    sk = me->query_skill("bagi_fist");
    basicd = sk + me->query_damage();
    damage = basicd/4 + random(basicd/4);

    power = me->query_temp("exert_mark/bagi-power"); //�Ȯɩʪ��F�賣�u�� temp ,quit�ɷ|�M��

    if (power>10)
    {
        if (power < 20)  {
            damage=damage+damage*1/8;
            pcost=5;
        }
        else if (power < 40)     {
            damage=damage+damage*2/8;
            pcost=10;
        }
        else if (power < 60)     {
            damage=damage+damage*3/8;
            pcost=15;
        }
        else            {
            damage=damage+damage*4/8;
            pcost=20;
        }
        me->add_temp("exert_mark/bagi-power",-pcost);
    }

    damage -= target->query_armor()/2;
    damage -= random(target->query_armor()/2);
    return COMBAT_D->Merits_damage(me,target,damage,"bar");
}

/* �K���s�� */
void do_continue_attack(object me, object target)
{
    int sk, attack_times, a, target_d, damage;
    mapping type;
    string msg;

    sk =  me->query_skill("bagi_fist");
    if ( sk < 20) attack_times = 1;
    else    if ( sk < 40) attack_times = 1 + random(2);
    else    if ( sk < 60) attack_times = 2 + random(2);
    else    if ( sk < 80) attack_times = 2 + random(3);
    else    attack_times = 3 + random(3);

    me->receive_damage("ap",attack_times*8);

    if (userp(me) && userp(target)) me->start_busy(2);
    else me->start_busy(1);

    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;
    for ( a = 0; a < attack_times; a++ )
    {
        if ( a > 0) msg = HIC"�X��$n"HIC"���j���ɡA$N���۾l�¤S�X���ۡI\n"NOR;
        else msg ="";
        type = action[ random(sizeof(action)-1) ];
        msg += type["action"]+NOR+", ";

        damage = get_continue_attack_damage(me, target);

        if ( damage < 1 ) damage = 1 + random(5);

        if ( sk/2+random(sk) > random(target_d)  )      //�s�����������R���v
        {
            msg += HIC"���G�y��$n"HIC"�@�B"+type["damage_type"]+"!!"NOR;
            message_vision(msg, me, target);

            damage_weapon(me);          // �Z���l��

            target->receive_damage("hp",damage,me);
            show_damage(me, target, damage);
            message_vision("\n", me);
            improve_skill(me);
        }
        else        {
            msg += "�i�O�Q$n���{�F�}�h�C\n";
            message_vision(msg, me, target);
        }
    }

    COMBAT_D->report_status(target);
}

/* �ĤG����exert �N�O�I�i�S�� */
int do_exert(object me, object target) {
    int target_d, sk;

    if ( !target ) target = offensive_target(me);
    if ( !target)
        return notify_fail("�A�w�g�b�ϥΡu�K�����v�F�C\n");
    if ( environment(me) != environment(target) )
        return notify_fail("�A�չϧ������ĤH�w�g���b�F�C\n");

    //�����ʪ��n�S�O�`�N�n�[�U�����.
    if (!me->can_fight(target)) return 0;
    if (target->is_corpse()) return notify_fail("�ݲM���A���v�g���F�C\n"); // add by wilfred �ѨM���O���骺���D

    target_d = -COMBAT_D->dodge_factor(target,"dodge")*10/15;

    sk = me->query_skill("bagi_fist");
    if ( sk > 49 && random(sk) > random(150) ) {
        do_tiger_attack(me, target); // �r��w���s
    } else {
        do_continue_attack(me, target); // �K���s��
        if ( !userp(me) && me->id("_BAGI_MASTER_WU_") ) {
            /* �w��d���~�|�o�ʪ��ĤG���s�� */
            target = offensive_target(me);  // �A��t�@�ӼĤH
            if ( objectp(target) && random(100) > 30 ) {


                message_vision( HIY "\n�u��v�a�@�n�j�T�A$N"HIY"�@�O�j�Ӧ��O���_�}�N����í��A���M�S���۹�$n"HIY"�o�ʧ�աI�I\n\n" NOR, me, target);

                do_continue_attack(me, target); // �K���s��
            }
        }
    }

    check_combat(me, target);

    return 1;
}


// �Ĥ@��exert --> enable �ޯ�
void do_enable(object me) {
    me->map_skill("unarmed", "bagi_fist");
    me->reset_action();
    message_vision("\n"HIC"$N�L�@�����A��y�B���y�M���y�T�y�۹�A�}�l�B�_�u�K�����v�ߪk�I\n"NOR,me);
    me->receive_damage("ap",5);
    me->start_busy(1);
}

int exert(object me, object target, string arg)
{

    if ( me->query_temp("weapon") && me->query_temp("weapon")->query("skill_type")!="unarmed")
        return notify_fail("�A�⤤�����Z�������A�ä���ϥΩ�u�K�����v�C\n");

    if (arg=="off" ) {
        if ( me->query_skill_mapped("unarmed")!="bagi_fist")
            return notify_fail("�A�èS���ϥΡu�K�����v�C\n");
        me->map_skill("unarmed");
        me->reset_action();
        write("�ޯ�u�K�����v�w�����C\n");
        return 1;
    }

    if (me->query_skill("unarmed")<5)
        return notify_fail("�A���Ť�i����¦�����L�k�ϥΡu�K�����v�C\n");
    if (me->query("ap")<10 || me->query("hp")<10)
        return notify_fail("�A�����骬�p�L�k�ϥΤK�����k�C\n");

    //�ĤG��exert --> �I�i�S��
    if (me->query_skill_mapped("unarmed")=="bagi_fist")
        return do_exert(me, target);

if (!me->skill_active( "bagi_fist",(: call_other, __FILE__, "delay", me ,5:), 10))
        return notify_fail("�A�����K�������ʧ@�٨S�����C\n");

    // �Ĥ@��exert --> �ϥθӧޯ�
    do_enable(me);

    return 1;
}

int valid_learn(object me) {
    return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) {
    return 1;
}

int improve_limite(object ob)
{
    return 60 + ob->query_str();
}

