#include <ansi.h>

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

             tell_object(me, NEWS_D->one_title() + "�C\n" );
        me->apply_condition("news_listing", duration -1);
        return 1;
}


