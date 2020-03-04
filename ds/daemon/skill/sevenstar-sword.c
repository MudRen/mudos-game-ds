// star-sword.c
// ���P�C�q - Star sword - By Cominging - 2000.2.10 = For Advanced Wind Party
// �o�ӼC�q�� 3 �� function
// 1. ���P�Цr(tian) 2. �E�E�G��(nine) 3. �C��(stun)
// Document:
//  1. ���P�Цr - �j����, �������D. �b�����ᦳ���|�٦� random ����
//  2. �E�E�G�� - �o���, �i�H���ĤH delay, ���Ůɥi�H�˨ǷL�ˮ`��
//  3. �C�� - Max �j����, �i�H�ˤH + delay, �����ŵ���.
//
// �򥻩ۦ� - (5) �� �\ �� �U �N ( now )
/************************************************
 * �s�o�Sdely................���j���D
 * �j�צn���W�L�Fbagi
 *
 ************************************************/
//Linjack �ץ��������D.
//
// Cominging �վ�T�w�j�� Aug, 26, 2000

#include <ansi2.h>
inherit SKILL;
inherit SSERVER;

void delay_0(object me);
void stop_delay(object me);

int p_force = this_player()->query_skill("star-sword")/5;
int b_force = random(this_player()->query_skill("moon_force"))/4;
int spal = ( p_force*p_force + b_force*b_force )/( p_force + b_force );

mapping *action = ({
                       ([
                            "action": "$N�}�C�@���A���O��i�C���A�ϥX"HIC"�u"HIR"��"HIC"�v"NOR"�r�Z�A�C�۬������檽���i",
                            "damage":	25,  //�o�ӬO�ˮ`�j�ƪ��ʤ��� , ���O�ˮ`�I��
                            "attack":	10,
                            "attact_type":  "bar",  // �]�w�ޯ઺�������� // �ͪ�(bio) �~��(bar) �]�k(wit)���F(sou)���(tec)
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N���C��e�C���A���_��C�P�A�h�h�]��$n�A�X����C�@���A�@��"HIC"�u"HIB"�\\"HIC"�v"NOR"�W�V$n��$l",
                            "damage":	15+random(spal/4),
                            "dodge":	-5,
                            "delay":	1,
                            "attack_type":	"bar",
                            "damage_type":	"���",
                        ]),
                       ([
                            "action": "$N������i�A��M�b$n���ǹ�$n�X�F�@��"HIC"�u"HIG"��"HIC"�v"NOR,
                            "damage":	18,
                            "delay":	2,
                            "attack_type":	"bar",
                            "damage_type":	"���",
                        ]),
                       ([
                            "action": "$N�f�������D�y�I�G�����U�l�A�A�s�����C�V�z�A�⤤���C��M�D�_�g�A�ϤF"HIC"�u"YEL"�U"HIC"�v"NOR,
                            "damage":	25,
                            "delay":	2,
                            "attack_type":	"bar",
                            "damage_type":	"���",
                        ]),
                       ([
                            "action": "$N�B����u�A��W���C��M���@�T�A����J�ɡA��$n��$l�ϥX�@��"HIC"�u"HIW"�N"HIC"�v"NOR,
                            "damage":	30,
                            "attack_type":	"bar",
                            "damage_type":	"���",
                        ])
                   });

int cast_skill(object me,string a, object target, string arg)
{
    int sk = me->query_skill("star-sword"),
             force = me->query_skill("force"),
                     w_force = me->query_skill("moon_force"),
                               sw = me->query_skill("sorgi_sword"),
                                    target_armor, me_damage, target_dodge, me_dex, sum_damage, g,damage, nine;

    object weapon, wp, *attack_targets;

    weapon = me->query_temp("weapon");
    force=me->query_skill("force");

    if( arg=="off" )
    {
        if( me->query_skill_mapped("sword")!="star-sword" )
            return notify_fail("�A�èS���b�����P�C�q��I\n");
        me->map_skill("sword");
        me->reset_action();
        write("�A���~������P�C�q�F�I\n");
        return 1;
    }

    if( me->query("ap") < 30 )
        return notify_fail("�A���骺���p�٤���ϥ����P�C�q�C\n");

    if( !weapon ) return notify_fail("�A�S���C�n���ϼC�r�H\n");

    if( sw < 70 ) return notify_fail("�A�������C�k�٤����¼��A��������P�C�q�A�_�h�N�������J�]�I\n");

    if( weapon->query("skill_type")!="sword" )
        return notify_fail("�A���μC�M�ٷQ�Τ���Z���ӨϼC�H\n");

    if( arg == "?" || arg == "help" )
    {
        tell_object(me, HIC"�u"HIB"���P�C�q"HIC"�v���\\�঳ ���P�Цr(tian) �E�E�G��(nine) �C��(penuma-sword)�C\n"NOR);
        return 1;
    }

    // �n�������D, �����n�}�C��
    //
    //	else if( weapon->query("skill_type")!="sword" && sk == 110 )
    //	{
    //		me->map_skill(weapon->query("skill_type"), "star-sword");
    //		me->set_temp("class/star-sword", weapon->query("skill_type"));
    //		write("�A�M�w�ϥ�"HIW"�C��"NOR"�ηN�h��|���P�C�q���u�q�I\n");
    //	}

    if( me->query_skill_mapped("sword") == "star-sword" )
    {
        if( !target ) target = offensive_target(me);
        if( !target ) return notify_fail("�A�èS���ؼХi�Hŧ���I\n"); // �� by cominging
        if( !me->can_fight(target) ) return me->can_fight(target);

        target_armor = target->query_armor();
        target_dodge = target->query_skill("dodge")/3 + random(target->query_dex()/4);
        me_dex = me->query_dex() * 3;
        //me_damage = me->query_damage() + w_force/4 + sk/3 + (int)(w_force * w_force + random(sk/4) * random(sk/2))/(w_force + sk);
        me_damage = me->query_damage() + w_force/4 + sk/3;
        me_damage = me_damage + random(me_damage/4);
        sum_damage = me_damage - target_armor/2 - random(target_armor/2);
        // qc section
        if(wizardp(me)) tell_object(me,sprintf("  me_damage=%-d  sum_damage=%-d\n",me_damage,sum_damage));
        // end of qc section
        if( !arg || arg == "?" )
        {
            tell_object(me, HIC"�u"HIB"���P�C�q"HIC"�v���\\�঳ ���P�Цr(tian) �E�E�G��(nine) �C��(penuma-sword)�C\n"NOR);
            return 1;
        }

        if( arg == "tian" )
        {
            if( !me->is_fighting(target) ) me->kill_ob(target);
            if( !target->is_fighting(me) ) target->kill_ob(me);
            if( me->is_busy() ) return notify_fail("�A���b���I\n");
            if( me->query_skill("star-sword") < 30 )
                return notify_fail("�A�����P�C�k�٨S�m���ܯ¼��I\n");
            message_vision("\n$N���C�@�ߡA�N�C�m��ݫe���o�e�A���ۥαN�⤤��" + weapon->name() + "�b�Ť����F�� "NOR+BLU"[��]"NOR" �r�A\n�j�ܤF�@�n�M�@��"HIC"�y"HIY"���P�Цr"HIC"�z"NOR"���V$n�C\n\n", me, target);
            if( random(me_dex) > random(target_dodge)
                    && sum_damage = COMBAT_D->Merits_damage(me, target, sum_damage + random(sum_damage/3), "bar") )
            {
                target->receive_damage("ap", sum_damage/10, me);
                target->receive_damage("hp", sum_damage, me);
                target->start_busy(1+random(3));
                message_vision(HIR"$n�@�Ӥ��p�ߡA�Q$N�����F���P�Цr�A���G�f���@�}�A��g�Q�I�I"NOR, me, target);
                // QC
                if(wizardp(me)) tell_object(me,sprintf("  (damage=%-d) \n",sum_damage));
                // End QC
                me->improve_skill("star-sword", random(me->query_int()/5) + 5);
                me->improve_skill("sword", random(me->query_int()/6) + 5 );
                me->add_busy(1+random(2)); //Luky and add by linjack // com random
                if( objectp(wp = me->query_temp("weapon")) ) wp->attack(); // wp �l�a�v add by wilfred
            }
            else
            {
                message_vision(HIY"���ơA$n���G�P����F$N���U�ۦU���A��$N�������ۦ��@�@�ƶ}�C"NOR, me, target);
                target->imporve_skill("dodge", 2);
                sum_damage = 0;
                me->add_busy(2+random(2)); //Luky and add by linjack // com random
            }
            if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                message_vision(HIY" ("+ HIR + sum_damage + HIY")"NOR" \n\n"NOR, me);
            else message_vision("\n\n", me);
            COMBAT_D->report_status(target);
            me->receive_damage("ap", 28 + sum_damage/40 );
            return 1;
        }

        if( arg == "nine" )
        {
            if( !me->is_fighting(target) ) me->kill_ob(target);
            if( !target->is_fighting(me) ) target->kill_ob(me);
            message_vision("$N�ϤF�Ϥ⤤���C�A�а_"HIW"�޹D����"NOR"�A���۫K�μC�I�V$n���޹D�A"NOR, me, target);
            if( random(target->query_dex()) < random(me->query_dex()*3/2) )
            {
                message_vision(HIW"�ϱo$N����ʼu!!\n"NOR, target);
                if( objectp(wp = me->query_temp("weapon")) ) wp->attack(); // wp �l�a�v add by wilfred
                if( sk < 30 ) target->start_busy(1+random(2));
                if( sk > 30 && sk < 60 ) target->start_busy(2+random(2));
                if( sk > 60 && sk < 90 ) target->start_busy(3+random(3));
                if( sk >= 90 )
                {
                    target->receive_damage("hp", me->query_damage()/3, me);
                    target->start_busy(4+random(2));
                    message_vision(HIR"$N���G���F�I�ˡI"NOR, target);
                    nine = 1;
                }
                if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                    message_vision(HIY" ("+ HIR + me->query_damage()/3 + HIY")"NOR" \n"NOR, me);
                else message_vision("\n", me);
                COMBAT_D->report_status(target);
            }
            else
            {
                message_vision("���o��$N�{�F�}�h�C\n"NOR,target);
                me->add_busy(random(2));
            }
            me->receive_damage("ap", 20 - sk/15);
            if( nine )
                me->add_busy(1);
            else me->add_busy(1+random(2)); //Luky // cominging �令 random
            return 1;
        }

        if( arg == "penuma-sword" )
        {
            if( me->query("level") < 35 )
                return notify_fail("�A�������٤�����!\n");
            if( me->query_skill("moon_force") < 95 )
                return notify_fail("�A���ݤ�ߪk�٤����¼��C\n");
            if( me->query_skill("star-sword") < 90 )
                return notify_fail("�A�����P�C�q�٤����¼��C\n");
            if( me->is_busy() )
                return notify_fail("�A�٦b���I\n");
            if( !me->is_fighting() )
                return notify_fail("�A�S�b���[, �ҥH����μC��I\n");
            if( !arrayp(attack_targets = me->query_enemy()) )
                return notify_fail("�S��������H�I\n");
            if( me->query_temp("class_wind/penuma-sword") )
                return notify_fail("�A�u�ɶ����٤���ϥμC��I\n");
            message_vision(HIC"\n�u��$N�|�P�~�M�@�ѱj�j����e�t�W�ɡK\n"NOR, me);
            message_vision(HIY"�@�@$N���C�a���Ĥ����A�����K$N�o�X�C��A�H�C�g�ġK\n\n"NOR, me);
            message_vision(HIM"  $N�ϥX - �i�� "HIY"�y "HIR"�� "HIG"�D "HIR"�P"HIG" �D "HIR"�C "HIG"�D "HIR"�� "HIY"�z "HIM"�СССССССС�\n\n"NOR, me);

            for(g=0;g<sizeof(attack_targets);g++)
            {
                if( objectp(wp = me->query_temp("weapon")) ) wp->attack(); // wp �l�a�v add by wilfred
                if( random( attack_targets[g]->query_dex() ) < random( me->query_dex()*2 ) + 15 ) {
                    if( random( attack_targets[g]->query_skill("force")/2 ) > random(force) )
                    {
                        damage = me->query_damage()*2/3 + w_force/4 + random( me->query_damage()/4 );
                        damage = COMBAT_D->Merits_damage(me, target, damage , "bar");
                        attack_targets[g]->receive_damage("hp",damage, me);
                        attack_targets[g]->start_busy(2);
                        message_vision(CYN"$N�ĤO����, �w�O���U�F�o�D�C��I"HIR" ("HIW+damage+HIR")"NOR,attack_targets[g]);
                        COMBAT_D->report_status(attack_targets[g]);
                    }
                    else
                    {
                        damage = me->query_damage() + w_force*2/3 + random( me->query_damage()/3 );
                        damage = COMBAT_D->Merits_damage(me, target, damage , "bar");
                        attack_targets[g]->receive_damage("hp", damage , me);
                        attack_targets[g]->start_busy(3);
                        message_vision(HIC"$N���Ω��, �Q�C�𥴭ӥ��ۡI"HIR" ("HIW+damage+HIR")"NOR,attack_targets[g]);
                        COMBAT_D->report_status(attack_targets[g]);
                    }
                }
                else {
                    message_vision(YEL"$N���L�F�o�D�C��I\n"NOR,attack_targets[g] );
                    attack_targets[g]->start_busy(1);
                }
            }
            message_vision("\n",me);
            me->start_busy(2);
            me->receive_damage("ap", 70);
            me->set_temp("class_wind/penuma-sword", 1);
            call_out("stop_delay", 25, me);
            return 1;
        }
    }

if( !me->skill_active( "star-sword",(: call_other, __FILE__, "delay_0", me :), 6) )
        return notify_fail("�A�������P�C�q���ʧ@�٨S�����I\n");

    message_vision(HIY"$N���[�|��M��ť�K��M�߾��N�b�M������|���P�C�q�I\n"NOR,me);
    me->map_skill("sword", "star-sword");
    me->receive_damage("ap", 10);
    me->reset_action();
    me->start_busy(1);
    return 1;
}

void delay_0(object me)
{
    object me_weapon;

    if( !me ) return;

    me_weapon=me->query_temp( "weapon" );

    if( !me_weapon || me_weapon->query("skill_type") != "sword" )
    {
        me->map_skill("sword");
        me->reset_action();
        return;
    }

    if( me->query_skill_mapped("sword")!="star-sword" ) return;

    if( me->query("ap") < 10 )
    {
        me->map_skill("sword");
        me->reset_action();
        tell_object(me, "�A����O�����~������P�C�q�F�I\n");
        return ;
    }

    if( me->is_fighting() ) me->receive_damage("ap", 7);

me->skill_active( "star-sword",(: call_other, __FILE__, "delay_0", me :), 6);
}

void stop_delay(object me)
{
    if( !me ) return;
    me->delete_temp("class_wind/penuma-sword");
}

int valid_learn(object me)
{
    return 1;
}

mapping query_action(object me, object weapon)
{
    /* �H�Uadd by alick -new skills*/
        // mark by tmr 2007/05/03
        /* 
    if( me->query_skill("star-sword") == 100 && !me->query_skill("sevenstar-sword"))
    {
        if( random(me->query("level")) == random(me->query_skill("star-sword")) )
        {
            me->set_skill("sevenstar-sword", 1);
            tell_object(me, HIW+BEEP"\n�A����F�ҵo�A�m���F�s�ޯ�-[���C�P�C�q (sevenstar-sword)]�C\n\n"NOR);
        }
    }
        */

    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    return 1;
}

int improve_limite(object ob)
{
    return 100;
}

void skill_improved(object me)
{
    if( me->query_skill("sevenstar-sword") )
    {
        me->set_skill("sevenstar-sword", me->query_skill("sevenstar-sword")-1 );
        tell_object(me, HIW"�]���A�m�^���P�C�q�A�ҥH�A���p�ߧѰO�F�@���������C�P�C�q�C\n\n"NOR);
    }
}
