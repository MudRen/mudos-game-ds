// secure.c

inherit F_CLEAN_UP;

int do_sec(object me, object obj,int flag);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
          object obj, *inv;
	int i;
         string item;

	if(!arg) return notify_fail("�A�n�O�s����F��S\n");
	
	if(arg=="all")
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_sec(me, inv[i], 0);
		}
		write("�A�N���W�Ҧ����~�]���O�s���A.\n");
		return 1;
	}

	if(arg=="all off")
	{
			inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++)
			{
				do_sec(me, inv[i], 1);
			}
			write("�A�N���W���Ҧ����~���O�s���A�Ѱ�!!\n");
			return 1;

	}
	
	if(sscanf(arg, "%s off", item )==1)
	{
		if( !objectp(obj = present(item, me)) )
			return notify_fail("�A���W�S���o�˪F��C\n");
		if( !obj->query("secured") )
			return notify_fail("�����èS���]�w�O�s���A�C\n");
		if( do_sec(me, obj, 1) )
		{
			write("�A�N"+obj->name()+"���O�s���A�Ѱ��C\n");
			return 1;
		}
		else notify_fail("�Ѱ��O�s���A���ѡC\n");
	}
	
	if(!objectp(obj = present(arg, me)))
		return notify_fail("�A���W�S���o�˪F��C\n");
	if( obj->query("secured") )
			return notify_fail("�����w�g�O�O�s���A�F�C\n");
	if(do_sec(me, obj, 0))
	{
		write("�A�N"+obj->name()+"�]�w���O�s���A�C\n");
		return 1;
	}
	else notify_fail("�]�w�O�s���A���ѡC\n");
}

int do_sec(object me, object obj,int flag)
{
	if(flag)
	{
		if(obj->query("secured")) obj->delete("secured");
		return 1;
	}
	else
	{
		obj->set("secured",1);
		return 1;
	}
}

int help(object me)
{
	write(@HELP
���O�榡 : secure <���~�W��> [off]
	   sec <���~�W��> [off]

�o�ӫ��O�i�H���A�N�A����a�����~�]�w�O�@�άO�Ѱ�(off).
 
HELP
    );
    return 1;
}
 
