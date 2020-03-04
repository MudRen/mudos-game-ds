// Last Modified by winder on Apr. 25 2001
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"軍機密件"NOR, ({ "mi jian"}));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "封");
		set("long", "一封軍機密件，記載著襄陽城守軍的兵力部署。\n");
		set("value", 0);
		set("material", "paper");
	}
}
void init()
{    
	add_action("do_xiaohui", "xiaohui");
}
int do_xiaohui(string arg)
{
	int i,exp,pot,count,base_exp,time;
	object ob,me,*team;
	me=this_player();
	ob=this_object();
	if(!arg||arg!="mi jian") return notify_fail("你要銷毀什麼？\n");
	if(ob->query_temp("host")!= me->query("id") ||
		!me->query_condition("guojx_mis") ||
		!me->query_temp("guojx_mis_tcount"))
		return notify_fail("這件事好像和你沒關係吧？\n");
	if (!present("mi jian",me) )
		return notify_fail("你身上沒有密件。\n"); 
	message_vision("$N從懷中掏出一只火折點燃了密件。\n"+HIR"只聽「轟」的一聲，密件在火中慢慢化為灰燼。\n"NOR, me);
	count=me->query_temp("guojx_mis_tcount");
	if (count<2) count=2;	
	base_exp=300;
	time = me->query_temp("guojx_mis_time",time);
	team=me->query_team();
	count=sizeof(team);
	for(i=0;i<count;i++)
	{
		if(team[i]!=0)
		{
			if (team[i]->query_condition("guojx_mis"))
			{
				exp=base_exp*time + random(300);
				pot=exp/3+random(100);
        log_file("mission/guo_team",sprintf("%-20s 做阻截奸細任務獲得 %-5s 經驗 %-5s 潛能",team[i]->query("name")+"("+team[i]->query("id")+")",exp,pot));
				team[i]->add("potential",pot);
				team[i]->add("combat_exp",exp);
	team[i]->set_temp("prize_reason","狙擊");
	team[i]->set_temp("can_give_prize",1);
	team[i]->set_temp("prize_exp",exp);
	team[i]->set_temp("prize_pot",pot);
				tell_object(team[i],HIW"你被獎勵了：" + 
				chinese_number(exp) + "點實戰經驗，" +
				chinese_number(pot) + "點潛能。\n"+ NOR);
				team[i]->delete_temp("guojx_mis_tcount");
				team[i]->delete_temp("guojx_mis_where");
				team[i]->delete_temp("guojx_mis_flag");
				team[i]->delete_temp("guojx_mis_time");
				team[i]->delete_temp("guojx_mis_max");
				team[i]->clear_condition("guojx_mis");
			}
		} 
	}
	destruct(this_object());
	return 1;
}

