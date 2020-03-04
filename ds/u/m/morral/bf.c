#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
mapping *action = ({
	([
	"action": "$N���}��X���b�}���B�A�ܥ������x�A�@���u����v,\n  �V$n���y�����h",
	"damage":                10,
	"dodge" :                20,
            "damage_type":  "�A��",
        ]),

	([
	"action": "$N�@���u�����v�A�����j�B�e�i�A\n  �G�i$n���e�A���k�x�ΤO���V$n���ݤf",
	"damage":                15,
	"dodge" :                10,
	"parry" :               -20,
            "damage_type":  "����",
        ]),

	([
	"action": "$N�ϥX�@���u�ĺO�ĩաv�k�x�e����½�A\n  ���x�V�׫e�詵�����V$n",
	"damage":                8,
	"dodge" :                -10,
	"parry" :                20,
        "damage_type":  "�A��",
        ]),

	([
	"action": "$N�r�a��a�޽��A�@���u�s���}�v�A���}�e���V$n",
	"damage":                13,
	"dodge" :                10,
	"parry" :                -25,
        "damage_type":  "���",
        ]),

	([
	"action": "$N���B�@���A�@���u�ϯ{�v�A�����ۤW�詹�e�פ�e�@�j���A\n  �����a���V$n�ӻH",
	"damage":                10,
	"dodge" :                10,
	"parry" :                20,
        "damage_type":  "����",
        ]),

	([
	"action": "$N�@�s�V�e�j��T�B�A�@��"+ HIY "�u�K�s�a�v" NOR + "��y�ਭ�A\n  ��B��I�ĤO�V$n���h",
	"damage":                17,
	"dodge" :                10,
	"parry" :                -10,
        "damage_type":  "����",
        ]),
	
	([
	"action": "$N���y�I���A���}���e����@�B�A�@���u�D�����y�v�צp�j�����V$n�ݤf",
	"damage":                12,
	"dodge" :                -10,
	"parry" :                20,
	"damage_type":  "����",
	]),

	([
	"action": "$N�@���u����v�A���x���B�~��̴X��A�k�x�n�ɦV�׫e�U�襴�V$n�U�y�L",
	"damage":                12,
	"dodge" :                -10,
	"parry" :                20,
	"damage_type":  "����",
	]),

	([
	"action": "$N�ϥX�u�j�񵷡v�A���⥪�B�k�����a�o�޵�$n�צp�h�h���j",
	"damage":                10,
	"dodge" :                -10,
	"parry" :                10,
	"damage_type":  "���",
	]),

	([
	"action": "$N���B�e��A�k���ťѨ��᩹�e�e�@�j��A�@���u���B�{�v�A\n  �{�V$n�W�L�G�j�n�`",
	"damage":                14,
	"dodge" :                -20,
	"parry" :                -10,
	"damage_type":  "����",
	]),
});

int exert(object me, object target, string arg)
{
	int a,c,i,j,damage;
	int hs;   
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
	if(me->query("mp")<10 || me->query("hp")<10) return notify_fail("�A�����骬�p�L�k�ϥΤK�����k�C\n");
	//�ĤG��exert
	if(me->query_skill_mapped("unarmed")=="bagi_fist")
	{
	  if( !target ) target = offensive_target(me);
	  if(!target) 	return notify_fail("�A���b�ϥΡu�K�����v�C\n");
	   
	   //�����ʪ��n�S�O�`�N�n�[�U�����.
	   if(!me->can_fight(target))
		return me->can_fight(target);
	  
	  c = target->query_armor();

	  hs=me->query_skill("horse-steps");
	  if(hs>79) hs+=hs/3+random(hs/2);

	  if(me->query_skill("bagi_fist") > random(200) && me->query_skill("bagi_fist") > 49 )
	  {
      	   msg = HIC "\n$N��ܤ@�n�A��B���x, �ϥX���ޡu�r��w���s�v�A�����a���V$n���ݤf�I�I\n\n" NOR ;
	   damage = me->query_skill("bagi_fist") + hs;
	   damage =  damage/2 + random(damage) + me->query_damage();
	   damage -= random(target->query_armor());
	   if(damage<60) damage=60+random(me->query_str());
	   me->start_busy(2);
           if(random(me->query_skill("bagi_fist")) > 30 )
           {
		msg += HIR "���G$n���ݤf�Q$N���������A�n�ɨg�Q�@�f�A��T\n" NOR;
		target->start_busy(3);
	        target->receive_damage("hp",damage,me);
                COMBAT_D->report_status(target);
	   }
	    else
	   {
	    msg += HIW"�i�O�Q$n�T�V�a���k�F�}�h�A��$n�]�~�a���y�����C\n" NOR;
	   }
	   if(!me->is_fighting(target)) me->kill_ob(target);
	   if(!target->is_fighting(me)) target->kill_ob(me);
	   message_vision(msg, me, target);
	   me->receive_daemage("mp",30);
           return 1;
          }
          else
          {
	    i=random(me->query_skill("bagi_fist")/20)+1;
	    if(i>5) i=5;
	    if(i<1) i=1;

	    for( a=0; a<i; a++ )
	    {
		if(a>0) message_vision(HIC"\n�X��$n���j���ɡA$N���۾l�¤S�X���ۡI\n"NOR,me,target);
		j=random(sizeof(action));
		type=action[j];
		msg = type["action"]+NOR+", ";
		damage = (me->query_damage()+me->query_skill("bagi_fist")/2)+hs/3-random(c*3)/2;
		damage += type["damage"];
        	if( damage < 1 ) damage = random(20);
		if( random(me->query_dex()*2+me->query_skill("bagi_fist")/2) > random(target->query_dex()*2+target->query_skill("dodge")/2)+type["dodge"]
		 && damage>0)
		{
			msg += HIC"���G�y��$n"HIC"�@�B"+type["damage_type"]+"!!\n"NOR;
			message_vision(msg, me, target);
 	    		me->improve_skill("bagi_fist",target->query("level")/3);
                	target->receive_damage("hp",damage,me);
                	COMBAT_D->report_status(target);
		}
		 else
		{
			msg += "�i�O�Q$n���{�F�}�h�C\n";
			message_vision(msg, me, target);
			target->improve_skill("dodge",1);
		}
	    }
	    me->receive_damage("mp",i*7);
	    me->start_busy(1);
          }
          if(!me->is_fighting(target)) me->kill_ob(target);
	  if(!target->is_fighting(me)) target->kill_ob(me);
          me->improve_skill("bagi_fist",1+random(me->query_int()/2));
          me->improve_skill("unarmed",1+random(me->query_int()/2));
	  return 1;
	}

	me->map_skill("unarmed", "bagi_fist");
	me->reset_action();
	message_vision("\n"HIC"$N�L�@�����A�n�ɻ�y�B���y�M���y�T�y�۹�A�}�l�B�_�u�K�����v�ߪk�I\n"NOR,me);
	me->receive_damage("mp",5);
	me->start_busy(1);
        me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
	return 1;
}

void delay(object me,int cost)
{
	object weapon;
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
	
	if(me->query_skill_mapped("unarmed")!="bagi_fist")
	{
	 return;
	}
	
	if(me->query("mp")<5)
	{
	 	me->map_skill("unarmed");
		me->reset_action();
		tell_object(me,"\n�A����O�����A�L�k�~��ϥΤK�����C\n");
		return ;
	}
	if( me->is_fighting() ) me->receive_damage("mp",5); //luky
        me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
}

int valid_learn(object me) {	return 1;	}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me) {	return 1; }
