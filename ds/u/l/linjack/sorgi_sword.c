// ��s���: 1999.10.16
// ��s��: Luky
// QCer: Luky
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me);
void running_fire(object me,object target,int damage);

mapping *action = ({
	([
	"action": "$N�����@�w�A�N�⤤���C���a�R���C��A\n  �X$n���`�N�ɡA�@�|�ϥX�u���S���s�v�A��$n�ݤf��h",
	"damage":                50,
	"dodge" :                -15,
	"attack":		-15,
        "damage_type":  "���", 
	]),
	([
	"action": "$N�j�ܤ@�n�A���t�ϥX�u���Ԧ۬١v�A�C�y��\n  $n��W�����j�n�ަӥh",
	"damage":                20,
	"dodge" :                -5,
        "damage_type":  "���", 
	]),
	([
	"action": "$N�����믫�A�����k��A��b���j�ߤ����u�𨳳t���^�Ȥ��A\n  �@�K�����A$N��C�ϥX�p÷���@�멹$n���W�g���ӥh",
	"damage":                25,
	"dodge" :                10,
        "damage_type":  "�@��", 
	]),
	([
	"action": "$N���ߤ@�ѽİʡA��C�ϥX�@�ۡu�p�üC�v�A\n  �N�C���s���������@�멹$n���Y���{�h",
	"damage":                15,
	"dodge" :                -3,
        "damage_type":  "�ж�", 
        ]),
	([
	"action": "$N�q�y�ڮ��F�@�U�s�U�A�ܤF�@�ܡA���G�K�F�@��A\n  �@���p�ߨϥX�u�s���K�H�v�A�K�p�s���@���$n���������Ӧp��O�n",
	"damage":                20,
	"dodge" :                -15,
        "damage_type":  "���", 
        ]),
	([
	"action": "$N�ߤ��@���A�y��@�C�A�ߧY��$n�U�F�@�ۡu����F�v�A\n  �C���K�p�������k�@��",
	"damage":                23,
	"dodge" :                13,
        "damage_type":  "���", 
        ]),
	([
	"action": "$N�ϥX�@�ۥ����L�_�����c�C��$n���W�n�ަӥh�A\n  ���Ʀb�~�������ܬ��u���s�զ�v�A�ϧ�V$n�U�L",
	"damage":                18,
	"dodge" :                5,
        "damage_type":  "���", 
        ]),
	([
	"action": "$N�⾮�@�ۡu�|�c��Ѫ�v�A���۫K�r��$n��W�j�ޡA\n  ���ۤS�p�p��@�뻴�X����V$n�V��",
	"damage":                17,
        "damage_type":  "�W��", 
        ]),
});

int exert(object me, object target, string arg)
{
	int a,c,i,j,damage,sk,p,cost,force;
	string msg;
	object weapon;
	mapping type;
	
	weapon=me->query_temp("weapon");
	sk=me->query_skill("sorgi_sword");
	force=me->query_skill("force");
	if( arg=="off" )
	{
		if( me->query_skill_mapped("sword")!="sorgi_sword" )
			return notify_fail("�����C�k�èS���b�ϥΡC\n");
		me->map_skill("sword");
		me->reset_action();
		me->delete_temp("exert_mark/sorgi_sword");
		me->delete_temp("power_exert");
		write("�ޯत���u�����C�k�v�w����ϥΡC\n");
		return 1;
	}

	if( !weapon)
		return notify_fail("�����D�ݭn�C�~��ϥΡC\n");

	if( weapon->query("skill_type")!="sword" )
		return notify_fail("�p�G�n�ϥί����C�k�A�h�����˳ƼC���Z���C\n");

	if( me->query("ap") < 20 )
		return notify_fail("�A����O�٤����H�ϥί����C�k�C\n");

	if( me->query_skill_mapped("sword")=="sorgi_sword" ) 
	{
		if( !target ) target = offensive_target(me);
		if( !target ) return notify_fail("�A�٦b�I�i�i�����C�k�j�C\n");
		if( me->query_temp("exert_mark/sorgi_sword") ) return notify_fail("(�A�W�@�Ӱʧ@�٨S�����C)\n");
		if( !me->can_fight(target) ) return me->can_fight(target);
		if( !me->is_fighting(target)) me->kill_ob(target);
		if( !target->is_fighting(me)) target->kill_ob(me);
		c = target->query_armor();
		p = me->query_damage();
		if( sk > random(300) && !target->is_busy())
		{
			msg = HIY"\n$N"HIY"�ߤ��K�p���R�����@��A���a�@�a���D�A�@�ۡu�Ѷ����s�b�v�q$n"HIY"����襩������$n"HIY"���R���ӥh�I�I\n"NOR ;
			damage = (me->query_skill("moon_force")*2/5) + p + random(p/4+sk/5);
			if( userp(me) ) damage = damage * (75+random(11)) / 100;
			damage = damage - c/3 - random(c/3);
			if( me->query_temp("sorgitimes") > 10 )
			{ damage = damage + (damage*67/100); cost = 4; } 
			else if( me->query_temp("sorgitimes") > 6 )
			{ damage = damage + (damage*43/100); cost = 3; }
			else if( me->query_temp("sorgitimes") > 3 )
			{ damage = damage + (damage*21/100); cost = 2; }
	 		if( damage < 25 ) damage = 20 + random(8);
			if( me->query_temp("sorgitimes") > 3 )
				message_vision(HIM"   $N�J�a�@�ݤ⤤���C�A�u�W���O�ѼC�y���I�ӥX�I\n",me);
	 		me->start_busy(2);

			if( random(sk+5)*5/3 > random(target->query_skill("dodge",2)) )
			{
				msg += HIM "$n"HIM"���R�����B�Q$N"HIM"��"+weapon->name()+HIM"�@���L�h�A�@�D�������岪�����z�X�@�ά����H�G�T" NOR;
				target->delete_temp("power_exert");
				target->delete_temp("power_cast");
				target->start_busy(3);
				damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
				target->receive_damage("hp",damage,me);
			        me->improve_skill("sorgi_sword",1+me->query_int()/7);
			        me->improve_skill("sword",1+me->query_int()/5);
			}
			else
			{
				msg += HIY"$n"HIY"�D�o�{$N"HIY"���I��R�����B�A�ਭ���F�}�ӡC" NOR;
				damage = 0;
			}
			message_vision(msg, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+damage+")\n"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_status(target);
			me->receive_damage("ap",30);
			return 1;
		}
		else
		{
			damage = sk/6 + p/3 + random(p/5) + random(force/7)+(force/7);
			if( userp(me) ) damage = damage * (73+random(10)) / 100;
			damage = damage - c/3 - random(c/3);
	 		if( damage < 10 ) damage = 8 + random(5); //�{�b�����| miss, �G���_�C��
			if( damage > 135) damage = 135 + ((damage-135)/3);  //�¤O�ӱj���_�H���
	 		//damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
	 		//�������ɤޥ�
			
			/*i=( sk+me->query_skill("fogseven"))/2;
			if ( i > 50 )i = 2;            //���շs��k, i ���N�J running-fire �� z ��.
			if ( i < 51 )i = 1;*/
			me->add_temp("power_exert",2+sk/25);
			message_vision(HIW"\n$N"HIW"�`�l�F�@�f��A�¤��u��B�ण���A���ۻW�իݵo�C\n"NOR,me,target);
			me->set_temp("skill/sorgi_sword",1);
			if(userp(me))
			{
				if(!me->query_temp("sorgitimes")) call_out("running_fire",3,me,target,damage);
				else call_out("running_fire",3-random(2),me,target,damage);
				me->start_busy(2);
			}
			else
			{
				if(!me->query_temp("sorgitimes")) call_out("running_fire",2,me,target,damage);
				else call_out("running_fire",2-random(2),me,target,damage);
				me->start_busy(2);
			}
			return 1;
		}
        }
        if(!me->skill_active( "sorgi_sword",(: call_other, __FILE__, "delay", me :), 6))
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

	if( me->query_skill_mapped("sword")!="sorgi_sword" )
	{
		return;
	}

	if( me->query("ap")<10 )
	{
	 	me->map_skill("sword");
		me->reset_action();
		message_vision("\n"HIW"$N"HIW"����O�����L�k�~��I�i�����C�k�C\n"NOR,me);
		return ;
	}

	if( me->is_fighting() ) me->receive_damage("ap",7);

	me->skill_active( "sorgi_sword",(: call_other, __FILE__, "delay", me :), 6);
}

void running_fire(object me,object target,int damage)
{
	int dam,dex,sk,tdod;
	string a="$N�⤤���C���a�R���C��A�ϥX�u���S���s�v�A��$n�ݤf��h�A",
	       b="$N���t�ϥX�u���Ԧ۬١v�A�C�v�@�������A����$n��W���j�n�ޡA",
	       c="$N���j�ߤ����u�𨳳t���^�Ȥ��A�K�����C���p÷���뮹��$n�A",
	       d="$N���_�s�U�ܤF�@�f�A�ϥX�u�s���K�H�v�A�C�զp�g���멹$n��h�A",
	       e="$N�@�ۤ��c�C���V$n�A���ର�u���s�զ�v�A�F�D�몽��$n�������A",
	       msg;
	sk=me->query_skill("sorgi_sword");
	dex=me->query_dex();
	dex=dex*5;
	tdod=target->query_skill("dodge");
	tdod=tdod*2/3;
	if(dex>200) dex = 200;
	if(dex<10) dex = 10;
	if(!me) return;
	if(!target) return;
	if(!me->is_fighting(target)) return;
	if(environment(me)!=environment(target))
	{
		message_vision("$N�]��������}�Ӱ���F�o������աC\n",me);
		return;
	}
	me->delete_temp("exert_mark/sorgi_sword");
	if(me->query_temp("power_exert")<1)
	{
	 message_vision(CYN"\n$N"CYN"����жˤ@�ɶäF�}�}�A�h�F�T�B�C\n"NOR,me);
	 return;
	}
	me->delete_temp("power_exert");
	if ( me->query_temp("sorgitimes") < 2 ) 
	{
		if ( random(target->query_skill("dodge")+target->query_dex()) <= random((me->query_skill("sorgi_sword")+me->query_dex())*2) )
		{
			if( random(dex+35) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
			{
			a += HIR"���G�y��$n"HIR"�@�B�ж�!!"NOR;
                	target->receive_damage("hp", dam , me );
                	} else { a+="���O�Q$n���}�F!!"NOR; dam = 0; }
                	message_vision(a, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+dam+")"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_statue(target);    
                	
			if( random(dex+25) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
			{
			b += HIR"���G�y��$n"HIR"�@�B�ж�!!"NOR;
                	target->receive_damage("hp", dam , me );
                	} else { b+="���O�Q$n���}�F!!"NOR; dam = 0; }
                	message_vision(b, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+dam+")"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_statue(target);    
                	
                	if( random(dex+15) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
                	{
			c += HIR"���G�y��$n"HIR"�@�B�ж�!!"NOR;
                	target->receive_damage("hp", dam , me );
			} else { c+="���O�Q$n���}�F!!"NOR; dam = 0; }
                	message_vision(c, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+dam+")"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_statue(target);    
			
		        me->improve_skill("sorgi_sword",1+me->query_int()/5);
		        me->improve_skill("sword",1+me->query_int()/5);
			me->receive_damage("ap",21);
		}
		else
		{
			msg = "$N�Q�ϥX�����C�����s�o���ޡA�i�O�o�Q$n���ݯ}�F�C\n";
			message_vision(msg, me, target);
			target->improve_skill("dodge",1);
		}
		return;
	}
	else if( me->query_temp("sorgitimes") > 1 )
	{
		if ( random(target->query_skill("dodge")+target->query_dex()) <= random((me->query_skill("sorgi_sword")+me->query_str())*2) )
		{
			message_vision(YEL"   $N�J�a�@�ݤ⤤���C�A�u�W���O�ѼC�y���I�ӥX�I\n"NOR,me);
			if(me->query_temp("sorgitimes") > 4) damage= damage+(damage/(5+random(3)));
			if( random(dex+30) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
			{
			a += HIR"���G�y��$n"HIR"�@�B�ж�!!"NOR;
                	target->receive_damage("hp", dam , me );
                	} else { a+="���O�Q$n���}�F!!"NOR; dam = 0; }
                	message_vision(a, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+dam+")"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_statue(target);                	
                	if( random(dex+25) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
			{
			b += HIR"���G�y��$n"HIR"�@�B�ж�!!"NOR;
                	target->receive_damage("hp",dam , me );
                	} else { b+="���O�Q$n���}�F!!"NOR; dam = 0; }
                	message_vision(b, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+dam+")"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_statue(target);    		
                	if( random(dex+20) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
			{
			c += HIR"���G�y��$n"HIR"�@�B�ж�!!"NOR;
                	target->receive_damage("hp", dam , me );
                	} else { c+="���O�Q$n���}�F!!"NOR; dam = 0; }
                	message_vision(c, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+dam+")"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_statue(target);    
                	if( random(dex+15) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
			{
			d += HIR"���G�y��$n"HIR"�@�B�ж�!!"NOR;
                	target->receive_damage("hp", dam , me );
                	} else { d+="���O�Q$n���}�F!!"NOR; dam = 0; }
                	message_vision(d, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+dam+")"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_statue(target);    		
                	if( random(dex+10) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
			{
			e += HIR"���G�y��$n"HIR"�@�B�ж�!!"NOR;
                	target->receive_damage("hp", dam , me );
                	} else { e+="���O�Q$n���}�F!!"NOR; dam = 0; }
                	message_vision(e, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+dam+")"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_statue(target);    			
			me->receive_damage("ap",35);
		        me->improve_skill("sorgi_sword",1+me->query_int()/4);
		        me->improve_skill("sword",1+me->query_int()/5);
			me->add_temp("sorgitimes",-1-random(2));
		}
		else
		{
			msg = "$N�Q�ϥX�����C�����s�o���ޡA�i�O�o�Q$n���ݯ}�F�C\n";
			message_vision(msg, me, target);
			target->improve_skill("dodge",2);
			me->add_temp("sorgitimes",-1);
		}
		return;
	}
	else return;
}

int valid_learn(object me)
{
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	return 1;
}