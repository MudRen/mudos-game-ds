#include <ansi.h> 
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        // ���a�i�঳quit�L
        if(me->query_temp("constant-virtue") == 0)
                return 0;

        if( !duration )
        {
                tell_object(me, HIC"�A�F�x�@�}�i�ʡA��ӬO�A�m�`�w�����n���O�q�����F�C\n"NOR);
                me->add_temp("apply/hit_ratio", -me->query_temp("constant-virtue"));
                me->delete_temp("constant-virtue");
                return 0;
        } 

        me->apply_condition("constant-virtue", duration-1 );
        return 1;
}


