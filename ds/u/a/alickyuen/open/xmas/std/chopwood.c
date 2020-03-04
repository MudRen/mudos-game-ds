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

	if( !str || str != "��K" )
		return notify_fail("�A�n�夰��?\n");

	if( me->query_temp("weapon") )
		return notify_fail("�A�⤤���Z���������h��j��W����ާˤU�ӡC\n");

	message_vision(HIM"$N�b�a�W��í���B�B�\\�A���x�x�𥴦V��W����K�C\n\n", me);

	me->receive_damage("ap", 10);

	message_vision(HIW"��W��M�Q�g���ìA�n�F�X�n......\n\n\n"NOR, me);

	if( random(2) == 0 )
	{
		guy = all_inventory(environment(me));

		wood = new(OBJ_DIR+"wood");

		weight = random(40000);

		while( weight < 10000 ) weight = random(40000);

		wood->set_weight(weight);

		message_vision(HIW"�ѤW��M���U�F�X�ڤ��Y�I\n"NOR, me);

		wood->move(environment(me));

		for(i=0;i<sizeof(guy);i++)
		{
			if(userp(guy[i]))
			{
				message_vision(HIR"$N�Q���U�Ӫ����Y�����F�I\n"NOR, guy[i]);
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
