// Room: /d/wiz/courthouse.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "法院");
	set("long", @LONG
這裡是夢幻七域的巫師審問機器人的法院﹐你一定是被人檢舉或是
行為太像機器人﹐才會來到這裡﹐如果你答不出審判官的三個問題﹐會
被做上記號﹐錯誤超過三次的人將會被處以極刑﹐好好回答吧。

	回答方法是用[answer]這個指令，格式為: answer <數字>


LONG
	);
	set("no_fight", 1);
	set("no_cast", 1);
	set("no_exert", 1);
	set("no_recall", 1);
	set("light", 1);
	set("objects", ([
		__DIR__"npc/judge":1 ]) );

	setup();
}

void init()
{
/*
	add_action("no_quit","quit");
	add_action("no_drop","drop");
	add_action("no_give","give");
*/
//        add_action("no_get","get");
        if( !wizardp(this_player()) && !this_player()->is_npc() )
	{
		add_action("do_action", "", 1);
		write(BEEP"");
	}
}

int no_quit(string arg)
{
	write("你現在不能Quit!!\n");
	return 1;
}
int no_drop(string arg)
{
	write("你現在不能Drop指令!!\n");
	return 1;
}
int no_give(string arg)
{
	write("你現在不能使用Give指令!!\n");
	return 1;
}
int no_get(string arg)
{
	write("你現在不能使用Get指令!!\n");
	return 1;
}

void test_me(object me)
{
	me->set_temp("old_startroom", me->query("startroom"));
	me->set("startroom", __FILE__);
	me->set_temp("last_location", base_name(environment(me)));
	message_vision("忽然一陣閃光罩住了$N。\n", me);
	me->move(this_object());
}

int do_action()
{
        if ( (string)query_verb() == "answer" )
        { return 0; }
        if ( (string)query_verb() == "tchat" )
        { return 0; }
        if ( (string)query_verb() == "look" )
        { return 0; }
        write("Sorry, 在法院還是安份點好。"NOR""WHT"注意: 在這裡能用的指令只有:\n  tchat, answer\n"NOR);
	return 1;
}
