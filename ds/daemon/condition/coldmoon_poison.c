//冷月寒毒 -By Tmr-

#include <ansi.h>

int update_condition(object me, int duration)
{
        int r;
          r=me->query_temp("coldmoon_poison");
        if( r > 0)
        {
                duration -=r;
                  me->set_temp("coldmoon_poison",0);
        }

        if( duration < 1 ) return 0;

          me->receive_damage("hp", 80);
        me->receive_damage("ap", 30);
          me->receive_damage("ap", 50);
           me->start_busy(1);

        tell_object(me, HIW "一陣又一陣的寒氣直衝你的心窩！！\n" NOR );
      if(me->query("race")=="人類" || me->query("race")=="human" )
        message_vision("$N使緊雙手的力量摀著心窩，臉上的表情因為疼痛而顯得非常掙擰。\n",me);
   else
         message_vision("$N發出一聲非常疼痛的吼聲！！\n",me);
        me->apply_condition("coldmoon_poison", duration -1);
        if( duration < 1 ) return 0;
        return 1;
}

