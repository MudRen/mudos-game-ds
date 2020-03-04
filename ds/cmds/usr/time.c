// time.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object env;
	int a;

	env = environment(me);
	a = NATURE_D->which_world(env);
	write(NATURE_D->game_time(a) + "。\n");
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: time

這個指令讓你(妳)知道現在的時辰。

HELP
    );
    return 1;
}
