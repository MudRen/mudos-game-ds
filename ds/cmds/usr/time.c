// time.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object env;
	int a;

	env = environment(me);
	a = NATURE_D->which_world(env);
	write(NATURE_D->game_time(a) + "�C\n");
	return 1;
}

int help(object me)
{
     write(@HELP
���O�榡: time

�o�ӫ��O���A(�p)���D�{�b���ɨ��C

HELP
    );
    return 1;
}
