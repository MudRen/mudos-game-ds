// Last Modified by Sir 2003.11.
// teamjob.c
#include <ansi.h>
mixed address = ({
	({
	"�����~��","�C�s�~��","�ժ�~��","�ȪZ�~��","�Ѧw��","�ȧ��[","�F���x",
	"�u�{�n��","�F�{�n��","�Ѹ��G��","�ϫB��","�n����","��s�n��",
	"�Ŷ����","�ߦ{��","���|��","��p��","�s����","���s�Y","���դѦ�",
	"�Ѥs�}�U","�R�K�|","��u�x","���Ѯp","������","�P���[","�׫n�s�}",
	"��l��","�ɥP�{","������","�ȧ��[","�m���I�|","�L�q�U","���a��", 
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
		tell_object(ob,"���t��A���D�G���A���Z�\�Ӯt�F�A���m�j�F�A�ӧa�C��\n");
		return 1;
	}
	if(guo->query("jxjob_start"))
	{
		tell_object(ob,"���t��A���D�G���w�g���^���e�h���I�l�ӤF�A�A�ݥh�������p��H��\n");
		return 1;
	}
	team=ob->query_team();
	count=sizeof(team);
	if(count<=1)
	{
		tell_object(ob,"���t��A���D�G���N�դU�@�ӤH�������ᦹ�����a�H��\n");
		return 1;
	}
	if(count>=5) 
	{
		tell_object(ob,"���t��A���D�G�����ƨ������j�A���y�i���I��\n");
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
		tell_object(ob,"���t��A���D�G���Ѧ�Z�\�ۮt�ӹL�a��A���������Ҧ������I��\n");
		return 1;
	}
	if (flag == 1)
	{
		tell_object(ob,"���t��A���D�G���A��������H�٨S�������ȩO�I��\n");
		return 1;
	}
	// ���\�˴�
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
	tell_object(ob,"���t��A���D�G���ڭ�o������A���@�W�X�j�l�Ӱ��s�F����
���������K���C�A�̻��֥h"+where+"�]�����I�A�m�����N
�a�P��(xiaohui)�C�X�j�H�֩w�|���L�����L�A�h�[�p�ߡC��\n");
message("channel:sys", HIR"�i���I�l�ӡj"+ob->query("name")+"�ӽЪ��I"+ob->query_temp("guojx_mis_where")+"�l�ӥ��ȡC\n"NOR, users());
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
		message_vision(HIY "��M���q���ǰ{�X�@���X�jŶ�l�A��������ۤ@���ܭ��H�A���^�^�A���G��ۭn���}�I\n"NOR, ob);
		message_vision(HIY "$N�ĵ��ܭ��H�j�ܤ@�n�G�j�x�l�ӡA���F���������ϡA�ٷQ�]��H\n"NOR, ob);
		message_vision(HIY "�ܭ��H�@�ݨƱ����S�A�g�����w�G�N�̧A�̴X�Ӥ]�Q�צ�ڪ��h���H\n"NOR, ob);
		for(j=0;j<time;j++)
		{
		for(i=0;i<count;i++)
		{
			lvl = random(20);
			obj=new(__DIR__"mengbing");
			if (lvl >16 )
			{   
				obj->do_copy( maxexp,3);
				obj->set("title",HIY"�X�j�d�Ҫ�"NOR);
			}
			else if (lvl > 8 )
			{ 
				obj->do_copy( maxexp,2);
				obj->set("title",HIY"�X�j�ʤҪ�"NOR);
			}
			else 
			{
				obj->do_copy( maxexp,1);
				obj->set("title",HIY"�X�j�L�h"NOR);
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
			tell_object(team[i], HIY "\n�l�Ӱ����ȥX�F����A�A�̪����ȥ��ѤF�I\n" NOR);
		}
	} 
	return;
}
