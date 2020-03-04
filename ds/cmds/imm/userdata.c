/*  
userdata.c

*/

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mixed main(object me, string arg)
{
	object *all;
	string msg="";
	
	all = filter(users(), (: objectp(environment($1)) && !wizardp($1) :));

	all = sort_array(all, "sort_user", this_object());
	foreach(object ppl in all)
	{
		
		msg = sprintf("%s�i %2d��|%4d�� �j%20s %-14s  �ݩ�[ %4d ]\n",
                    	msg,
                    	ppl->query("level"),
                    	ppl->query("age"),
			ppl->query("name"),
                    	"(" + capitalize(ppl->query("id")) + ")",
                    	ppl->query_total_gift()
                );
        }
    msg = sprintf("�� ���a�ݩʱƦ�:\n"
	"�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"
	"%s�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"
	"�@�C�X %d ��ϥΪ�\n",
	msg, sizeof(all));

    me->start_more(msg);
    return 1;
}

int sort_user(object ob1, object ob2)
{
    return ob2->query_total_gift()-ob1->query_total_gift();
}

int help(object me)
{
    write(@HELP
userdata : ���a�ݩʩM�C��
HELP
	);
    return 1;
}
