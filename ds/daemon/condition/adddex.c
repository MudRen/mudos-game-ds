//天梟 - 逸飄訣

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;

		// 玩家可能有quit過
		if(me->query_temp("adddex") == 0)
				return 0;

        if( !duration )
        {
                add = me->query_temp("adddex");
                tell_object(me,"你感覺《"HIW" 逸 飄 訣"NOR" 》給予你的力量已經消失了•\n");
                me->add_temp("apply/dex",-add);
                me->delete_temp("adddex");
                return 0;
        } 

        me->apply_condition("adddex", duration-1 );
        return 1;
}

