//天梟 - 太陽訣

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;

		// 玩家可能有quit過
		if(me->query_temp("addstr") == 0)
				return 0;

        if( !duration )
        {
                add = me->query_temp("addstr");
                tell_object(me,"你感覺《"HIY" 太 陽 訣"NOR" 》給予你的力量已經消失了•\n");
                me->add_temp("apply/str",-add);
                me->delete_temp("addstr");
                return 0;
        } 

        me->apply_condition("addstr", duration-1 );
        return 1;
}

