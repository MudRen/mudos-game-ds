// Last Modified by winder on Apr. 25 2001
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"�x���K��"NOR, ({ "mi jian"}));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@�ʭx���K��A�O�����������u�x���L�O���p�C\n");
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
	if(!arg||arg!="mi jian") return notify_fail("�A�n�P������H\n");
	if(ob->query_temp("host")!= me->query("id") ||
		!me->query_condition("guojx_mis") ||
		!me->query_temp("guojx_mis_tcount"))
		return notify_fail("�o��Ʀn���M�A�S���Y�a�H\n");
	if (!present("mi jian",me) )
		return notify_fail("�A���W�S���K��C\n"); 
	message_vision("$N�q�h���ǥX�@�u�����I�U�F�K��C\n"+HIR"�uť�u�F�v���@�n�A�K��b�����C�C�Ƭ����u�C\n"NOR, me);
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
        log_file("mission/guo_team",sprintf("%-20s �����I�l�ӥ�����o %-5s �g�� %-5s ���",team[i]->query("name")+"("+team[i]->query("id")+")",exp,pot));
				team[i]->add("potential",pot);
				team[i]->add("combat_exp",exp);
	team[i]->set_temp("prize_reason","����");
	team[i]->set_temp("can_give_prize",1);
	team[i]->set_temp("prize_exp",exp);
	team[i]->set_temp("prize_pot",pot);
				tell_object(team[i],HIW"�A�Q���y�F�G" + 
				chinese_number(exp) + "�I��Ըg��A" +
				chinese_number(pot) + "�I���C\n"+ NOR);
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

