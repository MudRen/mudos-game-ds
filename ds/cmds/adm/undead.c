// id.c
#include <ansi.h>
inherit F_CLEAN_UP;
void creat()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object undead_ob,shadows;
	int check;
	seteuid( geteuid(me) );
	undead_ob=load_object("/feature/undead");
	if(!undead_ob) return notify_fail("��������򥢡C\n");
	if(arg=="?")
	{
		shadows = query_shadowing( me );
		if(shadows) write(sprintf("%s ����v����O: %O\n",me->name(),shadows));
		shadows = query_shadowing( undead_ob );
		if(shadows) write(sprintf("%s ����v����O: %O\n",base_name(undead_ob),shadows));
		return 1;
	}
	if(arg == "off")
	{
		shadows = query_shadowing( undead_ob );
		if(!shadows) return notify_fail("���������èS�����{�o�ӥ@�ɡC\n");
		if(shadows!=me) return notify_fail("���������èS�����b�A�����W�C\n");
		remove_shadow(undead_ob);
		message_vision("�@�}�¼v�ƹL�A�����������}�F$N������C\n",me);
		return 1;
	}
	if(shadows = query_shadowing( undead_ob ))
	{
		if(shadows==me) return notify_fail("���������w�g���b�A�����W�F�C\n");
		return notify_fail(sprintf("%s ����v����O: %O\n",base_name(undead_ob),shadows));
	}
	check = undead_ob->apply_undead(me);
	if(check)
	{
		message_vision(HIW+"\n\t��M�������}�}�A$N�Q������������F!!\n\n"+NOR,me);
		return 1;
	}
	else return notify_fail("�L�k�I�s������������C\n");
}
int help(object me)
{
write(@HELP
���O�榡 : undead
 
�Q��shadow�ܦ�������.

HELP
    );
    return 1;
}
 
