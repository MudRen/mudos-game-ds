#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me);
void running_fire(object me,object target,int z,int damage);

mapping *action = ({
	([
	"action": "$N凝神一定，將手中的劍忽地舞成劍花，\n在趁$n不注意時，一舉使出「風嘯雲龍」，往$n胸口刺去。",
	"damage":                30,
	"dodge" :                15,
        "damage_type":  "刺傷", 
	]),
	([
	"action": "$N大喝一聲，迅速使出「內殮自省」，劍尖往$n手上的五大要穴而去。",
	"damage":                20,
	"dodge" :                -5,
        "damage_type":  "刮傷", 
	]),
	([
	"action": "$N集中精神，凝神歸氣，把在六大脈中的真氣迅速收回檀中，\n一霎那間，$N把劍使出如繩索一般往$n身上狂掃而去。",
	"damage":                25,
	"dodge" :                10,
        "damage_type":  "鞭傷", 
	]),
	([
	"action": "$N內心一股衝動，把劍使出一招「小亂劍」，\n將劍身彎成像圓環一般往$n的頭部砸去。",
	"damage":                15,
	"dodge" :                -3,
        "damage_type":  "創傷", 
        ]),
	([
	"action": "$N從腰際拿了一袋酒袋，喝了一喝，似乎醉了一般，\n一不小心使出「酒謎醉人」，便如酒拳一般把$n用的不知該如何是好。",
	"damage":                20,
	"dodge" :                -15,
        "damage_type":  "刺傷", 
        ]),
	([
	"action": "$N心中一狠，臉色一青，立即對$n下了一招「草滿囹圄」，劍式便如打草雜法一般。",
	"damage":                23,
	"dodge" :                13,
        "damage_type":  "刺傷", 
        ]),
	([
	"action": "$N使出一招平平無奇的中宮劍往$n身上要穴而去，不料在途中突轉變為「曲龍幽行」，反攻向$n下盤。",
	"damage":                18,
	"dodge" :                5,
        "damage_type":  "刺傷", 
        ]),
	([
	"action": "$N手凝一招「怙惡不悛」，接著便猛攻$n手上大穴，接著又如小花一般輕柔的攻向$n頸部。",
	"damage":                17,
        "damage_type":  "戳傷", 
        ]),
});

int exert(object me, object target, string arg)
{
	int a,c,i,j,damage;
	string msg;
	object weapon;
	mapping type;
	
	weapon=me->query_temp("weapon");
	
	if( arg=="off" )
	{
		if( me->query_skill_mapped("sword")!="sorgi_sword" )
			return notify_fail("索極劍法並沒有在使用。\n");
		me->map_skill("sword");
		me->reset_action();
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
		if( !me->can_fight(target) ) return me->can_fight(target);
		if( !me->is_fighting(target)) me->kill_ob(target);
		if( !target->is_fighting(me)) target->kill_ob(me);
		c = target->query_armor();

		if( me->query_skill("sorgi_sword") > random(300) )  
		{
			msg = HIY"\n$N心中便如平靜之水一般，倏地一縱跳躍，一招「天雲斬龍鶴」從$n的後方巧妙的往$n的命門而去！！\n"NOR ;
			damage = me->query_skill("sorgi_sword") + me->query_damage() *1.5;
			damage -= random( target->query_armor() );
	 		if( damage < 40 ) damage = 40 + random(me->query_str());

	 		me->start_busy(2);

			if( random(me->query_skill("sorgi_sword")) > random(30) )
			{
				msg += HIM "$n的命門之處被$N之"+weapon->name()+"一劃過去，一道長長的血痕須臾爆出一團紅色黏液﹗\n" NOR;
				target->start_busy(5);
				target->receive_damage("hp",damage,me);
				COMBAT_D->report_status(target);
			        me->improve_skill("sorgi_sword",1+me->query_int()/10);
			        me->improve_skill("sword",1+me->query_int()/10);
			}
			else
			{
				msg += HIY"$n乃發現$N於其背後命門之處，轉身跳了開來。\n" NOR;
			}

			message_vision(msg, me, target);
			me->receive_damage("ap",25);
			return 1;
		}
		else
		{
			damage = random(me->query_skill("sorgi_sword")) + me->query_damage();
			damage -= random( target->query_armor() );
	 		if( damage < 55 ) damage = 55+random(me->query_str());
			i=( me->query_skill("sorgi_sword")+me->query_skill("fogseven"))/2;
			if ( i > 50 )i = 2;
			if ( i < 51 )i = 1;
			if ( i == 2 )
			{
				me->start_busy(3);
				call_out("running_fire",0,me,target,2,damage);
			}
			if ( i == 1 )
			{
				me->start_busy(2);
				call_out("running_fire",0,me,target,1,damage);
			}
			return 1;
		}
        }

	message_vision("\n"HIC"$N大喝一聲，把全身的真氣鑽往胸口壇中而去！\n"NOR,me);
	me->map_skill("sword", "sorgi_sword");
	me->reset_action();
	me->receive_damage("ap", 7);
	me->start_busy(2);
	call_out("delay",8,me);
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
		remove_call_out("delay");
		return;
	}

	if( me->query_skill_mapped("sword")!="sorgi_sword" )
	{
		remove_call_out("delay");
		return;
	}

	if( me->query("ap")<10 )
	{
	 	me->map_skill("sword");
		me->reset_action();
		message_vision("\n"HIW"$N的體力不夠無法繼續施展索極劍法。\n"NOR,me);
		remove_call_out("delay");
		return ;
	}

	if( me->is_fighting() ) me->receive_damage("mp",7);

	call_out("delay",8,me);
}

void running_fire(object me,object target,int z,int damage)
{
	string a="$N凝神一定，將手中的劍忽地舞成劍花，\n在趁$n不注意時，一舉使出「風嘯雲龍」，往$n胸口刺去。\n",
	       b="$N大喝一聲，迅速使出「內殮自省」，劍尖往$n手上的五大要穴而去。\n",
	       c="$N集中精神，凝神歸氣，把在六大脈中的真氣迅速收回檀中，\n一霎那間，$N把劍使出如繩索一般往$n身上狂掃而去。\n",
	       d="$N從腰際拿了一袋酒袋，喝了一喝，似乎醉了一般，\n一不小心使出「酒謎醉人」，便如酒拳一般把$n用的不知該如何是好。\n",
	       e="$N使出一招平平無奇的中宮劍往$n身上要穴而去，\n不料在途中突轉變為「曲龍幽行」，把劍硬生生的轉了個彎，刺向$n的兩眼。\n",
	       msg;

	if ( z==1 ) 
	{
		if ( random(target->query_skill("dodge")+target->query_dex()) <= random((me->query_skill("sorgi_sword")+me->query_str())*2) )
		{
			a += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(a, me, target);
                	target->receive_damage("hp", random(damage) , me );
			b += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(b, me, target);
                	target->receive_damage("hp", random(damage) , me );
			c += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(c, me, target);
                	target->receive_damage("hp", random(damage) , me );
		        me->improve_skill("sorgi_sword",1+me->query_int()/8);
		        me->improve_skill("sword",1+me->query_int()/7);
			me->receive_damage("ap",20);
		}
		else
		{
			msg = "$N想使出索極劍中的連發絕技，可是卻被$n給看破了。\n";
			message_vision(msg, me, target);
			target->improve_skill("dodge",1);
		}
		return;
	}

	if ( z==2 )
	{
		if ( random(target->query_skill("dodge")+target->query_dex()) <= random((me->query_skill("sorgi_sword")+me->query_str())*2) )
		{
			a += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(a, me, target);
                	target->receive_damage("hp", random(damage) , me );
			b += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(b, me, target);
                	target->receive_damage("hp", random(damage) , me );
			c += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(c, me, target);
                	target->receive_damage("hp", random(damage) , me );
			d += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(d, me, target);
                	target->receive_damage("hp", random(damage) , me );
			e += HIR"結果造成$n一處創傷!!\n"NOR;
			message_vision(e, me, target);
                	target->receive_damage("hp", random(damage) , me );
			me->receive_damage("ap",30);
		        me->improve_skill("sorgi_sword",1+me->query_int()/6);
		        me->improve_skill("sword",1+me->query_int()/7);
		}
		else
		{
			msg = "$N想使出索極劍中的連發絕技，可是卻被$n給看破了。\n";
			message_vision(msg, me, target);
			target->improve_skill("dodge",1);
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