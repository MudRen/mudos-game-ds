// passwd.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object ob;

	if( me != this_player(1) ) return 0;

	ob = me->query_temp("link_ob");
	if( !ob ) return 0;
	while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

	write("���F�w���_���M�Х���J�z��Ӫ��K�X�R");
	input_to("get_old_pass", 1, ob);
	return 1;
}

private void get_old_pass(string pass, object ob)
{
	string old_pass;

	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("�K�X���~�T\n");
		return;
	}
	write("�п�J�s���K�X�R");
	input_to("get_new_pass", 1, ob );
}

private void get_new_pass(string pass, object ob)
{
	write("\n�ЦA��J�@���s���K�X�R");
	input_to("confirm_new_pass", 1, ob, crypt(pass,0));
}

private void confirm_new_pass(string pass, object ob, string new_pass)
{
	write("\n");
	if( crypt(pass, new_pass)!=new_pass ) {
		write("�藍�_�M�z��J���K�X�ä��ۦP�M�~��ϥέ�Ӫ��K�X�C\n");
		return;
	}
	seteuid(getuid());
	if( !ob->set("password", new_pass) ) {
		write("�K�X�ܧ󥢱ѡT\n");
		return;
	}

	ob->save();
	write("�K�X�ܧ󦨥\\�C\n");
}

int help(object me)
{
	write(@HELP
���O�榡 : passwd
 
�o�ӫ��O�i�H�ק�A���H���K�X�C
 
HELP
    );
    return 1;
}
 
