#include <ansi.h>

int ghost_heal(object ob);
int ghost_kill(object ob);

int ghost_heal(object ob) 
{
	if( ob->is_busy() )	return 1;
	message_vision( CYN "\n$N"+ CYN "�R�q�@�n�A���W�_�X�}�}�ͮ�...\n" NOR,ob);
	ob->receive_heal("hp",ob->query("hp")/10 );
	return 1;
}

int ghost_kill(object ob)
{
	return 1;
}
