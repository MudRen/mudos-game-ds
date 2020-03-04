// team.c

#include <ansi.h>

inherit F_CLEAN_UP;
string show_team_member(object me);
int main(object me, string arg)
{
	object *t;
        seteuid(getuid());

	if( !arg ) {
		if( !pointerp(t = me->query_team()) )
			return notify_fail("�A�{�b�èS���ѥ[���󶤥�C\n");
		write(show_team_member(me));
		return 1;
	}
	
	// team dismiss
	if( arg=="dismiss" )
	{
		if( !pointerp(t = me->query_team()) )
			return notify_fail("�A�{�b�èS���ѥ[���󶤥�C\n");
		if( me->is_team_leader() )
		{
			message("team", HIW "�i����j" +me->name(1) + "�M�w�N����Ѵ��C\n"+NOR, t, me);
			write("�A�N����Ѵ��F�C\n");
		}
		 else
		{
			message("team",HIW "�i����j" + me->name(1) + "�M�w��������C\n"+NOR, t, me);
			write("�A�����F"+(me->query_team_leader())->name(1)+"������C\n");
		}
		me->dismiss_team();
		return 1;
	}
	
	// team with <�Y�H>
	if( sscanf(arg, "with %s", arg)==1 )
	{
		object ob,ob_leader;

		if( !(ob = present(arg, environment(me)))
		||	!living(ob)
		||	!ob->is_character()
		||	ob==me )
			return notify_fail("�A�Q�M�֦����٦�S\n");

		if( ob_leader=ob->query_team_leader() )
		{
			if(ob!=ob_leader)
			return notify_fail("���w�g�O "+ob_leader->name(1)+"�p�� �������F�C\n");
		}

		if( !pointerp(me->query_team()) || me->is_team_leader() ) //�S������Τw�g�O����
		{
		  if( me==(object)ob->query_temp("pending/team") )  //����ܽйL
		  {
			if( !pointerp(me->query_team()) ) //�����S������
			{
				ob->add_team_member(me);
				message_vision("$N�M�w�[�J$n������C\n", me, ob);
				
			}
			 else //������ӥB�O����
			{
				me->add_team_member(ob);
				message_vision("$N�M�w��$n�[�J����C\n", me, ob);
			}
			ob->delete_temp("pending/team");
			return 1;
		   }
		   else  //�S���Q�ܽЬ���
		   {
		   	if(ob==ob_leader)
		   	{
		   	 message_vision("$N�Ʊ��[�J$n������C\n", me, ob);
			 tell_object(ob, YEL "�p�G�A�@�N�M�Х� team with " + me->query("id") + "�C\n" NOR);
			 me->set_temp("pending/team", ob); //�]�wob���n�D��H
			 return 1; 
			}
			
			message_vision("$N�ܽ�$n�[�J$P������C\n", me, ob);
			tell_object(ob, YEL "�p�G�A�@�N�[�J�M�Х� team with " + me->query("id") + "�C\n" NOR);
			me->set_temp("pending/team", ob); //�]�wob���n�D��H
			return 1;
		   }
		}
		else
		return notify_fail("�u�������S�i�H�ܽЧO�H�[�J�C\n");
	}
	
	// team talk <�T��>
	if( sscanf(arg, "talk %s", arg)==1 ) {
		if( !pointerp(t=me->query_team()) )
			return notify_fail("�A�{�b�èS���M�O�H�զ�����C\n");
		message("team", HIW "�i����j" + me->name(1) + "�R" + arg + "\n" NOR, t);

		return 1;
	}

	// team form <�}�k>
	if( sscanf(arg, "form %s", arg)==1 )
	{
		if( !pointerp(t=me->query_team()) || !me->is_team_leader() )
			return notify_fail("�A�����O�@�Ӷ����S�~���´�}�ΡC\n");
		if( !me->query_skill(arg, 1) )
			return notify_fail("�o�ذ}�ΧA�S�ǹL�C\n");
		return SKILL_D(arg)->form_array(me);
	}
	
	// team attack <�}�k>
	if( sscanf(arg, "form %s", arg)==1 )
	{
		if( !pointerp(t=me->query_team()) || !me->is_team_leader() )
			return notify_fail("�A�����O�@�Ӷ����S�~���´�}�ΡC\n");
		if( !me->query_skill(arg, 1) )
			return notify_fail("�o�ذ}�ΧA�S�ǹL�C\n");
		return SKILL_D(arg)->form_array(me);
	}
}

string show_team_member(object me)
{
 string str,mark;
 object *t;
 int i=0;
 t = me->query_team();
 str="\n�A�{�b������������R\n\n";
 while(i<sizeof(t))
 {
  if(i==0) mark="[�ⶤ]"; else mark="      ";
  if(t[i]==me) mark+=HIG;
  str+=mark+t[i]->name(1);
  str+="("+t[i]->query("id")+")";
  str+=NOR+"\n";
  i++;
 }
 str+="\n";
 return str;

}

int help(object me)
{
	write(@HELP
������O�ϥΤ�k:

team with <�Y�H> - ��Y�H�զ�����. �����n���賣�P�N�[�J�~�|�ͮġC
team dismiss     - ���}����. �Y�U�����O���O�ⶤ, �h��Ӷ���|�Ѵ��C
team talk <�T��> - �򶤥�̨�L���H�͸�, �i�H�� tt <�T��> ���N�C
team form <�}�k> - �p�G����ⶤ�ǹL�}�k���ܡM�i�H�N�����������´��
                   �Y�ذ}�ΡM�զ��}�Ϊ����A�u�n��S�@���ʴN�|�Ѱ��C

�����U team ���O�ɫh�|��ܧA�ثe�O�_���[�J����ζ����W��C

��: team �� follow �O�W�ߪ��M�A���@�w�n follow �����S�C
HELP
	);
	return 1;
}
