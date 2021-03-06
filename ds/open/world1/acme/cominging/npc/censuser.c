#include <ansi.h>
#define RENAME_MONEY            50000
inherit NPC;

void create()
{
	int x;
	x=random(2);
	set_name("王盛復",({ "shan-fu wang","wang","shan-fu","fu" }));
	set("long",
        "他是衙門裡專管戶政方面的官人，他可以任意的把一個人從一縣\n"
		"變成了另外一個地方的人，如果戶政官並不怎麼廉潔的話，有可\n"
		"能會有許\多人借此賄賂而改名換姓因而一直犯罪下去，他手上持\n"
		"著一本小簿子和拿著一隻小毛筆在批改人事，如果你想要換個好\n"
		"名字，也可以問他一下。\n"
	);
	set("title",HIC"滄縣戶政官"NOR);
	set("age",45);
	set("level",16);
	set("race","人類");
	set("gender","男姓");
	set("chat_chance",10);
	set("chat_msg",({
  (: command,"think" :),
  (: command,"say 這．．可就難了∼" :),
  name()+"搖搖頭，似乎想要放棄\n",
  name()+"拿著毛筆批改著小簿子裡面的資料\n",
}));
	set("chat_chance_combat",10);
	set("chat_msg_combat", ({
	   (:command("help!"):),
	   (:command("scream"):),
	   (:command("say 救命！！！"):),
}));
	set("inquiry",([
  "改名字" : "一個名字五兩黃金，貴的很！。改名(rename)\n",
  "改名" : "一個名字五兩黃金，貴的很！。改名(rename)\n",
  "換名" : "一個名字五兩黃金，貴的很！。改名(rename)\n",
  "尋人" : "你想問(query)誰呢?\n",
]));
	setup();
	carry_object(__DIR__"eq/cloth3")->wear();
	carry_object(__DIR__"eq/hat2")->wear();
	if( x==0 ) carry_object(__DIR__"wp/pen")->wield();
}

void init()
{
	add_action("do_rename","rename");
	add_action("do_query","query");
}
int do_query(string arg)
{
	object book;
	if(!arg) return notify_fail("您想要請戶政官幫你找誰呀？\n");
	if(arg=="小娟")
	{
		command("say 小娟? 嗯..我想想..一年前好像有這個人來找我改名..");
		command("hmm");
		command("say 對了!! 我記得她好像改名為葉..葉什麼來著?");
		command("think");
		command("say 葉..樺! 對了! 就是這個名字。");
		if(book=this_player()->query_temp("notebook"))
		book->add_quests_note("SadSworder","小娟已經改名為葉樺了。");
		return 1;
		
	}
	if(arg == "luky" || arg == "龍蝦")
	{
		command("say 你說的可是那個傳說中的大魔神?");
		command("scream");
		command("say 我可不敢談這個..說錯話可不得了");
		return 1;
	}
	command("dunno");
	command("say 我對這個名字沒印象。");
	return 1;
}

// 名字長度為六個中文字以內 - Shengsan@DS -
int do_rename(string arg)
{
	object me;
	me = this_player();

	if( !arg ) return notify_fail("您想要請戶政官幫你改成什麼名字呀？\n");
    if( !me->can_afford(RENAME_MONEY) )
       return notify_fail(name()+"對你說: 你恐怕付不出來這筆錢吧.. ? (50000文錢)\n");
	if( strlen(arg) > 12 )
		return notify_fail(name()+"對你說: 你名字太長了, 我寫不下...!!");
	if( strlen(arg) < 2 || strlen(arg)%2==1 )
		return notify_fail(name()+"對你說: 我看不懂ㄝ..");
	me->receive_money(-RENAME_MONEY);
	me->set("name",arg);
	me->save();
	return 1;
}

void die()
{
	int i;
	object ob;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);
	if( !ob ) 
	{
		::die();
		return;
	}
	
	i = ob->query_temp("SKYCITY/jail");
	ob->set_temp("SKYCITY/jail",i+1);

	::die();
//      destruct(this_object());
	return;
}
