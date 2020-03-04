//�K��� reckon-finger.c �H hammer �Φ����g..
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
mapping *action = ({
	([
	"action": "$N�|�_�⤤$w�N���$n���Y�{�U�h",
	"damage":                1,
	"attack":                40,
	"attact_type":  "bar",
            "damage_type":  "���",
        ]),

	([
	"action": "$N�N�⤤$w����F�X��, �A��$n��$l��L�h",
	"damage":                1,
	"dodge" :               10,
	"parry" :               20,
	"attact_type":  "bar",
            "damage_type":  "�A��",
        ]),

	([
	"action": "$N²�檺�@�Ӹ��D, ���_$w��$n�N���F�U�h",
	"damage":                1,
	"dodge" :               20,
	"attack":               15,
	"attact_type":  "bar",
        "damage_type":  "���",
        ]),

	([
	"action": "$N�j���X��, �⤤$w�e�۱j�j�O�D��$n��$l���F�L�h",
	"damage":                40,
	"dodge" :               -10,
	"parry" :               -10,
	"attact_type":  "bar",
	"damage_type": "�A��",
        ]),
});

int exert(object me, object target, string arg)
{
	int c,i,j,damage,f;
	int a,sk,force,dodge,hit,num,rf,b;
	string msg,damagemsg;
	object weapon;
	f=me->query_skill("force");
        rf=me->query_skill("reckon-finger");
        sk=me->query_skill("finger");
	weapon=me->query_temp("weapon");
	if(weapon)
	{
		if(!weapon->query("is_abacus"))
                        return notify_fail("�A�⤤���۪����O��L�A�p��ϥΡu�K����v?\n");
	}
	if(arg=="off" )
	{
		if( me->query_skill_mapped("finger")!="reckon-finger")
			return notify_fail("�A�èS���b�ϥΡu�K����v�C\n");
		me->map_skill("finger");
		me->reset_action();
		write("�A����ϥ��K����F�C\n");
		return 1;
	}
        if(arg=="iron-finger")
        {
        	if(!target)
        	{
        		target = offensive_target(me);
        		if(!target) return notify_fail("\n�A�n�b�԰����~��Ρy�K������z�S�ޡC\n");
        	}
                if(me->query_skill_mapped("finger")!="reckon-finger")
                        return notify_fail("�z�{�b�èS���ϥ��K�����C\n");
                if( f < 30 || sk < 25 || rf < 25 )
                        return notify_fail("\n�z����\�O�٤����H�ϥX�y�K������z�S�ޡC\n");
                if(me->query("ap") < 30)
                        return notify_fail("\n�z����O�����ϥΡy�K������z�S�ޡC\n");
		if(!weapon->query("can_shoot"))
			return notify_fail("�A�ثe�ϥΪ���L����u�g��]�C\n");
		if( me->query_skill("finger") < random(10)+5 ) //��������
		{
			weapon->set_temp("loaded",weapon->query_temp("loaded")-1);
			me->receive_damage("hp",weapon->query_temp("abacus/damage"));
			return notify_fail("�A�����k�����, ���p�߼u��F�ۤv.\n");
		}
		if(weapon->query_temp("loaded") < 1)
			return notify_fail("\n�A���ҳѺ�]�����H���A�ϥX�y�K������z�S�ޡC\n");
                if(me->is_busy())
                        return notify_fail("\n�z���b����L���Ʊ���I\n");
		weapon->set_temp("loaded",weapon->query_temp("loaded")-1);
                //num = random(sizeof(enemy));
                //enemy[num]=present(enemy[num],environment(me));
                //c=enemy[num]->query_temp("apply/armor");
                c = target->query_armor(); //luky
                hit = random(COMBAT_D->attack_factor(me,"finger")); //luky
                dodge = random( - (COMBAT_D->dodge_factor(target,"dodge"))); //luky
                damage=weapon->query_temp("abacus/damage")+weapon->query("weapon_prop/damage");
		damage+=(sk/3)+(f/2)+(rf/4)+(me->query_damage()/4);
	  	damage= damage*2/3+random(damage/3);
	  	damage-=(target->query_armor()/4)+random(target->query_armor()/4)+(target->query_skill("force")/4);
                if(damage > 266) damage = 266+((damage-266)/4);
	  	damage = COMBAT_D->Merits_damage(me,target,damage,"tec");
		message_vision("$N�@�Ӽu���A�K������@�ۤw�g���Y�q�g�V$n�A",me,target);
		if(damage < 1)
		{
			message_vision("\n��$N�ϴx�@��, �~�M��"+weapon->query_temp("abacus/name")+"�w�ͥͪ������}�F�C\n",target);
			target->improve_skill("parry",2+random(target->query_int()/4));
			return 1;
	  	}
		if(hit + 50> dodge && damage > 0)
                {
			if(damage < 10) damagemsg = "$N���L���ˮ`�C";
			else if(damage < 40) damagemsg = "$N�@�B�ˮ`�C";
			else if(damage < 80) damagemsg = "$N�@�B�Y�������ˡC";
			else if(damage < 150) damagemsg = "$N�@�B�Q���Y�������ˡI";
			else if(damage < 250) damagemsg = "$N�@�B�D�`�Y�������j�ˮ`�I";
			else if(damage < 350) damagemsg = "$N���˳B�֦��z�}�A�A��g�Q�I�I";
			else damagemsg = "$N�����˳B��F�ӳz��ӹL��׼ҽk���j�}�I�I";
		        msg = HIR"�y��"+damagemsg+"\n"NOR;
                        message_vision(msg,target);
                        me->improve_skill("reckon-finger",random(3)+(me->query_int()/3));
                        // �W�[�����ˮ`���v�T
                        target->receive_damage("hp",damage,me);
                        COMBAT_D->report_status(target);
                        me->start_busy(1);
                        target->start_busy(1);
                }
                else
                {
                        msg = "��$n�ਭ�@�{�A�w�g�׶}�F�o�@�ۡC\n";
                        message_vision(msg, me, target);
                        me->improve_skill("reckon-finger",2);
                        target->improve_skill("dodge",3+random(2));
                        me->start_busy(2);
                }
                me->receive_damage("ap",damage/10+random(8));
                me->improve_skill("finger",3+(me->query_int()/3));
                return 1;
        }
        if(arg=="few-finger")
        {
        	if(!target)
        	{
        		target = offensive_target(me);
        		if(!target) return notify_fail("\n�A�n�b�԰����~��Ρy�}���i�ơz�S�ޡC\n");
        	}
                if(me->query_skill_mapped("finger")!="reckon-finger")
                        return notify_fail("�z�{�b�èS���ϥ��K�����C\n");
                if( f < 30 || sk < 25 || rf < 25 )
                        return notify_fail("\n�z����\�O�٤����H�ϥX�y�}���i�ơz�S�ޡC\n");
                if(me->query("ap") < 30)
                        return notify_fail("\n�z����O�����ϥΡy�}���i�ơz�S�ޡC\n");
		if(!weapon->query("can_shoot"))
			return notify_fail("�A�ثe�ϥΪ���L����u�g��]�C\n");
		if( me->query_skill("finger") < random(20)+10 ) //��������
		{
			weapon->set_temp("loaded",weapon->query_temp("loaded")-2);
			me->receive_damage("hp",(weapon->query_temp("abacus/damage")*2));
			return notify_fail("�A�����k�����, ���p�߼u��F�ۤv.\n");
		}
		if(weapon->query_temp("loaded") < 2)
			return notify_fail("\n�A���ҳѺ�]�����H���A�ϥX�y�}���i�ơz�S�ޡC\n");
                if(me->is_busy())
                        return notify_fail("\n�z���b����L���Ʊ���I\n");
		weapon->set_temp("loaded",weapon->query_temp("loaded")-2);
                //num = random(sizeof(enemy));
                //enemy[num]=present(enemy[num],environment(me));
                //c=enemy[num]->query_temp("apply/armor");
                c = target->query_armor(); //luky
		for(a=1;a<=2;a++)
		{
          	 hit = random(COMBAT_D->attack_factor(me,"finger")); //luky
                 dodge = random( - (COMBAT_D->dodge_factor(target,"dodge"))); //luky
                 damage=weapon->query_temp("abacus/damage")+weapon->query("weapon_prop/damage");
		 damage+=(sk/3)+(f/2)+(rf/3)+(me->query_damage()/3)+random(11);
	  	 damage= damage*3/4+random(damage/4);
		 damage= damage/2+random(11);
	  	 damage-=(target->query_armor()/4)+random(target->query_armor()/4)+(target->query_skill("force")/4);
                 if(damage > 180) damage = 180+((damage-180)/3);
	  	 damage = COMBAT_D->Merits_damage(me,target,damage,"tec");
		 message_vision("$N���⼷�ʺ�L�A�}���i�Ʋ�"+chinese_number(a)+"�ۤw�g�g�V$n�ӥh�A",me,target);
		 if(hit + 30> dodge)
                 {
			if(damage < 1) damagemsg = "��$N���M�w�ͥͪ��׶}�F�o�@���I";
	 		else if(damage < 10) damagemsg = "�y��$N���L���ˮ`�C";
 			else if(damage < 40) damagemsg = "�y��$N�@�B�ˮ`�C"; 
			else if(damage < 80) damagemsg = "�y��$N�@�B�Y�������ˡC";
			else if(damage < 150) damagemsg = "�y��$N�@�B�Q���Y�������ˡI";
			else if(damage < 250) damagemsg = "�y��$N�@�B�D�`�Y�������j�ˮ`�I";
			else if(damage < 350) damagemsg = "�y��$N���˳B�֦��z�}�A�A��g�Q�I�I";
			else damagemsg = "�y��$N�����˳B��F�ӳz��ӹL��׼ҽk���j�}�I�I";
		        msg = HIR+damagemsg+"\n"NOR;
                        message_vision(msg,target);
			if(damage < 1) target->improve_skill("parry",3);
                        me->improve_skill("reckon-finger",random(2)+(me->query_int()/4));
                        // �W�[�����ˮ`���v�T
                        target->receive_damage("hp",damage,me);
                        COMBAT_D->report_status(target);
                        me->start_busy(1);
                        target->start_busy(1);
                 }
                 else
                 {
                        msg = "��$n�ਭ�@�{�A�w�g�׶}�F�o�@�ۡC\n";
                        message_vision(msg, me, target);
                        me->improve_skill("reckon-finger",1);
                        target->improve_skill("dodge",3+random(2));
                        me->start_busy(2);
                 }
                 me->receive_damage("ap",damage/12+random(6));
                 me->improve_skill("finger",3+(me->query_int()/3));
		}
         return 1;
        }
	if(me->query_skill("finger")<11) 
                return notify_fail("�A�����k��¦�����A�L�k�ϥΡu�K����v�C\n");
        if(me->query("ap")<20 || me->query("hp")<15) 
                return notify_fail("�A�����骬�p�Ӯt�F�A����ϥΡu�K����v�C\n");
        if(!me->skill_active( "reckon-finger",(: call_other, __FILE__, "delay", me ,5:), 5))
                return notify_fail("�A����ϥ��K������ʧ@�٨S�����C\n");
	me->map_skill("finger", "reckon-finger");
	me->reset_action();
	message_vision(HIW"\n$N����y�L���ʤ⤤"+weapon->query("name")+HIW+"����]�A�ϰ_"+HIY+"�u�K����v�C\n"NOR,me);
    	me->receive_damage("ap",5);
	me->start_busy(2);
        return 1;
}

void delay(object me,int cost)
{
	object weapon;
	if(!me) return;
	weapon=me->query_temp("weapon");
	if(weapon)
	{
		if(!weapon->query("is_abacus"))
		{
	 	 me->map_skill("finger");
		 me->reset_action();
		 return;
		}
	}
	if(me->query_skill_mapped("finger")!="reckon-finger")
	{
	 return;
	}
        if(me->query("ap")<15)
	{
	 	me->map_skill("finger");
		me->reset_action();
		tell_object(me,"\n�A����O�����A����A�Ρu�K����v�F�C\n");
		return;
	}
        if( me->is_fighting() )
        	me->receive_damage("ap",5);
        me->skill_active( "reckon-finger",(: call_other, __FILE__, "delay", me ,cost:), 5);
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
        a=(ob->query_skill("finger"))*2/3;
	if(a>70) a=70;
	if(ob->query("adv_class")==2) return 90;
        else if(ob->query("adv_class")==1) return a;
}