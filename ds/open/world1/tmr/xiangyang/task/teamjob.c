// Last Modified by Sir 2003.11.
// teamjob.c
#include <ansi.h>
mixed address = ({
	({
	"朱雀外門","青龍外門","白虎外門","玄武外門","天安門","玄妙觀","靈隱寺",
	"泉州南門","靈州南門","諸葛亮殿","煙雨樓","南陽城","佛山南門",
	"衡陽西街","喜州城","葛魯城","伊犁城","山海關","老龍頭","長白天池",
	"天山腳下","麗春院","湧泉寺","五老峰","紫金城","鬆風觀","終南山腳",
	"抱子岩","升仙坊","嘉應門","玄妙觀","峻極禪院","俠義廳","蕭家橋", 
	}),
});

int ask_jianxi()
{
	object ob,guo;
	object *team;
	int i=0,count=0,time,minexp,maxexp,flag;
	string where;
	ob=this_player();
	guo=this_object();

	if(ob->query("combat_exp")<500000) 
	{
		tell_object(ob,"郭靖對你笑道：“你的武功太差了，等練強了再來吧。”\n");
		return 1;
	}
	if(guo->query("jxjob_start"))
	{
		tell_object(ob,"郭靖對你笑道：“已經有英雄前去阻截奸細了，你看去幫幫忙如何？”\n");
		return 1;
	}
	team=ob->query_team();
	count=sizeof(team);
	if(count<=1)
	{
		tell_object(ob,"郭靖對你笑道：“就閣下一個人恐怕難擔此重任吧？”\n");
		return 1;
	}
	if(count>=5) 
	{
		tell_object(ob,"郭靖對你說道：“此事事關重大，不宜張揚！”\n");
		return 1;
	}
	minexp=team[0]->query("combat_exp");
	maxexp=minexp;
      
	for(i=1;i<count;i++)
	{
		if(team[i]!=0)
		{
			if(team[i]->query("combat_exp")<minexp)
				minexp=team[i]->query("combat_exp");
			if(team[i]->query("combat_exp")>maxexp)
				maxexp=team[i]->query("combat_exp");
			if((int)team[i]->query_condition("guojx_mis"))
				flag = 1;
		}
	}
	if ((maxexp-minexp)>2000000)
	{
		tell_object(ob,"郭靖對你說道：“諸位武功相差太過懸殊，恐難完成所托重任！”\n");
		return 1;
	}
	if (flag == 1)
	{
		tell_object(ob,"郭靖對你說道：“你的隊伍中有人還沒完成任務呢！”\n");
		return 1;
	}
	// 成功檢測
	where=address[0][random(sizeof(address[0]))];
	time = 3 + random(3);
	for(i=0;i<count;i++)
	{
		team[i]->set_temp("guojx_mis_tcount",count);
		team[i]->set_temp("guojx_mis_where",where);
		team[i]->set_temp("guojx_mis_flag",1);
		team[i]->set_temp("guojx_mis_time",time);
		team[i]->set_temp("guojx_mis_max",maxexp);
		team[i]->apply_condition("guojx_mis",60);
	}
	guo->set("jxjob_start",1);
	call_out("guojxjob",30,ob,maxexp,time);
//	call_out("new_start_jxjob",1200,guo);
	call_out("new_start_jxjob",300,guo);
	tell_object(ob,"郭靖對你說道：“我剛得到消息，有一名蒙古奸細偷盜了襄陽
城防的機密文件。你們趕快去"+where+"設防阻截，搶到文件後就
地銷毀(xiaohui)。蒙古人肯定會派兵接應他，多加小心。”\n");
message("channel:sys", HIR"【阻截奸細】"+ob->query("name")+"申請阻截"+ob->query_temp("guojx_mis_where")+"奸細任務。\n"NOR, users());
	return 1;
}

int new_start_jxjob()
{ 
   this_object()->delete("jxjob_start", 1);
}


void guojxjob(object ob,int maxexp,int time)
{
	object *team,obj,gift;
	int i=0,j=0,count,knum,lvl,flag = 999;
	
	team=ob->query_team();
	count=sizeof(team);
	for(i=0;i<count;i++)
	{
		if ((int)team[i]->query_condition("guojx_mis"))
		{
			if ( team[i]->query_temp("guojx_mis_flag") == 1 )
				flag = 0;
			else if( flag != 0 && team[i]->query_temp("guojx_mis_flag") == 2 )
				flag = 1;
		}
	}
	if ( flag == 0 )
	{
		ob->remove_call_out("guojxjob");
		call_out("guojxjob",10,ob,maxexp,time);
		return;
	}
	if(environment(ob)->query("short")==ob->query_temp("guojx_mis_where")&& (int)ob->query_condition("guojx_mis"))
	{
		message_vision(HIY "突然間從路旁閃出一隊蒙古韃子，隊伍中夾雜著一個幪面人，行色匆匆，似乎急著要離開！\n"NOR, ob);
		message_vision(HIY "$N衝著幪面人大喝一聲：大膽奸細，偷了襄陽城防圖，還想跑麼？\n"NOR, ob);
		message_vision(HIY "幪面人一看事情敗露，狂笑不已：就憑你們幾個也想擋住我的去路？\n"NOR, ob);
		for(j=0;j<time;j++)
		{
		for(i=0;i<count;i++)
		{
			lvl = random(20);
			obj=new(__DIR__"mengbing");
			if (lvl >16 )
			{   
				obj->do_copy( maxexp,3);
				obj->set("title",HIY"蒙古千夫長"NOR);
			}
			else if (lvl > 8 )
			{ 
				obj->do_copy( maxexp,2);
				obj->set("title",HIY"蒙古百夫長"NOR);
			}
			else 
			{
				obj->do_copy( maxexp,1);
				obj->set("title",HIY"蒙古兵士"NOR);
			}
			knum = random(count);
			if (environment(team[knum])->query("short")==ob->query_temp("guojx_mis_where"))
			{     
				obj->move(environment(team[knum]));
				obj->kill_ob(team[knum]);
			}
			else
			{	
				obj->move(environment(ob));
				obj->kill_ob(ob);
			}
		}
		}
	}
	else
	{
		for(i=0;i<count;i++)
		{
			team[i]->delete_temp("guojx_mis_tcount");
			team[i]->delete_temp("guojx_mis_where");
			team[i]->delete_temp("guojx_mis_flag");
			team[i]->delete_temp("guojx_mis_time");
			team[i]->delete_temp("guojx_mis_max");
			team[i]->clear_condition("guojx_mis");
			tell_object(team[i], HIY "\n奸細偷偷溜出了中原，你們的任務失敗了！\n" NOR);
		}
	} 
	return;
}
