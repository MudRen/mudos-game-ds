// NPC: /d/ruzhou/npc/xi-laifu.c  辦喜宴出現的喜來福老板
// llm 99/07/09

#include <ansi.h>

inherit NPC;
int ask_party();
void start_party(object ob,object me);
int do_start();
int do_serve();
void finish_party(object me,object ob);
int give_money(object me,object ob);
int do_kill(string arg);
int do_exert(string arg);
int do_steal(string arg);

void create()
{
	set_name("喜來福",({"xi laifu","xi","laifu" }));
   set("title", "迎賓樓老板");
   set("age", 42);
   set("gender", "男性");
   set("attitude", "friendly");
   set("combat_exp", 50000);
   set_skill("unarmed", 100);
   set_skill("dodge", 100);
   set_skill("parry", 100);
   set("per", 20);

	set("inquiry", ([
		"name": "喜來福呵呵笑道：“小可名字有點福氣，姓喜名來福，就是這里的老板。\n",
		"here": "喜來福搖頭晃腦地說：“我們迎賓樓可是方圓几十里的名樓，辦喜宴還得要來我們這里。”\n",
		"宴" : (: ask_party :),
		"喜宴" : (: ask_party :),
		"席" : (: ask_party :),
		"酒席" : (: ask_party :),
		"喜酒" : (: ask_party :),
		"酒宴" : (: ask_party :),
		"party" : (: ask_party :),
		]) );
   setup();
   carry_object("/d/beijing/npc/obj/pink_cloth")->wear();
}

void init()
{
   object me=this_player();
   ::init();
	if( interactive(me) && !is_fighting() )
   {
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
   add_action("do_serve", "kaixi");
   add_action("do_finish", "jieshu");
   add_action("do_start", "kaishi");
   add_action("do_kill", ({"kill","fight","hit","perform"}));
   add_action("do_steal", "steal");
   add_action("do_exert", "exert");
}

int greeting(object me)
{
	if( !me || environment(me) != environment() ) return;
   if(me->query_temp("married_party") )//新人
   {
   	write("喜老板對你拱手道：“喜宴布置得差不多了，等客人來齊了您問我喜宴就行了！”\n");
   }
   else if(!query_temp("party_finish"))//喜宴未結束，吃喜酒的人
   {
      write("喜老板點點頭：“喲！您來吃喜酒呀！新人的禮金由我代收，交給我就行。”\n");
   }
	else
   {
   	write("喜老板一拱手：“您吃好，慢走！”\n");
   }
   return 1;
}

int accept_object(object me, object ob)
{
   int i;
	if(query_temp("party_finish"))
   	return notify_fail("喜老板呵呵一笑：“您來遲了，喜宴已經結束了，您還是直接給新人吧！”\n");
   if (!ob->query("money_id"))
     	return notify_fail("喜老板皺了皺眉頭：“如今早就不時興送東西了，喝喜酒還是給現金的好！”\n");
   if(me->query_temp("marry_patty"))
   	return notify_fail("喜老板一愣，又笑道：“自己給自己送禮？也沒有這樣吃飽了撐著的事吧！”\n");
   i = ob->value();
   CHANNEL_D->do_channel(this_object(), "chat",
	   sprintf("%s恭賀%s和%s新婚大喜，送上賀禮"+MONEY_D->price_str(i)+"！\n",me->name(),query("name1"),query("name2")));
	add("chat_amount",1);//口水永遠不干
	add("money",i);//記錄送來的禮金數
   return 1;
}

int ask_party()
{
   object me,ob,wife;
   ob=this_object();
   me=this_player();
   if( me->query_temp("host_of_party") )
   {
   	message_vision("$N對$n說：“您的喜宴不是正在開著嗎？”\n", ob, me);
   	return 1;
   }
   if( (string)me->query("gender")=="女性" )
   {
     message_vision("$N笑著對$n說道：“媒婆是以新郎的名義在這訂酒席，還是叫你的丈夫來問吧！”\n", ob,me);
     return 1;
   }
	if( !me->query_temp("married_party") )
   {
   	message_vision("$N翻了翻帳本，對$n遲疑的問道：“媒婆好象沒有在我這里給您訂喜筵，會不會搞錯了？”\n", ob,me);
   	return 1;
   }
   if( !objectp(wife=present(me->query("couple/couple_id"), environment(me))) )
   {
   	message_vision("$N對$n說：新娘子都沒來，這喜宴怎么開？\n", ob,me);
      return 1;
   }
   if( ob->query_temp("ready_to_party") )
   {
   	message_vision("$N對$n不好意思的說：我這正開著一席呢，要不您明兒再來吧！\n",ob,me);
   	return 1;
   }
   if( (string)environment(ob)->query("short")!="喜福堂" )
   {
   	message_vision("$N對$n為難的說：“對不起，等我回店准備了再說吧！”\n",ob,me);
   	return 1;
   }
   if( me->query_temp("ready_to_ask") )
   {
   	message_vision("$N對$n不耐煩的說道：“不是都說了嗎？你怎么問個沒完！”\n",ob,me);
   	return 1;
   }
   me->set_temp("ready_to_ask",1);//新郎問過了的記號
   ob->set_temp("ready_to_party",1);//老板開始記號
   me->set_temp("host_of_party",1);//新郎的記號
   me->delete_temp("married_party");
   call_out("start_party",1,ob,me);
}

void start_party(object ob,object me)
{
   command("chat* "+name()+"一拱手道：“良宵一刻值千金，酒不醉人人自醉，今日迎賓樓榮幸地為" + me->query("name") +
		"\n大開喜宴，恭迎各位前來捧場！\n\n");
   message_vision("喜老板轉身又對$N小聲問了几句。\n",me);
   write("您要開始，就輸入 kaishi，如果想開席，就輸入 kaixi，\n"
   "大家吃飽了，喝足了就可以結束了(jieshu)。");
   me->delete_temp("ready_to_ask");
   me->set_temp("ready_to_party", 1);//新郎准備開始記號
}

int do_start()
{
   object me,ob,usr,obj,*list;
   int i;
   me = this_player();
	ob = this_object();

   if( !me->query_temp("host_of_party") )
     return notify_fail(name()+"對你說：“你又不是新郎官！喊什么喊？”\n");
   if( !ob->query_temp("ready_to_party") )
     return notify_fail(name()+"對你說：“開始什么呀，現在又沒人辦婚宴！”\n");
   if( me->query_temp("party_start_already") )
     return notify_fail(name()+"笑呵呵地對你說：“你看這不是已經開始了嘛！”\n");

   message_vision("$N對$n點點頭說：“喜老板，喜宴可以開始了！”\n\n"
		"$n立刻大聲喊著：“給客人上∼∼喜∼∼酒∼∼”\n\n",me,ob);
   me->set_temp("party_start_already", 1);//新郎已經開始記號
   me->delete_temp("ready_to_party");
   tell_room( environment(ob), HIY"喜老板又手一揮，几個彩衣樂手立刻吹起嗩吶、奏起喜樂。\n"NOR);

   list = all_inventory(environment(me));
   i = sizeof(list);
   while (i--)
   {
       usr= list[i];
       if( obj=new(__DIR__"obj/xijiu"))
       obj->move(usr);
   }
   tell_room(environment(usr), "\n從內堂走出一排漂亮的黃衫少女，依次走到每個人面前。\n"
		"黃衫少女遞給你一杯斟滿喜酒的玉盞又走開了去。\n");
   call_out("finish_party", 500, me,ob);
   return 1;
}

int do_serve()
{
   object ob=this_object();
   object me=this_player();
   object food;
   if( !me->query_temp("host_of_party") )
     return notify_fail(name()+"斜眼瞪了你一眼道：“主人沒說話，你嚷什么？！”\n");
   if( !me->query_temp("party_start_already") )
     return notify_fail(name()+"對你笑說：“還沒告訴我開始(kaishi)，我怎么好開席？”\n");

   message_vision("$N大聲嚷嚷著：上菜，上菜！\n", me);

   tell_room(environment(me), "“來啦！”四五個小伙計從內堂魚貫而出，一盤盤美味佳肴立刻擺上了桌。\n");
   if(food=new(__DIR__"obj/jiuyan"))
        food->move(environment(me));
   return 1;
}

int do_finish()
{
   object ob=this_object();
   object me=this_player();

   if( !me->query_temp("host_of_party") )
     return notify_fail(name()+"不滿意地瞪了你一眼：“你吃你的，不關你事不要亂說話！”\n");

   if( !me->query_temp("party_start_already") )
     return notify_fail(name()+"呵呵笑道：“喜筵不是已經結束了嗎！”\n");
   message_vision("$N對$n說道：“客人吃得都不錯，十分感謝喜老板的安排！”\n", me, ob);
   remove_call_out("finish_party");
   call_out("finish_party", 2, me,ob);
   return 1;
}

void finish_party(object me,object ob)
{
   int i;
   object *list,ob1,ob2,usr;

   message_vision(HIC"\n$N大聲說道：“小小薄宴，怠慢諸位，$n的喜宴就此結束，多謝大家光臨！\n"NOR, ob,me);
   command("gongxi " + me->query("id"));

   me->set_temp("party_finish",1);
   me->delete_temp("party_start_already");
   me->delete_temp("host_of_party");
	message("vision","\n一旁的黃衫少女連忙上來把酒席上的殘羹剩菜收拾干淨抬下去。\n",environment(me));
   if(ob1=present("jiuxi", environment(ob)))
      destruct (ob1);
   list = all_inventory(environment(ob));
   i = sizeof(list);
   while (i--)
   {
       usr= list[i];
       ob2=new(__DIR__"obj/xitang");
       ob2->set("name",me->name()+"和"+me->query("couple/couple_name")+"的喜糖");
       ob2->move(usr);
   }
   tell_room(environment(usr), "\n喜老板吩咐手下的伙計把喜糖一包包地發給每一個人。\n");
   remove_call_out("give_money");
   call_out("give_money",1,me,ob);
}

int give_money(object me,object ob)
{
	if( !me || environment(me) != environment(ob) )
   {
   	message_vision("喜老板突然向四周一看：“咦？人去哪里了，連代收的禮金都不要了？”一邊\n"
      "搖著頭一邊向內堂走去，伙計、黃衫少女也一齊走進去，喜福堂一下子空下來了。\n",ob);
		ob->move("/u/llm/workroom");//不要直接dest，以備查
	   return  1;
   }
   message_vision("\n喜老板笑呵呵地走到$N面前，一揮手，旁邊的小伙計捧過來一盤銀兩，喜老板說道：\n"
   "“這是小可代二位收下的客人送上的禮金，一共是"+MONEY_D->price_str((int)ob->query("money"))+"\n"
   "現在交給您，可得收好！”說完，將錢如數交給$N。然后一齊走進內堂不見了。\n",me);
	MONEY_D->pay_player(me,(int)ob->query("money"));
  	ob->move("/u/llm/workroom");//不要直接dest，以備查
	return 1;
}

int do_kill(string arg)
{
   object me = this_player();
   object ob = this_object();

   if(!arg || present(arg,environment(ob))!=ob) return 0;

   message_vision("$N臉色不大對，好象動了殺機！\n$n對$N直搖頭：這大喜的日子動手干什么啊！\n", me,ob);
   return 1;
}

int do_exert(string arg)
{
   object me = this_player();
   object ob = this_object();
   message_vision("$N鬼鬼祟祟地一運氣。\n$n對$N瞪了一眼，說：剛吃過飯，不要亂用內功！\n", me,ob);
   return 1;
}

int do_steal(string arg)
{
   object me = this_player();
   object ob = this_object();
   message_vision("$N伸出手，想要偷點什么。\n$n對$N罵道：怎可隨便光天化日施盜行竊！\n",me,ob);
     return 1;
}
