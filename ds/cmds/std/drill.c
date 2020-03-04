// go.c
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

void drill_in(object me,object ground)
{
	message_vision("$N���a�U�p�h�C\n",me);
	me->move(ground);
	tell_room(ground,me->name()+"�q�a���W�p�F�U�ӡC",({me}));
	return ;
}

int main(object me, string arg)
{
	object env,ground;
	string env_file,ground_file;
	env = environment(me);
	env_file=base_name(env);
	if( userp(me) && !wizardp(me) ) return 0;
	write(env_file +"\n");
	
	if(env->query("no_drill")) return notify_fail("�o�̵L�k�P�a�C\n");
	if(sscanf(env_file,"%*s.ug") != 0) return notify_fail("�A�w�g�b�a���F�C\n");
	ground_file = env_file + ".ug";
	if(ground=find_object(ground_file+".c")) drill_in(me,ground);
	else if(ground=load_object(ground_file)) drill_in(me,ground);
	else return notify_fail("�o�̵L�k�P�a�C\n");
	return 1;
}

int help(object me)
{
	write(@HELP
���O�榡 : drill
 
���A�p�J�a�U�C
 
HELP
    );
    return 1;
}
