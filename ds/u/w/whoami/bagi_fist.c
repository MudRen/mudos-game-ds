//New bagi_fist by Tmr  1999/10/15 18:30
// QC: Luky 1999.10.16 14:39
//Update By Tmr 2000/5/7

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


int exert(object me, object target, string arg)
{
	int a,c,i,j,k,damage,sk,lvtest,power,pcost,target_d,basicd;
	string msg;
    object weapon, wp;
	mapping type;
    
	weapon=me->query_temp("weapon");
	if(weapon && weapon->query("skill_type")!="unarmed")
		 return notify_fail("�A�⤤���۪Z���A����ϥΡu�K�����v�a�T\n");
	if(arg=="off" )
	{
        if( me->query_skill_mapped("unarmed")!="bagi_fist")
            return notify_fail("�A�èS���ϥΡu�K�����v�C\n");
        me->map_skill("unarmed");
        me->reset_action();
        write("�ޯ�u�K�����v�w�����C\n");
        return 1;
	}

	if(me->query_skill("unarmed")<5) 
		return notify_fail("�A���Ť�i����¦�����L�k�ϥΡu�K�����v�C\n");
	if(me->query("ap")<10 || me->query("hp")<10) 
		return notify_fail("�A�����骬�p�L�k�ϥΤK�����k�C\n");

	//�ĤG��exert
	if(me->query_skill_mapped("unarmed")=="bagi_fist")
	{
	if( !target ) target = offensive_target(me);
	if(!target)   return notify_fail("�A���b�ϥΡu�K�����v�C\n");
	if( environment(me) != environment(target) )
		return notify_fail("�A�̤��O�b�P�@��C\n");
       
        //�����ʪ��n�S�O�`�N�n�[�U�����.
	if(!me->can_fight(target)) return 0;
    if(target->is_corpse()) return notify_fail("�ݲM���A���v�g���F�C\n");  // add by wilfred �ѨM���O���骺���D
	c = target->query_armor();
	sk=me->query_skill("bagi_fist");
	target_d=-COMBAT_D->dodge_factor(target,"dodge")*10/15;
	power=me->query_temp("exert_mark/bagi-power"); //�Ȯɩʪ��F�賣�u�� temp ,quit�ɷ|�M��


        if( sk > 49 && random(sk) > random(150) )
	{
        msg = HIC "$N��ܤ@�n�A��B���x, �ϥX���ޡu�r��w���s�v�A�����a���V$n�I�I\n\n" NOR ;

        damage = sk + me->query_damage();
        damage = damage + random(damage/2);
	damage = damage - c/3 - random(c/3);
        if(power > 5)
        {
            if(power < 20)  { damage=damage+damage* 1/6; pcost=5;  }
            else if(power < 40) { damage=damage+damage* 2/6; pcost=10;  } //5��
            else if(power < 60) { damage=damage+damage* 3/6; pcost=15;  } //4��
            else if(power < 80) { damage=damage+damage* 4/6; pcost=20;  } //3��
            else  { damage=damage+damage*5/6; pcost=30; } //2��
            me->add_temp("exert_mark/bagi-power",-pcost);
        }
       damage = COMBAT_D->Merits_damage(me,target,damage,"bar");

       if( userp(me) && userp(target) ) me->start_busy(2);
       else me->start_busy(1);
       me->receive_daemage("ap",50 );
       if(  damage > 0 && sk + random(sk/2) > random(target_d) )
        {
	msg += HIR "$n�Q$N" HIR "���������A�n�ɨg�Q�@�f�A��T�I" NOR;
  if( objectp(wp = me->query_temp("weapon")) ) wp->attack(); // wp �l�a�v add by wilfred
        target->add_busy(1+random(2));
        message_vision(msg, me, target);
        target->receive_damage("hp",damage,me);
        if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
		tell_object(me,HIY"("+damage+")"NOR);
        if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
		tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
	message_vision("\n", me);
        COMBAT_D->report_status(target);
	}
	else    {
		msg += HIW"�i�O�Q$n" HIW "�T�V�a���k�F�}�h.....\n" NOR;
		message_vision(msg, me, target);
	}
	if(!me->is_fighting(target)) me->kill_ob(target);
        if(!target->is_fighting(me)) target->kill_ob(me);
        return 1;
	}
        else
	{
	if( sk < 20) i=1;
	else 	if( sk < 40) i=1+random(2);
	else 	if( sk < 60) i=2+random(2);
	else 	if( sk < 80) i=2+random(3);
	else 	i=3+random(3);
        if(userp(me) && userp(target)) me->start_busy(2);
        else me->start_busy(1);
        k=0;
        basicd =sk+me->query_damage();
        for( a = 0; a < i; a++ )
        {
	if ( a > 0) msg=HIC"�X��$n"HIC"���j���ɡA$N���۾l�¤S�X���ۡI\n"NOR;
        else msg ="";
        j=random(sizeof(action));
        type=action[j];
        msg += type["action"]+NOR+", ";
        damage = basicd/4+random(basicd/4);
        if(power>10)
        {
            if(power < 20)  { damage=damage+damage*1/8; pcost=5; }
            else if(power < 40)     { damage=damage+damage*2/8; pcost=10; }
            else if(power < 60)     { damage=damage+damage*3/8; pcost=15; }
            else            { damage=damage+damage*4/8; pcost=20; }
            me->add_temp("exert_mark/bagi-power",-pcost);
        }
        damage = damage - c/2 - random(c/2);
        damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
        if(damage<1) damage = 1+random(5);
        if( sk/2+random(sk) > random(target_d)  )	//�s�����������R���v
        {
            msg += HIC"���G�y��$n"HIC"�@�B"+type["damage_type"]+"!!"NOR;
            message_vision(msg, me, target);
  if( objectp(wp = me->query_temp("weapon")) ) wp->attack(); // wp �l�a�v add by wilfred
                me->improve_skill("bagi_fist",target->query("level")/3);
                    damage=damage*(6-k)/6;
                    target->receive_damage("hp",damage,me);
                if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                        tell_object(me,HIY"("+damage+")"NOR);
                if(target->query_temp("apply/show_damage") || target->query_temp("show_damage") )
                        tell_object(target,HIR"("+damage+")"NOR+" ("+target->query("hp")+"/"+target->query("max_hp")+")");
                if(wizardp(me) && me->query("env/debug")) 
                        tell_object(me,"  �y��"+damage+"�I�ˮ`!!\n"); 
                message_vision("\n", me);
                k++;
	}
	else        {
		msg += "�i�O�Q$n���{�F�}�h�C\n";
		message_vision(msg, me, target);
		target->improve_skill("dodge",1);
        }
        }

        if(k) COMBAT_D->report_status(target);
        me->receive_damage("ap",i*8);
	}
	if(!me->is_fighting(target)) me->kill_ob(target);
	if(!target->is_fighting(me)) target->kill_ob(me);
	me->improve_skill("bagi_fist",1+random(me->query_int()/2));
	me->improve_skill("unarmed",1+random(me->query_int()/2));
	return 1;
	}
	if(!me->skill_active( "bagi_fist",(: call_other, __FILE__, "delay", me ,5:), 10))
	return notify_fail("�A�����K�������ʧ@�٨S�����C\n");

	me->map_skill("unarmed", "bagi_fist");
	me->reset_action();
	message_vision("\n"HIC"$N�L�@�����A��y�B���y�M���y�T�y�۹�A�}�l�B�_�u�K�����v�ߪk�I\n"NOR,me);
		me->receive_damage("ap",5);
	me->start_busy(1);
	return 1;
}

int valid_learn(object me) {    return 1;   }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
	int a;
	a=ob->query_int();
	a=75+a;
	return a;
}
