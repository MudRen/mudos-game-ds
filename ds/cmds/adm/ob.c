// id.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i, j;
	object obj, *inv;
	string *id,sec;

	if( !arg ) {
		inv = all_inventory(me);
		if( !sizeof(inv) )
			return notify_fail("�A���W�S������F��C\n");
        write( "�A(�p)���W��a���~���O�٦p�U(�k��) :\n");
		for(i=0; i<sizeof(inv); i++)
		{
			if( !me->visible(inv[i]) ) continue;
			if(inv[i]->query("secured")) sec=" (�O�@��)"; else sec="";
			printf("%-20s = %O\n", inv[i]->name()+sec,inv[i]);
		}
		return 1;
	}

	if( arg=="here" && wizardp(me))
	{
		inv = all_inventory(environment(me));
		if( !sizeof(inv) )
			return notify_fail("�o�̨S������F��C\n");
        	write( "�b�o�өж���, �ͪ��Ϊ��~��(�^��)�W�٦p�U :\n");
		for(i=0; i<sizeof(inv); i++)
		{
			if(!me->visible(inv[i]) ) continue;
			if(inv[i]->query("secured")) sec=" (�O�@��)"; else sec="";
			printf("%-20s = %O \n", inv[i]->name()+sec,inv[i]);
		}
		return 1;
	}
}
int help(object me)
{
write(@HELP
���O�榡 : id
	   id [here]	�Ův�M��
 
�o�ӫ��O�i�H���A���D���~���^��W�٤ΦW�r. �u�� id �|���
�A���W����a���~���W��. 

�Ův�i�H�� 'id here' ����ܩҦ���A�b�P�@�����Ҹ̪�����W��.

 Also see: [search]

HELP
    );
    return 1;
}
 
