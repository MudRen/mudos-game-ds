// Last Modified by winder on Apr. 25 2001
// pi1.c 裨將 玄武內門
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("裨將", ({ "pi jiang", "pi", "jiang" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "這是一個大宋年輕將領，滿臉征塵。\n");
	set("combat_exp", 45000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 10);

	setup();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query_temp("guosc_mis_flag")==2)
	{
		say("裨將皺了皺眉：這位" + RANK_D->query_respect(ob) + "，你還是安心守城吧。\n");
	}	
	else if(ob->query_temp("guosc_mis_flag")==1)
	{
		say("裨將拱手說道：這位" + RANK_D->query_respect(ob) + "，你來得正是時候，蒙古靼子已經快攻上城了。\n");
	}
	if(ob->query_temp("guosc_mis_flag")==3)
	{
		say("裨將拱手說道：這位" + RANK_D->query_respect(ob) + "，你已經可以回去覆命了。\n");
		return;
	}
}

