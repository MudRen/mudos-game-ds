// id.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	
	if(me->is_busy()) return notify_fail("你的上一個動作還沒完成。\n");
	if(me->query("mp")<5) return notify_fail("你的體力不足, 無法進行搜查動作。\n");
	if(!arg) return notify_fail("你要搜查什麼? \n");
	if( arg=="here" )
	{
		message_vision("$N開始仔細的檢查這個地方...\n",me);
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
	  notify_fail("這裡沒有這個東西。\n");
	  return environment(me)->do_search(me,arg);
	 }
	 if(!ob->do_search(me,arg)) return notify_fail("你仔細的搜查"+ob->name()+"但是沒有什麼發現。\n");
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
		 tell_object(me,"\n在仔細的搜查之後, 你沒有發現什麼可疑的東西。\n");
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
				 if(inv[i]->query_temp("hide")) temp+=HIY"(躲藏)"NOR;
				 if(inv[i]->query_temp("invis")) temp+=HIG"(隱身)"NOR;
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
		 output=sprintf("\n經過仔細的搜查, 你發現這裡有:\n\n%s\n",output);
		 if(j>0) output+="而且附近似乎有微弱的呼吸聲。\n";
		}
		else if(j>0)
		     {
		     	output="\n\n 經過仔細的搜查之後, 你沒有發現什麼東西, 但是你注意到附近有微弱的呼吸聲。\n\n";
		     } else output="\n\n 經過仔細的搜查之後, 你沒有發現什麼可疑的東西。\n";
		tell_object(me,output+">");
		return;
}

int help(object me)
{
write(@HELP
指令格式 : search [here || 物品]
 
這個指令可以讓你仔細搜查一個房間.
 
HELP
    );
    return 1;
}
 
