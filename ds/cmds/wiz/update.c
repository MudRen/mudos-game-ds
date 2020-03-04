// update.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int update_player(object me);

int main(object me, string file)
{
	int i;
	object obj, *inv;
	string err;

	seteuid( geteuid(me) );

	if (!file) file = me->query("cwf");
	if (!file)
		return notify_fail("�A�n���s�sĶ�����ɮסS\n");

	if( (obj = present(file, environment(me))) && interactive(obj) )
		return update_player(obj);

	if( file == "me" )
		return update_player(me);
	else {
		file = resolve_path(me->query("cwd"), file);
		if( !sscanf(file, "%*s.c") ) file += ".c"; 
	}

	if( file_size(file)==-1 )
		return notify_fail("�S���o���ɮסC\n");

	me->set("cwf", file);

	if (obj = find_object(file)) {
		if( obj==environment(me) ) {
			if( file_name(obj)==VOID_OB )
				return notify_fail("�A����b VOID_OB �̭��s�sĶ VOID_OB�C\n");
			inv = all_inventory(obj);
			i = sizeof(inv);
			while(i--)
				if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
				else inv[i] = 0;
		}
		destruct(obj);
	}

	if (obj) return notify_fail("�L�k�M���µ{���X�C\n");

    write("���s�sĶ " + file + "�R");
	err = catch( call_other(file, "???") );
	if (err)
		printf( "�o�Ϳ��~�R\n%s\n", err );
	else {
		write("���\\�T\n");
		if( (i=sizeof(inv)) && (obj = find_object(file))) {
			while(i--)
				if( inv[i] && userp(inv[i]) ) inv[i]->move(obj, 1);
		}
	}
		
	return 1;
}

int update_player(object me)
{
	object env, link_ob, obj;

	env = environment(me);

	// First, create the new body.
	link_ob = me->query_temp("link_ob");
	obj = LOGIN_D->make_body(link_ob);
	if (!obj) return 0;

	// Save the data and exec the player to his/her link object.
	me->save();
	exec(link_ob, me);
	destruct(me);

	// Restore new body and exec to it via enter_world in LOGIN_D
	obj->restore();
	LOGIN_D->enter_world(link_ob, obj, 1);

	write("�����s�����C\n\n");
	obj->move(env);
	obj->write_prompt();

	return 1;
}

int help(object me)
{
  write(@HELP
���O�榡 : update <�ɦW|here|me|���a�W>
 
�o�ӫ��O�i�H��s�ɮ�, �ñN�s�ɪ����e���J�O���餺. �Y�ؼЬ�
'here' �h��s�Ҧb����. �Y�ؼЬ� 'me' �h��s�ۤv���H��. �Y��
�Ь����a�h�i��s���a����.
 
HELP
    );
    return 1;
}
 
