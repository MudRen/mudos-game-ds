//化血腐骨毒(body-decayed)   sk 100 機率性削減敵人 merits                  (bar bio wit tec sou 擇一種扣一點)
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int anti = me->query_skill("anti_poison");
        string *merits = ({ "bio", "bar", "wit", "sou", "tec" }), merit;

        if( !duration )
        {
                tell_object(me,HIB"你身上殘餘的化血腐骨毒毒性消失了。\n"NOR);
                me->delete_temp("conditions/body-decayed");
                me->add_temp("apply/"+me->query_temp("shouyu-poison/body-decayed/merits"), 1);
                return 0;
        } else 
        {
                if(random(8+duration)<random(5))
                {
                        me->apply_condition("body-decayed", duration);
                        return 1;
                }
 //        if( !living(me) ) {
//                message("vision",HIW + me->name() + "瑟瑟發抖，全身結上一層薄薄的白霜。\n"NOR, environment(me), me);
//        }
//        else {
                tell_object(me, YEL "你身上傷口正以無可想像的速度腐爛，還不停留出黃色的濃。\n" NOR );
                tell_room(environment(me), HIR + me->name()+"全身上下散出陣陣腐屍一般的惡臭，讓你不由自主的隱隱作嘔。\n" NOR,({me}));
//                }
                merit = merits[random(4)];
                if( !me->query_temp("shouyu-poison/body-decayed/merits") ){
                me->set_temp("shouyu-poison/body-decayed/merits", merit);
                me->add_temp("apply/"+merit, -1);
                }
                me->add_block(1);
                me->improve_skill("anti_poison", duration+random(me->query_con()));
                me->set_temp("conditions/body-decayed",duration - 1);
                me->apply_condition("body-decayed", duration - 1);
        }
        return 1;
}
