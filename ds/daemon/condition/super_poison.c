// 
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int anti,damage;
	if( !duration )
	{
		tell_object(me,HIR"�A���W�ݾl�����r�r�ʮ����F�C\n"NOR);
		me->delete_temp("conditions/super_poison");
		return 0;
	} else 
	{
		if(random(8+duration)<random(5))
		{
            		me->apply_condition("super_poison", duration);
			return 1;
		}
		anti=me->query_skill("anti_poison");
		anti=100-anti+random(500);
		damage=duration*anti/50;

    	if( !living(me) ){
    		message("vision",HIW + me->name() + "�������M��ʤF�@�U�I\n"NOR, environment(me), me);
    	}
   else {
      	if( me->query("hp") >= 1500)
              	tell_room(environment(me), YEL+me->name()+"��M�u���s���A���l�C�C���U�A�f���o�X���H���~���������n�C\n" NOR, ({ me }));            
      	else if( me->query("hp") < 1500 && me->query("hp") >= 1000)
              	tell_room(environment(me), BLU+me->name()+"���M�������w���L�H���A����o�޲��L�ۡC\n" NOR,  ({ me }));        
      	else if( me->query("hp") < 1000 && me->query("hp") >= 500)
              	tell_room(environment(me), HIB+me->name()+"���ɯ�����[�k��A���F����A�çq�ër�C\n" NOR,({ me }));           
      	else    tell_room(environment(me), HIR+me->name()+"��M�Y���@�ΡA�u�b�a�W�����a�oŸ�C\n" NOR,({ me }));
   }
    tell_object(me, HIR "�A���M�P�쨭������A�w�g��ť�ϳ�F�C\n" NOR );
		me->set_temp("temp/death_type","[[1;31m���u�۬r�Ӧ�[0m]"); 
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
