// ��s���: 1999.10.15
// ��s��: Luky
// QCer: Luky
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me,int cost);
void delay2(object me);
int h=this_player()->query_skill("horse-steps")/10;

mapping *action = ({
	([
	"action": "$N�@���⤤$w�A�@��"+HIW"�y"+NOR"�ﶳ�g��"+HIW"�z"+NOR"�{�Y�q���p�w���a��V$n�ݤ��n�`",
	"damage":                10+h,
	"dodge" :                20,
	"parry" :		 20,
	"attact_type":  "bar",	
        "damage_type":  "���",
        ]),

	([
	"action": "�u��$N�⤤$w�ɵo�ƤV��l�A���M�@��"+HIW"�y"+NOR"���s�D�W"+HIW"�z"+NOR"����$n�ݡB���n�`",
	"damage":                10+h,
	"dodge" :                10,
	"parry" :		 15,
	"attact_type":  "bar",	
        "damage_type":  "���",
        ]),

	([
	"action": "�u��$N�L�@�����A�@��"+HIW"�y"+NOR"�����I�B"+HIW"�z"+NOR"�A�⤤$w�D�_�Ʀ��J�j�j��A�ɸn$n���e�ƳB�n�`",
	"damage":                10+h,
	"dodge" :                10,
	"parry" :		 20,
	"attact_type":  "bar",	
        "damage_type":  "���",
        ]),

	([
	"action": "$N�~�a�N�⤤$w��L�ѻڵe�F�Ӫ����A�@��"+HIW"�y"+NOR"���i¶��"+HIW"�z"+NOR"��$n�Y���۩I",
	"damage":                10+h,
	"dodge" :                10,
	"parry" :		 10,
	"attact_type":  "bar",	
        "damage_type":  "�A��",
        ]),

	([
	"action": "$N�I�i�@��"+HIW"�y"+NOR"�^�����v"+HIW"�z"NOR+"�A�j�դ@�ܡA�{�Y�D����H�_������쪽��$n�I���n�`",
	"damage":                10+h,
	"dodge" :                -10,
	"parry" :		 -10,
	"attact_type":  "bar",	
        "damage_type":  "���",
        ]),

	([
	"action": "$N�r�ܤ@�n�A�g�R�⤤$w�A�n�ɤۤƥX�ƹD�a����l�A�@��"+HIW"�y"+NOR"�ɱa¶�y"+HIW"�z"NOR+"����$n�U�L",
	"damage":                10+h,
	"dodge" :                10,
	"parry" :		 10,
	"attact_type":  "bar",	
        "damage_type":  "���",
        ]),

	([
	"action": "$N�@��"+HIW"�y"+NOR"��P�|��"+HIW"�z"+NOR"�A��W$w�ѤU���W�@�D�A�l���L��a��$n���V��h",
	"damage":                15+h,
	"dodge" :                20,
	"parry" :		 20,
	"attact_type":  "bar",	
        "damage_type":  "���",
        ]),
});

int exert(object me, object target, string arg)
{
	int a,c,i,j,damage;
	int hs,dt,hst,hslv,temp;   
	string msg;

	object weapon,*enemy;
	mapping type;
		
	weapon=me->query_temp("weapon");
	if (!weapon) return notify_fail("�A�o���K�j�~��I�i�u�j�j�Z�v�C\n");
	if(weapon->query("skill_type")!="fork") return notify_fail("�A�o���K�j�~��I�i�u�j�j�Z�v�C\n");

	if(arg=="off" )
	{
		if( me->query_skill_mapped("fork")!="da-fork")
			return notify_fail("�A�èS���ϥΡu�j�j�Z�v�C\n");
		me->map_skill("fork");
		me->reset_action();
		write("�ޯ�u�j�j�Z�v�w�����C\n");
		return 1;
	}

	if(me->query_skill("da-fork")<10) return notify_fail("�̧A�ثe���\\�O�A�|�����I�i�u�j�j�Z�v�C\n");
	if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("�A�����骬�p�L�k�ϥΡu�j�j�Z�v�C\n");


	//�ĤG��exert
	if(me->query_skill_mapped("fork")=="da-fork")
	{
		if (!me->is_fighting()) 
		return notify_fail("�A�w���b�I�i�j�j�Z�F�C\n");		  
		if (me->query_skill("da-fork") < 50)
		return notify_fail("�̧A�ثe���j�j�Z���ԡA�|����I�i����\n");
		if(me->query("ap")<200) 
		return notify_fail("�A�ثe�����l�����C\n");
		if(me->query("hp") <150)
		return notify_fail("�A�ثe����O�����I�i�j�j�Z���ޡC\n");

	   //�����ʪ��n�S�O�`�N�n�[�U�����.
	   	message_vision("\n"HIW"$N���O�@���A�⤤"+weapon->query("name")+HIW "���@�T�A�j�j�Z�W�իݵo�I�I\n"NOR,me);
	   	me->start_busy(2);
		call_out("delay2",3,me);
		return 1;
	}
	
        if(!me->skill_active( "da-fork",(: call_other, __FILE__, "delay", me ,5:), 10))
          return notify_fail("�A�����B�\\���ʧ@�٨S�����C\n");
	
	me->map_skill("fork", "da-fork");
	me->reset_action();
	message_vision("\n"HIW"$N�⤤"+weapon->query("name")+HIW "�~�a�@�_�A�j�j�Z��l�n�ɥ|���ӥX�I�I\n"NOR,me);
	me->receive_damage("ap",10);
	me->start_busy(1);
        //me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 10);
	return 1;
}

void delay2(object me)
{
	int hs,dt,hslv,hst,damage,temp,c,damage1,k,power,pcost;
	object *enemy,target,weapon;
	string *limbs;
	hs=me->query_skill("horse-steps");
	if(hs>79) hs=70+(random(hs-79))+random(15);

	damage1 = me->query_skill("da-fork") + hs;
	weapon=me->query_temp("weapon");
	if(!weapon) return;
	enemy = me->query_enemy();
	
	if(sizeof(enemy)<1 || !me->is_fighting())
	{
	  message_vision( HIW "\n$N�~�a�@�}�M�S�A�����H�J����ư�A�⤤"
         +weapon->query("name")+HIW "���a�a�ƹD��l�V�ѪŮg�h!\n" NOR
	,me);
	return;
	}
      	
      	message_vision(
	 HIW "\n$N�~�a�@�}�M�S�A�����H�J����ư�A�⤤"
         +weapon->query("name")+HIW "���a�a�ƹD��l�V�|���K��g�h\n" NOR
	,me); 
	k=2+random(3);
	power=me->query_temp("exert_mark/bagi-power");
	for (dt=0;dt<sizeof(enemy) && dt<k;dt++)
	{
		write("\n");
		target=enemy[dt];
		if(environment(target)!=environment(me)) break;
        	c = target->query_armor();
	  if(random(me->query_skill("da-fork")*2) > random(target->query_dex()/2) )
	  {
		hslv=me->query_skill("horse-steps");
		hslv /=10;
		if (hslv<2) hslv=2;
		if (hslv>4) hslv=4;
		
		hslv=hslv/2+random(hslv/2+1);
		
		for (hst=0;hst<hslv;hst++)
		{
			limbs = target->query("limbs");
			message_vision(
				HIY "$N�����@�ۨ�V$n��"+limbs[random(sizeof(limbs))]+"�I�I" NOR
				,me,target);
		if(damage<20) damage=20+random(20);
                    if(random(me->query_dex()*2)+random(me->query_skill("da-fork")*3/2)<random((target->query_dex()/2)+target->query_skill("dodge")))
                		message_vision(HIG "\n�i�O�Q$N�׶}�F�I�I\n"NOR,target);
                	else
                	{
				damage = (damage1/4)+(me->query_damage()/2)+random(me->query_damage()/4);
				if(power>10)
				{
					if(power < 20) 	{ damage=damage+damage/7; pcost=3; }
					else if(power < 40) 	{ damage=damage+damage/5; pcost=5; }
					else if(power < 60) 	{ damage=damage+damage*2/7; pcost=7; }
					else 			{ damage=damage+damage*2/5; pcost=9; }
					me->add_temp("exert_mark/bagi-power",-pcost);
				}
				if(userp(me)) damage = damage * (85+random(11)) / 100;
				if(damage > 50) damage = 50 + ((damage-50)/2);
				damage = damage - (c/2) - random(c/2);
                		damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
				tell_object(me,HIY+" ("+HIR+damage+HIY+")"+NOR);
				message_vision("\n",me);
        target->receive_damage("hp",damage,me);
	        		COMBAT_D->report_status(target);
			}
	 	}	
	  }
	  else   message_vision(HIG "�i�O�Q$N�T�V�a�k�F�}�L�ƺj�l����աI�I\n"NOR,target);
	} 
	 
	me->receive_damage("ap",(hslv*10*(sizeof(enemy))));
	temp=5+(hslv*4*(sizeof(enemy)));
	if(me->query("hp")>temp) me->receive_damage("hp",5+(hslv*4*(sizeof(enemy))));
	else me->set("hp",1);
	   //me->start_busy(2);
		me->improve_skill("da-fork",1+me->query_int()/4+random(3));
		me->improve_skill("fork",1+me->query_int()/4+random(2));
        return ;
}

void delay(object me,int cost)
{
	object weapon,target;

	if(!me) return;
	weapon=me->query_temp("weapon");
	if (!weapon)
	{
		me->map_skill("fork");
	 	me->reset_action();
		return;
	}
	if(weapon->query("skill_type")!="fork")
	{
 	 me->map_skill("fork");
	 me->reset_action();
	 return;
	}
	
	if(me->query_skill_mapped("fork")!="da-fork")  return;
	
	if(me->query("ap")<15)
	{
	 	me->map_skill("fork");
		me->reset_action();
		tell_object(me,"\n�A����O�����A�L�k�~��ϥΤj�j�Z�C\n");
		return ;
	}

	if( me->is_fighting() ) 
	{
		if(random(10)>5 && me->query_skill("horse-steps") >50 && me->query_skill("da-fork")>random(110) )
		{
	          if( !target ) target = offensive_target(me);
                  if(!target)   return;
                  message_vision(
 		  YEL"$N�C�����n�A�F�@�B�B��@�B�a�۪�$n���e�A��a�N"+weapon->query("name")+YEL"��b$n����B\n"
		  +YEL "�n�ɥk������e���I��$n�޹D�A���O�j�j�Z�@��"+HIY "�y�����ۤs�z"+NOR"�I�I\n" NOR,
		  me,target);
		  me->receive_damage("ap",15); 

		  if(random(target->query_dex()+target->query_int()) <=random(80))
		  {
			message_vision(HIB"�u��$N���ηL���A�w���F�o�@���C\n" NOR ,target);
			target->start_busy(2);
		  } else
		  {
			message_vision(HIW"$N���Τ@��A�׶}�o�@���C\n" NOR ,target);
		  }
	        }
		me->receive_damage("ap",10);
	}
        //me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
        me->skill_active( "da-fork",(: call_other, __FILE__, "delay", me ,cost:), 10);
        return;
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
	a=70+a;
	return a;
}
