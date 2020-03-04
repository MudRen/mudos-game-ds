//ice-sky �B�N�i�H�ѳZ�j (�E�H�Ѯc�J���k�N���@)
//���P���� spell �d��:  �� set ice-sky 0 or 1 or 2 or 3 or 4
#include <ansi.h>
inherit SSERVER;
inherit SKILL;
int cast(object me, object target, string arg)
{
    int inn,cost,mk,busy;

    if(!me) me=this_player();
    inn=me->query_int();
    mk=me->query_spell("ice-sky");
    cost=20-(me->query_int()/6);
    if(cost < 12) cost = 12;
    if(!me->query("env/ice-sky") || me->query("env/ice-sky") == 0 || me->query("env/ice-sky") > 4)
        return notify_fail("�Х� set ice-sky 1 �ϥδH�ѭ�a�Z���Ĥ@�h�k�N, �̰��i�H�]��4, �A������help ice-sky.\n");
    if(environment(me)->query("no_cast")) return notify_fail("�o�̤���I�k�C\n");

    if ( !target ) target = offensive_target(me);
    if ( !target ) return notify_fail("�A�n��֬I�i�o�Ӫk�N�S\n");

    //�ˬd�O�_�i�H����
    if(!me->can_fight(target))
        return me->can_fight(target);

    if( (int)me->query("mp") < cost*(me->query("env/ice-sky"))+1
            || (int)me->query("ap") < (cost/2)*(me->query("env/ice-sky"))+1
            || (int)me->query("hp") < cost+1 )
        return notify_fail("�A�����骬�p���}�C\n");

    if( (int)me->query("env/ice-sky") == 1)
    {
        message_vision(CYN"\n$N�߯��X�@�A�f����������A��M�@�}�H���w�w����¶�b$N���ǡC\n"NOR,me);
        busy=2;
        me->start_busy(busy); //�I�k�ʧ@�ɶ�
        me->receive_damage("mp",cost); //�I�k��MP
        me->set_temp("power_cast",1+mk/20);
        if(userp(me)) call_out("delay1",busy,target,me,mk);
        else call_out("delay1",busy-1,target,me,mk);
        return 1;
    }
    if( (int)me->query("env/ice-sky") == 2)
    {
        message_vision(CYN"\n$N�߯��X�@�A�f����������A��M�@�}�N�檺�������F$N�|�P�C\n"NOR,me);
        busy=2;
        me->start_busy(busy); //�I�k�ʧ@�ɶ�
        me->receive_damage("mp",cost*3/2); //�I�k��MP
        me->receive_damage("ap",cost/3); //�I�k��AP
        me->set_temp("power_cast",1+mk/25);
        if(userp(me)) call_out("delay2",busy*2-2,target,me,mk);
        else call_out("delay2",busy*2-2-random(2),target,me,mk);
        return 1;
    }
    if( (int)me->query("env/ice-sky") == 3)
    {
        message_vision(CYN"\n$N�߯��X�@�A�f����������A��M�@�}�p�M�몺�Q�b�H��E�b$N�e��C\n"NOR,me);
        busy=2;
        me->start_busy(busy); //�I�k�ʧ@�ɶ�
        me->receive_damage("mp",cost*2); //�I�k��MP
        me->receive_damage("ap",cost*2/3); //�I�k��AP
        me->set_temp("power_cast",1+mk/30);
        if(userp(me)) call_out("delay3",busy*2-2,target,me,mk);
        else call_out("delay3",busy*2-2,target,me,mk);
        return 1;
    }
    if( (int)me->query("env/ice-sky") == 4 && (int)me->query("env/ice-ground") == 4 &&
            (int)me->query_spell("ice-sky") > 98 && (int)me->query_spell("ice-ground") > 98 &&
            (int)me->query("mp") > 100 && (int)me->query("ap") > 60 && (int)me->query("hp") > 40)
    {
        message_vision(CYN"\n$N�߯��X�@�A�f����������A��M�@�}�n���N�n��Ѧa�ᵲ���_�H���E�b$N�|�P��C\n"NOR,me);
        busy=3;
        me->start_busy(busy); //�I�k�ʧ@�ɶ�
        me->receive_damage("mp",cost*4); //�I�k��MP
        me->receive_damage("ap",cost*2); //�I�k��AP
        me->receive_damage("hp",cost*3/2); //�I�k��HP
        me->set_temp("power_cast",1+mk/30);
        if(userp(me)) call_out("delay5",busy*2-1-random(2),target,me,mk);
        else call_out("delay5",busy*2-2-random(2),target,me,mk);
        return 1;
    }
    if( (int)me->query("env/ice-sky") == 4)
    {
        message_vision(CYN"\n$N�߯��X�@�A�f����������A��M�@�}�n���N�n��Ѧa�ᵲ���_�H���E�b$N�|�P��C\n"NOR,me);
        busy=3;
        me->start_busy(busy); //�I�k�ʧ@�ɶ�
        me->receive_damage("mp",cost*3); //�I�k��MP
        me->receive_damage("ap",cost*3/2); //�I�k��AP
        me->receive_damage("hp",cost); //�I�k��HP
        me->set_temp("power_cast",1+mk/30);
        if(userp(me)) call_out("delay4",busy*2-3,target,me,mk);
        else call_out("delay4",busy*2-3-random(2),target,me,mk);
        return 1;
    }
}
int delay1(object target,object me,int mk)
{
    string damagemsg,*limbs;
    int inn,sk,damage,shield,level,test,delay;
    limbs = ({ "�Y��","����","�ⳡ","�}��" });
    if(!me) return 0;
    if(!target) return notify_fail("�ؼЮ����F�C\n");
    if( environment(me) != environment(target) )
        return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
    if( me->query_spell("ice-sky") < random(15) )
    {
        message_vision(CYN"$N"CYN"���M�ܧV�O��������O�A���L���m�����A�I�k���ѤF�C\n"NOR,me);
        return 1;
    }
    if( me->query_temp("power_cast") < 1)
    {
        message_vision(HIC"$N"HIC"�]������ж˦ӶäF���, �L�k���Q�I�i�k�N�C\n"NOR,me);
        return 1;
    }
    me->delete_temp("power_cast");
    sk=mk/20+random(mk/20)+1;
    inn=me->query_int();
    level=me->query("level");
    shield=target->query_shield();

    damage = mk+inn+(level/2);
    damage = damage*2/3 + random(damage/3);
    if(userp(me)) damage=damage+(damage/6)-random(damage/8);
    damage = damage - (shield/3) -random(shield*2/3);
    if(damage>65) damage=65+((damage-65)/5);

    message_vision(CYN"$N��M�F���@�{�A�f����X�@�y:�u"+HIC+"�����i�ơj"+NOR+CYN+"�v�I\n"NOR,me);
    message_vision(CYN"�|�P�H���M���E���ӸH�����A�ѤU���_�ֳt�V$n�ƥh�I\n\n"NOR,me,target);

    if(damage > 0)
    {
        // COMBAT_D->dodge_factor(target,"dodge") �|�Ǧ^���{���v(�t��)
        if( random(mk*2 + inn*2)>random(-(COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int())))
        {
            // �W�[�����ˮ`���v�T
            damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
            if(damage < 10) damagemsg = "�D�`���L����ˡC";
            else if(damage < 20) damagemsg = "�@�ǨǪ���ˡC";
            else if(damage < 40) damagemsg = "�@�B��ˡC";
            else if(damage < 60) damagemsg = "�@�B�Y������ˡI";
            else if(damage < 100) damagemsg = "���Y������ˡI";
            else if(damage < 150) damagemsg = "�Q���Y������ˡI";
            else if(damage < 200) damagemsg = "�D�`�Y������ˡI";
            else if(damage < 301) damagemsg = "�����ʪ���ˡA$N���W�����F�B�I�I";
            else damagemsg = "�v�L�e�Ҫ��W�ŭ�ˡA����$N��������F�Y���ˮ`�I�I";
            target->receive_damage("hp", damage, me );
            message_vision(HIC"$N�Q�\\�h�H�������A�y��$N"+damagemsg+""NOR,target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            COMBAT_D->report_status(target);         //���target���A
            /*	if( damage > 199 && random(me->query_int()) > random(target->query_int()) )
            	{
            		test = random(sizeof(limbs));
            		limbs = limbs[test];
            		message_vision(HIC"\n   $N��"+limbs+"�]����H�방�ӳQ��ˤF�I\n"NOR,target);
            		if(limbs == "�Y��") target->receive_wound("head",(damage/100));
            		if(limbs == "�}��") target->receive_wound("foot",(damage/100));
            		if(limbs == "����") target->receive_wound("body",(damage/100));
            		if(limbs == "�ⳡ") target->receive_wound("hand",(damage/100));
            	}*/
            if( damage > 50 )
            {
                message_vision(CYN"   $N����ʳQ�B�H�Ҽv�T�A�y�L�w�C�F�@�I�C\n"NOR,target);
                delay = damage / 50;
                if(delay > 4) delay = 4;
                target->start_busy(delay);
                if( damage > 100 ) {
                    me->receive_heal("mp",damage/7);
                    tell_object(me,HIG"   �A�����p�ݰ_�Ӧn�F�@�I�C\n"NOR);
                }
                if( damage > 200 ) me->receive_heal("ap",damage/7);
                if( damage > 300 ) me->receive_heal("hp",damage/7);
            }
        }
        else
        {
            message_vision(CYN"���L$N½���@���A�������׶}�F�o�ǭ����C\n"NOR,target);
        }
    } else message_vision(CYN"���O�\\�\\�h�h�ӸH�������b$N���W�A���G�S������@�ΡC\n"NOR,target);

    if( random(40+inn) > 15 )
    {
        me->improve_spell("ice-sky",inn/3+random(inn/3)+1);
    }
    if(random(2+mk/5)==0) me->start_busy(1);
    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    if(random(20)<1) me->add_busy(1);
    return 1;
}

int delay2(object target,object me,int mk)
{
    string damagemsg,*limbs;
    int inn,sk,damage,shield,level,test,delay;
    limbs = ({ "�Y��","����","�ⳡ","�}��" });
    if(!me) return 0;
    if(!target) return notify_fail("�ؼЮ����F�C\n");
    if( environment(me) != environment(target) )
        return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
    if( me->query_spell("ice-sky") < (random(23)+8) )
    {
        message_vision(CYN"$N"CYN"���M�ܧV�O��������O�A���L���m�����A�I�k���ѤF�C\n"NOR,me);
        return 1;
    }
    if( me->query_temp("power_cast") < 1)
    {
        message_vision(HIC"$N"HIC"�]������ж˦ӶäF���, �L�k���Q�I�i�k�N�C\n"NOR,me);
        return 1;
    }
    me->delete_temp("power_cast");
    sk=mk/20+random(mk/20)+1;
    inn=me->query_int();
    level=me->query("level");
    shield=target->query_shield();

    damage = (mk*3/2)+(inn*3/2)+level;
    damage = damage*2/3 + random(damage/3);
    if(userp(me)) damage=damage+(damage/6)-random(damage/8);
    damage = damage - (shield/3) -random(shield/2);
    if(damage>100) damage=100+((damage-100)/5);

    message_vision(CYN"$N��M�F���@�{�A�f����X�@�y:�u"+HIC+"�����i�ơj"+NOR+CYN+"�v�I\n"NOR,me);
    message_vision(CYN"�|�P�����~�M�������H�A�ѤU���_�ֳt�V$n�ƥh�I\n\n"NOR,me,target);

    if(damage > 0)
    {
        // COMBAT_D->dodge_factor(target,"dodge") �|�Ǧ^���{���v(�t��)
        if( random(mk*2 + inn*2)>random(-(COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int())))
        {
            // �W�[�����ˮ`���v�T
            damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
            if(damage < 10) damagemsg = "�D�`���L����ˡC";
            else if(damage < 20) damagemsg = "�@�ǨǪ���ˡC";
            else if(damage < 40) damagemsg = "�@�B��ˡC";
            else if(damage < 60) damagemsg = "�@�B�Y������ˡI";
            else if(damage < 100) damagemsg = "���Y������ˡI";
            else if(damage < 150) damagemsg = "�Q���Y������ˡI";
            else if(damage < 200) damagemsg = "�D�`�Y������ˡI";
            else if(damage < 301) damagemsg = "�����ʪ���ˡA$N���W�����F�B�I�I";
            else damagemsg = "�v�L�e�Ҫ��W�ŭ�ˡA����$N��������F�Y���ˮ`�I�I";
            target->receive_damage("hp", damage, me );
            message_vision(HIC"$N�Q�\\�h�B�������A�y��$N"+damagemsg+""NOR,target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            COMBAT_D->report_status(target);         //���target���A
            /*	if( damage > 199 && random(me->query_int()) > random(target->query_int()) )
            	{
            		test = random(sizeof(limbs));
            		limbs = limbs[test];
            		message_vision(HIC"\n   $N��"+limbs+"�]����H�방�ӳQ��ˤF�I\n"NOR,target);
            		if(limbs == "�Y��") target->receive_wound("head",(damage/100));
            		if(limbs == "�}��") target->receive_wound("foot",(damage/100));
            		if(limbs == "����") target->receive_wound("body",(damage/100));
            		if(limbs == "�ⳡ") target->receive_wound("hand",(damage/100));
            	}*/
            if( damage > 50 )
            {
                message_vision(CYN"   $N����ʳQ�B�H�Ҽv�T�A�y�L�w�C�F�@�I�C\n"NOR,target);
                delay = damage / 50;
                if(delay > 4) delay = 4;
                target->start_busy(delay);
                if( damage > 100 ) {
                    me->receive_heal("mp",damage/7);
                    tell_object(me,HIG"   �A�����p�ݰ_�Ӧn�F�@�I�C\n"NOR);
                }
                if( damage > 200 ) me->receive_heal("ap",damage/7);
                if( damage > 300 ) me->receive_heal("hp",damage/7);
            }
        }
        else
        {
            message_vision(CYN"���L$N½���@���A�������׶}�F�o�ǦB���C\n"NOR,target);
        }
    } else message_vision(CYN"���O�\\�h�B�����b$N���W�A���G�S������@�ΡC\n"NOR,target);

    if( random(40+inn) > 22 )
    {
        me->improve_spell("ice-sky",inn/3+random(inn/3)+4);
    }
    if(random(2+mk/8)==0) me->start_busy(1);
    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    if(random(17)<1) me->add_busy(1);
    return 1;
}

int delay3(object target,object me,int mk)
{
    string damagemsg,*limbs;
    int inn,sk,damage,shield,level,test,delay;
    limbs = ({ "�Y��","����","�ⳡ","�}��" });
    if(!me) return 0;
    if(!target) return notify_fail("�ؼЮ����F�C\n");
    if( environment(me) != environment(target) )
        return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
    if( me->query_spell("ice-sky") < (random(31)+20) )
    {
        message_vision(CYN"$N"CYN"���M�ܧV�O��������O�A���L���m�����A�I�k���ѤF�C\n"NOR,me);
        return 1;
    }
    if( me->query_temp("power_cast") < 1)
    {
        message_vision(HIC"$N"HIC"�]������ж˦ӶäF���, �L�k���Q�I�i�k�N�C\n"NOR,me);
        return 1;
    }
    me->delete_temp("power_cast");
    sk=mk/20+random(mk/20)+1;
    inn=me->query_int();
    level=me->query("level");
    shield=target->query_shield();

    damage = (mk*3/2)+(inn*2)+(level*3/2);
    damage = damage*2/3 + random(damage/3);
    if(userp(me)) damage=damage+(damage/6)-random(damage/8);
    damage = damage - (shield/3) -random(shield/3);
    if(damage>140) damage=140+((damage-140)/5);

    message_vision(CYN"$N��M�F���@�{�A�f����X�@�y:�u"+HIC+"�H���M�i�ơj"+NOR+CYN+"�v�I\n"NOR,me);
    message_vision(CYN"�|�P�H�𾮦��@�������B�M�A�ѤU���_�ֳt�V$n�g�h�I\n\n"NOR,me,target);

    if(damage > 0)
    {
        // COMBAT_D->dodge_factor(target,"dodge") �|�Ǧ^���{���v(�t��)
        if( random(mk*2 + inn*2)>random(-(COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int())))
        {
            // �W�[�����ˮ`���v�T
            damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
            if(damage < 10) damagemsg = "�D�`���L����ˡC";
            else if(damage < 20) damagemsg = "�@�ǨǪ���ˡC";
            else if(damage < 40) damagemsg = "�@�B��ˡC";
            else if(damage < 60) damagemsg = "�@�B�Y������ˡI";
            else if(damage < 100) damagemsg = "���Y������ˡI";
            else if(damage < 150) damagemsg = "�Q���Y������ˡI";
            else if(damage < 200) damagemsg = "�D�`�Y������ˡI";
            else if(damage < 301) damagemsg = "�����ʪ���ˡA$N���W�����F�B�I�I";
            else damagemsg = "�v�L�e�Ҫ��W�ŭ�ˡA����$N��������F�Y���ˮ`�I�I";
            target->receive_damage("hp", damage, me );
            message_vision(HIC"$N�Q�\\�h�B�M�����A�y��$N"+damagemsg+""NOR,target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            COMBAT_D->report_status(target);         //���target���A
            /*	if( damage > 199 && random(me->query_int()) > random(target->query_int()) )
            	{
            		test = random(sizeof(limbs));
            		limbs = limbs[test];
            		message_vision(HIC"\n   $N��"+limbs+"�]����H�방�ӳQ��ˤF�I\n"NOR,target);
            		if(limbs == "�Y��") target->receive_wound("head",(damage/100));
            		if(limbs == "�}��") target->receive_wound("foot",(damage/100));
            		if(limbs == "����") target->receive_wound("body",(damage/100));
            		if(limbs == "�ⳡ") target->receive_wound("hand",(damage/100));
            	}*/
            if( damage > 50 )
            {
                message_vision(CYN"   $N����ʳQ�B�M���˩Ҽv�T�A�y�L�w�C�F�@�I�C\n"NOR,target);
                delay = damage / 50;
                if(delay > 4) delay = 4;
                target->start_busy(delay);
                if( damage > 100 ) {
                    me->receive_heal("mp",damage/5);
                    tell_object(me,HIG"   �A�����p�ݰ_�Ӧn�F�@�I�C\n"NOR);
                }
                if( damage > 200 ) me->receive_heal("ap",damage/5);
                if( damage > 300 ) me->receive_heal("hp",damage/5);
            }
        }
        else
        {
            message_vision(CYN"���L$N½���@���A�������׶}�F�o�ǦB�M�C\n"NOR,target);
        }
    } else message_vision(CYN"���O�\\�\\�h�h�W�Q�B�M���b$N���W�A���G�S������@�ΡC\n"NOR,target);

    if( random(40+inn) > 27 )
    {
        me->improve_spell("ice-sky",inn/2+random(inn/2)+1);
    }
    if(random(2+mk/9)==0) me->start_busy(1);
    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    if(random(14)<1) me->add_busy(1);
    return 1;
}

int delay4(object target,object me,int mk)
{
    string damagemsg,*limbs;
    int inn,sk,damage,shield,level,test,delay;
    limbs = ({ "�Y��","����","�ⳡ","�}��" });
    if(!me) return 0;
    if(!target) return notify_fail("�ؼЮ����F�C\n");
    if( environment(me) != environment(target) )
        return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
    if( me->query_spell("ice-sky") < (random(31)+40) )
    {
        message_vision(CYN"$N"CYN"���M�ܧV�O��������O�A���L���m�����A�I�k���ѤF�C\n"NOR,me);
        return 1;
    }
    if( me->query_temp("power_cast") < 1)
    {
        message_vision(HIC"$N"HIC"�]������ж˦ӶäF���, �L�k���Q�I�i�k�N�C\n"NOR,me);
        return 1;
    }
    me->delete_temp("power_cast");
    sk=mk/20+random(mk/20)+1;
    inn=me->query_int();
    level=me->query("level");
    shield=target->query_shield();

    damage = (mk*2)+(inn*3/2)+(level*3/2);
    damage = damage*2/3 + random(damage/3);
    if(userp(me)) damage=damage+(damage/6)-random(damage/8);
    damage = damage - (shield/3) -random(shield/3);
    if(damage>200) damage=200+((damage-200)/5);

    message_vision(CYN"$N��M�F���@�{�A�f����X�@�y:�u"+HIC+"�H�ѭ�a�i�ơj"+NOR+CYN+"�v�I\n"NOR,me);
    message_vision(CYN"�|�P�_�H��M���E���@���m�@�H��A�ѤU���_�ֳt�V$n�ƥh�I\n\n"NOR,me,target);

    if(damage > 0)
    {
        // COMBAT_D->dodge_factor(target,"dodge") �|�Ǧ^���{���v(�t��)
        if( random(mk*2 + inn*2)>random(-(COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int())))
        {
            // �W�[�����ˮ`���v�T
            damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
            if(damage < 10) damagemsg = "�D�`���L����ˡC";
            else if(damage < 20) damagemsg = "�@�ǨǪ���ˡC";
            else if(damage < 40) damagemsg = "�@�B��ˡC";
            else if(damage < 60) damagemsg = "�@�B�Y������ˡI";
            else if(damage < 100) damagemsg = "���Y������ˡI";
            else if(damage < 150) damagemsg = "�Q���Y������ˡI";
            else if(damage < 200) damagemsg = "�D�`�Y������ˡI";
            else if(damage < 301) damagemsg = "�����ʪ���ˡA$N���W�����F�B�I�I";
            else damagemsg = "�v�L�e�Ҫ��W�ŭ�ˡA����$N��������F�Y���ˮ`�I�I";
            target->receive_damage("hp", damage, me );
            message_vision(HIC"$N�Q�j�j�H��������A�y��$N"+damagemsg+""NOR,target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            COMBAT_D->report_status(target);         //���target���A
            /*	if( damage > 199 && random(me->query_int()) > random(target->query_int()) )
            	{
            		test = random(sizeof(limbs));
            		limbs = limbs[test];
            		message_vision(HIC"\n   $N��"+limbs+"�]����H�방�ӳQ��ˤF�I\n"NOR,target);
            		if(limbs == "�Y��") target->receive_wound("head",(damage/100));
            		if(limbs == "�}��") target->receive_wound("foot",(damage/100));
            		if(limbs == "����") target->receive_wound("body",(damage/100));
            		if(limbs == "�ⳡ") target->receive_wound("hand",(damage/100));
            	}*/
            if( damage > 50 )
            {
                message_vision(CYN"   $N����ʳQ�j�j�H��Ҽv�T�A�y�L�w�C�F�@�I�C\n"NOR,target);
                delay = damage / 50;
                if(delay > 4) delay = 4;
                target->start_busy(delay);
                if( damage > 100 ) {
                    me->receive_heal("mp",damage/5);
                    message_vision(HIG"   $N�����p�ݰ_�Ӧn�F�@�I�C\n"NOR,me);
                }
                if( damage > 200 ) me->receive_heal("ap",damage/5);
                if( damage > 300 ) me->receive_heal("hp",damage/5);
            }
        }
        else
        {
            message_vision(CYN"���L$N½���@���A�������׶}�F�o�D�j�j���H��C\n"NOR,target);
        }
    } else message_vision(CYN"���O�j�j�H�𥴦b$N���W�A���G�S������@�ΡC\n"NOR,target);

    if( random(40+inn) > 35 )
    {
        me->improve_spell("ice-sky",inn/2+random(inn/2)+5);
    }
    if(random(2+mk/12)==0) me->start_busy(1);
    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    if(random(11)<1) me->add_busy(1);
    return 1;
}
int delay5(object target,object me,int mk)
{
    string damagemsg,*limbs,limb;
    int inn,sk,damage,shield,level,test,delay;
    limbs = ({ "�Y��","����","�ⳡ","�}��" });
    if(!me) return 0;
    if(!target) return notify_fail("�ؼЮ����F�C\n");
    if( environment(me) != environment(target) )
        return notify_fail("�ؼ����}�F�A���I�k�d��C\n");
    if( me->query_spell("ice-sky") < (random(31)+40) )
    {
        message_vision(CYN"$N"CYN"���M�ܧV�O��������O�A���L���m�����A�I�k���ѤF�C\n"NOR,me);
        return 1;
    }
    if( me->query_temp("power_cast") < 1)
    {
        message_vision(HIC"$N"HIC"�]������ж˦ӶäF���, �L�k���Q�I�i�k�N�C\n"NOR,me);
        return 1;
    }
    me->delete_temp("power_cast");
    sk=mk/20+random(mk/20)+1;
    inn=me->query_int();
    level=me->query("level");
    shield=target->query_shield();

    damage = (mk*2)+(inn*3/2)+(level*3/2)+random(10);
    damage = damage*2/3 + random(damage/3);
    if(userp(me)) damage=damage+(damage/6)-random(damage/8);
    damage = damage - (shield/8);
    if(damage>305) damage=305+((damage-305)/5);

    message_vision(CYN"$N��M�F���@�{�A�f����X�@�y:�u"+HIC+"�i�ơj�H�ѡE�i���j��a�E�����X��"+NOR+CYN+"�v�I\n"NOR,me);
    message_vision(CYN"�|�P�_�H��M���E���@���m�@�H��A�W�U�]���ֳt�V$n���h�I\n\n"NOR,me,target);

    if(damage > 0)
    {
        // COMBAT_D->dodge_factor(target,"dodge") �|�Ǧ^���{���v(�t��)
        if( inn/3 + random(mk*2 + inn*2)>random(-(COMBAT_D->dodge_factor(target,"dodge")/2+target->query_int())))
        {
            // �W�[�����ˮ`���v�T
            damage = COMBAT_D->Merits_damage(me,target,damage,"wit");
            if(damage < 10) damagemsg = "�D�`���L����ˡC";
            else if(damage < 20) damagemsg = "�@�ǨǪ���ˡC";
            else if(damage < 40) damagemsg = "�@�B��ˡC";
            else if(damage < 60) damagemsg = "�@�B�Y������ˡI";
            else if(damage < 100) damagemsg = "���Y������ˡI";
            else if(damage < 150) damagemsg = "�Q���Y������ˡI";
            else if(damage < 200) damagemsg = "�D�`�Y������ˡI";
            else if(damage < 301) damagemsg = "�����ʪ���ˡA$N���W�����F�B�I�I";
            else damagemsg = "�v�L�e�Ҫ��W�ŭ�ˡA����$N��������F�Y���ˮ`�I�I";
            target->receive_damage("hp", damage, me );
            message_vision(HIC"$N�Q�j�j�H��������A�y��$N"+damagemsg+""NOR,target);
            if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                tell_object(me,HIY"("+damage+")"NOR);
            if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
            message_vision("\n",target);
            COMBAT_D->report_status(target);         //���target���A
            if( damage > 199 && random(me->query_int()) > random(target->query_int()) )
            {
                test = random(sizeof(limbs));
                limb = limbs[test];
                message_vision(HIC"\n   $N��"+limb+"�]����H�방�ӳQ��ˤF�I\n"NOR,target);
                if(limb == "�Y��") target->receive_wound("head",(damage/70));
                if(limb == "�}��") target->receive_wound("foot",(damage/70));
                if(limb == "����") target->receive_wound("body",(damage/70));
                if(limb == "�ⳡ") target->receive_wound("hand",(damage/70));
            }
            if( damage > 80 )
            {
                message_vision(CYN"   $N����ʳQ�j�j�H��Ҽv�T�A�y�L�w�C�F�@�I�C\n"NOR,target);
                delay = damage / 80;
                if(delay > 3) delay = 3;
                target->start_busy(delay);
                if( damage > 100 ) {
                    me->receive_heal("mp",damage/5);
                    message_vision(HIG"   $N�����p�ݰ_�Ӧn�F�@�I�C\n"NOR,me);
                }
                if( damage > 200 ) me->receive_heal("ap",damage/5);
                if( damage > 300 ) me->receive_heal("hp",damage/5);
            }
        }
        else
        {
            message_vision(CYN"���L$N½���@���A�������׶}�F�o�D�j�j���H��C\n"NOR,target);
        }
    } else message_vision(CYN"���O�j�j�H�𥴦b$N���W�A���G�S������@�ΡC\n"NOR,target);

    if( random(40+inn) > 35 )
    {
        me->improve_spell("ice-sky",inn/2+random(inn/2)+5);
    }
    if(random(2+mk/12)==0) me->start_busy(1);
    if(!target->is_fighting(me)) target->kill_ob(me);
    if(!me->is_fighting(target)) me->kill_ob(target);
    if(random(9)<1) me->add_busy(1);
    return 1;
}

