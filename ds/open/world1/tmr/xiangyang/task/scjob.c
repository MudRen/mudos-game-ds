#include <ansi.h>
#include <dbase.h>
#include <login.h>
int ask_shoucheng()
{
	object *ene;
	object me,ob; 
	object* ob_list;
	int i;
	
	me = this_player();
	ob = this_object();

	if( ob->query("shoucheng_start") )
	{
		tell_object(me,"���t��A���D�G����~�ϴ����^���w�h�����A�A�ݥh�������p��H��\n");
		return 1;
	}
	if(!me->query("family/family_name"))
	{
		tell_object(me,"���t��A���D�G���L���L���A�����L�v�O�֡H��\n");
		return 1;
	}
	if((int)me->query_temp("guosc_mis_flag") > 0 )
	{
		tell_object(me,"���t���D�G���A���O�w�����ȤF�ܡH��\n");
		return 1;
	}
	if ((int)me->query("combat_exp")<100000)
	{
		tell_object(me,"���t���D�G���A��L�������O�A�٬O�O����Ȫ����n�I��\n");
		return 1;
	}
	if ( (int)me->query_skill("force") < 50 )
	{
		tell_object(me,"���t���D�G���u���O��M�I�u�@�A�ڬݧA���򥻤��\�׬������A���y�_�I�I��\n");
		return 1;
	}
	if ((int)me->query_condition("guosc_mis")>1)
	{
		tell_object(me,"���t��A��F�@�n�D�G���A�J�w���U�����I��i��������¾�u�H���I�^�A���^��h�I��\n");
		return 1;
	}
	ob->set("shoucheng_start", 1);
	call_out("new_start_scjob",900,ob);
	call_out("guosc_begin",30,me);
	me->set_temp("guosc_mis_flag",1);
	me->set_temp("guosc_mis_num",1);

	ob_list = children("/d/xiangyang/task/wandao");
    for(i=0; i<sizeof(ob_list); i++) 
	{
			destruct(ob_list[i]);
    }
	switch( random(4) )
	{
		case 0:
			me->set_temp("guosc_mis_where","�ȪZ����");
			me->apply_condition("guosc_mis",15+random(5));
			tell_object(me,"���t��A�m��D�G���{�b�X�j�ޤl�I�Ǥ���A�лդU�t�h�ȪZ�������U���x�u���a�I��\n");
			break;
		case 1:
			me->set_temp("guosc_mis_where","�C�s����");
			me->apply_condition("guosc_mis",15+random(5));
			tell_object(me,"���t��A�m��D�G���{�b�X�j�ޤl�I�Ǥ���A�лդU�t�h�C�s�������U���x�u���a�I��\n");
			break;
		case 2:
			me->set_temp("guosc_mis_where","��������");
			me->apply_condition("guosc_mis",15+random(5));
			tell_object(me,"���t��A�m��D�G���{�b�X�j�ޤl�I�Ǥ���A�лդU�t�h�����������U���x�u���a�I��\n");
			break;
		case 3:
			me->set_temp("guosc_mis_where","�ժꤺ��");
			me->apply_condition("guosc_mis",15+random(5));
			tell_object(me,"���t��A�m��D�G���{�b�X�j�ޤl�I�Ǥ���A�лդU�t�h�ժꤺ�����U���x�u���a�I��\n");
			break;
	}
	message("channel:sys", HIR"�i�u���������j"+me->query("name")+"�ӽЦu��"+me->query_temp("guosc_mis_where")+"���ȡC\n"NOR, users());
	return 1;
}

int new_start_scjob()
{ 
   this_object()->delete("shoucheng_start", 1);
}

void guosc_begin(object me)
{
	object *target, robber;
	mapping my_fam = me->query("family");
	int i;
	target = users();
	if ( me->query_temp("guosc_mis_flag") == 1 && (int)me->query_condition("guosc_mis") )
	{
		me->remove_call_out("guosc_begin");
		call_out("guosc_begin",10,me);
		return;
	}
	else if ( me->query_temp("guosc_mis_flag") != 3&& (int)me->query_condition("guosc_mis"))
	{
		if ( environment(me)->query("short")!=me->query_temp("guosc_mis_where") )
		{
			me->remove_call_out("guosc_begin");
			call_out("guosc_begin",10,me);
			return;
		}
		else
		{
			for(i=0;i<sizeof(target);i++)
		{
			if(target[i]->query("family/family_name") == my_fam["family_name"] && target[i]->query("id")!=me->query("id"))
			message("vission",HIR"�@�u�����A�媺�F�l����A���e�ǵ��A�@�i�ȱ��G\n"HIW"��������������������������������������������������������
��          �X�j�ޤl�J�I����A"+me->query_temp("guosc_mis_where")+"�Y��I          ��\n�������������������������������������������������������� \n                              "+NOR+CYN+me->query("family/family_name")+" "+me->query("name")+"("+me->query("id")+")\n" NOR,target[i]);
		}
			robber=new(__DIR__"robber1");
			robber->do_change(me);
			robber->move(environment(me));
			message_vision(HIR"��M���U���W�Ӥ@�ӻX�j�L�h�C\n" NOR,me);
			robber->kill_ob(me);
			me->kill_ob(robber);
		}
	}
	else
	{
		me->remove_call_out("guosc_begin");
	}
}

int job_over(string arg)
{
	int job_pot,job_exp;
	object me = this_player();

	if(!arg) return 1;

	if(arg!="over") return 1;
	if(!me->query_temp("guosc_mis_flag"))
	{
		tell_object(me,"���t��A��F�@�n�D�G���A�ڥ��S����ȡA�]���ܥ\�H��\n");
		return 1;
	}
	if(me->query_temp("guosc_mis_flag")!=3)
	{
		tell_object(me,"���t��A��F�@�n�D�G�������٨S�����A�]���ܥ\�H��\n");
		return 1;
	}
	if(me->query_temp("guosc_mis_num")<3)
	{
		tell_object(me,"���t��A��F�@�n�D�G���A���F�X�ӼĤH�A�A�٨ӻ��H��\n");
		me->delete_temp("guosc_mis_flag");
		me->delete_temp("guosc_mis_num");
		me->delete_temp("guosc_mis_where");
		return 1;
	}
	if(me->query_temp("guosc_mis_flag")==3)
	{
		tell_object(me,"���t��F��A���ӻH���D�G��������ġA���������I��\n");
		job_exp=((int)me->query_temp("guosc_mis_num"))*150;
		job_pot=job_exp*1/3;
		job_exp=job_exp;
		if (job_exp>4000) 
			job_exp=4000+(job_exp-4000)/10;
		if (job_pot>1300) 
			job_pot=1300+(job_pot-1300)/2;
    if (job_pot>job_exp/2)
      job_pot=job_exp/2-500;
    log_file("mission/guo_shoucheng",sprintf("%-20s �u�����F%3i�ӻX�j�L�A��o%-5i �g�� %-5i ���\n",me->query("name")+"("+me->query("id")+")",me->query_temp("guosc_mis_num"),job_exp,job_pot));
		me->add("combat_exp", job_exp);
		me->add("potential",job_pot);
	me->set_temp("prize_reason","�u��");
	me->set_temp("can_give_prize",1);
	me->set_temp("prize_exp",job_exp);
	me->set_temp("prize_pot",job_pot);
		tell_object(me, HIW"�A�Q���y�F"+chinese_number(job_exp)+"�I�g��ȡA"+chinese_number(job_pot)+"�I���C\n"NOR);
		me->delete_temp("guosc_mis_flag");
		me->delete_temp("guosc_mis_num");
		me->delete_temp("guosc_mis_where");
		this_object()->delete("shoucheng_start", 1);
		return 1;
	}
}
