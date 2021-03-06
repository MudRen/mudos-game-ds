/* 八極門 初級師父
 *
 * -By Tmr 
 * -Update 2002/02/22
 *
 */
inherit NPC;
inherit SSERVER;

#include <ansi.h>

void create()
{
    set_name("李書文", ({ "lee shu wen master", "master", "lee" }) );
    set("nickname", "神槍李");
    set("gender", "男性");
    set("class","fighter");
    set("age", 60);
    set("adv_class",1);
    set("class1","八極門");
    set("guild_gifts",({10,7,0,3}));
    set("long",
"李書文看來短小，卻給人相當精悍的感覺，一臉肅穆，令人望之生畏。\n"
"他更是現今「八極門」的第六代掌門，不僅精通八極拳，其大槍訣更是已達\n"
"登峰造極的境界，在江湖上是位極有名的一代宗師。\n"
    );
    set("attitude", "peaceful");
    set("level",40);
    set("guild_skills",([
        "bagi_fist":({150,3,60}),
        "horse-steps":({130,4,100}),
        "dodge" : ({120,2,60}),
        "parry" : ({120,3,70}),
        "unarmed":({110,3,80}),
        "fork":({120,3,70}),
        "da-fork":({150,3,60}),
    ])  );
    set_skill("unarmed", 100);
    set_skill("parry", 100);
    set_skill("dodge", 100);
    set_skill("fork",100);
    set_skill("bagi_fist",100);
    set_skill("da-fork",100);
    set_skill("horse-steps",100);
    set_skill("six_open",100);
        map_skill("unarmed", "bagi_fist");
        map_skill("fork", "da-fork");

        set("no_check_class",1);
        set("chat_chance",20);
        /*
        set("chat_msg",({
            "李書文口中說著「攉打頂肘」的歌訣，一面演練起來。\n",
            "李書文口中說著「抱打頂肘」的歌訣，一面演練起來。\n",
            "李書文口中說著「提腿」的歌訣，一面演練起來。\n",
            "李書文口中說著「單陽打」的歌訣，一面演練起來。\n",
            "李書文口中說著「胯打」的歌訣，一面演練起來。\n",
            "李書文口中說著「翻身小纏」的歌訣，一面演練起來。\n",
            "李書文振奮起精神，繼續練習「六大開」的六個基本招式。\n",
            }) );
*/


        set("chat_msg",({
          "李書文輕輕說道：「世與我而相違，復駕言兮焉求？」\n" ,
          "李書文輕輕說道：「世與我而相違，復駕言兮焉求？」\n" ,
          "李書文輕輕說道：「悅親戚之情話，樂琴書以消憂。」\n" ,
          "李書文輕輕說道：「已矣乎.......」\n" ,
        (:command("exert horse-steps twine-power"):),
          "李書文輕輕說道：「寓形宇內復幾時，曷不委心任去留，胡為遑遑欲何之？」\n" ,
          "李書文輕輕說道：「懷良辰以孤往，或植杖而耘耔，」\n" ,
          (:command("think"):),
          "李書文輕輕說道：「登東皋以舒嘯，臨清流而賦詩。」\n" ,
          "李書文輕輕說道：「聊乘化以歸盡，樂夫天命復奚疑。」\n" ,
        (:command("sigh"):),
         }) );

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
            (:command("exert bagi_fist"):), // 八極拳 特攻
            (:command("exert bagi_fist"):), // 八極拳 特攻
            (:command("exert six_open"):),  //  六大開 特攻
            (:command("exert da-fork"):),   // 大槍訣 特攻 
         }) );
    
    create_family("八極門", 6, "掌門人");
    set_temp("apply/armor", 100);
    set_temp("apply/damage", 150);

    setup();
    carry_object(__DIR__"eq/cloth")->wear();
      carry_object(__DIR__"eq/heave-boots")->wear();
        carry_object(__DIR__"eq/black-leggings")->wear();
    carry_object(__DIR__"wp/masterfork")->wield();
}


void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
	add_action("do_advance","advance");
	add_action("do_speak","speak");
	add_action("do_join","join");
}

int do_skill_list(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	return GUILDMASTER->do_skill_list(ob,me,arg);	
}

int do_skill_train(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
	int i;
	object ob, me;

	ob = this_object();
	me = this_player();
      if( me->id("ghost") ) return 0;
	message_vision("$N想加入「"+ arg+ "」。\n",me);	
	if(arg != "八極門") return notify_fail("李書文疑惑的看著你。\n");
	if(me->query("adv_class")) return notify_fail("你已加入門派了。\n");
	if(me->query_temp("can_join_bagi"))
	{
		i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
		switch(i)
		{
		case 1:
			me->set("adv_class",1);
			me->set("class1","八極門");
 			me->create_family("八極門",7,"俠客");
 			message_vision("$N加入了八極門。\n",me);
 			me->delete_temp("can_join_bagi");
			return 1;
		case -1: return notify_fail("你已有門派了。\n");
		case -2: return notify_fail("你已有門派了。\n");
		case -8: return notify_fail("沒有這種門派。\n");
		}
		return 0;
	}
	if(me->query_temp("eight_speak") )
		command("say 這位"+ RANK_D->query_respect(me) +"如不知那句話，就是在此跪了三天三夜，我也是不會收的。\n");
	else	
	{
		command("say 不敢當，如你能說出(speak)本門被江湖所盛傳的一句話，我就收了你吧");
		me->set_temp("eight_speak",1);			
	}

	return 1;
}

int do_speak(string arg)
{
	object me;
	me=this_player();

	if(!me->query_temp("eight_speak") )return 0;

	if(arg != "劈掛參八極，英雄歎莫及")
	{
		message_vision("$N大聲說出：「"+ arg +"。」\n",me);
		command("shake");
		command("say 不是不是，再想想吧。");
	}
	else
	{
		message_vision("$N大聲說出：「"+ arg +"。」\n",me);
		command("say 好，就是這句話，你可以加入「八極門」了！(join 八極門)。");
		me->set_temp("can_join_bagi",1);
 		me->delete_temp("eight_speak");
	}	
	return 1;

}

int do_advance(string arg)
{
	object ob, me;
	ob = this_object();
	me = this_player();
            if(me->query("level") > 24 && me->query("class2")=="八極門" )
          return notify_fail("你不是李書文的弟子。\n");
	if(me->query("class1")=="八極門" )
		return GUILDMASTER->do_advance(ob,me,arg);
	else 
		return notify_fail("你不是八極門的弟子。\n");
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
	message("world:world1:vision",
  HIG"\n【武林消息】" +HIW"一代宗師「神槍」李書文死在"+ob->name(1)+"的手中了。\n\n"+NOR
	,users());
	ob->add("popularity",1); //聲望
	::die();
	//destruct(this_object());
	return;
}
string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/10;     // 將 rank 分為六個層次

        if( me->query("gender") == "男性" )
        {
                switch( lv )
                {
                                // LV 1 ~ 9
                        case 0: rank = "八極門之初出茅蘆"; break;
                                // LV 10 ~ 19
                        case 1: rank = "八極門之略有小名"; break;
                                // LV 20 ~ 29
                        case 2: rank = "八極門之仗義江湖"; break;
                                // LV 30 ~ 39
                        case 3: rank = "八極門之俠氣遠播"; break;
                                // LV 40 ~ 49
                        case 4: rank = "八極門之揚名天下"; break;
                                // LV 50
                        default: rank = HIC "八極門之一代宗師" NOR;
                }
        }
        else
        {
                switch( lv )
                {
                                // LV 1 ~ 9
                        case 0: rank = "八極門之初出閏房"; break;
                                // LV 10 ~ 19
                        case 1: rank = "八極門之略有英名"; break;
                                // LV 20 ~ 29
                        case 2: rank = "八極門之仗義四海"; break;
                                // LV 30 ~ 39
                        case 3: rank = "八極門之英氣遠播"; break;
                                // LV 40 ~ 49
                        case 4: rank = "八極門之揚名天下"; break;
                                // LV 50
                        default: rank = HIC "八極門之一代女傑" NOR;
                }

        }
        return rank;
}

