/*
    這個技能的特點是機敏愈高，發出強力攻擊的機會愈大，如果機敏100加上此技能等級100
    則可以有75左右的攻擊力，但是受到random的影響，也有可能只有5而已。招式的攻擊力
     加上技能的影響，最多不超過10，算是十分沒威力的招式。由於是三次方的取值，所以機敏
     60之前，都不會有多大威力，頂多20左右，但60之後，威力增加的極快。我希望能保留此特
     點，如此來強調此技能機敏的重要性，區別以力量造成傷害的武者招式，使運氣及速度成為
     盜賊門派與眾不同之處。此技能我是以更改「大槍訣」而來，在此特別感謝。
 */
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
int h = this_player()->query_dex()/5;
int h = h*h*h;
int h = h*7/800;
int h = random(h)+this_player()->query_skill("handing-dagger")/20;//攻擊力的計算式

mapping *action = ({
	([
	"action": "$N突然將手上的$w旋轉起來，輕叱一聲，使出「快字訣」﹗只見無數刀影襲向$n",
	"damage":		1+h,
	"dodge" :		40,
	"parry" :		-10,
	"attact_type":  "bar",  
	"damage_type":  "刺傷",
	]),

	([
	"action": "$N突然向後飄開，說了一聲﹔「疾。」也不見$N如何移動，一道寒光已劃上了$n的頸項",
	"damage":		4+h,
	"dodge" :		30,
	"parry" :		-20,
	"attact_type":  "bar",  
	"damage_type":  "割傷",
	]),

	([
	"action": "$N眼神一閃，趁$n手中招式將盡未盡之時，一式「破字訣」直攻$n招式上的破綻",
	"damage":		1+h,
	"dodge" :		20,
	"parry" :		20,
	"attact_type":  "bar",  
	"damage_type":  "刺傷",
	]),

	([
	"action": "$N將$w舉與眼平，刃尖前指，口中喝了一聲「殺」，整個人猶如電閃雷擊一般向$n衝了過來",
	"damage":		5+h,
	"dodge" :		-30,
	"parry" :		-30,
	"attact_type":  "bar",  
	"damage_type":  "殺傷",
	]),

	([
	"action": "只見$N左一踏，右一轉，使出「迴字訣」﹗不等$n看清其身型，一把$w已向$n遞了過去…",
	"damage":		2+h,
	"dodge" :		30,
	"parry" :		30,
	"attact_type":  "bar",  
	"damage_type":  "削傷",
	]),

	([
	"action": "$N頭一低，腳一踩，順勢鑽入$n的懷中，一招「入字訣」瞬間勾掠削砍攻了數招…",
	"damage":		3+h,
	"dodge" :		-20,
	"parry" :		40,
	"attact_type":  "bar",  
	"damage_type":  "擊傷",
	]),
});

int exert(object me, object target,string arg)
{
	int damage,d,w;
            
	object weapon;
		
	weapon=me->query_temp("weapon");
	if(!weapon) return notify_fail("「入手匕」除了手以外還需要一把匕首才能施展。\n");
	if( weapon->query("skill_type")!="dagger") return notify_fail("你確定要拿這東西施展「入手匕」嗎﹖\n");

	if( arg=="off" )
	{
		if( me->query_skill_mapped("dagger")!="handing-dagger")
			return notify_fail("嗯﹗沒錯，你現在的確沒有使用「入手匕」。\n");
		me->map_skill("dagger");
		me->reset_action();
		message_vision("$N將手上的匕首轉了兩轉，暫時不打算使用「入手匕」了。\n",me);
		return 1;
	}

	if( me->query_skill("dagger")<1 )
		return notify_fail("你連匕首怎麼用都不會ㄝ…\n");
	if( me->query("ap") < 10 || me->query("mp") < 20 )
		return notify_fail("你的注意力不夠，無法發揮「入手匕」的招式。\n");


	// 第二次 exert
	if(me->query_skill_mapped("dagger")=="handing-dagger")
	{
                       if( !target ) target = offensive_target(me);
                         if(!target)   
			return notify_fail("你仔細的檢查了手上的匕首，活動活動手腕，嗯﹗現在使用「入手匕」絕對沒問題﹗\n");	       
		if( me->query_skill("handing-dagger") < 70 )
			return notify_fail("你現在想使用「狂字訣」嗎﹖太危險了﹗你根本還不熟招式，無法將它們連貫起來。\n");
		if( me->query("ap")<50 )
			return notify_fail("你很想使出「狂字訣」，但是內勁就是不聽話。\n");
		if( me->query("mp") <150 )
			return notify_fail("你的注意力不夠集中，無法使用「狂字訣」…\n");
                          if(!me->can_fight(target))
                                       return me->can_fight(target);
		me->start_busy(1);
		me->receive_damage("mp",70);//因為會給予傷害，消耗較大

             d=target->query_dex();
	damage = (random(me->query_skill("handing-dagger"))+me->query_dex() *4/3);//單純的威力計算
            damage=damage-random(d);

	message_vision(HIR"$N向後一踏，手上的匕首輕輕一揮，「快疾破殺迴入」五訣合一的「狂訣」在毫無前兆的情\況\下斗然發出﹗\n"NOR,me);
	if( target->query_skill("dodge") > random(me->query_dex()*5) )//增加屬性對命中率的影響，並加強命中率
	{
		message_vision(HIW"$P向旁邊一跳，避開了這瘋狂的攻擊。\n"NOR,target);
                        me->start_busy(2);
		return 1;
	}
           
	target->receive_damage("hp",damage, me );
                       w=damage*2/d;
                      if (target->query("wound/foot")>25) w=0;//限制傷害值
	target->receive_wound("foot",w);  //給予傷害，藉由傷害對方腿部間接增加我方命中率
             /*switch(random(4)) {
		case 0: target->receive_wound("hand",(random(damage/d)));break;
		case 1: target->receive_wound("head",(random(damage/d)));break;
		case 2: target->receive_wound("body",(random(damage/d))); break;
		case 3: target->receive_wound("foot",(random(damage/d)));break;
		}        //隨機給予不同部位傷害
            */
	message_vision(HIR"$P的鮮血隨著匕首的攻勢四散而出﹗竟在地上描繪出一朵血牡丹﹗\n",target);
	target->start_busy(1);
	me->start_busy(2);//避免玩家連發，玩家暫停的回合大於對象
	me->improve_skill("handing-dagger",1+random(me->query_int()/3+me->query_dex()/4));
	me->improve_skill("dagger",1+random(me->query_int()/3+me->query_dex()/4));

		return 1;

	}
	
	me->map_skill("dagger", "handing-dagger");
	me->reset_action();
	message_vision("\n"HIG"$N將手中的"+weapon->query("name")+HIG"反手握住，彎臂凝氣、刃藏於袖，正是「入手匕」的起手式﹗\n"NOR,me);
	me->receive_damage("mp",20);
	me->start_busy(1);
	me->skill_active( "handing-dagger",(: call_other, __FILE__, "delay", me ,4 :), 1);
	return 1;
}

void delay(object me,int cost)
{
	object weapon,target;

	if(!me) return;
	weapon=me->query_temp("weapon");
	if (!weapon || weapon->query("skill_type")!= "dagger" )
	{
		me->map_skill("dagger");
		me->reset_action();
		return;
	}
	
	if(me->query_skill_mapped("dagger")!="handing-dagger")  return;
	
	if(me->query("ap")<10)
	{
		me->map_skill("dagger");
		me->reset_action();
		tell_object(me,"\n你漸漸喪失了注意力，無法再繼續使用「入手匕」了。\n");
		return ;
	}
	me->receive_damage("ap", cost);
	me->receive_damage("mp", cost-2);
	me->skill_active("handing-dagger",(: call_other, __FILE__, "delay", me ,cost:), 4);
	return;
}

int valid_learn(object me) {    return 1;       }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
        int a;
        a=(ob->query_dex())*2/3;
	if(a>70) a=70;
	if(ob->query("adv_class")==2) return 100;
        else if(ob->query("adv_class")==1) return a;
}
/*
     匕首乃近戰之器....入手匕更將匕首藏入手中........
     招式又快又狠....招招搶攻.....如果不是反應極快之人....
     多半無法抵擋....招式共分七訣
     快 疾 破 殺 迴 入 狂
     快訣有如千手共出
     疾訣有如閃電掠空
     破訣攻敵招之心以破招
     殺訣捨己之安危以殺敵
     迴訣以敵為支點迴旋....前後左右眾所難測...
     入訣入敵寸身之際......勾掠削砍防不勝防...
     狂訣毫無章法.....匕首若有似無.....
     不知由何來從何去....乃融合前六訣之大成而生之極招......
*/