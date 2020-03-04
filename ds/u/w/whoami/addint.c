//天梟 - 陰心訣

#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        int add;
        if( !duration )
        {
                add = me->query_temp("addint");
                tell_object(me,"你感覺《"HIW+BLK" 陰 心 訣"NOR" 》給予你的力量已經消失了•\n");
                me->add_temp("apply/int",-add);
                me->delete_temp("addint");
                me->delete_temp("e_int");
                return 0;
        } 
        else
        {         
                me->apply_condition("addint", duration-1 );
        }
        return 1;
}

