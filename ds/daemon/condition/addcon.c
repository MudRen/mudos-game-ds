//天梟 - 三焦訣

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;

		// 玩家可能有quit過
		if(me->query_temp("addcon") == 0)
				return 0;

        if( !duration )
        {
                add = me->query_temp("addcon");
                tell_object(me,"你感覺《"HIG" 三 焦 訣 "NOR"》給予你的力量已經消失了•\n");
                me->add_temp("apply/con",-add);
                me->delete_temp("addcon");
                return 0;
        } 

        me->apply_condition("addcon", duration-1 );
        return 1;
}

