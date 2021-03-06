//鐵算指 reckon-finger.c 以 hammer 形式撰寫..
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void delay(object me,int cost);
mapping *action = ({
	([
	"action": "$N舉起手中$w就對著$n當頭砸下去",
	"damage":                1,
	"attack":                40,
	"attact_type":  "bar",
            "damage_type":  "鎚傷",
        ]),

	([
	"action": "$N將手中$w旋轉了幾圈, 再往$n的$l橫打過去",
	"damage":                1,
	"dodge" :               10,
	"parry" :               20,
	"attact_type":  "bar",
            "damage_type":  "劈傷",
        ]),

	([
	"action": "$N簡單的一個跳躍, 拿起$w見$n就打了下去",
	"damage":                1,
	"dodge" :               20,
	"attack":               15,
	"attact_type":  "bar",
        "damage_type":  "鎚傷",
        ]),

	([
	"action": "$N迴身幾圈, 手中$w貫著強大力道往$n的$l打了過去",
	"damage":                40,
	"dodge" :               -10,
	"parry" :               -10,
	"attact_type":  "bar",
	"damage_type": "劈傷",
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
                        return notify_fail("你手中拿著的不是算盤，如何使用「鐵算指」?\n");
	}
	if(arg=="off" )
	{
		if( me->query_skill_mapped("finger")!="reckon-finger")
			return notify_fail("你並沒有在使用「鐵算指」。\n");
		me->map_skill("finger");
		me->reset_action();
		write("你停止使用鐵算指了。\n");
		return 1;
	}
        if(arg=="iron-finger")
        {
        	if(!target)
        	{
        		target = offensive_target(me);
        		if(!target) return notify_fail("\n你要在戰鬥中才能用『鐵指神算』特技。\n");
        	}
                if(me->query_skill_mapped("finger")!="reckon-finger")
                        return notify_fail("您現在並沒有使用鐵算指喔。\n");
                if( f < 30 || sk < 25 || rf < 25 )
                        return notify_fail("\n您的能\力還不足以使出『鐵指神算』特技。\n");
                if(me->query("ap") < 30)
                        return notify_fail("\n您的體力不夠使用『鐵指神算』特技。\n");
		if(!weapon->query("can_shoot"))
			return notify_fail("你目前使用的算盤不能彈射算珠。\n");
		if( me->query_skill("finger") < random(10)+5 ) //控制難度
		{
			weapon->set_temp("loaded",weapon->query_temp("loaded")-1);
			me->receive_damage("hp",weapon->query_temp("abacus/damage"));
			return notify_fail("你的指法不精熟, 不小心彈到了自己.\n");
		}
		if(weapon->query_temp("loaded") < 1)
			return notify_fail("\n你的所剩算珠不足以讓你使出『鐵指神算』特技。\n");
                if(me->is_busy())
                        return notify_fail("\n您正在忙其他的事情喔！\n");
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
		message_vision("$N一個彈指，鐵指神算一招已經迅即電射向$n，",me,target);
		if(damage < 1)
		{
			message_vision("\n但$N反掌一擋, 居然把"+weapon->query_temp("abacus/name")+"硬生生的給撥開了。\n",target);
			target->improve_skill("parry",2+random(target->query_int()/4));
			return 1;
	  	}
		if(hit + 50> dodge && damage > 0)
                {
			if(damage < 10) damagemsg = "$N輕微的傷害。";
			else if(damage < 40) damagemsg = "$N一處傷害。";
			else if(damage < 80) damagemsg = "$N一處嚴重的擊傷。";
			else if(damage < 150) damagemsg = "$N一處十分嚴重的擊傷！";
			else if(damage < 250) damagemsg = "$N一處非常嚴重的重大傷害！";
			else if(damage < 350) damagemsg = "$N受傷處皮肉爆開，鮮血狂噴！！";
			else damagemsg = "$N的受傷處穿了個透體而過血肉模糊的大洞！！";
		        msg = HIR"造成"+damagemsg+"\n"NOR;
                        message_vision(msg,target);
                        me->improve_skill("reckon-finger",random(3)+(me->query_int()/3));
                        // 增加素質對傷害的影響
                        target->receive_damage("hp",damage,me);
                        COMBAT_D->report_status(target);
                        me->start_busy(1);
                        target->start_busy(1);
                }
                else
                {
                        msg = "但$n轉身一閃，已經避開了這一招。\n";
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
        		if(!target) return notify_fail("\n你要在戰鬥中才能用『屈指可數』特技。\n");
        	}
                if(me->query_skill_mapped("finger")!="reckon-finger")
                        return notify_fail("您現在並沒有使用鐵算指喔。\n");
                if( f < 30 || sk < 25 || rf < 25 )
                        return notify_fail("\n您的能\力還不足以使出『屈指可數』特技。\n");
                if(me->query("ap") < 30)
                        return notify_fail("\n您的體力不夠使用『屈指可數』特技。\n");
		if(!weapon->query("can_shoot"))
			return notify_fail("你目前使用的算盤不能彈射算珠。\n");
		if( me->query_skill("finger") < random(20)+10 ) //控制難度
		{
			weapon->set_temp("loaded",weapon->query_temp("loaded")-2);
			me->receive_damage("hp",(weapon->query_temp("abacus/damage")*2));
			return notify_fail("你的指法不精熟, 不小心彈到了自己.\n");
		}
		if(weapon->query_temp("loaded") < 2)
			return notify_fail("\n你的所剩算珠不足以讓你使出『屈指可數』特技。\n");
                if(me->is_busy())
                        return notify_fail("\n您正在忙其他的事情喔！\n");
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
		 message_vision("$N雙手撥動算盤，屈指可數第"+chinese_number(a)+"招已經射向$n而去，",me,target);
		 if(hit + 30> dodge)
                 {
			if(damage < 1) damagemsg = "但$N竟然硬生生的擋開了這一擊！";
	 		else if(damage < 10) damagemsg = "造成$N輕微的傷害。";
 			else if(damage < 40) damagemsg = "造成$N一處傷害。"; 
			else if(damage < 80) damagemsg = "造成$N一處嚴重的擊傷。";
			else if(damage < 150) damagemsg = "造成$N一處十分嚴重的擊傷！";
			else if(damage < 250) damagemsg = "造成$N一處非常嚴重的重大傷害！";
			else if(damage < 350) damagemsg = "造成$N受傷處皮肉爆開，鮮血狂噴！！";
			else damagemsg = "造成$N的受傷處穿了個透體而過血肉模糊的大洞！！";
		        msg = HIR+damagemsg+"\n"NOR;
                        message_vision(msg,target);
			if(damage < 1) target->improve_skill("parry",3);
                        me->improve_skill("reckon-finger",random(2)+(me->query_int()/4));
                        // 增加素質對傷害的影響
                        target->receive_damage("hp",damage,me);
                        COMBAT_D->report_status(target);
                        me->start_busy(1);
                        target->start_busy(1);
                 }
                 else
                 {
                        msg = "但$n轉身一閃，已經避開了這一招。\n";
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
                return notify_fail("你的指法基礎不足，無法使用「鐵算指」。\n");
        if(me->query("ap")<20 || me->query("hp")<15) 
                return notify_fail("你的身體狀況太差了，不能使用「鐵算指」。\n");
        if(!me->skill_active( "reckon-finger",(: call_other, __FILE__, "delay", me ,5:), 5))
                return notify_fail("你停止使用鐵算指的動作還沒完成。\n");
	me->map_skill("finger", "reckon-finger");
	me->reset_action();
	message_vision(HIW"\n$N雙手稍微撥動手中"+weapon->query("name")+HIW+"的算珠，使起"+HIY+"「鐵算指」。\n"NOR,me);
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
		tell_object(me,"\n你的體力不夠，不能再用「鐵算指」了。\n");
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
