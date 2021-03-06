
inherit NPC;

void create()
{
	set_name("伊吹虎正", ({ "hunjun ibuki", "hunjun", "ibuki" }) );
	set("nickname", "和老爸勢不兩立");
	set("gender", "男性");
	set("class","fighter");
	set("age", 21);
	set("adv_class",1);
	set("class1","虎正流");
	set("long",
"伊吹虎正看來不怎麼高大，但是你可以感到他無比的堅毅，\n"
"顯現在他的臉上。自己還超脫他老爸和空手道家族的境界，\n"
"自創了自己的流派，實力不可小覷。\n"

	);
	set("attitude", "peaceful");
	set("level",50);
	set("guild_skills",([
		"dodge" : ({140,2,50}),
		"parry" : ({140,2,50}),
		"unarmed":({150,2,55}),
		"hunjun":({160,2,40}),
	])  );
	set_skill("unarmed", 100);
	set_skill("parry", 90);
	set_skill("dodge", 90);
	set_skill("hunjun",100);
	set_temp("apply/armor",50);
            set("chat_chance_combat", 90);
            set("chat_msg_combat", ({
            	 (:command("exert hunjun"):),
       	 }) );
	
	create_family("【虎正流】空手道", 1, "創始者");
	setup();
     //carry_object(__DIR__"eq/cloth")->wear();
     //carry_object(__DIR__"wp/dragon-fist")->wield();
}

void init()
{
::init();
            add_action("do_skill_list","list");
            add_action("do_skill_train","train");
	add_action("do_advance","advance");
	add_action("do_join","join");
}

int do_skill_list(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();
	if(me->query("class1")=="虎正流" )
		return GUILDMASTER->do_advance(ob,me,arg);
	else 
		return notify_fail("你不是【虎正流】空手道的弟子。\n");

	return GUILDMASTER->do_skill_list(ob,me,arg);	
}

int do_skill_train(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();
	if(me->query("class1")=="虎正流" )
		return GUILDMASTER->do_advance(ob,me,arg);
	else 
		return notify_fail("你不是【虎正流】空手道的弟子。\n");
	return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
	int i;
	object ob, me;

	ob = this_object();
	me = this_player();

	i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);

	message_vision("$N想學習「"+ arg+ "」。\n",me);	

	switch(i)
	{

	case -1: return notify_fail("你已經有門派了。....o_o\n");
	case -2: return notify_fail("你已經是【虎正流】空手道的弟子了。\n");
	case -8: return notify_fail("沒有這種門派耶....x_x\n");
	}
	if(me->query_temp("rbook") )
		command("say "+ RANK_D->query_respect(me) +"，還沒有幫我送禮物嗎？\n");
	else	
	{
		command("say 嗯，是可以教你，但是在之前，請你先幫我送一本詩集給河村麻希");
		me->set_temp("rbook",1);			
	}
    	if (me->query_temp("bookok",1) )
	   {
		command("smile");
		command("say 謝謝，我都知道了，我就教你【虎正流】空手道吧。");
		me->set("adv_class",1);
		me->set("class1","虎正流");
 		me->create_family("【虎正流】空手道",2,"弟子");
 		me->delete_temp("bookok");
	}	

	return 1;
}

int do_advance(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	if(me->query("class1")=="虎正流" )
		return GUILDMASTER->do_advance(ob,me,arg);
	else 
		return notify_fail("你不是【虎正流】空手道的弟子。\n");
}
