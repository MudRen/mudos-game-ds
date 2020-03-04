// guild.c

inherit ROOM;

void setup()
{
	::setup();
}

void init()
{
	add_action("do_join", "join");
}

int do_join(string arg)
{
	object me;

	me = this_player();
	if( stringp(me->query("class")) )
		return notify_fail("�A�w�g�ѥ[�F��L���|�C\n");
	me->set("class", "fighter");
	me->set("startroom", CLASS_D("fighter") + "/guildhall");
	write("\n���ߡM�q���Ѱ_�z�w�g�����@�W�Z�̡T\n\n");
	return 1;
}

