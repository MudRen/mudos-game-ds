// 
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int anti,damage;
	if( !duration )
	{
		tell_object(me,HIR"你身上殘餘的熱毒毒性消失了。\n"NOR);
		me->delete_temp("conditions/hot_poison");
		return 0;
	} else 
	{
		if(random(8+duration)<random(5))
		{
            		me->apply_condition("hot_poison", duration);
			return 1;
		}
		anti=me->query_skill("anti_poison");
		anti=100-anti+random(200);
		damage=duration*anti/50;

   if( !living(me) ) {
      message("vision", me->name() + "全身變黑，散發出一陣焦糊味。\n", environment(me), me);
   }
   else {
		 tell_object(me, HIR "忽然一股火熱之氣襲來，燙得你手腳發顫！\n" NOR );
    		tell_room(environment(me), HIR + me->name()+"突然全身冒出陣陣紅煙，嘴唇乾裂，雙手胡亂地揮舞著。\n" NOR,({me}));
   }
		me->set_temp("temp/death_type","[[1;31m奇異熱毒而死[0m]"); 
		me->receive_damage("hp", 10+damage*5);
		me->receive_damage("ap", 5+damage*3);
		me->receive_damage("mp", 5+damage*3);
		me->add_block(1);
		if(duration>50) duration=50;
		me->improve_skill("anti_poison", duration+random(me->query_con()));
		me->set_temp("conditions/poison",duration - 1);
		me->apply_condition("poison", duration - 1);
	}
	return 1;
}
