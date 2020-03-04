#include <ansi.h>
inherit NPC;
void create()
{
	set_name("不知名的刀客",({"unknown blade man","man"}));
	set("long" ,
    "此人碧眼紫鬚, 面貌有如神聖, 長得霸氣十足, 人高八尺三寸, 十分高大, \n"
    "不過你卻無法認出他到底是哪一位江湖中的高手, 不過你知道最好還是少惹他\n"
    "為妙, 一看就知道此人絕非普通人物, 你或許\可以問問他是誰?(say 你是誰).\n"
    );
	set("attitude", "peaceful"); 
	set("level",51);
	set("age",58);
	set("chat_chance",10);
    set("chat_msg",({
			 (:command,"exert dragonblade":),
			 (:command,"exert dragonfist":),
			 (:command,"exert dragonsteps":)}));
	set("chat_chance_combat",70);
	set("chat_msg_combat",({(:command,"exert dragonfist dragon-voice":),
				(:command,"exert dragonsteps":),
				(:command,"exert dragonblade":)}));
	set_skill("unarmed",90);
	set_skill("blade",90);
	set_skill("dodge",95);
	set_skill("force",90);
	set_skill("parry",90);
	set_skill("dragonblade",95);
	set_skill("dragonfist",95);
	set_skill("dragonsteps",95);
	set("guild_gifts",({6,7,2,5}));
	setup();
	carry_object(__DIR__"eq/dragonblade")->wield();
	carry_object(__DIR__"eq/dragonring")->wear();
	carry_object(__DIR__"eq/dragonbelt")->wear();
	carry_object(__DIR__"eq/dragonboots")->wear();
	carry_object(__DIR__"eq/dragoncloth")->wear();
	carry_object(__DIR__"eq/dragoncloak")->wear();
	carry_object(__DIR__"eq/dragonarmor")->wear();
}
void init()
{
	add_action("do_say","say");
}
int do_say(string arg)
{
	object me,obj;
	me=this_player();
	obj=this_object();
	if(arg=="你是誰" && me->query_temp("talk/whoareyou") < 4)
	{
		if(me->query("level") < 25 && me->query_temp("talk/whoareyou") < 4) 
		{
			command("hmm");
			command("say 看來你還沒有資格問我是誰。");
			me->add_temp("talk/whoareyou",1);
		}
		else if(me->query("level") > 24 && me->query("level") < 41 && me->query_temp("talk/whoareyou") < 4)
		{
			command("hmm "+me->query("id"));
			command("say 閣下有何貴幹?");
			me->add_temp("talk/whoareyou",random(2));
		}
		else if(me->query("level") > 40)
		{
			command("look "+me->query("id"));
			command("say 我乃七海遊龍 -- 龍嘯天! 閣下若願意與我比試比試, 就算瞧得起我吧!");
			obj->set_name("龍嘯天",({"shout tan long","long"}));
			obj->set("title",HIC"七海遊龍"NOR);
			command("fight "+me->query("id"));
		}
	}
	else if(arg=="你是誰" && me->query_temp("talk/whoareyou") > 3)
	{
		command("angry");
		command("say 煩吶! 你找死!");
		obj->kill_ob(me);
	}
	else return 0;
}
