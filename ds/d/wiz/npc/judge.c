// judge.c

#include <login.h>
#include <ansi.h>

inherit NPC;

int in_ask, answer;

string *gender_num(int num)
{
	string *output;
	switch(num)
	{
		case 1:
			output = ({
					"    �i�i  ",
					"      �i  ",
					"      �i  ",
					"      �i  ",
					"      �i  "
				});
			break;
		case 2:
			output = ({
					"  �i�i�i�i",
					"        �i",
					"  �i�i�i�i",
					"  �i      ",
					"  �i�i�i�i"
				});
			break;
		case 3:
			output = ({
					"  �i�i�i�i",
					"        �i",
					"  �i�i�i�i",
					"        �i",
					"  �i�i�i�i"
				});
			break;
		case 4:
			output = ({
					"    �i�i  ",
					"  �i  �i  ",
					"�i    �i  ",
					"�i�i�i�i�i",
					"      �i  "
				});
			break;
		case 5:
			output = ({
					"  �i�i�i�i",
					"  �i      ",
					"  �i�i�i�i",
					"        �i",
					"  �i�i�i�i"
				});
			break;
		case 6:
			output = ({
					"  �i�i�i�i",
					"  �i      ",
					"  �i�i�i�i",
					"  �i    �i",
					"  �i�i�i�i"
				});
			break;
		case 7:
			output = ({
					"  �i�i�i�i",
					"        �i",
					"        �i",
					"        �i",
					"        �i"
				});
			break;
		case 8:
			output = ({
					"  �i�i�i�i",
					"  �i    �i",
					"  �i�i�i�i",
					"  �i    �i",
					"  �i�i�i�i"
				});
			break;
		case 9:
			output = ({
					"  �i�i�i�i",
					"  �i    �i",
					"  �i�i�i�i",
					"        �i",
					"        �i"
				});
			break;
		default:
			output = ({
					"  �i�i�i�i",
					"  �i    �i",
					"  �i    �i",
					"  �i    �i",
					"  �i�i�i�i"
				});
	}
	return output;
}

int number_quest()
{
	string output="",*str1,*str2;
	int first,second,i;
	first = 1+random(9);
	second = random(10);
	str1 = gender_num(first);
	str2 = gender_num(second);
	for(i=0;i<5;i++)
	{
		output+=str1[i]+" ";
		output+=str2[i];
		output+="\n";
	}
	output+="\n";
	tell_room(environment(this_object()),BEEP"\n"+output);
	return first*10+second;
}
void create()
{
	set_name("�f�P�x", ({ "judge" }) );
	set("short", "�M����I�����H��" HIY "�f�P�x" NOR "(judge)" );
	set("long",
		"�o�O�@��f�d���a�O�_�O�����H���f�P�x�M�A��������(answer)�L�T�Ӱ��D�~��\n"
		"�����L���x���C\n");

	set("gender", "�k��");
	set("title","�ѼC��");
	set("age", 40);
	set("combat_exp", 9000000);
	set("level", 100);
	set_temp("apply/armor", 500);
	set_temp("apply/attack", 200);
	set_temp("apply/damage", 500);

	setup();

	in_ask = 0;
}

void init()
{
	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_answer", "answer");
}

void chat()
{
	string oper;
	
	if( in_ask || random(20) > 10 ) return;
	delete_temp("wrong");
	answer = number_quest();		

	command("say �W�����Ʀr�O�h��? �Цb�Q���@��(answer)�C");
	in_ask = 1;
	foreach(object ppl in all_inventory(environment(this_object())))
	{
                if( userp(ppl) && !wizardp(ppl) )
		{
			if( ppl->query_temp("accusing_robot") >= 20 )
			{
                                "/cmds/wiz/putjail"->main(this_object(), ppl->query("id")+" because 2");
				ppl->delete_temp("accusing_robot");
			}
			else ppl->add_temp("accusing_robot", 1);
		}
	}
	call_out("say_answer", 10);
}

void say_answer()
{
	command("say �o��²�泣���|�S���׬O " + answer + "�C");
	in_ask = 0;	
}

int do_answer(string arg)
{
	string s;
	int ans;

	if( !in_ask ) return notify_fail("�A�������U�@�D�C\n");
	if( !arg ) return notify_fail("�ЧA�^���@�ӼƦr�C\n");

	message_vision( CYN "$N���D�R" + arg + "\n" NOR, this_player());
	
	if( sscanf(arg, "%d", ans)==1 ) {
		if( ans==answer ) {
			this_player()->add_temp("robot_check", 1);
			command("say ����F�T");
			command("pat " + this_player()->query("id") );
			remove_call_out("say_answer");
			in_ask = 0;
			if( this_player()->query_temp("robot_check") >= 3 ) {
				command("say �ܦn�M�A�ݰ_�Ӥ��������H�M�A�i�H���F�C\n");
				if( stringp(s = this_player()->query("accuse_position")) )
					this_player()->set("startroom", s);
                                this_player()->delete_temp("robot_check");
                                this_player()->delete_temp("accusing_robot");
				if( stringp(s = this_player()->query("accuse_position")) )
					this_player()->move(s);
				else
					this_player()->move(START_ROOM);
			}
		} else {
			command("say ���T");
			add_temp("wrong/" + this_player()->query("id"), 1);
			if( query_temp("wrong/" + this_player()->query("id")) > 3 )
			{
				command("say " + this_player()->name() + "�A�A���ڶòq�ڡM�h���a�C\n");
                this_player()->receive_damage("hp", 1, this_object());
                this_player()->move(__DIR__"judge_room");
                this_player()->start_busy(5);
                call_out("go_die",2,this_player());
			} else if( query_temp("wrong/" + this_player()->query("id")) == 3 )
			{
				command("say " + this_player()->name() + "�A���ڪ`�N!! �A�òq���ܱN�B�H���D�C\n");
			}
		}
	}
	return 1;
}

void go_die(object ppl)
{
  if(!ppl || !environment(ppl)) return;
  ppl->die();
  return;
}
