// force_push.c
// mulder 我只幫你寫被攻擊者被移到別格房間的程式...
// 剩下的部分你應該自己寫囉....還有...被攻擊者能不能到那間房間
// 也要你自己把它完成...就降子...
//					Shengsan@DS
inherit SSERVER;
inherit SKILL;

int cast(object me, object target)
{
	mapping exit=([ ]);
	string to_dir,to_dir_name,*dir,*dir_name;
	int i;
	object env;

	if(!me) me=this_player();

	env = environment(me);

	if(env->query("no_cast")) return notify_fail("這裡不能施法。\n");

	if ( !target ) target = offensive_target(me);
	if ( !target )	return notify_fail("你要對誰施展這個法術﹖\n");

	exit = env->query("exits");
	dir_name = keys(exit);
	dir = values(exit);

// debug 用....
//	for(i=0;i<sizeof(dir);i++)
//	{
//		write(i+" :"+dir[i]+"\n");
//	}
	i = random(sizeof(dir));
	to_dir = dir[i];
	to_dir_name = dir_name[i];
	target->move(to_dir);
	write( target->query("name")+"被莫名之力推至 "+to_dir_name+" 了\n");

	return 1;
}