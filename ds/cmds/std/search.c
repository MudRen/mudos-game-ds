// id.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	
	if(me->is_busy()) return notify_fail("�A���W�@�Ӱʧ@�٨S�����C\n");
	if(me->query("mp")<5) return notify_fail("�A����O����, �L�k�i��j�d�ʧ@�C\n");
	if(!arg) return notify_fail("�A�n�j�d����? \n");
	if( arg=="here" )
	{
		message_vision("$N�}�l�J�Ӫ��ˬd�o�Ӧa��...\n",me);
		me->start_busy(2);
		me->add("mp",-5);
		call_out("do_search",4,me);
		return 1;
	}
	else 
	{
	 ob=present(arg, environment(me));
	 if(!ob) ob=present(arg, me);
	 if(!ob)
	 {
	  notify_fail("�o�̨S���o�ӪF��C\n");
	  return environment(me)->do_search(me,arg);
	 }
	 if(!ob->do_search(me,arg)) return notify_fail("�A�J�Ӫ��j�d"+ob->name()+"���O�S������o�{�C\n");
	 return 1;
	}
}

void do_search(object me)
{
	int i,j,k,detect_lv;
         object *inv;
	string output,temp,*item_name;
	mapping item;
	output="";
		inv = all_inventory(environment(me));
		if( !sizeof(inv) )
		{
		 tell_object(me,"\n�b�J�Ӫ��j�d����, �A�S���o�{����i�ê��F��C\n");
		 return;
		}
		temp="";
		detect_lv=1+random(me->query_skill("perception")/25);
		me->add_temp("detect",detect_lv);
		for(i=0; i<sizeof(inv); i++)
		{
			temp="";
			if(inv[i]==me) continue;
			if( inv[i]->query_temp("hide") || inv[i]->query_temp("invis") )
			{
				j++;
				if( !me->visible(inv[i]) )  continue;
				else
				{
				 if(inv[i]->query_temp("hide")) temp+=HIY"(����)"NOR;
				 if(inv[i]->query_temp("invis")) temp+=HIG"(����)"NOR;
				 inv[i]->add_temp("visible_ob",({me}));
				 j--;
				}
			}
			k++;
			output+=sprintf("%s %s\n",temp, inv[i]->short());
		}
		me->add_temp("detect",-detect_lv);
		item=environment(me)->query("item_desc");
		if(mapp(item))
		{
			item_name=keys(item);
			for(i=0; i<sizeof(item_name); i++)
			{
				k++;
				output+=sprintf(" %s\n",item_name[i]);
			}
		}
	
		if(k>0)
		{
		 output=sprintf("\n�g�L�J�Ӫ��j�d, �A�o�{�o�̦�:\n\n%s\n",output);
		 if(j>0) output+="�ӥB������G���L�z���I�l�n�C\n";
		}
		else if(j>0)
		     {
		     	output="\n\n �g�L�J�Ӫ��j�d����, �A�S���o�{����F��, ���O�A�`�N����񦳷L�z���I�l�n�C\n\n";
		     } else output="\n\n �g�L�J�Ӫ��j�d����, �A�S���o�{����i�ê��F��C\n";
		tell_object(me,output+">");
		return;
}

int help(object me)
{
write(@HELP
���O�榡 : search [here || ���~]
 
�o�ӫ��O�i�H���A�J�ӷj�d�@�өж�.
 
HELP
    );
    return 1;
}
 
