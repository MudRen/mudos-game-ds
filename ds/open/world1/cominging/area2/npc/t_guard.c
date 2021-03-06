#include <ansi.h>
inherit NPC;

string drink();
string eat();

void create()
{
	set_name("守衛塔衛兵", ({ "tower janitor","janitor" }) );
	set("long",
		"一個在守衛塔之中防守步靈城中出口的衛兵，他手上拿著一把長戟，\n"
		"似乎有些沉重的樣子，身上穿著一付皮鎧甲。\n");
	set("level",24+random(2));
        set("age",30+random(3));

	set("combat_exp", 29000);
	set("chat_chance", 10);
        set("chat_msg", ({
  (: command,"idle" :),
  (: drink :),
  (: eat :),
  (: command,"yawn" :),
  (: command,"zzz" :),
  (: command,"say 真累阿∼∼" :),
  (: drink :),
  (: eat :),
  (: drink :),
  (: eat :),
}));
	set("chat_chance_combat", 14);
	set("chat_msg_combat", ({
  (: command,"angry" :),
  (: command,"say 別打擾我休息！" :),
  (: command,"hmm" :),
}));
	set_skill("fork", 60);
	set_skill("parry", 70);
	set_skill("unarmed", 76);
	set_skill("dodge", 65);

        setup();
	carry_object(__DIR__"wp/halbert")->wield();
	carry_object(__DIR__"eq/tg_boots")->wear();
	carry_object(__DIR__"eq/tg_armor")->wear();
}

void init()
{

	object ob;
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	::init();
}

void greeting(object me)
{
	string gender;
	if( me->query("gender") == "男性" )
		gender = "小子";
	else gender = "小妹";
	if( random(100) < 10 )
	{
		message_vision("$N似乎看到了$n偷偷摸摸的進來了這個地方。\n",this_object(),me);
		message_vision("$N不太客氣的對$n說："+gender+"，這可不是給你進來玩的地方！\n",this_object(),me);
	}
	else tell_object(me,"你似乎偷偷摸摸的進來沒有給"+this_object()->name(1)+"看到！\n");
}

string drink()
{
	string msg;
	if( environment(this_object())->query("level") == "tower_1" )
	{
		msg = this_object()->name(1)+"拿起桌上的茶水開始咕嚕咕嚕開始喝了起來...\n";
		message_vision("$N拿起桌上的茶水開始咕嚕咕嚕開始喝了起來...\n",this_object());
		this_object()->receive_heal("ap",30);
	}
	return msg;
}

string eat()
{
	string msg;
	if( environment(this_object())->query("level") == "tower_1" )
	{
		command("unwield halbert");
		message_vision("$N放下手中東西，拿起中上乾糧，吃了起來...\n",this_object());
		msg = this_object()->name(1)+"放下手中東西，拿起中上乾糧，吃了起來...\n";
		this_object()->receive_heal("ap",40);
		this_object()->receive_heal("hp",40);
		call_out("wield_h",4);
	}
	return msg;
}

void wield_h()
{
	command("wield halbert");
	return;
}

void die()
{
	object ob, counter, room;
	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);
	if( !ob )
	{
		::die();
		return;
	}

	counter = find_object(__DIR__"counter.c");
	if( objectp(counter) )
		counter->query_bandit_war(1);
	else tell_object(ob,"錯誤: 請通知 Cominging 大大, 謝謝.\n");

	::die();
        //destruct(this_object());
        return;
}