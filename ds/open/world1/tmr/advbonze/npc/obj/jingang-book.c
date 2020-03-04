#include <ansi.h>

inherit ITEM;

int do_learn(string arg);

void create()
{
	set_name("����ù�~�}�k���",({"jingang plan book","book"}) );
	set_weight(80);
	set("long",@long
�o�O�@���p����A�W�Y�O���ۡu����ù�~�}�k�v�������έ����k�C(learn)
long
);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit","��");
		set("value",0);
	}
	setup();
}
void init()
{
	add_action("do_learn","learn");
}

int do_learn(string arg)
{
	object me=this_player();
	if(arg!="book")	return 0;
	if(me->is_fighting() || me->is_busy() )
                return notify_fail("�A�����ۡA�S�ž\\Ū���y�C\n");
	if( query("do_learn") )
		return notify_fail("�o������w�g�Q½�}��F�A�A�L�k�q�W���Ǩ쪾�ѡC\n");
	if(me->query_skill("jingang-plan") > 80)
		return notify_fail("�A���u����ù�~�}�k�v�w�g��F�@�w���ԡA���ΦA�\\Ū�o���ѤF�C\n");

	message_vision(HIC "$N�ӲӾ\\Ū�F����W���t�m��k�A���G�����ù�~�}�k�S�h���m�@�ǤF�C\n" NOR,me);
               me->add_skill("jingang-plan");
	set("do_learn",1);
return 1;
}
