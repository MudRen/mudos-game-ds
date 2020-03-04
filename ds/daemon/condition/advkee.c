//天梟 - 三焦訣

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;

		// 玩家可能有quit過
		if(me->query_temp("advkee") == 0)
				return 0;

        if( !duration )
        {
                tell_object(me,"你感覺《"HIC"善世訣"NOR"》的效果已經消失了•\n");
                me->delete_temp("advkee");
                return 0;
        } 

        add = me->query_temp("advkee");
		me->receive_heal("hp", add );	// 恢復hp
		tell_object(me, "打在你胸腔神道穴上的"HIC"善世訣"NOR"，正緩緩地治瘉你的傷勢。\n"NOR);

        me->apply_condition("advkee", duration-1 );
        return 1;
}

