//凌雲寺 進階 Master -By Tmr 2002/1/24-
#include <ansi.h>
// 2006.6.7 新增一機率性 EQ by Jangshow
// eq/ring-of-guard

inherit NPC;

void do_heal();
void do_heal2();
varargs int receive_damage(string type, int damage, object who);

void create()
{
        set_name("妙見",({"miao-jian bonze","bonze","master","miao-jian"}));
        set("gender", "男性");
        set("long",@LONG
妙見高僧為凌雲寺前任住持，畢生鑽研佛道，慧根深厚，中年時期因緣際會
習得佛門中第一絕技「如來九式」，自此佛、武二道互輔互長，修為幾以達
到「虹化」的境界。
LONG
        );
        set("level",60);
        set("age",80);
        set("race","tiger");
        set("adv_class",2);
        set("class1","凌雲寺");
        set("class2","凌雲寺");
        set("title","凌雲寺高僧");
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
         set_skill("constant-virtue",50);
		set_skill("buddha-skill",100);
		set_skill("wuchen-staff",100);
		set_skill("jingang-finger",100);
		set_skill("staff",100);
          map_skill("staff","buddha-skill");
        map_skill("unarmed","jingang-finger");

        set("inquiry", ([
			"如來九式" : "相傳佛祖為普渡眾生、解劫除危，留傳世人的一套曠世絕學！",
			"陣法" : "施主是要詢問老納有關"+HIY"「金剛羅漢陣」"+NOR CYN "的事情嗎？",
			"金剛羅漢陣" : "嗯....此乃為佛門中三大陣法之一，其奧妙可經由一份"+HIY"手卷"+NOR CYN"可學習到。",
			"手卷" : "此手卷由"+HIY"四金剛"+NOR CYN"守護在"HIY"凌雲峰頂" 
					   +NOR CYN"上，施主如佛緣深厚，不彷可去"+HIY "闖關"+NOR CYN"。",
			"四金剛":"此四金剛即為如來佛祖身體的四大護法使者，各具有神通力，對待奸邪妖魔是不留情面的。",
			"凌雲峰頂":"凌雲峰頂山勢險峻，非輕功\高超者，難以登上山頂。",
			"闖關":"如來佛祖所設下的試煉，心地善良、佛法深厚者，可通過四金剛的考驗，取得此陣法的手卷。"
			]) );

          set("chat_chance", 30);
        set("chat_msg",({
              (:do_heal2:),
		}) );
	
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
					(:do_heal:), 
					(:do_heal:), 
                        (:command("exert buddha-skill"):),

		}) );        
        
		set("guild_skills",([           // 難度, 等級1可學, 上限
                "buddha-skill":({200,4,100}),
                  "force":({130,4,100}),
                    "buddha-body":({130,4,70}),
        ]) );

             set("guild_gifts",({8,4,8,0}));
        set_temp("apply/armor",100);
        set_temp("apply/damage",50);
            set_temp("apply/shield",100);

        set("evil",-100);

		setup();
		carry_object(__DIR__"wp/hit-daemon")->wield();
		carry_object(__DIR__"obj/shelizi");
          set_temp("apply/wit", 2);     
        carry_object(__DIR__"eq/cloth.c")->wear();
          carry_object(__DIR__"eq/waist.c")->wear();
        carry_object(__DIR__"eq/helmet.c")->wear();
        carry_object(__DIR__"eq/boots.c")->wear();
        carry_object(__DIR__"eq/armor.c")->wear();
        carry_object(__DIR__"eq/hands.c")->wear();
        add_money("gold",5);



}

void init()
{
        add_action("do_say","say");
		add_action("do_skill_list","list");
		add_action("do_skill_train","train");
		add_action("do_guild_join","join");
        add_action("do_advance","advance");
}

int do_say(string arg)
{
	object me=this_player();
	object book;
	if(arg!="要求闖關" || this_object()->is_fighting() 	||me->is_fighting() )
		return 0;
	message_vision("$N說道：「要求闖關。」\n",me);
	// 等級不高
            if(!userp(me) || me->query("level") < 25)
	{
		message_vision("$N說道：「我想這位施主的功\夫還未到能闖關的程度吧。」\n",this_object());
		return 1;
	}
	// 已經有書了
	if( objectp( book=present("_BUDDHA_WAR_BOOK_",me)	)
		) 
	{
		message_vision("$N似乎不想理會$n。\n",this_object(),me);
		return 1;
	}
	book=new(__DIR__"obj/bore-book");
	message_vision("$N點了點頭，從懷裡拿了本書，在上面寫了幾個字，然後交給了$n\n",this_object(),me);
	book->set_warname(me->query("id"));
	//command("give " + me->query("id"));	
	book->move(me); 
	return 1;
}

// 戰鬥中療傷
void do_heal()
{
	object me=this_object();
	if(me->query("hp") < me->query("max_hp")/2)
	{
    do_heal2();
	} else {
		if(me->is_busy() ) return;
		if(me->query_temp("do_attack") ) return;
		message_vision(HIR "$N手中結了個「怒意金剛」佛印，登時攻勢劇增！！\n" NOR,me);
		me->set_temp("do_attack",1);	// mark 避免多次攻擊
		me->add_temp("apply/damage",50);
		me->add_temp("apply/hit",300);
			me->attack();
			me->attack();
		me->add_temp("apply/hit",-300);
		me->add_temp("apply/damage",-50);
		me->set_temp("do_attack",0);
	}

}

// 一般療傷
void do_heal2()
{
    object me=this_object();
    if(me->query("hp") < me->query("max_hp"))
    {
        message_vision(HIG "$N使出金剛伏魔指中的「雨天曼陀羅華」，左手小指迅速點住了身上的各個止血的穴道。\n" NOR,me);
         me->receive_heal("hp",1000);
    }
    else {
        switch(random(3)) {
                case 0: command("say 阿彌陀佛∼∼∼"); break;
                case 1: command("say 我為佛長子，惟垂分別說。"); break;
                default: command("say 如來佛祖體諒世間妖魔眾多，特留下一組「陣法」造福世人啊。");
        }
    }
}



// 吸除傷害
varargs int receive_damage(string type, int damage, object who)
{

        if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: 傷害種類錯誤( 只能是 hp, mp, ap其中之一 )。\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

		if(random(100)<30)
		{
              damage/=3;
			message_vision(HIY "$N渾厚堅實的護體金身化解了大半傷害。\n" NOR,this_object());

		}

		if(objectp(who) )
			::receive_damage(type,damage,who);
		else
			::receive_damage(type,damage,who);
		return damage;
}


// train skill  成功後 GUILDMASTER會自動呼叫
void train_skill_cost(object me,string argx)
{
        int cost;
        cost=me->query_skill(argx);
        cost-=1;
        if( cost<30 )   cost=1;
        else    if(cost<60) cost=2;
        else    if(cost<90) cost=3;
        else    cost=4;
        me->add("popularity",-cost);
        return;
}

// advance  成功後 GUILDMASTER會自動呼叫
void advance_cost(object me,string arg)
{
        int cost;
        if(!arg || arg=="level") {
                cost=(me->query("level")-21)*(me->query("level")-21);
                me->add("popularity",-cost );
                me->save();
                return;
        }
        else {
         if( me->query("popularity") < 3 ) {
                 me->set("popularity",0 );  
                 me->save();
         }
         else {
              me->add("popularity",-3);
              me->save();
              return;
         }
        }
}

int do_skill_list(string arg)
{
        return  GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        int j,lv,cost;
        object ob,me;
        ob = this_object();
        me = this_player();
        j=me->query("popularity");

        if(this_player()->query("class2") != "凌雲寺")
               return notify_fail("你並不是凌雲寺的和尚。\n");
        if(arg=="buddha-skill")
                lv=me->query_skill("buddha-skill");

            if(arg=="buddha-skill" || arg=="force" || arg=="buddha-body")
        {
	        cost=me->query_skill(arg,1);
		    if( cost<30 )   cost=1;
			else    if(cost<60) cost=2;
			else    if(cost<90) cost=3;
			else    cost=4;
	        if(lv==100)
		            return notify_fail("你已經到達登峰造極的境界了。\n");
			if( j < cost)
				    return notify_fail("看來妙見並不想指導你更深一層。(除非你有"+cost+"點聲望)\n");
			if( me->query("evil") > - 400)	 //　不夠善良
				    return notify_fail("由於你善性不足，妙見並不想指導你更深一層。\n");
        }
        return  GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_guild_join(string arg)
{
        object ob, me;
        int i;

        ob = this_object();
        me = this_player();

        if(!arg) return 0;
		message_vision("$N想加入"+arg	+"。\n",me);

        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
               case 0: break;
               case -1: notify_fail("你已是其他門派的徒弟了。\n");break;
               case -2: notify_fail("你已是其他門派的徒弟了。\n");break;
               case -8: notify_fail("此時此時並沒有這個門派。\n");break;
	    }
        if(arg!="凌雲寺" )
				notify_fail("此時此時並沒有這個門派。\n");
        if(me->query("class2")=="凌雲寺")
                return notify_fail("你已是凌雲寺的和尚了。\n");
        if( me->query("class1")=="凌雲寺" 
			&& me->query("level")==25 
			&& me->query("adv_class")==1 )
             {
                command("say 你修為深厚，老納就指導你更深的佛學吧。\n");
				ob->command("pat "+me->query("id") );
				message("world:world1:vision",
				HIY "\n\t【正道消息】：一代高僧「妙見」收了"+me->name(1)+HIY
				"為凌雲寺第四代弟子。\n"NOR
				,users() );
		        me->command("kneel bonze");
				me->set("class2","凌雲寺");
				me->create_family("凌雲寺",4,"弟子");
				me->set("adv_class",2);
        		return 1;
		}
        else return notify_fail("看起來妙見高僧並不想收你為徒。\n");

        return 1;
}


int do_advance(string arg)
{
          int j;
        object ob, me;

        ob = this_object();
        me = this_player();
        j=me->query("popularity");
        if(j < 3 ) 
			return notify_fail("你的聲望不夠。\n");
        if(me->query("class2") != "凌雲寺") 
                return notify_fail("你並不是凌雲寺的和尚。。\n");
        //新修正，adv level 扣聲望 (lv-20)^2
        if( (!arg || arg=="level") && j < (me->query("level")-20)*(me->query("level")-20) ) return notify_fail("你的聲望不夠。\n");
        else return GUILDMASTER->do_advance(ob,me,arg);
}

string guild_rank(object me)
{
        string rank;
        int lv;

        
		return "凌雲寺第四代弟子";

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

		tell_room( environment(),
			 HIG "\n妙見高僧臉露微笑，卻已再沒有動靜。\n"
			+HIY "\t只見妙見高僧七孔綻放七色虹光！！\n"
			+HIC "\t歷盡劫難得道，妙見高僧圓寂虹化，身軀幻化虹光飛天....\n"
			+HIM "\t芳香四溢，妙見面泛微笑地成佛登上西天極樂. \n\n" NOR		);

		message("world:world1:vision",
HIG"\n\t武林快報："HIW"佛門高僧「妙見」死在"+ob->name(1)+"的手中了！！！\n\n"+NOR


        ,users());

        ob->add("popularity",5);
          if( random(100) > 90 ) carry_object(__DIR__"eq/ring-of-guard.c");
          else if( random(100) > 95 )  carry_object(__DIR__"eq/five-thunder-ring.c");

/*
     switch(random(100))
     {
     case 0..3: b=new(__DIR__"eq/ring-of-guard"); 
     b->move(environment(this_object()));
     break;
     message_vision(HIW"$N臨雙眼一閤，隨即從袖口掉出了一樣東西"NOR,this_object());
     break;
     case 4..10: break;
     case 11..20: break;
     case 21..30: break;
     case 31..40: break;
     case 41..50: break;
     case 51..60: break;
     case 61..70: break;
     case 71..80: break;
     case 81..90: break;
     case 91..99: break;
     }
*/
        ::die();

        return;
}
