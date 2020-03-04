//eeman, 法術要加 delay 你不知道嗎??
// 還有醫療技能不是用在你的戰鬥對象身上的, 用不到SSERVER

#include <ansi.h>
inherit SKILL;
int cast(object me, object target)
{
	if( !target ) target = me;

	if( !target
	||	!target->is_character()
	||	target->is_corpse())
		return notify_fail("你要對誰施展這個法術﹖\n");
	if( !living (target) )
     		return notify_fail(HIY"這不是生物喔！\n"NOR);

	if((int)me->query("mp") < 5 )
		return notify_fail("你的法力不夠﹗\n");

	 if( me->query_temp("cast") )
	    return notify_fail("你正在施法。\n");
	    
	me->add("mp", -5);
	me->set_temp("cast","heal");
	me->start_busy(2);
	message_vision("\n[1;35m$N將雙手放在$n的雙肩, 口中唸著醫療咒文..[0m\n\n",me);
	call_out("do_heal",2,me,target);
}

int do_heal(object me, object target)
{
  string msg;
  
  if(!me) return 0;
  if(target!=present(target->query("id"), environment(me)))
  {
    me->delete_temp("cast");
    return notify_fail("對象似乎脫離了你的施法範圍..\n");
  }
	if( random(me->query("max_mp")) < 30 )
	{
		write("你失敗了。\n");
		return 1;
	}

	msg = HIM "$N的雙手一合﹐$n身旁漸漸聚起一團紫光﹗\n\n" NOR;

	msg += "$n身上的創傷漸漸恢復了。\n";

	message_vision(msg, me, target);
	me->improve_skill("berserk",1+random(me->query_int()/10));
	target->receive_heal("hp", 50);

	me->delete_temp("cast");
	return 1;
}

