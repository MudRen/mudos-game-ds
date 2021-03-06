// 更新日期: 1999.10.15
// 更新者: Luky
// QCer: Luky
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void delay(object me,int cost);
void delay2(object me);
int h=this_player()->query_skill("horse-steps")/10;

mapping *action = ({
	([
	"action": "$N一振手中$w，一式"+HIW"『"+NOR"穿雲射日"+HIW"』"+NOR"宛若電馳雷掣似地攻向$n胸中要害",
	"damage":                10+h,
	"dodge" :                20,
	"parry" :		 20,
	"attact_type":  "bar",	
        "damage_type":  "刺傷",
        ]),

	([
	"action": "只見$N手中$w暴發數丈氣勁，赫然一式"+HIW"『"+NOR"潛龍躍淵"+HIW"』"+NOR"直取$n胸、腹要害",
	"damage":                10+h,
	"dodge" :                10,
	"parry" :		 15,
	"attact_type":  "bar",	
        "damage_type":  "刺傷",
        ]),

	([
	"action": "只見$N微一凝神，一式"+HIW"『"+NOR"梅花點額"+HIW"』"+NOR"，手中$w挑起數朵碗大槍花，盡罩$n身前數處要害",
	"damage":                10+h,
	"dodge" :                10,
	"parry" :		 20,
	"attact_type":  "bar",	
        "damage_type":  "刺傷",
        ]),

	([
	"action": "$N陡地將手中$w橫過天際畫了個長弧，一式"+HIW"『"+NOR"長虹繞天"+HIW"』"+NOR"往$n頭頂招呼",
	"damage":                10+h,
	"dodge" :                10,
	"parry" :		 10,
	"attact_type":  "bar",	
        "damage_type":  "劈傷",
        ]),

	([
	"action": "$N施展一式"+HIW"『"+NOR"回身捕影"+HIW"』"NOR+"，槍勢一變，宛若蛇失般以奇異的方位直取$n背部要害",
	"damage":                10+h,
	"dodge" :                -10,
	"parry" :		 -10,
	"attact_type":  "bar",	
        "damage_type":  "刺傷",
        ]),

	([
	"action": "$N猛喝一聲，狂舞手中$w，登時幻化出數道帶狀氣勁，一式"+HIW"『"+NOR"玉帶繞腰"+HIW"』"NOR+"直攻$n下盤",
	"damage":                10+h,
	"dodge" :                10,
	"parry" :		 10,
	"attact_type":  "bar",	
        "damage_type":  "刺傷",
        ]),

	([
	"action": "$N一式"+HIW"『"+NOR"魁星舉筆"+HIW"』"+NOR"，手上$w由下往上一挑，勁迅無比地往$n喉嚨刺去",
	"damage":                15+h,
	"dodge" :                20,
	"parry" :		 20,
	"attact_type":  "bar",	
        "damage_type":  "刺傷",
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
	if (!weapon) return notify_fail("你得拿枝槍才能施展「大槍訣」。\n");
	if(weapon->query("skill_type")!="fork") return notify_fail("你得拿枝槍才能施展「大槍訣」。\n");

	if(arg=="off" )
	{
		if( me->query_skill_mapped("fork")!="da-fork")
			return notify_fail("你並沒有使用「大槍訣」。\n");
		me->map_skill("fork");
		me->reset_action();
		write("技能「大槍訣」已取消。\n");
		return 1;
	}

	if(me->query_skill("da-fork")<10) return notify_fail("依你目前的功\力，尚不足施展「大槍訣」。\n");
	if(me->query("ap")<10 || me->query("hp")<10) return notify_fail("你的身體狀況無法使用「大槍訣」。\n");


	//第二次exert
	if(me->query_skill_mapped("fork")=="da-fork")
	{
		if (!me->is_fighting()) 
		return notify_fail("你已正在施展大槍訣了。\n");		  
		if (me->query_skill("da-fork") < 50)
		return notify_fail("依你目前的大槍訣火候，尚不能施展絕技\n");
		if(me->query("ap")<200) 
		return notify_fail("你目前的內勁不足。\n");
		if(me->query("hp") <150)
		return notify_fail("你目前的體力不足施展大槍訣絕技。\n");

	   //攻擊性的要特別注意要加下面兩行.
	   	message_vision("\n"HIW"$N內力一提，手中"+weapon->query("name")+HIW "嗡嗡作響，大槍訣蓄勢待發！！\n"NOR,me);
	   	me->start_busy(2);
		call_out("delay2",3,me);
		return 1;
	}
	
        if(!me->skill_active( "da-fork",(: call_other, __FILE__, "delay", me ,5:), 10))
          return notify_fail("你結束運功\的動作還沒完成。\n");
	
	me->map_skill("fork", "da-fork");
	me->reset_action();
	message_vision("\n"HIW"$N手中"+weapon->query("name")+HIW "陡地一震，大槍訣氣勁登時四散而出！！\n"NOR,me);
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
	  message_vision( HIW "\n$N陡地一陣清嘯，身形隨既急轉數圈，手中"
         +weapon->query("name")+HIW "挾帶地數道氣勁向天空射去!\n" NOR
	,me);
	return;
	}
      	
      	message_vision(
	 HIW "\n$N陡地一陣清嘯，身形隨既急轉數圈，手中"
         +weapon->query("name")+HIW "挾帶地數道氣勁向四面八方射去\n" NOR
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
				HIY "$N狠狠一招刺向$n的"+limbs[random(sizeof(limbs))]+"！！" NOR
				,me,target);
		if(damage<20) damage=20+random(20);
                    if(random(me->query_dex()*2)+random(me->query_skill("da-fork")*3/2)<random((target->query_dex()/2)+target->query_skill("dodge")))
                		message_vision(HIG "\n可是被$N避開了！！\n"NOR,target);
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
	  else   message_vision(HIG "可是被$N狼狽地逃了開無數槍勁的攻勢！！\n"NOR,target);
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
		tell_object(me,"\n你的體力不夠，無法繼續使用大槍訣。\n");
		return ;
	}

	if( me->is_fighting() ) 
	{
		if(random(10)>5 && me->query_skill("horse-steps") >50 && me->query_skill("da-fork")>random(110) )
		{
	          if( !target ) target = offensive_target(me);
                  if(!target)   return;
                  message_vision(
 		  YEL"$N低笑數聲，東一步、西一步地欺近$n身前，斗地將"+weapon->query("name")+YEL"交在$n左手、\n"
		  +YEL "登時右手伸指疾伸點往$n穴道，正是大槍訣一式"+HIY "『雲霧幻山』"+NOR"！！\n" NOR,
		  me,target);
		  me->receive_damage("ap",15); 

		  if(random(target->query_dex()+target->query_int()) <=random(80))
		  {
			message_vision(HIB"只見$N身形微滯，已中了這一指。\n" NOR ,target);
			target->start_busy(2);
		  } else
		  {
			message_vision(HIW"$N身形一轉，避開這一指。\n" NOR ,target);
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
