// 急救技巧(livesaving)  
// 外科醫生 

#include <ansi.h>
inherit SKILL;
int exert(object me, object target)
{
        if(!objectp(present("first aid box",me) ) ) 
                return notify_fail("你得先有救護工具。\n");
	if( !target ) target = me;
	if( !living (target) )
     		return notify_fail("這不是生物喔！\n");
	if((int)me->query("ap") < 10 )
		return notify_fail("你的內勁點數不夠﹗\n");
	 if( me->query_temp("ex_sav") )
	    return notify_fail("你正在施法。\n");
	me->add("ap", -10);
	me->set_temp("ex_sav"); 
	me->start_busy(2);
	message_vision("\n $N拿出救護工具來幫$n包紮傷口..\n\n",me, target);
	call_out("do_heal",2,me,target);
return 1;
}

int do_heal(object me, object target)
{
  if(!me) return 0;
  if(target!=present(target->query("id"), environment(me)))
  {
    me->delete_temp("ex_sav");
    return notify_fail("對象似乎不在這裡。\n");
  }
	message_vision("$n身上的傷口復合了。\n",me, target);
// 不知有沒寫錯
me->improve_skill("livesaving",20+random(10));
	target->receive_curing("head", random(me->query_skill("livesaving")/10));
	target->receive_curing("body", random(me->query_skill("livesaving")/10));
	target->receive_curing("left_arm", random(me->query_skill("livesaving")/10));
	target->receive_curing("right_arm", random(me->query_skill("livesaving")/10));
	target->receive_curing("left_leg", random(me->query_skill("livesaving")/10));
	target->receive_curing("right_leg", random(me->query_skill("livesaving")/10));
	me->delete_temp("ex_sav");
	return 1;
}

