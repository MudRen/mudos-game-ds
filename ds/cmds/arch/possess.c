// possess.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg || me != this_player(1)) return 0;
	ob = present(arg, environment(me));
	if( !ob || !living(ob))
		return notify_fail("�o�̨S���o�ӥͪ��C\n");
	if( geteuid(ob) != geteuid(me) )
		return notify_fail( ob->name() + "�� euid �M�A���X�M�L�k�i������C\n");
	if( ob->query_temp("body_ob") )
		return notify_fail( ob->name() + "�w�g�Q�H�����L�F�C\n");
	message_vision("$N�Ʀ��@�D���~�p�i$n�餺�C\n", me, ob);
	LOGIN_D->enter_world(me, ob, 1);

	return 1;
}

int help()
{
	write(@TEXT
���O�榡�Rposssess <�ؼХͪ�>

������t�@�ӥͪ��W�M�o�ӥͪ������M�A���ۦP�� EUID�C
������� quit ���O�|�^���Ӫ�����C
TEXT
	);
	return 1;
}
