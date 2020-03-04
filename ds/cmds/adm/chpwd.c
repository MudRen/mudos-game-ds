/*	File : "/cmds/adm/chpwd.c"	*
 *	Author : "Alickyuen@DS"		*
 *	Last modify : 2002�~8��15��	*/

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object ob, link;
	string id, passwd;

      if(!arg || sscanf(arg, "%s %s", id, passwd) != 2 )
		return notify_fail("���O�榡�Gchpwd <player id> <new passwd>�C\n");

	if( !ob = find_player(id) ) 
		return notify_fail("���a�G"+id+"�ä��b�u�W�C\n");

	if( sizeof(passwd) < 4 )
		return notify_fail("�K�X�̤֥|�Ӧ�C\n");

	link = ob->query_temp("link_ob");

	link->set("password", crypt(passwd, 0));
//(find_player(arg)->query_temp("link_ob"))->set("password", crypt("1234", 0));
	return 1;
}
