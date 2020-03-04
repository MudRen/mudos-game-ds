// hp cmds
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object env,ob;
	string who;
        int amount,amount2;
	if(!arg) return notify_fail("�Х� help remit �d�ߥΪk�C\n");
	if(sscanf(arg,"%s %d",who,amount)!=2)
	{
		if(sscanf(arg,"%d to %s",amount,who)!=2) return notify_fail("�Х� help remit �d�ߥΪk�C\n");
	}
	if(amount < 2) return notify_fail("���B�����j��@�ӳ��C\n");
	if(!env = environment(me)) return 0;
	if(area_domain(base_name(env)) != "world3") return notify_fail("�u�����ӥ@�ɤ~���q�Ǻ����C\n");
	if(me->query("bank/future")< amount) return notify_fail("�A���b���̨S���o��h�q�l���C\n");
	if(!ob = present(who, env))
	{
		if(!ob = find_player(who)) return notify_fail("�S���o�ӤH�C\n");
	}
	if( me == ob ) return notify_fail("���ۤv?�Q�Ǫk�a\n");
	if(!living(ob))
	{
		if(!ob = find_player(who)) return notify_fail("�S���o�ӤH�C\n");
	}
	if(area_domain(base_name(environment(ob)))!="world3") return notify_fail("��褣�b�q�Ǻ���������d��C\n");
	amount2 = amount - amount/20;
	if(amount%20 > 0) amount2 -=1;
	if( !interactive(ob) )
	{
		notify_fail("�q�Ǻ����^���F�@����b���Ѫ��T���C\n");
		if(ob->accept_remit(me,amount2))
		{
			ob->add("bank/future",amount2);
			me->add("bank/futrue",-amount);
			return 1;
		} else return 0;
	}
	tell_object(ob,HIW"�q�Ǻ����q���A: "+me->name(1)+"�ǰe�F"+amount2+"�I�q�l����A���b��C\n"NOR);
	tell_object(me,HIW"�q�Ǻ����^��: �w�ǰe"+amount+"�I�q�l����"+ob->name(1)+"���b��C\n"NOR);
	ob->add("bank/future",amount2);
        me->add("bank/future",-amount);
	return 1;
}
 
int help(object me)
{
        write(@HELP
���O�榡 : remit <who> <�ƶq> �� remit <�ƶq> to <who>
 
�Q�Υ��ӥ@�ɥ��i���q�Ǻ����A�N�A(�p)�b���Ӯɪž֦����s�ڶ׵�
��L�H�A���O�N�|�����״ڪ��B��5%��������O�C

HELP
);

    return 1;
}

