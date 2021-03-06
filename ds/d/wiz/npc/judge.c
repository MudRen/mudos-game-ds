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
					"    ██  ",
					"      █  ",
					"      █  ",
					"      █  ",
					"      █  "
				});
			break;
		case 2:
			output = ({
					"  ████",
					"        █",
					"  ████",
					"  █      ",
					"  ████"
				});
			break;
		case 3:
			output = ({
					"  ████",
					"        █",
					"  ████",
					"        █",
					"  ████"
				});
			break;
		case 4:
			output = ({
					"    ██  ",
					"  █  █  ",
					"█    █  ",
					"█████",
					"      █  "
				});
			break;
		case 5:
			output = ({
					"  ████",
					"  █      ",
					"  ████",
					"        █",
					"  ████"
				});
			break;
		case 6:
			output = ({
					"  ████",
					"  █      ",
					"  ████",
					"  █    █",
					"  ████"
				});
			break;
		case 7:
			output = ({
					"  ████",
					"        █",
					"        █",
					"        █",
					"        █"
				});
			break;
		case 8:
			output = ({
					"  ████",
					"  █    █",
					"  ████",
					"  █    █",
					"  ████"
				});
			break;
		case 9:
			output = ({
					"  ████",
					"  █    █",
					"  ████",
					"        █",
					"        █"
				});
			break;
		default:
			output = ({
					"  ████",
					"  █    █",
					"  █    █",
					"  █    █",
					"  ████"
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
	set_name("審判官", ({ "judge" }) );
	set("short", "專門對付機器人的" HIY "審判官" NOR "(judge)" );
	set("long",
		"這是一位審查玩家是否是機器人的審判官﹐你必須答對(answer)他三個問題才能\n"
		"脫離他的掌握。\n");

	set("gender", "男性");
	set("title","書劍版");
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

	command("say 上面的數字是多少? 請在十秒內作答(answer)。");
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
	command("say 這麼簡單都不會﹖答案是 " + answer + "。");
	in_ask = 0;	
}

int do_answer(string arg)
{
	string s;
	int ans;

	if( !in_ask ) return notify_fail("你必須等下一題。\n");
	if( !arg ) return notify_fail("請你回答一個數字。\n");

	message_vision( CYN "$N答道﹕" + arg + "\n" NOR, this_player());
	
	if( sscanf(arg, "%d", ans)==1 ) {
		if( ans==answer ) {
			this_player()->add_temp("robot_check", 1);
			command("say 答對了﹗");
			command("pat " + this_player()->query("id") );
			remove_call_out("say_answer");
			in_ask = 0;
			if( this_player()->query_temp("robot_check") >= 3 ) {
				command("say 很好﹐你看起來不像機器人﹐你可以走了。\n");
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
			command("say 錯﹗");
			add_temp("wrong/" + this_player()->query("id"), 1);
			if( query_temp("wrong/" + this_player()->query("id")) > 3 )
			{
				command("say " + this_player()->name() + "你再給我亂猜啊﹐去死吧。\n");
                this_player()->receive_damage("hp", 1, this_object());
                this_player()->move(__DIR__"judge_room");
                this_player()->start_busy(5);
                call_out("go_die",2,this_player());
			} else if( query_temp("wrong/" + this_player()->query("id")) == 3 )
			{
				command("say " + this_player()->name() + "你給我注意!! 再亂猜的話將處以極刑。\n");
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
