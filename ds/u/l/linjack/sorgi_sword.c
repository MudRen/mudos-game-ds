// 更新日期: 1999.10.16
// 更新者: Luky
// QCer: Luky
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me);
void running_fire(object me,object target,int damage);

mapping *action = ({
	([
	"action": "$N凝神一定，將手中的劍忽地舞成劍花，\n  趁$n不注意時，一舉使出「風嘯雲龍」，往$n胸口刺去",
	"damage":                50,
	"dodge" :                -15,
	"attack":		-15,
        "damage_type":  "刺傷", 
	]),
	([
	"action": "$N大喝一聲，迅速使出「內殮自省」，劍尖往\n  $n手上的五大要穴而去",
	"damage":                20,
	"dodge" :                -5,
        "damage_type":  "刮傷", 
	]),
	([
	"action": "$N集中精神，凝神歸氣，把在六大脈中的真氣迅速收回檀中，\n  一霎那間，$N把劍使出如繩索一般往$n身上狂掃而去",
	"damage":                25,
	"dodge" :                10,
        "damage_type":  "鞭傷", 
	]),
	([
	"action": "$N內心一股衝動，把劍使出一招「小亂劍」，\n  將劍身彎成像圓環一般往$n的頭部砸去",
	"damage":                15,
	"dodge" :                -3,
        "damage_type":  "創傷", 
        ]),
	([
	"action": "$N從腰際拿了一袋酒袋，喝了一喝，似乎醉了一般，\n  一不小心使出「酒謎醉人」，便如酒拳一般把$n打的不知該如何是好",
	"damage":                20,
	"dodge" :                -15,
        "damage_type":  "刺傷", 
        ]),
	([
	"action": "$N心中一狠，臉色一青，立即對$n下了一招「草滿囹圄」，\n  劍式便如打草雜法一般",
	"damage":                23,
	"dodge" :                13,
        "damage_type":  "刺傷", 
        ]),
	([
	"action": "$N使出一招平平無奇的中宮劍往$n身上要穴而去，\n  不料在途中突轉變為「曲龍幽行」，反攻向$n下盤",
	"damage":                18,
	"dodge" :                5,
        "damage_type":  "刺傷", 
        ]),
	([
	"action": "$N手凝一招「怙惡不悛」，接著便猛攻$n手上大穴，\n  接著又如小花一般輕柔的攻向$n頸部",
	"damage":                17,
        "damage_type":  "戳傷", 
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
			return notify_fail("索極劍法並沒有在使用。\n");
		me->map_skill("sword");
		me->reset_action();
		me->delete_temp("exert_mark/sorgi_sword");
		me->delete_temp("power_exert");
		write("技能中的「索極劍法」已停止使用。\n");
		return 1;
	}

	if( !weapon)
		return notify_fail("索極乃需要劍才能使用。\n");

	if( weapon->query("skill_type")!="sword" )
		return notify_fail("如果要使用索極劍法，則必須裝備劍類武器。\n");

	if( me->query("ap") < 20 )
		return notify_fail("你的體力還不足以使用索極劍法。\n");

	if( me->query_skill_mapped("sword")=="sorgi_sword" ) 
	{
		if( !target ) target = offensive_target(me);
		if( !target ) return notify_fail("你還在施展【索極劍法】。\n");
		if( me->query_temp("exert_mark/sorgi_sword") ) return notify_fail("(你上一個動作還沒結束。)\n");
		if( !me->can_fight(target) ) return me->can_fight(target);
		if( !me->is_fighting(target)) me->kill_ob(target);
		if( !target->is_fighting(me)) target->kill_ob(me);
		c = target->query_armor();
		p = me->query_damage();
		if( sk > random(300) && !target->is_busy())
		{
			msg = HIY"\n$N"HIY"心中便如平靜之水一般，倏地一縱跳躍，一招「天雲斬龍鶴」從$n"HIY"的後方巧妙的往$n"HIY"的命門而去！！\n"NOR ;
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
				message_vision(HIM"   $N驟地一抖手中之劍，臂上內力由劍尖直點而出！\n",me);
	 		me->start_busy(2);

			if( random(sk+5)*5/3 > random(target->query_skill("dodge",2)) )
			{
				msg += HIM "$n"HIM"的命門之處被$N"HIM"用"+weapon->name()+HIM"一劃過去，一道長長的血痕須臾爆出一團紅色黏液﹗" NOR;
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
				msg += HIY"$n"HIY"乃發現$N"HIY"於其背後命門之處，轉身跳了開來。" NOR;
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
	 		if( damage < 10 ) damage = 8 + random(5); //現在索極會 miss, 故給于低限
			if( damage > 135) damage = 135 + ((damage-135)/3);  //威力太強的于以制止
	 		//damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
	 		//放到攻擊時引用
			
			/*i=( sk+me->query_skill("fogseven"))/2;
			if ( i > 50 )i = 2;            //測試新辦法, i 不代入 running-fire 的 z 中.
			if ( i < 51 )i = 1;*/
			me->add_temp("power_exert",2+sk/25);
			message_vision(HIW"\n$N"HIW"深吸了一口氣，壇中真氣運轉不息，殺招蓄勢待發。\n"NOR,me,target);
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
          return notify_fail("你結束索極劍法的動作還沒完成。\n");
          
	message_vision("\n"HIC"$N"HIC"大喝一聲，把全身的真氣鑽往胸口壇中而去！\n"NOR,me);
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
		message_vision("\n"HIW"$N"HIW"的體力不夠無法繼續施展索極劍法。\n"NOR,me);
		return ;
	}

	if( me->is_fighting() ) me->receive_damage("ap",7);

	me->skill_active( "sorgi_sword",(: call_other, __FILE__, "delay", me :), 6);
}

void running_fire(object me,object target,int damage)
{
	int dam,dex,sk,tdod;
	string a="$N手中的劍忽地舞成劍花，使出「風嘯雲龍」，往$n胸口刺去，",
	       b="$N迅速使出「內殮自省」，劍影一分為五，直取$n手上五大要穴，",
	       c="$N六大脈中的真氣迅速收回檀中，霎那間劍光如繩索般捆住$n，",
	       d="$N拿起酒袋喝了一口，使出「酒謎醉人」，劍勢如狂風般往$n攻去，",
	       e="$N一招中宮劍擊向$n，突轉為「曲龍幽行」，靈蛇般直取$n的雙眼，",
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
		message_vision("$N因為對手離開而停止了這次的攻勢。\n",me);
		return;
	}
	me->delete_temp("exert_mark/sorgi_sword");
	if(me->query_temp("power_exert")<1)
	{
	 message_vision(CYN"\n$N"CYN"受到創傷一時亂了陣腳，退了三步。\n"NOR,me);
	 return;
	}
	me->delete_temp("power_exert");
	if ( me->query_temp("sorgitimes") < 2 ) 
	{
		if ( random(target->query_skill("dodge")+target->query_dex()) <= random((me->query_skill("sorgi_sword")+me->query_dex())*2) )
		{
			if( random(dex+35) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
			{
			a += HIR"結果造成$n"HIR"一處創傷!!"NOR;
                	target->receive_damage("hp", dam , me );
                	} else { a+="但是被$n躲開了!!"NOR; dam = 0; }
                	message_vision(a, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+dam+")"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_statue(target);    
                	
			if( random(dex+25) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
			{
			b += HIR"結果造成$n"HIR"一處創傷!!"NOR;
                	target->receive_damage("hp", dam , me );
                	} else { b+="但是被$n躲開了!!"NOR; dam = 0; }
                	message_vision(b, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+dam+")"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_statue(target);    
                	
                	if( random(dex+15) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
                	{
			c += HIR"結果造成$n"HIR"一處創傷!!"NOR;
                	target->receive_damage("hp", dam , me );
			} else { c+="但是被$n躲開了!!"NOR; dam = 0; }
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
			msg = "$N想使出索極劍中的連發絕技，可是卻被$n給看破了。\n";
			message_vision(msg, me, target);
			target->improve_skill("dodge",1);
		}
		return;
	}
	else if( me->query_temp("sorgitimes") > 1 )
	{
		if ( random(target->query_skill("dodge")+target->query_dex()) <= random((me->query_skill("sorgi_sword")+me->query_str())*2) )
		{
			message_vision(YEL"   $N驟地一抖手中之劍，臂上內力由劍尖直點而出！\n"NOR,me);
			if(me->query_temp("sorgitimes") > 4) damage= damage+(damage/(5+random(3)));
			if( random(dex+30) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
			{
			a += HIR"結果造成$n"HIR"一處創傷!!"NOR;
                	target->receive_damage("hp", dam , me );
                	} else { a+="但是被$n躲開了!!"NOR; dam = 0; }
                	message_vision(a, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+dam+")"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_statue(target);                	
                	if( random(dex+25) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
			{
			b += HIR"結果造成$n"HIR"一處創傷!!"NOR;
                	target->receive_damage("hp",dam , me );
                	} else { b+="但是被$n躲開了!!"NOR; dam = 0; }
                	message_vision(b, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+dam+")"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_statue(target);    		
                	if( random(dex+20) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
			{
			c += HIR"結果造成$n"HIR"一處創傷!!"NOR;
                	target->receive_damage("hp", dam , me );
                	} else { c+="但是被$n躲開了!!"NOR; dam = 0; }
                	message_vision(c, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+dam+")"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_statue(target);    
                	if( random(dex+15) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
			{
			d += HIR"結果造成$n"HIR"一處創傷!!"NOR;
                	target->receive_damage("hp", dam , me );
                	} else { d+="但是被$n躲開了!!"NOR; dam = 0; }
                	message_vision(d, me, target);
			if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
			{ tell_object(me,HIY"("+dam+")"NOR); message_vision("\n",me); }
			else message_vision("\n",me);
			COMBAT_D->report_statue(target);    		
                	if( random(dex+10) > random(tdod) && dam=COMBAT_D->Merits_damage(me,target,damage*2/3+random(damage/3),"bar"))
			{
			e += HIR"結果造成$n"HIR"一處創傷!!"NOR;
                	target->receive_damage("hp", dam , me );
                	} else { e+="但是被$n躲開了!!"NOR; dam = 0; }
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
			msg = "$N想使出索極劍中的連發絕技，可是卻被$n給看破了。\n";
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