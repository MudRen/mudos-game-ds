// halt.c

#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *obj;
	int i;
	if(wiz_level(me) < 5)
	{
		if( !me->is_fighting() ) return notify_fail("�A�{�b�èS���b�԰��C\n");
		me->remove_all_killer();
		message_vision("$N�ΧŮv�����O����F�o�������C\n", me);
		write("Ok.\n");
		return 1;
	} else
	{
		obj=all_inventory(environment(me));
		for(i=0;i<sizeof(obj);i++)
		{
			obj[i]->remove_all_killer();
		}
		message_vision("$N�Τj�����O�q����F�o�̩Ҧ��������C\n", me);
		return 1;
	}
}

int help(object me)
{
   write(@HELP
���O�榡: halt

�i�H����Ҧ��P�A(�p)�������԰��C
HELP
   );
   return 1;
}
