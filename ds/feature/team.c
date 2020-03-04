// team.c

#include <command.h>
#include <dbase.h>
#include <origin.h>

nosave object leader, *team;
void clean_up_team();
int set_leader(object ob)
{
	if( ob==this_object() )
	{
		leader = 0;
		error("set_leader: �L�k�N�ۤv�]��leader,�t�Φ۰ʲM��leader.\n");
	}
	leader = ob;
}

object query_leader() { return leader; }

protected int follow_path(string dir)
{
//	if( ((int)origin()==ORIGIN_LOCAL) || ((int)origin()==ORIGIN_CALL_OUT) ) {
		//this_object()->remove_all_enemy();
		//tell_object(this_object(),"..\n"); //debug msg
		return GO_CMD->main(this_object(), dir);
//	}
//	tell_object(this_object(),"���O�o���F.\n"); //debug msg
//	return 0;
}

int follow_me(object ob, string dir)
{
	if( !living(this_object()) || ob==this_object() ) return 0;
//	if( !this_object()->visible(ob)) return 0;
	if( ob==leader )
	{
			remove_call_out("follow_path");
			call_out("follow_path", 2, dir);
//			tell_object(this_object(),"�A�ߨ�l�F�L�h.."); //debug msg
			return 1;
	}
	return 0;
}

// �H�U������B�z
//
//

int add_team_member(object ob)
{
	if( ob==this_object() ) return 0;
	clean_up_team();
	if( arrayp(team) ) //������
	{
		if( member_array(ob, team)==-1 ) //ob���bme�����
		{
			team += ({ ob });
			for(int i=sizeof(team)-1; i>=0; i--)
				team[i]->set_team(team);
		} else //�b����h����
			return 0;
	}
	 else
	{
		team = ({ this_object(), ob });
		ob->set_team(team);
	}
	return 1;
}

object query_team_leader()
{
	clean_up_team();
	if(sizeof(team)) return team[0];
	else return 0;
}

int is_team_leader()
{
	clean_up_team();
	return arrayp(team) && team[0]==this_object();
}

int set_team(object *t)
{
	team = t;
	clean_up_team();
}

varargs int dismiss_team(object ob)
{
	int i;

	if( !arrayp(team) ) return 0;
	clean_up_team();
	if( !ob )
	{
		if( team[0]==this_object() )
		{
			for(i=1; i<sizeof(team); i++)
			{
			        tell_object(team[i],"����Q�Ѵ��F�C\n");
				team[i]->set_team(0);
			}
		}
		 else
		{
			for(i=0; i<sizeof(team); i++)
			{
				team[i]->dismiss_team( this_object() );
			}
			if(sizeof(team)==1) team[0]->dismiss_team();
		}
		team = 0;
	} else
		team -= ({ ob });

	return 1;
}

void clean_up_team()
{
	int i;
	
	if( sizeof(team) > 0 )
	{
		if( !objectp(team[0]) || !living(team[0])  ) team = 0;
		else
		{
			for(i=0; i<sizeof(team); i++)
			{
				if( !objectp(team[i]) || (!living(team[i]) ) )
					team[i] = 0;
			}
			team -= ({ 0 });
		}
	}

}


object *query_team()
{
	return team;
}

int team_reward(object victim,object *killers,int k)
{
	object *members=({});
	int i,total_lv,exp;
	string output;
	
	if(userp(victim)) exp=victim->query("exp")/12;
        else exp=victim->query("exp");  // �⥴mob�V�hexp�V�֪��]�w�qteam������ -alick 12 Apr 2005
	total_lv=this_object()->query("level");
	for(i=0;i<sizeof(killers);i++)
	{
	 if( member_array(killers[i], team)!=-1 )
	 {
	 	if(killers[i]==this_player()) continue;
	 	members+=({killers[i]});
	 	total_lv+=killers[i]->query("level");
	 }
	}
	
	message_vision("$N���̫�@�������F$n�C\n",this_object(),victim);

	if( sizeof(members)<1 )
	{
		this_player()->add("exp", exp );
	  	tell_object(this_object(),"  �A�o�� "+exp+" �I�g���!\n" );
	  	return 1;
	} else
	{
		output="[����]  ";
		for(i=0;i<sizeof(members);i++)
		{
	  		members[i]->add("exp", 1+(exp*(members[i]->query("level")))/total_lv );
	  		tell_object(members[i],output+"�A�o�� "+(1+(exp*(members[i]->query("level")))/total_lv)+" �I�g���!\n" );
		}
	}
	return sizeof(members)+1;
}
