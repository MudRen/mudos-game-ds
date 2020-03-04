// kill.c

#include <ansi.h>
inherit F_CLEAN_UP;
inherit SSERVER;
void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{

	object obj,target;
	int k=0;
	if( !arg )
	{
		if(obj=me->query_temp("protecter"))
		{
			write("\n�A���b�O�@"+obj->name(1)+"�C\n");
			k++;
		}
		if(obj=me->query_temp("defender"))
		{
			write("\n"+obj->name(1)+"���b�O�@�A�C\n");
			k++;
		}
		if(!k) write("\n�ثe�S���H�b�O�@�A, �A�]�S���O�@����H�C\n");
		return 1;
	}
	
	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("�o�̨S���o�ӤH�C\n");
	if( !me->visible(obj) )	return notify_fail("�o�̨S���o�ӤH�C\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�ݲM���@�I�M���ä��O�ͪ��C\n");

 	if(!obj->is_fighting()) return notify_fail("���èS���԰��欰, ���ݭn�O�@�C\n");
        if( obj==me ) return notify_fail("�A������|�D�ʫO�@�ۤv���C\n");
	if(obj->query_temp("defender")==me) return notify_fail("�A�w�g�b�O�@�L�F��C\n");
	if(obj->query_temp("protecter")==me) return notify_fail("���Χa...��西�b�O�@�A�C�C\n");
	if(!userp(obj))
        {
		if(!obj->query("can_defend")) return notify_fail("���ڵ��A���O�@�C\n");
	}
	me->set_temp("protecter",obj);
	obj->set_temp("defender",me);
	message_vision("$N��M�Ĩ�$n���e��, �յ���$n�פU�Ҧ��������C\n",me,obj);
	target = offensive_target(obj);
	if(!target) return 1;
	if(target->can_fight(me))
	{
		target->kill_ob(me);
		me->kill_ob(target);
	}
	return 1;
}
int help(object me)
{
  write(@HELP
���O�榡 : defend <�H��>
 
�o�ӫ��O���A�D�ʶ}�l�O�@�@�ӤH��, �o�ӤH�������|�����A, ����A���}����C

HELP
    );
    return 1;
}
 
