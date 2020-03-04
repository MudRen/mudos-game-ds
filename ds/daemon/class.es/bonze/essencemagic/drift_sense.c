// drift_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("�԰����L�k�ϥιC�ѯ��q�T\n");
	if( me->query("atman") < 75 )
		return notify_fail("�A���F�O�����T\n");
	if( target )
		return notify_fail("�C�ѯ��q�u���ۤv�ϥΡT\n");
	write("�A�n���ʨ���@�ӤH����S");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	object ob;

	if( !name || name=="" ) {
		write("����I�k�C\n");
		return;
	}

	ob = find_player(name);
	if( !ob || !me->visible(ob) || wizardp(ob) )
		ob = find_living(name);
	if( !ob || !me->visible(ob) || wizardp(ob) ) {
		write("�A�L�k�P����o�ӤH���F�O ....\n");
		write("�A�n���ʨ���@�ӤH����S");
		input_to( (: call_other, __FILE__, "select_target", me :));
		return;
	}
	if( me->is_fighting() ) {
		write("�԰����L�k�ϥιC�ѯ��q�T\n");
		return;
	} else if( me->query("atman") < 75 ) {
		write("�A���F�O�����T\n");
		return;
	}

	me->add("atman", -75);
	me->receive_damage("gin", 30);
	
	message_vision( HIY "$N�C�Y���ءM�}�l�I�i�C�ѯ��q ....\n" NOR, me);
	if( random(ob->query("max_atman")) < (int)me->query("atman") / 2 ) {
		write("�A�P�����誺�F�O�M���O�����j�P�C\n");
		return;
	}
	if( random(me->query_skill("magic")) < (int)ob->query("atman") / 50 ) {
		write("�A�]���������m�ӥ��ѤF�C\n");
		return;
	}
	message( "vision", HIY "\n�@�Dģ�������~���M�n��" + me->name() 
		+ "�M�X������M���~�M�H�@�������o�L�v�L�ܡT\n\n", environment(me), ({ me }) );
	me->move(environment(ob));
	message( "vision", HIY "\n�A�����e��M�X�{�@��ģ�������~�M���~���B�{�X�@�ӤH�v�T\n\n" NOR,
		environment(ob), ({ me }) );
}

