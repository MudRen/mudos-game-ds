#include <ansi.h>
inherit ITEM;


void create()
{
	set_name(HIY"Naboo Starfighter"NOR,({"Naboo Starfighter","fighter"}));
	set("long","�o�O��Naboo��s�X�Ӫ�����C\n");
	set_weight(3000000);
	set_temp("apply/damage",10);
	set_temp("apply/armor", 15);
	set("no_get",1);
	set("amount",1);
	set("unit","��");
	set("value",10000);
	setup();
}
void init()
{
	add_action("do_ascend","ascend");
	add_action("do_descend","descend");
}

int do_descend()
{
	object me;
	string *name;

	me=this_player();
	if(!me->query_temp("marks/ascend"))
	return notify_fail("�A�w�g���}����F�C\n");
	message_vision("$N�H��"+this_object()->name()+"���w���議�F�U�ӡC\n",me);
	me->delete_temp("marks/ascend");
	me->delete_temp("apply/short");
	move(environment(me));
	return 1;
}

int do_ascend()
{
	object me;

	me=this_player();
	if(me->query_temp("marks/ascend"))
	return notify_fail("�A�w�g�b����n�C\n");
	message_vision("$N�i�J�F"+this_object()->name()+"�������C\n",me);
	me->set_temp("marks/ascend",1);
	me->add_temp("apply/short",({me->short()+HIY"(���������"NOR+this_object()->name()+HIY")"NOR}));
	move(me);
	return 1;
}


