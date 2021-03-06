// say.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  string name,gender;
  switch(me->query("gender"))
  {
  	case "女性": gender="妳"; break;
  	default : gender="你";	
  }
  if(!environment(me)) return notify_fail(gender+"正在虛無飄渺間, 不能說話。\n");
  if(me->query_temp("invis")) name = "某人";
  else name =  me->name();
	if (!arg) {
		write(YEL+gender+"自言自語不知道在說些什麼。\n"NOR);
		message("sound",YEL + name + "自言自語不知道在說些什麼。\n"NOR,
			environment(me), me);
		return 1;
	}
	
	if(arg[sizeof(arg)-1..] == "?")
	{
		write( YEL+gender+"一臉疑惑的說﹕" + arg + "\n"NOR );
		message("sound", YEL + name + "一臉疑惑的說﹕" +  arg + "\n"NOR ,
			environment(me), me);
	}
	else if(arg[sizeof(arg)-1..] == "!")
	{
		write( YEL+gender+"激動的說﹕" + arg + "\n"NOR );
		message("sound", YEL + name + "激動的說﹕" +  arg + "\n"NOR ,
			environment(me), me);
	}
	else
	{
		write( YEL+gender+"說﹕" + arg + "\n"NOR );
		message("sound", YEL + name + "說﹕" +  arg + "\n"NOR ,
			environment(me), me);
	}
	
	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: say <訊息>
 
說話﹐所有跟你在同一個房間的人都會聽到你說的話。
 
註: 本指令可用 ' 取代.
 
HELP
	);
	return 1;
}
