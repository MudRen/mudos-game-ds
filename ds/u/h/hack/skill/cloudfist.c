//QC: Luky 1999.8.17
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
int fistpower=this_player()->query_skill("cloudforce")/10;
void delay(object me,int cost);

mapping *action = ({
	([
	"action": "$N身傾向前, 雙掌卯足全力向前一推, 一招「徹貫雲霄」擊向$n",
	"damage":                11+fistpower,
	"attack":                20,
	"attact_type":  "bar",
            "damage_type":  "掌傷",
        ]),

	([
	"action": "$N一個箭步衝向$n發出一招「破雲穿天」化掌為指疾刺$n印堂",
    "damage":                13+fistpower,
	"dodge" :               -10,
	"parry" :               -20,
	"attact_type":  "bar",
            "damage_type":  "戳傷",
        ]),

	([
	"action": "$N蹬上半空翻身一轉, 正面以一掌「烏雲蔽日」蓋\向\$n面門",
	"damage":                11+fistpower,
	"dodge" :               -20,
	"attack":                15,
	"attact_type":  "bar",
        "damage_type":  "內傷",
        ]),

	([
	"action": "$N雙手運動內息, 一招「天雷殛雲」凝氣於掌轉身劈向$n",
    "damage":                14+fistpower,
	"dodge" :               -25,
	"parry" :               -25,
	"attact_type":  "bar",
	"damage_type": "劈傷",
        ]),

	([
	"action": "$N轉身數周, 化敵之力為己之力, 一招「祥雲冉冉」推向$n",
    "damage":                10+fistpower,
	"attack":                20,
	"parry" :                20,
	"attact_type":  "bar",
	"damage_type": "內傷",
        ]),

	([
	"action": "$N雙手規律的揮動, 勢成「翻雲覆雨」之殺招猛然攻向$n身上要害",
    "damage":                16+fistpower,
	"dodge" :               -10,
	"parry" :               -10,
	"attact_type":  "bar",
	"damage_type": "掌傷",
        ]),
});

int exert(object me, object target, string arg)
{
	int a,c,i,j,damage,f;
	int hs,sk,force,dodge,hit,num,cf;
	string msg;
	object weapon;
	f=me->query_skill("force")/3;
        cf=me->query_skill("cloudfist");
        sk=me->query_skill("unarmed");
	force=me->query_skill("cloudforce");
	weapon=me->query_temp("weapon");
	if(weapon)
	{
		if(weapon->query("skill_type")!="unarmed")
                        return notify_fail("你手中正拿著武器，如何使用「貫雲掌法」?\n");
	}
	if(arg=="off" )
	{
		if( me->query_skill_mapped("unarmed")!="cloudfist")
			return notify_fail("你並沒有在使用「貫雲掌法」。\n");
		me->map_skill("unarmed");
		me->reset_action();
		write("你停止使用貫雲掌法了。\n");
		return 1;
	}
        if(arg=="sky-force")
        {
        	if(!target)
        	{
        		target = offensive_target(me);
        		if(!target) return notify_fail("\n您必須在戰鬥中才能使用『一氣貫雲天』。\n");
        	}
                if(!me->is_fighting(target))
                        return notify_fail("\n您必須在戰鬥中才能使用『一氣貫雲天』。\n");
                if(me->query_skill_mapped("unarmed")!="cloudfist")
                        return notify_fail("您現在並沒有使用貫雲掌法喔。\n");
                if( force < 80 || sk < 85 || cf < 80 )
                        return notify_fail("\n您的能\力還不足以使出『一氣貫雲天』。\n");
                if(me->query("ap") < 500)
                        return notify_fail("\n您的體力不夠使用『一氣貫雲天』。\n");
                if(me->is_busy())
                        return notify_fail(HIW"\n您正在忙其他的事情喔！\n"NOR);
                //num = random(sizeof(enemy));
                //enemy[num]=present(enemy[num],environment(me));
                //c=enemy[num]->query_temp("apply/armor");
                c = target->query_armor(); //luky
                hit = random(COMBAT_D->attack_factor(me,"unarmed")); //luky
                dodge = random( - (COMBAT_D->dodge_factor(target,"dodge"))); //luky
                message_vision(HIM"$N氣凝心神，息聚雙掌，大喝道：\n\n"NOR+
                               HIC"           『"HIY"神凝印眉間，蘊息雙臂延\n"NOR+
                               HIY"             勢似山海巔，一氣貫雲天！"HIC"』\n\n"NOR+
                               HIG"瞬間，強大氣勁如排山倒海之勢攻向$n！\n"NOR,me,target);
                damage = ((sk + force)*2) + random(me->query_damage()) + me->query_damage()/2;
		damage = (damage*3)/2;
                damage -= (random(c/2) + c/2);
                if(damage < 150) damage = 140+random(30);
                if(damage > 900) damage = 900+((damage-900)/5);
				if(hit + 50> dodge)
                {
                        msg = HIR"        結果命中$n，「嘩啦」一聲，$n登時口噴鮮血！\n\n"NOR;
                        message_vision(msg, me, target);
                        me->improve_skill("cloudfist",random(4)+(me->query_int()/5));
                        // 增加素質對傷害的影響
                        damage = COMBAT_D->Merits_damage(me,target,damage,"bar");
                        target->receive_damage("hp",damage,me);
                        COMBAT_D->report_status(target);
                        me->start_busy(3);
                        target->start_busy(2);
                }
                else
                {
                        msg = MAG"        但$n急忙轉身一閃，避開了猛烈的一招。\n\n"NOR;
                        message_vision(msg, me, target);
                        me->improve_skill("cloudfist",2);
                        target->improve_skill("dodge",3+random(2));
                        me->start_busy(3);
                }
                //me->add("ap",-225-(damage/8));
                me->receive_damage("ap",200+damage/10+random(20));
                me->improve_skill("unarmed",3+(me->query_int()/5));
                return 1;
        }
	if(me->query_skill("unarmed")<11) 
                return notify_fail("你的空手搏擊基礎不足，無法使用「貫雲掌法」。\n");
        if(me->query("ap")<20 || me->query("hp")<15) 
                return notify_fail("你的身體狀況太差了，不能使用「貫雲掌法」。\n");
        if(!me->skill_active( "cloudfist",(: call_other, __FILE__, "delay", me ,5:), 5))
                return notify_fail("你停止使用貫雲掌法的動作還沒完成。\n");
	me->map_skill("unarmed", "cloudfist");
	me->reset_action();
	message_vision(HIC"\n$N勁聚雙手之上，使起「貫雲掌法」。\n"NOR,me);
    	me->receive_damage("ap",5);
	me->start_busy(2);
        return 1;
}

void delay(object me,int cost)
{
	object weapon,*enemy;
        string *limbs;
        int c,cs,cf,force,count,num,eny,i,j,damage,hit,dodge,steps,lv;
	lv=me->query("level");
        cf=me->query_skill("cloudfist");
        force=me->query_skill("cloudforce");
        steps=cs=me->query_skill("cloudsteps");
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
	if(me->query_skill_mapped("unarmed")!="cloudfist")
	{
	 return;
	}
        if(me->query("ap")<15)
	{
	 	me->map_skill("unarmed");
		me->reset_action();
		tell_object(me,"\n你的體力不夠，不能再用「貫雲掌法」了。\n");
		return;
	}
        if( me->is_fighting() )
        { 
		if( me->query_skill("force")>25 && cf>random(135) && me->query("ap") > 100)
		{
	                enemy=me->query_enemy();
                        cs=cs/15;
                        if(cs<1) cs=1;
                        if(cs>5) cs=5;
                        for(count=0;count<sizeof(enemy) && count<cs;count++)
                        {
                                limbs = enemy[count]->query("limbs");
                                c=enemy[count]->query_armor();
                                hit = random(COMBAT_D->attack_factor(me,"unarmed")+cf/3);
                                dodge = random(- (COMBAT_D->dodge_factor(enemy[count],"dodge")));
				if(lv>30) lv=30;
                                damage = (steps/2) + (cf/2) + (random(me->query_damage()*5/2) + random(force/2)) + (lv*3);
                                damage -= (c/2 +random(c/3));
                                if(damage < 20) damage = 18+random(5);
				if(damage > 375) damage = 375+((damage-375)/4);
				if(hit + 35 > dodge)
	                        {
		                        message_vision("\n$N突然發掌攻向$n，$n閃避不及，被這招『飄渺雲端』擊中了"+limbs[random(sizeof(limbs))]+"。\n",me,enemy[count]);
                                        me->improve_skill("cloudfist",random(2)+(me->query_int()/5)); //特攻時額外增加
                                        // 增加素質對傷害的影響
                                        damage = COMBAT_D->Merits_damage(me,enemy[count],damage,"bar");
                                        enemy[count]->receive_damage("hp",damage,me);
                                        me->receive_damage("ap",damage/10+random(5));
                                        COMBAT_D->report_status(enemy[count]);
	                        }
	                        else
                                {
                                        message_vision("$N突然發掌攻向$n，但$n窺破這招『飄渺雲端』的破綻，閃開了這一招。\n",me,enemy[count]);
                                        enemy[count]->improve_skill("dodge",2);
	                        	me->receive_damage("ap",5+random(5));
	                        }
                                me->improve_skill("unarmed",(me->query_int()/4)+1);
                        }
                }
                me->receive_damage("ap",5); //luky
        	me->improve_skill("unarmed",(me->query_int()/5)+1); //luky
        	me->improve_skill("cloudfist",1+(me->query_int()/5)); //luky 作戰時慢慢增加
        }
        me->skill_active( "cloudfist",(: call_other, __FILE__, "delay", me ,cost:), 5);
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
        a=ob->query_skill("unarmed");
        if(a>80) a=80;
	if(ob->query("adv_class")==2) return 90;
        else if(ob->query("adv_class")==1) return a;
}
