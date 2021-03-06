//mage_steps.c
#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
string *dodge_msg = ({
"$n身形一晃，使出「仙龍現」閃開了$N的招式。\n",
"$n縱身使出「衝九天」躲過了$N的攻擊。\n",
"$n步法隨心轉，一招「遊四方」躲開了$N的攻擊。\n",
"$n腳下一動，「動乾坤」一招閃開了$N的攻勢。\n",
});
int exert(object me, object target, string arg)
{
	string msg;

	if(arg=="off" )
	{
		if( me->query_skill_mapped("dodge")!="dragonsteps")
			return notify_fail("你並沒有使用遊龍步。\n");
		me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIW"$N停下了$N的腳步。\n"NOR,me);
		write("技能[遊龍步]已取消。\n");
		return 1;
	}

	if(me->query_skill("dodge")<40) return notify_fail("你的縱躍閃避能力還不夠使用遊龍步。\n");
	if(me->query_skill_mapped("dodge")=="dragonsteps")
		return notify_fail("你正在使用遊龍步。\n");
	if(me->query("mp")<40 || me->query("hp")<40) return notify_fail("你的身體狀況無法使用遊龍步。\n");

        if(!me->skill_active( "dragonsteps",(: call_other, __FILE__, "delay", me ,5:), 5))
          return notify_fail("你收起遊龍步的動作還沒完成。\n");
          
	me->map_skill("dodge", "dragonsteps");
	me->reset_action();
	message_vision("\n"HIG"$N開始施展遊龍步, 身形馬上如龍般飛縱了數下。\n"NOR,me);
	me->add("mp", -5);
	me->start_busy(2);
        //me->start_call_out( (: call_other, __FILE__, "delay", me ,2:), 10);
	return 1;
}

void delay(object me,int cost)
{
	if(!me) return;
	if(me->query_skill_mapped("dodge")!="dragonsteps")
	{
	 return;
	}
	if(me->query("ap")<cost+15)
	{
	 	me->map_skill("dodge");
		me->reset_action();
		message_vision("\n"HIW"$N突然慢了下來。\n"NOR,me);
		tell_object(me,"你的體力不夠使用遊龍步了。\n");
		return ;
	}
	me->receive_damage("ap", cost);
        //me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 10);
        me->skill_active( "windmove",(: call_other, __FILE__, "delay", me ,cost:), 5);
}

int valid_learn(object me) {	return 1;	}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) {	return 1; }
int improve_limite(object ob)
{
        int a;
        a=ob->query_dex();
	a=60+a;
	return a;
}
