// haunt.c

#include <ansi.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
	if( me->is_fighting() )	return notify_fail("�A���b�԰����T\n");
	
	if( (int)me->query("mana") < 20 ) return notify_fail("�A���k�O�����F�T\n");

	if( !arg ) return notify_fail("�A�n�b�o�i�ŤW�g�֪��W�r�S\n");

	sheet->set_name(YEL "�L�Ͱl���" NOR, ({ "haunting sheet", "sheet"}) );	
	sheet->set("attach_func", (: call_other, __FILE__, "do_haunt", arg :) );
	me->add("mana", -20);
	me->receive_damage("sen", 10);

	return 1;
}

int do_haunt(string target, object who)
{
	object dest;

	if( !who->is_zombie() )
		return notify_fail(YEL "�L�Ͱl���" NOR "�u��Φb�L�ͨ��W�C\n");

	if( !who->query("possessed") )
		return notify_fail("�A�������Ϊk�O���" + who->name() + "�~��ϥγo�D�šC\n");

	dest = present(target, environment(who));
	if( !dest ) dest = find_player(target);
	if( !dest ) dest = find_living(target);
	if( objectp(dest) ) {
		who->kill_ob(dest);
		who->set_leader(dest);
		message_vision("$N�������M�C�}�M���a���D�R" RED "��....��....$n....\n" NOR,
			who, dest);
		if( environment(dest)==environment(who) ) {
			dest->fight_ob(who);
		}
	} else {
		message_vision("$N�������M�C�}�M���a���D�R" RED "��....��....��....\n" NOR,
			who);
		if( this_player() ) {
			who->kill_ob(this_player());
			who->set_leader(this_player());
			this_player()->fight_ob(who);
		}
	}
	return 1;
}
