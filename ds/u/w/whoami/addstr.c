//天梟 - 太陽訣

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;
        if( !duration )
        {
                add = me->query_temp("addstr");
                tell_object(me,"你感覺《"HIY" 太 陽 訣"NOR" 》給予你的力量已經消失了•\n");
                me->add_temp("apply/str",-add);
                me->delete_temp("addstr");
                me->delete_temp("e_str");
                return 0;
        } 
        else
        {         
                me->apply_condition("addstr", duration-1 );
        }
        return 1;
}

