#include <ansi.h>

int ghost_heal(object ob);
int ghost_kill(object ob);

int ghost_heal(object ob) 
{
	if( ob->is_busy() )	return 1;
         if( ob->query("hp") > ob->query("max_hp")/2 ) return 1;
	message_vision( CYN "\n$N"+ CYN "�R�q�@�n�A���W�_�X�}�}�ͮ�...\n" NOR,ob);
	ob->receive_heal("hp",ob->query("hp")/10 );
	return 1;
}

int ghost_kill(object ob)
{
	if(ob->is_busy() ) return 1;
	switch(random(3) ) {
	case 0:
                message_vision(HIM "\n$N���������@�{�A���ۨ��l�S�W�e�@�B..\n" NOR,ob);
		ob->attack();
	break;
	case 1:
		message_vision(RED "$N�Q�F�Q�g�b�ջȾԥҤW���Q�Q�A��....\n" NOR,ob);
		ob->receive_heal("hp",ob->query("hp")/10 );
	break;
	case 2:
		message_vision(HIY "\n$N�Y�W�������в��o�X�@�}ģ�������~�A�A�X�G�ָC���}�����F......\n" NOR,ob);
		ob->query_enemy()->start_busy(1);
	break;
	}
	return 1;
}
