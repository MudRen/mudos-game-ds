// use.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
         string item, arg1;
          object target;
	
	seteuid(getuid());
        if(me->is_ghost()) return notify_fail("	�A�{�b�٬O����a\n");
	if( me->is_busy() )
		return notify_fail("( �A�W�@�Ӱʧ@�٨S�������M����ϥΪ��~�C)\n");

	if( !arg ) return notify_fail("���O�榡�Ruse <���~> [<�Ѽ�>]\n");
	if( sscanf(arg, "%s %s", item, arg1)==2 )
	{
		target = present(item, me);
		if( !target ) target = present(item, environment(me));
		if( !target ) 
		{
			target = environment(me);
			arg1 = arg;
		}
	}
	else
	{
		target = present(arg, me);
		if( !target ) target = present(arg, environment(me));
		if( !target )
		{
			target = environment(me);
		}
	}
	
	if(!target) return 0;
	if(!arg1) arg1 = arg;
	if(wizardp(me) && me->query("env/debug")) write(" target = "+base_name(target)+" .. arg = "+arg1+"  ..\n");
	//if(target!=environment(me)) return notify_fail("�o�� "+target->name()+" �ä���o��ϥΡC\n");
	return target->do_use(me,arg1);
}

int help (object me)
{
        write(@HELP
���O�榡�Ruse <�D��W��> [<�Ѽ�>]��[<��H>]
 
�ϥΪ��~, �����O���W�����D�� �άO �ж��̭������D��.
 
HELP
        );
        return 1;
}
