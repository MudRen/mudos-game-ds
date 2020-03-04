// dump.c (should be admin cmd?)
#include <ansi.h>
inherit F_CLEAN_UP;
int sort_item(object ob1, object ob2);
int main(object me,string arg)
{
	object *ob;
	string output="",temp;
	int i,j,size,check;
	seteuid(geteuid(me));
	ob=livings();
	ob = sort_array(ob, "sort_item", this_object());
	size=sizeof(ob);
	j=1;
    	if(arg && arg=="add") check=1;
    	for(i=0;i<size;i++)
    	{	
    		if(i<size-1 && base_name(ob[i])==base_name(ob[i+1]) && base_name(ob[i])!="/obj/user")
    		{
    			j++;
    			continue;
    		}
    		output+=sprintf("%4d  %-6s "+NOR+"%-10s  %-16s (%d)\n",i,userp(ob[i])? HIR"User->":"",ob[i]->query("name"),ob[i]->query("id"),j);
    		j=1;
    		if(check && !userp(ob[i]) && strsrch(base_name(ob[i]),"/open/world")!=-1 && strsrch(ob[i]->query("id")," ")==-1)
    			IDCHECK_D->set_mob_id(me,ob[i],0);
    	}
	me->start_more(output);
	return 1;
}
int sort_item(object ob1, object ob2)
{
	string file1,file2;
	if(userp(ob1) && !userp(ob2)) return 1;
	if(!userp(ob1) && userp(ob2)) return -1;
	file1=base_name(ob1);
	file2=base_name(ob2);
	return strcmp(file1,file2);
}

int help(object me)
{
	write(@HELP
���O�榡 : lifelist
 
�C�X�Ҧ��� living objects [use livings()].

HELP
    );
    return 1;
}
 
