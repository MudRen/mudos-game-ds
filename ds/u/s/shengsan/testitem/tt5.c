#include <ansi.h>
inherit ITEM;

mixed *sortinv(object env);

void create()
{
	set_name(HIC"�ŤѴ��ջ�(�ѱ�)"NOR,({"tt5"}));
	set("long","�o�O�@�Ӥ��Ŵ��ջ��C\n");
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("value",9999);
	}
	setup();
}

void init()
{
	add_action("do_tt5","tt5");
}

int do_tt5(string arg)
{
	object me,ob;
	
	me = this_player();

	if(!arg)
		return notify_fail("�Ы��w��H!!\n");

	ob = present(arg, environment(me));
	if (!ob) ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("�o�̨S���o�ӤH!!\n");

	if( ob == me )
		return notify_fail("�A�ѱϧA�ۤv�F����?\n");

	if( !ob->is_fighting() )
		return notify_fail(ob->query("name")+"�ثe�èS�������H�b�԰�, �A�ѱϽ֪�?\n");

	if( me->is_fighting_ob(ob) )
		return notify_fail("�A���b��"+ob->query("name")+"�԰��C...���h�ѱϥL��...\n");
	if( ob->is_fighting_ob(me) )
		return notify_fail(ob->query("name")+"���b��A�԰��C...���h�ѱϥL��...\n");

	if( ! ob->relieve(me) )
		return notify_fail(me->query("name")+"�ѱ�"+ob->query("name")+"����ʥ��ѤF...\n");
	else tell_object(me,"�ѱϦ��\\�F�T\n");

	return 1;
}
