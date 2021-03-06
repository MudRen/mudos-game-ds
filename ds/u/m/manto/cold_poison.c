// 
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int anti,damage;
	if( !duration )
	{
		tell_object(me,HIB"你身上殘餘的寒毒毒性消失了。\n"NOR);
		me->delete_temp("conditions/cold_poison");
		return 0;
	} else 
	{
		if(random(8+duration)<random(5))
		{
            		me->apply_condition("cold_poison", duration);
			return 1;
		}
		anti=me->query_skill("anti_poison");
		anti=100-anti+random(50);
		damage=duration*anti/50;
        if( !living(me) ) {
                message("vision",HIW + me->name() + "瑟瑟發抖，全身結上一層薄薄的白霜。\n"NOR, environment(me), me);
        }
        else {
		tell_object(me, HIW "忽然一股寒氣猶似冰箭，循著手臂，迅速無倫的射入胸膛，你中的寒毒發作了！\n" NOR );
                message("vision", HIW + me->name() + "全身發顫，牙關格格直響，過得片刻，嘴唇也紫了，臉色漸漸由青而白。\n"NOR,({me}));
		}
		me->set_temp("temp/death_type","[[1;31m奇異寒毒身亡[0m]"); 
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
