// �򥻪��O�Ѧ�godsword�Bstar-sword�A�b�o�����@�U�C
// 8/15 2000 by lestia
// �F�פۼC 
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay_0(object me);
void stop_delay(object me);

mapping *action = ({
        ([
        "action": "$N�⮳$w�A�H��$w���R�ʡA�C���X�@�A������V$N�C",
        "damage":                15,
        "dodge" :                10,
        "parry" :                -8,
        "attact_type":  "bio",  // �]�w�ޯ઺��������
                                // ������ �ͪ�(bio) �~��(bar)
                                // �]�k(wit)���F(sou)���(tec)
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�ϥX�F�פۼC�����y�ۼv�F�C�z�A�u��$N�⤤��$w���v���{�A��M����$n���W��h�C",
        "damage":                10,
        "dodge":                 -5,
        "parry" :                14,
        "attact_type":  "bio",
        "damage_type":  "���",
        ]),

        ([
        "action": "$N�N�⤤��$w�A�⹺�j��A�C���Q�D�A�@���y�{�F�p�C�z�V�@�D�p�q�ĦV$n�C",
        "damage":                17,
        "dodge" :               -10,
        "parry" :                10,
        "attact_type":  "bio",
        "damage_type":  "�A��",
        ]),

        ([
        "action": "$N�}�B����A���B��í�A�⤤$w�S�p�@�����D�A��$n���b�ӥh�C",
        "damage":                13,
        "dodge" :                20,
        "parry" :                -10,
        "attact_type":  "bio",
        "damage_type":  "�C��",
        ]),

        ([
 "action": "$N�B�k�g�ۡA�H�ۤ߷N�\\�ʡA�������k�A$w�N��������V$n�C",
        "damage":                10,
        "dodge" :               -10,
        "parry" :                15,
        "attact_type":  "bio",
        "damage_type":  "���",
        ]),
});
// �S����A�����O�n�Q��
int cast_skill(object me,string a, object target, string arg)
{
        int x,damage,i; 
        string msg;
        string *attack = ({
                HIY"�@�D�o�X������C�𪺥������h��V$n�C\n"NOR,
                HIR"�@�D�o�X������C�𪺥������h��V$n�C\n"NOR,
                HIC"�@�D�o�X���Ŧ�C�𪺥������h��V$n�C\n"NOR, 
                NOR""YEL"�@�D�o�X�g����C�𪺥������h��V$n�C\n"NOR,
		HIG"�@�D�o�X�G���C�𪺥������h��V$n�C\n"NOR,
		HIB"�@�D�o�X�`�Ŧ�C�𪺥������h��V$n�C\n"NOR,
		HIM"�@�D�o�X�L����C�𪺥������h��V$n�C\n"NOR,
		HIW"�@�D�o�X�¥զ�C�𪺥������h��V$n�C\n"NOR,
	});
        string *miss = ({
                HIG"$n"+HIG"���Ϋ��ơA�׶}�F�o�� \n"NOR,
                HIR"$n"+HIR"�˪ŦӰ_�A�������{�} \n"NOR, 
                HIG"$n"+HIG"�N���O�B������R�ߡA�w�ͥͪ��N$N�_�F�}�h \n"NOR, 
                });
                string *hit = ({
                HIR"$n"+HIR"�Q�C�Ҩ�A�{�����ΡA�w�ͥͪ����ۡC\n"NOR,
                HIR"$n"+HIR"�٨S�Ӫ��Τ����A�w�Q$N�C��ҶˡC\n"NOR, 
        });
  int p_force = this_player()->query_skill("soul-of-magic-sword")/5,
            w_force = this_player()->qiery_skill("soul-force"),
            b_force = random(this_player()->query_skill("soul_force"))/4,
            spal = ( p_force*p_force + b_force*b_force )/( p_force + b_force ),
            sk = me->query_skill("soul-of-magic-sword"), 
            force = me->query_skill("force"),
            sw = me->query_skill("soul-of-magic-sword"),
            target_armor, me_damage, target_dodge, me_dex, sum_damage, penuma_damage, g,
            myexp=(int)me->query("combat_exp")/5000,
            mylev=(int)me->query_skill("soul-of-magic-sword"),
            mykar=(int)me->query_kar(),
       targetlev,targetkar,targetexp,targeteffkee;
        object weapon, *attack_targets;        
        weapon = me->query_temp("weapon");
        if( arg=="off" )
        {
        	if( me->query_skill_mapped("sword")!="soul-of-magic-sword" )
                        return notify_fail(HIR"�A�èS���b�Ρi�F�פۼC�j��I\n"NOR);
                me->map_skill("sword");
                me->reset_action();
                write(HIY"�A���~��ϥΡu�F�פۼC�v�F�I\n"NOR);
                return 1;
        }

        if( me->query("ap") < 30 ) return notify_fail("�A�����l�٤���ϥ��F�פۼC�C\n");
        if( !weapon ) return notify_fail("�n�ϥX�F�פۼC�n���˳ƼC��C\n");
        if( sw < 70 ) return notify_fail("�A���F�פۼC�٤����¼��C\n");
        if( weapon->query("skill_type")!="sword" )return notify_fail("�n�ϥX�F�פۼC�n���˳ƼC��C\n");
        if( arg == "?" || arg == "help" )
        {
        	tell_object(me,
        	HIR"�i�F�פۼC�j���\\�঳:\n"
        	HIR"\t�Ĥ@�h: ���P(fire-dagger)\n"
        	HIR"\t�ĤG�h: �H�b(ice-blade)\n"
        	HIR"\t�ĤT�h: ���M(wind-blade)\n"
        	HIR"\t�ĥ|�h: �۴u(dream-lance)\n"
        	HIR"\t�Ĥ��h: �}�ѩ�(sky-axe)\n"
        	HIR"\t�̲׼h: �K�C����(eight-sword)\n"NOR);
        	return 1;
        }
      if( me->query_skill_mapped("sword") == "soul-of-magic-sword" )
        {
                if( !target ) target = offensive_target(me);
                if( !target ) return notify_fail("�A�٦b�ϥ��F�פۼC��I\n");
                if( !me->can_fight(target) ) return me->can_fight(target);
                target_armor = target->query_armor();
                target_dodge = target->query_skill("dodge")/3 + random(target->query_dex()/4);
                me_dex = me->query_dex() * 3;
                me_damage = me->query_damage() + w_force/4 + sk/3;
                me_damage = me_damage + random(me_damage/4);
                sum_damage = me_damage - target_armor/2 - random(target_armor/2);
                if(wizardp(me)) tell_object(me,sprintf("  me_damage=%-d  sum_damage=%-d\n",me_damage,sum_damage));
                if( !arg || arg == "?" )
                {
                	tell_object(me,
                	HIR"�i�F�פۼC�j���\\�঳:\n"
                	HIR"\t�Ĥ@�h: ���P(fire-dagger)\n"
                        HIR"\t�ĤG�h: �H�b(ice-blade)\n"
                        HIR"\t�ĤT�h: ���M(wind-blade)\n"
                        HIR"\t�ĥ|�h: �۴u(dream-lance)\n"
                        HIR"\t�Ĥ��h: �}�ѩ�(sky-axe)\n"
                        HIR"\t�̲׼h: �K�C����(eight-sword)\n"NOR);
                        return 1;
                }
                if( me->query_skill_mapped("sword") == "soul-of-magic-sword" )
                {
                	if( !target ) target = offensive_target(me);
                        if( !target ) return notify_fail("�A�٦b�ϥ��F�פۼC��I\n");
                        if( !me->can_fight(target) ) return me->can_fight(target);
                //�S�Q�׵���A������C
                        target_armor = target->query_armor();
                        target_dodge = target->query_skill("dodge")/3 + random(target->query_dex()/4);
                        me_dex = me->query_dex() * 3;
                        me_damage = me->query_damage() + w_force/4 + sk/3;
                        me_damage = me_damage + random(me_damage/4);
                        sum_damage = me_damage - target_armor/2 - random(target_armor/2);
                        if(wizardp(me)) tell_object(me,sprintf("  me_damage=%-d  sum_damage=%-d\n",me_damage,sum_damage));
                        if( !arg || arg == "?" )
                        {
                        	tell_object(me,
                        	HIR"�i�F�פۼC�j���\\�঳:\n"
                                HIR"\t�Ĥ@�h: ���P(fire-dagger)\n"
                                HIR"\t�ĤG�h: �H�b(ice-blade)\n"
                                HIR"\t�ĤT�h: ���M(wind-blade)\n"
                                HIR"\t�ĥ|�h: �۴u(dream-lance)\n"
                                HIR"\t�Ĥ��h: �}�ѩ�(sky-axe)\n"
                                HIR"\t�̲׼h: �K�C����(eight-sword)\n"NOR);
                                return 1;
                        }
                        if( arg == "fire-dagger" )
                        {
                        	if( !me->is_fighting(target) ) me->kill_ob(target);
                        	if( !target->is_fighting(me) ) target->kill_ob(me);
                        	if( me->is_busy() ) return notify_fail("�A���b���I\n");
                        	if( me->query_skill("soul-of-magic-sword") < 30 )
                        	        return notify_fail("�A����O�����ϥX���P�I\n");
                        	message_vision(HIY"\n\t$N�N�F��o���A�B��N�⤤��" + weapon->name() + "�ܤƦ��@�⨪���������P���C\n\n\t"NOR""YEL"�P���b�Ť���¶���A�Ƨ@�@�D�����A��$n����V�g�h�C\n"NOR, me, target);
                        	if( random(me_dex) > random(target_dodge)&& sum_damage = COMBAT_D->Merits_damage(me, target, sum_damage + random(sum_damage/3), "bar") )
                        	{
                        		target->receive_damage("ap", sum_damage/10, me);
                        		target->receive_damage("hp", sum_damage, me);
                        		target->start_busy(random(3));
                        		message_vision(HIR"$n�Q�����������~��A�b�ߦb���Aíí���Y�F�@�O�A�A�媽�Q�I�I"NOR, me, target);
                        		if(wizardp(me)) tell_object(me,sprintf("  (damage=%-d) \n",sum_damage));
                        		me->improve_skill("soul-of-magic-sword", random(me->query_int()/5) + 5);
                        		me->improve_skill("sword", random(me->query_int()/6) + 5 );
                        		me->add_busy(2);
                        		message_vision(HIC"�]��$N�ϥΤF���P�A�ϱo$N�⤤��" + weapon->name() + "���b�a�W�F�I\n"NOR,me);
                        		me->query_temp("weapon")->move(environment(me)); //�����b�a�W�n���N�����g���a..:PPP 
                        	}
                        	else
                        	{
                        		message_vision(HIG"$n�����E��A�ݷǤF�����A�{���ӹL�C"NOR, me, target);
                        		target->imporve_skill("dodge", 2);
                        		sum_damage = 0;
                        		message_vision(HIC"�]��$N�ϥΤF���P�A�ϱo$N�⤤��" + weapon->name() + "���b�a�W�F�I\n"NOR,me);
                        		me->query_temp("weapon")->move(environment(me));
                        		me->add_busy(2);
                        	}
                        	if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                        	message_vision(HIY" ("+ HIR + sum_damage + HIY")"NOR" \n\n"NOR, me);
                        	else message_vision("\n\n", me);
                        	//              COMBAT_D->report_status(target);
                        	me->receive_damage("ap", 28 + sum_damage/40 );
                        	return 1;
               			}
                		if( arg == "ice-blade" )
                		{
                        	if( !me->is_fighting(target) ) me->kill_ob(target);
                        	if( !target->is_fighting(me) ) target->kill_ob(me);
                        	if( me->is_busy() ) return notify_fail("�A���b���I\n");
                        	if( me->query_skill("soul-of-magic-sword") < 50 )
                        	        return notify_fail("�A����O�����ϥX�H�b�I\n");
                        	message_vision(HIY"\n\t$N�N�F��o���A�B��N�⤤��" + weapon->name() + "�ܤƦ��@��B�H�����M�b�C\n\n\t"NOR""YEL"�@��M�����F��C�C�q$N���e�B�{��M���A�V$n�C\n"NOR, me, target);
                                if( random(me_dex) > random(target_dodge)&& sum_damage = COMBAT_D->Merits_damage(me, target, sum_damage + random(sum_damage/3), "bar") )
                                {
                                	target->receive_damage("ap", sum_damage/10, me);
                                	target->receive_damage("hp", sum_damage, me);
                                	target->start_busy(random(3));
                                	message_vision(HIC"$n�Q�B�H���B����A�����o�H�Aíí���Y�F�@�M�A�A�媽�Q�I�I"NOR, me, target);
                                	if(wizardp(me)) tell_object(me,sprintf("  (damage=%-d) \n",sum_damage));
                                	me->improve_skill("soul-of-magic-sword", random(me->query_int()/5) + 5);
                                	me->improve_skill("sword", random(me->query_int()/6) + 5 );
                                	me->add_busy(2);
                                }
                                else
                                {
                                	message_vision(HIG"$n�����E��A�ݷǤF�M�b�A�{���ӹL�C"NOR, me, target);
                			target->imporve_skill("dodge", 2);
                			sum_damage = 0;
                			me->add_busy(2);
                		}
                	if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                	message_vision(HIY" ("+ HIR + sum_damage + HIY")"NOR" \n\n"NOR, me);
                	else message_vision("\n\n", me);
//           	   	COMBAT_D->report_status(target);
                	me->receive_damage("ap", 28 + sum_damage/40 );
                        return 1;
                }
              	if( arg == "wind-blade" )
              	{
	                if( !me->is_fighting(target) ) me->kill_ob(target);
        	        if( !target->is_fighting(me) ) target->kill_ob(me);
                	if( me->is_busy() ) return notify_fail("�A���b���I\n");
                	if( me->query_skill("soul-of-magic-sword") < 70 )
                		return notify_fail("�A����O�����ϥX���M�I\n");
			message_vision(HIG"\n\t$N�N�F��B������A�B�έ����O�q�A�N�⤤��" + weapon->name() + "��"NOR""GRN"�Ʀ��@�⥨�j�����M�b�C\n\n\t"NOR""GRN"$N�⤤��M�X�{�@�⥨�M�A��$n�٤U�C"NOR, me, target);
                	if( random(me_dex) > random(target_dodge)&& sum_damage = COMBAT_D->Merits_damage(me, target, sum_damage + random(sum_damage/3), "bar") )
                	{
                		target->receive_damage("ap", sum_damage/10, me);
                		target->receive_damage("hp", sum_damage, me);
                		target->start_busy(random(3));
                		message_vision(HIR"$n�Q�@�⥨�j���M�b�ٶˡA�����o�ݡA�������Y�F�@�M�A�A�媽�Q�I�I"NOR, me, target);
                		if(wizardp(me)) tell_object(me,sprintf("  (damage=%-d) \n",sum_damage));
                		me->improve_skill("soul-of-magic-sword", random(me->query_int()/5) + 5);
                		me->improve_skill("sword", random(me->query_int()/6) + 5 );
                		me->add_busy(2);
                	}
                	else
                	{
                		message_vision(HIG"$n�����E��A�ݷǤF�M���A�{���ӹL�C"NOR, me, target);
                		target->imporve_skill("dodge", 2);
                		sum_damage = 0;
                		me->add_busy(2);
                	}
        	        if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	                message_vision(HIY" ("+ HIR + sum_damage + HIY")"NOR" \n\n"NOR, me);
                	else message_vision("\n\n", me);
//      	        COMBAT_D->report_status(target);
	                me->receive_damage("ap", 28 + sum_damage/40 );
             	        return 1;
                }
                if( arg == "dream-spear" )
                {
                	if( !me->is_fighting(target) ) me->kill_ob(target);
                	if( !target->is_fighting(me) ) target->kill_ob(me);
                	message_vision(HIM"$N�N�⤤��" + weapon->name() +"���@"NOR""MAG"��j�A�ϥX�ۼv�C"NOR, me, target);
                	if( random(target->query_dex()) < random(me->query_dex()*3/2) )
                	{
                	message_vision(HIR"�]��$N�Q�ۼv�Ҵb�A�ϱo$N�ʼu���o�I\n"NOR, target);
                	if( sk < 30 ) target->start_busy(1+random(2));
                	if( sk > 30 && sk < 60 ) target->start_busy(2+random(2));
	        	if( sk > 60 && sk < 90 ) target->start_busy(3+random(2));
        		if( sk >= 90 )
        		{
		                target->receive_damage("hp", me->query_damage()/3, me);
        		        target->start_busy(3+random(2));
                		message_vision(HIR"�]��$N�Q�ۼv�Ҵb�A�]��$N���F�I�ˡI"NOR, target);
                	}
                	if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                	message_vision(HIY" ("+ HIR + me->query_damage()/3 + HIY")"NOR" \n"NOR, me);
                	else message_vision("\n", me);
                	COMBAT_D->report_status(target);
                	}
                	else
                	{
	                	message_vision(HIW"���o�Q$N���P���{�F�}�h�C\n"NOR,target);
        	        	me->add_busy(random(2));
                	}
                	me->receive_damage("ap", 20 - sk/15);
                	me->add_busy(1); //Luky
                	return 1;
                }
                if( arg == "sky-axe" )
                {
                if( !me->is_fighting(target) ) me->kill_ob(target);
                if( !target->is_fighting(me) ) target->kill_ob(me);
                message_vision(HIC"$N�����E��A�N�⤤" + weapon->name() +"�ΤO�@�ݡA����$N�⤤�X�{�@��W�Q�����Y�C"NOR""CYN"\n\n\t$N�ΤO����$n�Y���{�U�C"NOR, me, target);
                if( random(target->query_dex()) < random(me->query_dex()*3/2) )
                {
                message_vision(HIW"�]��$N�Q�ۼv�Ҵb�A�ϱo$N�ʼu���o�I\n"NOR, target);
                if( sk < 40 ) target->start_busy(1+random(2));
                if( sk > 50 && sk < 70 ) target->start_busy(2+random(2));
                if( sk > 80 && sk < 100 ) target->start_busy(3+random(2));
                if( sk >= 100 )
                {
                target->receive_damage("hp", me->query_damage()/3, me);
                target->start_busy(3+random(2));
                message_vision(HIR"$N�Q��p��Ӫ�����{���A�^�˦b�a�I"NOR, target);
                }
                if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                message_vision(HIY" ("+ HIR + me->query_damage()/3 + HIY")"NOR" \n"NOR, me);
                else message_vision("\n", me);
                COMBAT_D->report_status(target);
                }
                else
                {
                message_vision(HIG"���o�Q$N���P���{�F�}�h�C\n"NOR,target);
                me->add_busy(random(2));
                }
                me->receive_damage("ap", 20 - sk/15);
                me->add_busy(1); //Luky
                return 1;
                }
// �H�U�|�o��crash

                if( arg == "eight-sword" )
                {
 	        if( !target ) 
  	        target = offensive_target(me);
  		if(!target
  		|| !target->is_character()
  		|| !me->is_fighting(target) )
  		return notify_fail("�K�C�����A�u���԰����I�ΡC\n");
  	        targetexp=(int)target->query("combat_exp")/5000;
  		targetlev=(int)target->query_skill("parry");
  		targetstr=(int)target->query("str")+(int)(target->query_skill("unarmed")/10-2);
  		targeteffkee=(int)target->query("eff_kee"); 
  		targetkar=(int)target->query_kar();
  
	        if(me->query_skill("soul-of-magic-sword",1)<150)
  		return notify_fail("�A�٤��|�ϥΤK�C�����T\n");

	        if(me->query_skill("soul-force",1)<100)
  		return notify_fail("�A�٤��|�ϥΤK�C�����T\n"); 

  		if(me->query_skill("dream-soul-step",1)<110) 
  		return notify_fail("�A�٤��|�ϥΤK�C�����T\n"); 

  		if( me->query("max_ap") < 1500 || me->query("ap")<400 )
  		return notify_fail("�A�����l�����C\n");

		msg=HIR"$N"HIR"�B�_�F��k�A�N���l�ʦܳ��p�A"NOR""RED"�B����������A$N"HIR"�Y�W�X�{�@���j�C���A"NOR""RED"�y�ɬ�M��$n���W���h"NOR;
  
  		message_vision(msg, me, target);
  
  		me->add("ap", -300);
 
  		x=8; 
  		i=0;
  		damage=(int)me->query_skill("soul-of-magic-sword",1);

  		while(x < 9)
  		{
//  			if(target->query_temp("pk_die"))break;
                        msg = attack[random(sizeof(attack))];
 if( random(mylev) >   (targetlev))
                        {
                        	msg += attack[random(sizeof(damage))];
                        	target->receive_wound("hp", damage/2); 
                        	target->receive_damage("hp",damage+random(damage));
                        	message_vision(msg+"\n", me, target);
                        	COMBAT_D->report_status(target);
                        	i=1;
                        } 
                        else
                        {
                        	msg +=miss[random(sizeof(miss))];
                        	message_vision(msg+"\n",me,target);        
                        }
                        x++;
		} 	
  		me->start_busy(2);  
  		return 1;
}  

}
}
}
void delay_0(object me)
{
        object me_weapon;
        int sk = me->query_skill("soul-of-magic-sword");
        if( !me ) return;
        me_weapon=me->query_temp( "weapon" );
        if( !me_weapon || me_weapon->query("skill_type") != "sword" )
        {
        me->map_skill("sword");
        me->reset_action();
        return;
        }
        if( me->query_skill_mapped("sword")!="soul-of-magic-sword" ) return;
        if( me->query("ap") < 20 )
        {
        me->map_skill("sword");
        me->reset_action();
        tell_object(me, HIR"�A����O�����~��ϡy�F�פۼC�z�F�I\n"NOR);
        return;
        }
        if( me->is_fighting() ) me->receive_damage("ap", 10);
        me->skill_active("soul-of-magic-sword",(: call_other, __FILE__, "delay_0", me :), 6);
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
