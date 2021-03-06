#include <ansi.h>
#define OBJ_DIR "/u/a/alickyuen/open/xmas/obj/"

void init()
{
	add_action("do_chop", "chop");
}

int do_chop(string str)
{
	object me, wood, *guy;
	int weight, i;

	me = this_player();

	if( !str || str != "樹枝" )
		return notify_fail("你要砍什麼?\n");

	if( me->query_temp("weapon") )
		return notify_fail("你手中的武器不夠長去把大樹上的樹技弄下來。\n");

	message_vision(HIM"$N在地上紮穩馬步運功\，雙掌掌氣打向樹上的樹枝。\n\n", me);

	me->receive_damage("ap", 10);

	message_vision(HIW"樹上突然被狂風亂括搖了幾搖......\n\n\n"NOR, me);

	if( random(2) == 0 )
	{
		guy = all_inventory(environment(me));

		wood = new(OBJ_DIR+"wood");

		weight = random(40000);

		while( weight < 10000 ) weight = random(40000);

		wood->set_weight(weight);

		message_vision(HIW"天上突然落下了幾根木頭！\n"NOR, me);

		wood->move(environment(me));

		for(i=0;i<sizeof(guy);i++)
		{
			if(userp(guy[i]))
			{
				message_vision(HIR"$N被掉下來的木頭擊中了！\n"NOR, guy[i]);
				guy[i]->receive_wound("left_arm", random(2));
				guy[i]->receive_wound("right_arm", random(2));
				guy[i]->receive_wound("left_leg", random(2));
				guy[i]->receive_wound("right_leg", random(2));
				guy[i]->receive_wound("body", random(4));
				guy[i]->receive_wound("head", random(6));
			}
		}
	}

	me->start_busy(5);

	return 1;
}
