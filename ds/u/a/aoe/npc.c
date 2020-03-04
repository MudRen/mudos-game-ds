// npc.c

#include <command.h>
#include <localtime.h>
inherit CHARACTER;
inherit F_CLEAN_UP;

int last_scheduled_time_tag;
/*
object carry_object(string file)
{
	object ob;

	if( !objectp(ob = new(file)) ) return 0;
	ob->move(this_object());
	return ob;
}
*/
int is_npc() { return 1; }

object carry_object(string file,int amount)
{
	object ob;

	// Don't let master copy clone equips
	if( !clonep() ) return load_object(VOID_OB);

	if( !objectp(ob = new(file)) ) return 0;

	// �䴩�ߤ@���~(�tNPC)
	if( ob->violate_unique() ) ob = ob->create_replica();
	if( !ob ) return load_object(VOID_OB);
	if(ob->move(this_object())) return ob;
		else
		{
			ob->move(environment(this_object()));
			log_file( "debug", "/std/npc.c ERROR in carry_object():\n"+
				this_object()->query("name") + "["+base_name(this_object())+"] ������ " + ob->name() +"["+
				base_name(ob)+"] at:" + ctime(time()) + "\n" );
		}

	return ob;
}

object carry_multi_object(string file, int amount)
{
	object ob;
	ob = carry_object(file);
	if( !ob ) return 0;
//	if (!amount) amount == 1;
	ob->set_amount(amount);
}

object add_money(string type, int amount)
{
	object ob;
	int total;
	//�ץ��j�N����
	if(type=="silver")
	{
		type="coin";
		total=amount*60;
	}
	else
	if(type=="gold")
	{
		type="coin";
		total=amount*3000;
	}
	else total=amount;
	ob = carry_object("/obj/money/" + type);
	if( !ob ) return 0;
	ob->set_amount(total);
}

int accept_fight(object who)
{
	string att;

	att = query("attitude");

	if( is_fighting() )	switch(att) {
		case "heroism":
			command("say ��T�X�ۧa�T\n");
			break;
		default:
			command("say �Q�ʦh���ӡM�o���O�ۤH�ӬƶܡT\n");
			return 0;
	}

	if( (int)query("hp") * 100 / (int)query("max_hp") >= 90
	&&	(int)query("mp") * 100 / (int)query("max_mp") >= 90 )
	{
		switch(att)
		{
			case "friendly":
				command("say �j�a���ܦn��, ���ΰʪZ�a�C");
				return 0;
			case "aggressive":
			case "killer":
				command("say ��T�J��ں�A�˷��T\n");
				break;
			default:
				if( !is_fighting() )
					command("say �J�M" + RANK_D->query_respect(who)
						+ "��СM" + RANK_D->query_self(this_object())
						+ "�u�n�^���C\n");
		}
		
		return 1;
	} else
	
		return 0;
}

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
	// Are we at home already?
	if( !environment()
	||	environment()==home )
		return 1;

	// Are we able to leave?
	if( !living(this_object())
	||	is_fighting()
	||	!mapp(environment()->query("exits")) ) return 0;

	// Leave for home now.
	message("vision", this_object()->name() + "��榣���a���}�F�C\n",
		environment(), this_object());
	return move(home);
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int chat()
{
	mixed *msg;
	int chance, rnd;

	if( !environment() ) return 0;

	if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
		return 0;

	if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
		if( random(101) < chance )
		{
			if(sizeof(msg)<1) return 1;
			rnd = random(sizeof(msg));
			if( stringp(msg[rnd]) )	say(msg[rnd]);
			else if( functionp(msg[rnd]) )
				return evaluate(msg[rnd]);
		}
		return 1;
	}
}

// Default chat function: Let the npc random move to another room.
int random_move()
{
	object env;
	mapping exits;
	string *dirs;
	env=environment(this_object());
	if(!env) return 0;
	if( !mapp(exits = env->query("exits")) ) return 0;
	dirs = keys(exits);
	command("go " + dirs[random(sizeof(dirs))]);
}

// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
	if( query_spell(spell) )
		SPELL_D(spell)->cast_spell(this_object(), spell);
}

void cast_spell_dir(string spell,string dir)
{
	object env,target;
	string file;

	if( query_spell(spell) )
	{
		 if(env = environment(this_object()))
		 {
		 	if(stringp(file = env->query("exits/"+dir)))
		 	{
		 	 target = load_object(file);
	 	 	 SPELL_D(spell)->cast_spell_dir(this_object(), spell, target, dir);
		 	} 
		 }
	}
}

// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
	string force_skill;

	if( stringp(force_skill = query_skill_mapped("force")))
		SKILL_D(force_skill)->exert_function(this_object(), func);
}

// Default chat function: Let the npc perform special action with 
// his/her enabled martial art
int perform_action(string action)
{
	object weapon;
	string martial_skill, act;

	if( sscanf(action, "%s.%s", martial_skill, act) != 2 )
		return 0;
	martial_skill = query_skill_mapped(martial_skill);
	if( stringp(martial_skill) )
		return SKILL_D(martial_skill)->perform_action(this_object(), act);		
}

int accept_object(object me, object ob)
{
	return notify_fail(this_object()->name(1)+"���G��"+ob->name()+"�ä��P����C\n");
}

void heart_beat()
{
        mapping schedule;
	
        if( living(this_object()) && !is_busy() )
        {
                chat();
                if( !this_object() ) return;
        }

        if( living(this_object()) && clonep(this_object())
        && mapp(schedule = query("schedule")) )
        {
                mapping gt;
                int time_tag;
                string mark;

                gt = CLOCK_D->query_game_time();
                time_tag = gt[LT_HOUR] ;
                switch(time_tag)
                {
                	case 0: mark="00"; break;
                	case 1: mark="01"; break;
                	case 2: mark="02"; break;
                	case 3: mark="03"; break;
                	case 4: mark="04"; break;
                	case 5: mark="05"; break;
                	case 6: mark="06"; break;
                	case 7: mark="07"; break;
                	case 8: mark="08"; break;
                	case 9: mark="09"; break;
                	case 10: mark="10"; break;
                	case 11: mark="11"; break;
                	case 12: mark="12"; break;
                	case 13: mark="13"; break;
                	case 14: mark="14"; break;
                	case 15: mark="15"; break;
                	case 16: mark="16"; break;
                	case 17: mark="17"; break;
                	case 18: mark="18"; break;
                	case 19: mark="19"; break;
                	case 20: mark="20"; break;
                	case 21: mark="21"; break;
                	case 22: mark="22"; break;
                	case 23: mark="23"; break;
                	default:	
                	mark="00";
                }
                if( time_tag != last_scheduled_time_tag )
                {
			if(!undefinedp(schedule[mark]))
                        {
                        	if( stringp(schedule[mark]) ) say(schedule[mark]);
				else if(functionp(schedule[mark])) evaluate(schedule[mark]); 
                        }
                        last_scheduled_time_tag = time_tag;
                }
                if( !this_object() ) return;
        }

        ::heart_beat();
}
