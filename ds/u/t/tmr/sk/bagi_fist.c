//New bagi_fist by Tmr 	1999/10/15 18:30
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
	int a,c,i,j,k,damage,sk,lvtest,power,pcost;
	string msg;
	object weapon;
	mapping type;
	
	weapon=me->query_temp("weapon");
	if(weapon)
	{
		if(weapon->query("skill_type")!="unarmed") return notify_fail("�A�⤤���۪Z���A����ϥΡu�K�����v�a�T\n");
	}
	if(arg=="off" )
	{
		if( me->query_skill_mapped("unarmed")!="bagi_fist")
			return notify_fail("�A�èS���ϥΡu�K�����v�C\n");
		me->map_skill("unarmed");
		me->reset_action();
		write("�ޯ�u�K�����v�w�����C\n");
		return 1;
	}

	if(me->query_skill("unarmed")<5) return notify_fail("�A���Ť�i����¦�����L�k�ϥΡu�K�����v�C\n");
	if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("�A�����骬�p�L�k�ϥΤK�����k�C\n");

	//�ĤG��exert
	if(me->query_skill_mapped("unarmed")=="bagi_fist")
	{
	  if( !target ) target = offensive_target(me);
	  if(!target) 	return notify_fail("�A���b�ϥΡu�K�����v�C\n");
	   
	   //�����ʪ��n�S�O�`�N�n�[�U�����.
	   if(!me->can_fight(target))
		return me->can_fight(target);
	  c = target->query_armor();
	  sk=me->query_skill("bagi_fist");

	  if( sk > 49 && random(sk) > random(150) )
	  {
      	   msg = HIC "$N��ܤ@�n�A��B���x, �ϥX���ޡu�r��w���s�v�A�����a���V$n���ݤf�I�I\n\n" NOR ;

		damage = sk+me->query_str()+me->query_damage();

//�ĥ�horse-steps ���B�~�n�s��bagi-power �Ӫ��[�S��¤O�C
//�˱��ĥ� horse-setps LV �p��覡�C
//bagi-power �̺���1000�C�]���n����horse-steps= 100)�C by Tmr

		power=me->query("bagi-power");
		if(power>10)
		{
		if(power < 100) 	{damage=damage+damage* 1/10; pcost=5;  }
		else if(power <250) 	{damage=damage+damage* 3/10; pcost=25;  }  //����
		else if(power < 500) 	{damage=damage+damage* 5/10; pcost=60;}   //�T��
		else if(power < 800) 	{damage=damage+damage* 7/10; pcost=150;} //�G��
		else 			{damage=damage*2;    	       pcost=200;} //�@��
		me->add("bagi-power",-pcost);
		if(wizdarp(me) )
			tell_object(me,"bagi-power -> "+me->query("bagi-power") +"\n");
		}
	   damage = damage - c/2 - random(target->query_skill("parry")/2+target->query_skill("dodge") /2 );

//�����̧C�ˮ`�O
//	   if(damage < 30) damage=30+random(me->query_str()/2);

	   if(userp(me) && userp(target) ) me->start_busy(2);
	   else me->start_busy(1);

           if(  damage => 0 && random(sk) > 40 )
           {
		msg += HIR "$n���ݤf�Q$N���������A�n�ɨg�Q�@�f�A��T�I\n" NOR;
		target->start_busy(random(3));
		// �W�[�����ˮ`���v�T
		damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
		target->receive_damage("hp",damage,me);
		if(wizardp(me)) printf("%d\n",damage);
	}
	else
	{
	  msg += HIW"�i�O�Q$n�T�V�a���k�F�}�h�A��$n�]�~�a���y�����C\n" NOR;
	}
	   if(!me->is_fighting(target)) me->kill_ob(target);
	   if(!target->is_fighting(me)) target->kill_ob(me);
	   message_vision(msg, me, target);
               COMBAT_D->report_status(target);
	   me->receive_daemage("ap",30 );
	   return 1;
         }
         else
	{
	    i=random(sk/20)+1;
	    if(i>5) i=5;
	    if(i<1) i=1;

	    if(userp(me) && userp(target)) me->start_busy(2);
	    else me->start_busy(1);

	    for( a=0; a<i; a++ )
	    {
		if(a> 0) msg=HIC"�X��$n���j���ɡA$N���۾l�¤S�X���ۡI\n"NOR;
		else msg ="";
		j=random(sizeof(action));
		type=action[j];
		msg += type["action"]+NOR+", ";

		damage = me->query_damage()/2+me->query_str()/2+sk/3+type["damage"];

//�ĥ�horse-steps ���B�~�n�s��bagi-power �Ӫ��[�S��¤O�C
//�˱��ĥ� horse-setps LV �p��覡�C
// bagi-power �̺���1000�C�]���n����horse-steps= 100)�C by Tmr
		if(power>10)
		{
		if(power < 300) 	{damage=damage+damage* 1/10; pcost=5;}
		else if(power < 500) 	{damage=damage+damage*3/10; pcost=10;}
		else if(power < 800) 	{damage=damage+damage*5/10; pcost=20;}
		else 			{damage=damage+damage*8/10;   pcost=35;}
		me->add("bagi-power",-pcost);
		}

//�����̧C�ˮ`�O
//        	if( damage < 1 ) damage = random(20);

			// �W�[�����ˮ`���v�T
		damage = COMBAT_D->Merits_damage(me,target,damage,"bar");

		if( random(COMBAT_D->attack_factor(me,"unarmed")) > random(-COMBAT_D->dodge_factor(target,"dodge"))+type["dodge"]  && damage>0)
		k=0;
		if( damage > 0 )
		{
			msg += HIC"���G�y��$n"HIC"�@�B"+type["damage_type"]+"!!\n"NOR;
			message_vision(msg, me, target);
 	    		me->improve_skill("bagi_fist",target->query("level")/3);
	            if(wizardp(me)) printf("%d\n",damage);
                	target->receive_damage("hp",damage,me);
                	k++;
		}
		 else
		{
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
//	me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
	return 1;
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
	a=75+a;
	return a;
}
