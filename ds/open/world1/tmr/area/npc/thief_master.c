inherit NPC;
#include <ansi.h>
#include <guild_mark.h>
void create()
{
	set_name("李貓", ({ "lee mou", "mou", }) );
	set("title", "神手");
	set("gender", "男性");
	set("age", 38);
	set("long",@LONG
你看到一個矮小的中年人正在若無其事的吹著口哨，可是你卻有
一種感覺，彷彿你的一舉一動他都能瞭如指掌。深遂的眼神顯示他曾
歷經過不少大風大浪。他就是人稱「神手」的大盜，李貓。

[ 若想加入小偷公會, 請輸入 join thief ]
[ 查閱小偷公會技能, 請輸入 list       ]
[ 如果你的工會信物遺失, 請輸入 apply  ]

LONG
	);
	set("attitude", "peaceful");
	set("level",40);
	set("evil",50);
	
	set_skill("unarmed", 95);
	set_skill("parry", 90);
	set_skill("dodge", 100);
	set_skill("dagger",92);
	set_skill("combat_backstab",61);
	set_temp("apply/armor",38);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
		(:command("exert combat_backstab"):),
		(:command("grin"):),
      }) );

	
	//公會設定
	
	set("class","thief");
	set("adv_class",1);
	set("class1","thief");
	set("no_check_class",1);
	set("guild_gifts",({3,3,4,10}));
	set("guild_skills",([
        "dagger":   ({100,4,95}),
       "bow":      ({130,3,80}),
        "blade":    ({120,3,70}),
        "sword":    ({130,3,60}),
        "dodge":    ({90,4,95}),
        "parry":    ({130,3,70}),
        "sneak":    ({100,4,95}),
        "hide":     ({100,4,90}),
        "backstab":     ({110,3,90}),
        "peep":     ({110,4,90}),
        "stealing":     ({120,3,90}),
        "perception":   ({130,4,90}),
        "organization": ({120,4,90}),
	"free_action":	({180,2,40}),
	])  );

	setup();
	carry_object(__DIR__"eq/boots12")->wear();
	carry_object(__DIR__"eq/cloth31")->wear();
        carry_object(__DIR__"wp/bloodneedle")->wield();
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
	add_action("do_advance","advance");
	add_action("do_join","join");
	add_action("do_check_mark","apply");
}

int do_check_mark(string arg)
{
	object me,ob,mark;
	me=this_player();
	if(mark=present("mulit-function dagger",me)) return notify_fail("你已經有萬能匕首了。\n");
	
	if(me->query("class1")!="thief") return notify_fail("你並沒有參加小偷公會的紀錄。\n");

	ob=new(THIEF_MARK);
	if(!ob->can_move(me))
	{
		destruct(ob);
		return notify_fail("你必須丟掉一些東西才拿的動本公會信物。\n");
	}
	ob->move(me);
	message_vision("$N拿了一"+ob->query("unit")+ob->name()+"給$n。\n",this_object(),me);
	me->save();
	return 1;

}

int do_skill_list(string arg)
{
	return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);	
}

int do_skill_train(string arg)
{
	return GUILDMASTER->do_skill_train(this_object(),this_player(),arg);
}

int do_join(string arg)
{
	int i;
	string guild_rank, title;
	object ob, me, mark;

	ob = this_object();
	me = this_player();
	mark=new(THIEF_MARK);

	if(me->query("evil")<50) return notify_fail("你太善良了不適合加入本公會。\n");
	if(me->query_max_encumbrance()<mark->query_weight()+me->query_encumbrance())
	{
		return notify_fail("你必須丟掉一些東西才拿的動本公會信物。\n");
	}
	i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);

	switch(i)
	{
	case 0:  return notify_fail("人物設定錯誤，請通知巫師幫忙解決。\n");
	case -1: return notify_fail("你已經加入其他公會了。\n");
	case -2: return notify_fail("你已經加入其他公會了。\n");
	case -3: return notify_fail("你不適合加入本公會。\n");
	case -4: return notify_fail("你目前的等級不適合加入本公會。\n");
	case -5:
	case -6:
	case -7: return notify_fail("你的條件不適合加入本公會。\n");
	case -8: return notify_fail("沒有這種職業。\n");
	}
	if( !guild_rank = this_object()->guild_rank(me) || guild_rank=="")
			guild_rank = "還很菜的新手小偷";
	me->set("guild_rank",guild_rank);
	if( !(title=me->query("title")) || title == "時空漂泊者" )
		me->set("title", "傳說中的第三隻手"); // ps這是多加的, luky 記得要改成你要的喔！！

	mark->move(me);
	message_vision("$N加入了小偷公會。\n",me);
	tell_object(me,ob->name()+"從口袋中拿出了一把"+mark->name()+"給你。\n");
	return 1;
}

int do_advance(string arg)
{
	object ob, me;
	string title;
	ob = this_object();
	me = this_player();
        if(me->query("class1")!="thief" )
                return notify_fail("你不是小偷公會的會員。\n");
        if( me->quert("level") > 25)
		return notify_fail("你無法在此提昇你的等級。\n");
        return GUILDMASTER->do_advance(ob,me,arg);

}
string guild_rank(object me)
{
	string rank;
	if( me->query("gender") == "女性" )
	{
		switch( me->query("level")/5 )
		{
			case 0: rank = "笨手笨腳的小女賊"; break;
			case 1: rank = "四處流竄的小女賊"; break;
			case 2:	rank = "技術純熟的女飛賊"; break;
			case 3:	rank = "難以捉摸的女盜賊"; break;
			case 4:	rank = "橫行霸道的女大盜"; break;
			case 5:	rank = "神出鬼沒的女神偷"; break;
			default: rank = "神出鬼沒的女神偷";
		}
	}
	else
	{
		switch( me->query("level")/5 )
		{
			case 0: rank = "笨手笨腳的笨小偷"; break;
			case 1: rank = "動作靈活的小盜賊"; break;
			case 2:	rank = "技巧熟練的小飛賊"; break;
			case 3:	rank = "前科累累的老慣竊"; break;
			case 4:	rank = "橫行霸道的賊大哥"; break;
			case 5:	rank = "神出鬼沒神偷之王"; break;
			default: rank = "神出鬼沒神偷之王";
		}
	}
	return rank;
}

void die()
{
	object ob;
	if( !ob = query_temp("last_damage_from") )
	ob = this_player(1);
	if( !ob ) 
	{
		::die();
		return;
	}
	message("world:world2:vision",
HIC"\n  [本日頭條]:"HIW"\n\n\t"+ob->name(1)+"涉嫌殺害號稱「神手」的黑道分子李貓，警方目前正全力偵辦中。\n\n"+NOR
	,users());
	ob->add("popularity",3); //聲望
	::die();
	tell_object(ob,"  你得到一些聲望。\n");
	//destruct(this_object());
	return;
}
