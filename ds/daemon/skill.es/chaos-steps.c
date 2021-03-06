// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$n一招「天璣離樞」輕輕巧巧地避了開去。\n",
	"只見$n身影一晃﹐一式「天璇亂步」早已避在七尺之外。\n",
	"$n使出「倒轉天權」﹐輕輕鬆鬆地閃過。\n",
	"$n左足一點﹐一招「逐影天樞」騰空而起﹐避了開去。\n",
	"可是$n使一招「風動玉衡」﹐身子輕輕飄了開去。\n",
	"$n身影微動﹐已經藉一招「開陽薄霧」輕輕閃過。\n",
	"但是$n一招「瑤光音遲」使出﹐早已繞到$N身後﹗\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的內力不夠﹐沒有辦法練倒亂七星步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的氣或內力不夠﹐不能練倒亂七星步法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
