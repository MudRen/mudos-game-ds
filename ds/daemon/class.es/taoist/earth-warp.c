// earth-warp.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
	if( me->is_fighting() )	return notify_fail("�A���b�԰����T\n");
	
	if( (int)me->query("mana") < 90 ) return notify_fail("�A���k�O�����F�T\n");
	if( (int)me->query("sen") < 10 ) return notify_fail("�A���믫���������T\n");

	sheet->set_name(YEL "���ɶǰe��" NOR, ({ "earth-warp sheet", "sheet"}) );	
	sheet->set("attach_func", (: call_other, __FILE__, "do_warp", arg :) );
	me->add("mana", -90);
	me->receive_damage("sen", 10);

	return 1;
}

int do_warp(string target, object who)
{
	object env;

	if( who && who!=this_player() )
		return notify_fail("���ɶǰe�ťu���ۤv�ϥΡC\n");

	env = environment(this_player());
	message("vision",
		HIB + this_player()->name() + "���_�@�i���ɶǰe�šC\n\n"
		"���M�|�P�j�_�F�@�}�D�B�B�������M���������ϩ����\\�h�H�v�b�̰�...\n\n"
		"�M��@�}������M�z�_�T\n" NOR, env);
	DROP_CMD->main(this_player(), "all");
	this_player()->move(DEATH_ROOM);
	message("vision",
		CYN "�i�O...." + this_player()->name() + "�w�g�����F�C\n" NOR, env);
	message("vision",
		CYN "�A�uı�o���l���_�U�Y�M�@���U�Y�M�@���U�Y�M�@���U�Y�M�@���U�Y .....\n\n"
		NOR	"�����D����ɭԡM�A�o�{�A���@�������b��w���a���W�M�i�O�|�P������\n\n"
			"�o���@�ˤF....\n", this_player() );
	
	return 1;
}
