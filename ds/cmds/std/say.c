// say.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  string name,gender;
  switch(me->query("gender"))
  {
  	case "�k��": gender="�p"; break;
  	default : gender="�A";	
  }
  if(!environment(me)) return notify_fail(gender+"���b��L�ƴ���, ���໡�ܡC\n");
  if(me->query_temp("invis")) name = "�Y�H";
  else name =  me->name();
	if (!arg) {
		write(YEL+gender+"�ۨ��ۻy�����D�b���Ǥ���C\n"NOR);
		message("sound",YEL + name + "�ۨ��ۻy�����D�b���Ǥ���C\n"NOR,
			environment(me), me);
		return 1;
	}
	
	if(arg[sizeof(arg)-1..] == "?")
	{
		write( YEL+gender+"�@�y�ôb�����R" + arg + "\n"NOR );
		message("sound", YEL + name + "�@�y�ôb�����R" +  arg + "\n"NOR ,
			environment(me), me);
	}
	else if(arg[sizeof(arg)-1..] == "!")
	{
		write( YEL+gender+"�E�ʪ����R" + arg + "\n"NOR );
		message("sound", YEL + name + "�E�ʪ����R" +  arg + "\n"NOR ,
			environment(me), me);
	}
	else
	{
		write( YEL+gender+"���R" + arg + "\n"NOR );
		message("sound", YEL + name + "���R" +  arg + "\n"NOR ,
			environment(me), me);
	}
	
	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
���O�榡: say <�T��>
 
���ܡM�Ҧ���A�b�P�@�өж����H���|ť��A�����ܡC
 
��: �����O�i�� ' ���N.
 
HELP
	);
	return 1;
}
