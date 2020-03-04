//horse-steps (八極紮馬) by tmr PM 07:32 1999/4/16

#include <ansi.h>
inherit SKILL;
void delay(object me,int cost);
int exert(object me, object target, string arg)
{

        if(arg=="off" )
        {
		if(!me->query_temp("is_busy/horse-steps")) return notify_fail("你並沒有在紮馬吧....\n");
	        message_vision("\n"HIW"$N深呼一口氣，結束紮馬的動作，站起身來舒鬆已疲累不堪的雙腳。\n"NOR,me);
		me->delete_temp("is_busy/horse-steps");
                return 1;
        }
	if(me->is_ghost() ) return notify_fail("你是鬼耶，那來的腳...:P\n");
	if(me->is_fighting() ) return notify_fail("你正在打架中，沒有空紮馬吧..\n");
	if(me->is_busy() ) return notify_fail("你正忙著，沒有空做其他事。\n");
	
	if(me->query("hp")<10 || me->query("mp")<10 ) return notify_fail("你現在的體力不好，不能紮馬，免得昏倒..P\n");
        
	if( sizeof(me->query_temp("is_busy")) ) return notify_fail("你現在正在忙。\n");

        message_vision("\n"HIW"只見$N立身中正、虛領頂頸、二目平視、尾閭中正，正開始紮起馬步，以練腳力。\n"NOR,me);
        me->receive_damage("mp", 5);
        me->receive_damage("hp", 5);
        me->set_temp("is_busy/horse-steps","你正在練紮馬不能移動。");
        me->start_busy(2);
        me->start_call_out( (: call_other, __FILE__, "delay", me ,5:), 3);
        return 1;
}

void delay(object me,int cost)
{
        if(!me) return;
        if(!me->query_temp("is_busy/horse-steps") )
        {
	         return;
        }

        if(me->query("mp")<5 || me->query("hp") <5)
        {
                message_vision("\n"HIB"只見$N深呼一口氣，結束紮馬的動作，站起身來舒鬆已疲累不堪的雙腳。\n"NOR,me);
	        me->delete_temp("is_busy/horse-steps");
                return ;
        }
        me->receive_damage("mp",5);
        me->receive_damage("hp",5);
        me->improve_skill("horse-steps",1 + random(1+me->query_int()/3) + random(1+me->query_con()/4) );	
        me->start_call_out( (: call_other, __FILE__, "delay", me ,cost:), 3);
}

int valid_learn(object me) { return 1; }
int practice_skill(object me) { return 1; }
