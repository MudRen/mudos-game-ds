// 寒澈派
// tmr 2007/03/03

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        if( !duration )
        {
			    message_vision(  "$N全身一陣酸麻，塵垢淨盡的效果也消失了。\n" ,me);
                return 0;
        } 

        me->apply_condition("frost_dust", duration-1 );
        return 1;
}

