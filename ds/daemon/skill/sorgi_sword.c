// Sorgi_sword By Cominging code ,...
// ��s���: Apr, 17, 2000.
// ��s��: Linjack
// Aug, 26, 2000
// ��h powerin, �[�j.

#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me);
void running_fire(object me,object target,int damage);

int force = (int)(this_player()->query_skill("moon_force")*0.3) + (int)(this_player()->query_skill("force")*0.2);

mapping *action = ({
                       ([
                            "action": "$N�����@�w�A�N�⤤���C���a�R���C��A�X$n���`�N�ɡA�@�|�ϥX�u���S���s�v�A��$n�ݤf��h",
                            "damage":		15+force,
                            "dodge" :		-15,
                            "attack_type":	"bio",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�j�ܤ@�n�A���t�ϥX�u���Ԧ۬١v�A�C�y��$n��W�����j�n�ަӥh",
                            "damage":		force,
                            "dodge" :		-5,
                            "attack_type":	"bio",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�����믫�A�����k��A��b���j�ߤ����u�𨳳t���^�Ȥ��A\n�@�K�����A$N��C�ϥX�p÷���@�멹$n���W�g���ӥh",
                            "damage":		15+force,
                            "dodge" :		10,
                            "attack_type":	"bio",
                            "damage_type":  "�@��",
                        ]),
                       ([
                            "action": "$N���ߤ@�ѽİʡA��C�ϥX�@�ۡu�p�üC�v�A�N�C���s���������@�멹$n���Y���{�h",
                            "damage":		10+force,
                            "dodge" :		-3,
                            "attack_type":	"bio",
                            "damage_type":  "�ж�",
                        ]),
                       ([
                            "action": "$N���G�K�F�@��A�ϥX�F�@�ۡu�s���K�H�v\n�A�K�p�s���@���$n���������Ӧp��O�n",
                            "damage":		12+force,
                            "dodge" :		-15,
                            "attack_type":	"bio",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�ߤ��@���A�y��@�C�A�ߧY��$n�U�F�@�ۡu����F�v�A�C���K�p�������k�@��",
                            "damage":		15+force,
                            "dodge" :		13,
                            "attack_type":	"bio",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�ϥX�@�ۥ����L�_�����c�C��$n���W�n�ަӥh�A���Ʀb�~�������ܬ��u���s�զ�v�A�ϧ�V$n�U�L",
                            "damage":		18+force,
                            "dodge" :		5,
                            "attack_type":	"bio",
                            "damage_type":  "���",
                        ]),
                       ([
                            "action": "$N�⾮�@�ۡu�|�c��Ѫ�v�A���۫K�r��$n��W�j�ޡA���ۤS�p�p��@�뻴�X����V$n�V��",
                            "damage":		17+force,
                            "dodge"	:		5,
                            "attack_type":	"bio",
                            "damage_type":  "�W��",
                        ]),
                   });

mapping *action2 = ({
                        ([
                             "action": "$�⤤$w"NOR"�C�ۥH�ӷ����ΡA�e�X�j�j�p�p����A�@�ۡy�V�P�}�ѡz�C���{�{�b$n���e",
                             "damage":		21+force,
                             "dodge":		-10,
                             "attack_type":	"bio",
                             "damage_type":	"�ζ�",
                         ])
                    });

int exert(object me, object target, string arg)
{
      int c,damage,sk,p,force;
    string msg;
    object weapon;

    weapon=me->query_temp("weapon");
    sk=me->query_skill("sorgi_sword");
    force=me->query_skill("force");

    if( arg=="off" )
    {
        if( me->query_skill_mapped("sword")!="sorgi_sword" )
            return notify_fail("�A�S���ϥΡu�����C�k�v�C\n");
        me->map_skill("sword");
        me->reset_action();
        me->delete_temp("exert_mark/sorgi_sword");
        me->delete_temp("power_exert");
        write("�ޯत���u�����C�k�v�w����ϥΡC\n");
        return 1;
    }

    if( !weapon)
        return notify_fail("�ϥΡu�����C�k�v�ݭn����C�~��ϥΡC\n");

    if( weapon->query("skill_type")!="sword" )
        return notify_fail("�p�G�n�ϥΡu�����C�k�v�A�h�����˳ƼC���Z���C\n");

    if( me->query("ap") < 20 )
        return notify_fail("�A����O�����A�L�k�ϥΡu�����C�k�v�C\n");

    if( me->query_skill_mapped("sword")=="sorgi_sword" )
    {
        if( !target ) target = offensive_target(me);
        if( !target ) return notify_fail("�A�٦b�I�i�i�����C�k�j�C\n");
        if( me->query_temp("exert_mark/sorgi_sword") ) return notify_fail("(�A�W�@�Ӱʧ@�٨S�����C)\n");
        if( !me->can_fight(target) ) return me->can_fight(target);
        if( !me->is_fighting(target)) me->kill_ob(target);
        if( !target->is_fighting(me)) target->kill_ob(me);
        
        c = target->query_armor();
        if( sk > random(300) && !target->is_busy()) {
            msg = HIY"\n$N"HIY"�ϥX�e�����ۡu����ð}�v�A�@�C�������a��$n"HIY"���ݽ�����ӥh�I�I\n"NOR ;
            damage = me->query_damage()*3/2 + me->query_skill("force")/2;
            damage = damage + random(damage/4);
            damage = damage - c/3 - random(c/3);
            if( damage < 25 ) damage = 20 + random(8);
			damage = COMBAT_D->Merits_damage(me, target, damage, "bio");
            me->start_busy(1);
            
            // �� query_skill("dodge") �Y�i, �o�ˤ~�|�ѦҨ��⪺���\
            // �[�W dex ���P�_
            if( me->query_dex()/2+random(sk+5)*2 > target->query_dex()/2+random(target->query_skill("dodge")) )
            {
                msg += HIM "$n"HIM"�ݽ��Q$N"HIM"��"+weapon->name()+HIM"�e�X�@�D�������岪�A�X�G�`�i�����I�I" NOR;
                target->delete_temp("power_exert");
                target->delete_temp("power_cast");
                target->start_busy(2+random((sk/100)+1));
                target->receive_damage("hp", damage,me);
                me->improve_skill("sorgi_sword",1+me->query_int()/5);
                me->improve_skill("sword",1+me->query_int()/3);
            }
            else
            {
                msg += HIY"���O$n"HIY"���}�F�o�@�C�C" NOR;
                me->improve_skill("sorgi_sword", 1);
                me->improve_skill("sword", 1);
                damage = 0;
            }
            message_vision(msg, me, target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") ) {
                tell_object(me,HIY"("+damage+")\n"NOR);
            }
			message_vision("\n",me);
            COMBAT_D->report_status(target);
            me->receive_damage("ap", 35 );
            return 1;
        }
        else
        {
            damage = sk/6 + p/3 + force/5 + random(me->query_skill("sword")/7);
            damage = damage - c/2 - random(c/2);
            if( damage < 6 ) damage = 3 + random(4);
            // damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
            // �������ɤޥ�

            /*i=( sk+me->query_skill("fogseven"))/2;
            if ( i > 50 )i = 2;	    //���շs��k, i ���N�J running-fire �� z ��.
            if ( i < 51 )i = 1;*/

            me->add_temp("power_exert", 2 + sk/30);
            message_vision(HIW"\n$N"HIW"�`�l�F�@�f��A�¤��u��B�ण���A��W���C�B�ण�_�A���ۻW�իݵo�C\n"NOR,me,target);
            me->set_temp("skill/sorgi_sword",1);
            if( userp(me) )
            	call_out("running_fire",2,me,target,damage);
            else
            	call_out("running_fire",1,me,target,damage);
            me->start_busy(2);
            return 1;
        }
    }
if( !me->skill_active( "sorgi_sword",(: call_other, __FILE__, "delay", me :), 6) )
        return notify_fail("�A���������C�k���ʧ@�٨S�����C\n");

    message_vision("\n"HIC"$N"HIC"�j�ܤ@�n�A��������u���p���ݤf�¤��ӥh�I\n"NOR,me);
    me->map_skill("sword", "sorgi_sword");
    me->reset_action();
    me->receive_damage("ap", 7);
    me->start_busy(2);
    return 1;
}

void delay(object me)
{
    object weapon;

    if( !me ) return;
    weapon=me->query_temp( "weapon" );
    if( !weapon )
    {
        me->map_skill("sword");
        me->reset_action();
        return;
    }
    if( weapon->query("skill_type")!="sword" )
    {
        me->map_skill("sword");
        me->reset_action();
        return;
    }
    if( me->query_skill_mapped("sword")!="sorgi_sword" )
        return;

    if( me->query("ap")<10 )
    {
        me->map_skill("sword");
        me->reset_action();
        message_vision("\n"HIW"$N"HIW"����O�����L�k�~��I�i�����C�k�C\n"NOR,me);
        return ;
    }

    if( me->is_fighting() ) me->receive_damage("ap", 4);

me->skill_active( "sorgi_sword",(: call_other, __FILE__, "delay", me :), 6);
}


void running_fire(object me, object target, int damage)
{
    int dam, dex, sk, tdod, i;
    object weapon, wp;
    string msg, *d_msg;
    if( !me ) return;
    if( !weapon=me->query_temp("weapon") ) return;

    if( !target )  {
        message_vision("$N�]�����w�g���b�F�Ӱ���F�o������աC\n",me);
        return;
    }
    if( !me->is_fighting(target) ) return;
    
    if( environment(me) != environment(target) ) {
        message_vision("$N�]��������}�Ӱ���F�o������աC\n",me);
        return;
    }

    me->delete_temp("exert_mark/sorgi_sword");
    if( me->query_temp("power_exert") < 1 ) {
        message_vision(CYN"\n$N"CYN"����жˤ@�ɶäF�}�}�A�h�F�T�B�C\n"NOR,me);
        return;
    }
    me->delete_temp("power_exert");
    sk = me->query_skill("sorgi_sword");
    tdod = target->query_skill("dodge")*3/4;
    dex = me->query_dex()*4;
    if( dex > 250 ) dex = 250;
    if( dex < 10 ) dex = 10;

	d_msg = ({
                          HIG"$N�ϥX�����C�k���ۡA�⤤��"+weapon->name()+HIG "��V$n���褤�C\n"NOR,
                          HIG"$N�ϥX�����C�k���ۡA�⤤��"+weapon->name()+HIG "���V$n�������C\n"NOR,
                          HIG"$N�ϥX�����C�k���ۡA�⤤��"+weapon->name()+HIG "��V$n�������C\n"NOR,
                          HIG"$N�ϥX�����C�k���ۡA�⤤��"+weapon->name()+HIG "��V$n����áC\n"NOR,
                          HIG"$N�ϥX�����C�k���ۡA�⤤��"+weapon->name()+HIG "��V$n�������C\n"NOR,
                      });


    if( random(target->query_skill("dodge")+target->query_dex()) <= random((me->query_skill("sorgi_sword")+me->query_dex()))+20 && random(sk) > 55)
    {
        message_vision(YEL"$N�J�a�@�ݤ⤤���C�A���������O�ѼC�y���g�ӥX�I\n"NOR, me);

        for(i=0;i<5;i++)
        {
        	 dam = COMBAT_D->Merits_damage(me,target,(damage*4/5) + random(damage/5),"bio");
        	 if(dam < 1) dam = 1;
            if( random(dex) > random(tdod))   {
                d_msg[i] += HIR"���G�y��$n"HIR"�@�B�ж�!!"NOR;
                target->receive_damage("hp", dam , me );
                if( objectp(wp = me->query_temp("weapon")) ) wp->attack(); // wp �l�a�v add by wilfred
            }
            else
            {
                d_msg[i] +="���O�Q$n���}�F�C"NOR;
                dam = 0;
            }
            message_vision(d_msg[i], me, target);
            if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
            {
                tell_object(me,HIY"("+dam+")"NOR);
                message_vision("\n",me);
                dam = 0; //�k�s�ʧ@, �קK�¤O�֭p
            }
            else { message_vision("\n",me);  dam = 0; }
            COMBAT_D->report_statue(target);
        }

        me->receive_damage("ap",25);
        me->improve_skill("sorgi_sword", me->query_int()/3 +me->query("level"));
        me->improve_skill("sword", me->query_int()/5 + me->query("level"));
    }
    else if( random(target->query_skill("dodge")+target->query_dex()) <= random((me->query_skill("sorgi_sword")+me->query_dex())*2)+20 )
    {
        for(i=0;i<3;i++)
        {
            if( random(dex)+25 > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,(damage*5/6)+random(damage/5),"bar"))
            {
                d_msg[i] += HIR"���G�y��$n"HIR"�@�B�ж�!!"NOR;
                target->receive_damage("hp", dam , me );
            }
            else
            {
                d_msg[i] += "���O�Q$n���}�F!!"NOR;
                dam = 0;
            }
            message_vision(d_msg[i], me, target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
            {
                tell_object(me,HIY"("+dam+")"NOR);
                message_vision("\n",me);
                dam = 0; //�k�s�ʧ@, �קK�¤O�֭p
            }
            else { message_vision("\n",me);  dam = 0; }
            COMBAT_D->report_statue(target);
        }

        me->improve_skill("sorgi_sword", me->query_int()/4);
        me->improve_skill("sword", me->query_int()/4);
        me->receive_damage("ap",15);
    }
    else
    {
        msg = "$N�Q�ϥX�����C�����s�o���ޡA�i�O�o�Q$n���ݯ}�F�C\n";
        message_vision(msg, me, target);
        target->improve_skill("dodge", 2);
    }
    return;
}

int valid_learn(object me)
{
    return 1;
}

mapping query_action(object me, object weapon)
{
    if( random(me->query_skill("sorgi_sword")) < random(me->query_skill("sorgi_sword")/2+1)
            && me->query_skill("sorgi_sword") > 70 )
        return action[random(sizeof(action))];

    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    return 1;
}
