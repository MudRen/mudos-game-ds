// tell.c

#include <ansi.h>
#include <net/i3.h>

inherit F_CLEAN_UP;

int help(object me);

	void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
        if(!wizardp(me) && me->query("talk_point")<1) return notify_fail("�A�{�b�f������, �n���@�U�~���O�𻡸ܳ�!\n");
	if( sscanf(target, "%s@%s", target, mud)==2 )
	{	
		mud = replace_string(mud,"."," ");
		I3_TELL->send_tell(geteuid(me), me->name(1),mud,target,msg);
		write("I3�����T���w�e�X�M�i��n�y�Ԥ~��o��^���C\n");
		return 1;
	}

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("�S���o�ӤH....�C\n");

	if(obj->query("env/auto_reply") && !wizardp(me))
	{
	 if(stringp(obj->query("env/auto_reply"))) 
	 	return notify_fail(HIW+obj->name()+"�y���H�c: "+obj->query("env/auto_reply")+"�C\n");
	 return notify_fail("���w�]�w�ť��Z, ť����A�����ܡC\n");
	}
	write("�A�i�D" + obj->name(1) + "�R" + msg + "\n" NOR);
	tell_object(obj, sprintf( HIW "%s�i�D�A�R[1;37;41m�i %s �j[0m\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));

	obj->set_temp("reply", me->query("id"));
	if(!wizardp(me)) me->add("talk_point",-1);
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) ) {
		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)�i�D�A�R%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s �i�D�A�R%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
���O�榡�Rtell <�Y�H> <�T��>

�A�i�H�γo�ӫ��O�M��L�a�誺�ϥΪ̻��ܡC

	�]�w�ť��Z: set auto_reply < 1 > �� < �۰ʦ^����r >
	�Ѱ��ť��Z: unset auto_reply �άO set auto_reply 0
	
��L�������O�Rreply
HELP
	);
	return 1;
}
