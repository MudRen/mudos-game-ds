// id.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int i;
        object *inv;
        string str;


	if( !arg ) {
		inv = all_inventory(me);
		if( !sizeof(inv) )
			return notify_fail("�A���W�S������F��C\n");
        write( "�A(�p)���W��a���~���O�٦p�U(�k��) :\n");
		for(i=0; i<sizeof(inv); i++) {
			if( !me->visible(inv[i]) ) continue;
			if(inv[i]->query("secured")) str=" (�O�@��)"; else str="";
			printf("%-20s = %s\n", inv[i]->name()+str,
				implode(inv[i]->parse_command_id_list(), ", ") );
		}
		return 1;
	}

	if( arg=="here" )
	{
		inv = all_inventory(environment(me));
		if( !sizeof(inv) )
			return notify_fail("�o�̨S������F��C\n");
        	write( "�b�o�өж���, �ͪ��Ϊ��~��(�^��)�W�٦p�U :\n");
		if( wizardp(me) )
		{
			for(i=0; i<sizeof(inv); i++)
			{
				if(!me->visible(inv[i]) ) continue;
				printf("%-20s = %s (�ɮ�:%s.c)\n", inv[i]->name(),
				implode(inv[i]->parse_command_id_list(), ", "),base_name(inv[i]));
			}
			return 1;
		}
		else
		{
			for(i=0; i<sizeof(inv); i++)
			{
				if(!me->visible(inv[i]) ) continue;
				printf("%-20s = %s \n", inv[i]->name(),
				implode(inv[i]->parse_command_id_list(), ", ") );
			}
			return 1;
		}
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
 
