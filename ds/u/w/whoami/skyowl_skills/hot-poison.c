//奇異熱毒(hot-poison)       sk 40  削減敵人 命中 & 閃躲    (固定扣 sk/5)     
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int anti = me->query_skill("anti_poison"),
            damage = me->query("shouyu-poison/hot-poison/effect");
        if( !duration )
        {
                tell_object(me,HIB"你身上殘餘的奇異熱毒毒性消失了。\n"NOR);
                me->delete_temp("conditions/hot-poison");
                me->delete_temp("shouyu-poison/hot-poison/effect");
                me->add_temp("apply/dodge", me->query_temp("shouyu-poison/hot-poison/damage"));
                me->add_temp("apply/hit", me->query_temp("shouyu-poison/hot-poison/damage"));
                return 0;
        } else 
        {
                if(random(8+duration)<random(5))
                {
                        me->apply_condition("hot-poison", duration);
                        return 1;
                }
 //        if( !living(me) ) {
//                message("vision",HIW + me->name() + "瑟瑟發抖，全身結上一層薄薄的白霜。\n"NOR, environment(me), me);
//        }
//        else {
                tell_object(me, HIR "忽然一股火熱之氣襲來，燙得你手腳發顫！\n" NOR );
                tell_room(environment(me), HIR + me->name()+"突然全身冒出陣陣紅煙，嘴唇乾裂，雙手胡亂地揮舞著。\n" NOR,({me}));
//                }
                damage /= 5;
                damage -= random(anti/20);
                if( damage < 0 ) damage = 0;
                me->set("shouyu-poison/hot-poison/damage", damage);
                if( !me->query_temp("shouyu-poison/hot-poison/damage") ){
                  me->add_temp("apply/dodge", -damage);
                me->add_temp("apply/hit", -damage);
                }
                me->add_block(1);
                me->improve_skill("anti_poison", duration+random(me->query_con()));
                me->set_temp("conditions/hot-poison",duration - 1);
                me->apply_condition("hot-poison", duration - 1);
        }
        return 1;
}
