#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIG"顏輿"NOR,({"yen-eu","yen"}) );
        set("long","一個全身是傷的老人，兩眼好似充滿了悔恨，看來離死不遠了。\n");
	set("age",50);
	set("level",60);
	set("race","人類");
        
	set("chat_chance",8);
	set("chat_msg",({
		(:command("say 為什麼..為什麼我會那麼糊塗...."):),
		(:command("sigh"):),
		(:command("sob"):),
	})	);

	set("chat_chance_combat", 47);
	set("chat_msg_combat", ({
		(:command("say 我不能死！我還有沒做完的事，我絕對不能死！！"):),
	}) );
	set_skill("dodge",10);
	set_skill("block",10);
	set_skill("parry",10);
	set_skill("unarmed",100);
	set_skill("sword",100);

	set("talk_reply","我的傷已經沒救了...但是在我死之前有件重要的事...請...幫幫我...咳咳....好嗎?");
	setup();

	carry_object(__DIR__"area/naboo/npc/wp/lasersword")->wield();
}

void init()
{
        int i;
        object ob;
        ::init();
        i= this_object()->query("max_hp");
        this_object()->set("hp",i*9/10);
        ::init();
        add_action("do_kill","kill");
        add_action("do_backstab","backstab");
        add_action("do_steal","steal");
        add_action("do_nod","nod");
       this_object()->set("hp", 170);
}
void do_nod(object obj)
{

            command ("say 多謝這位...咳咳...這件事說來話長...");

            command ("sigh");
            command ("say 我本是摘星門主的至交...");
            command ("say 卻因聽信小人讒言而將摘星門中的重要信物偷了出來!");
            

            command ("say 咳咳....沒想到中途遇上了摘星門主....");
            command ("say 他沒發現我偷了這東西還很殷勤的招待我....");
            command ("say 我這狼心狗肺的東西怕他發現...");
            command ("say 咳咳....我竟然....我竟然...");
            say ("顏輿說到一半突然臉色變得很痛苦的樣子....\n");

            command ("say 我竟然趁他不注意時殺了他!!");
            command ("say 不僅如此....他弟子趕來救他...結果我..滅了他的摘星門...嗚嗚...");
            command ("cry");


            command ("say 我...那小人騙我說...把這東西...拿到這...鬼森林...");
            command ("say 就能進九寒天宮...得到至高無上的武林秘笈.......咳咳");
            command ("say 我竟然傻傻的相信了.....在這鬼森林找了好幾個月....");
            command ("say 結果....被一群妖魔鬼怪打成這樣......咳咳");


            command ("say 我現在快死了......才發覺到我被騙了....真是笨蛋....不是嗎?");
            command ("say 為了....一個謊....謊言....殺了至交....滅了摘..摘星門....枉費了...我...我一世為人...咳咳");
            command ("say 我..做..什麼..也..不能挽回了...至少...把那信物還給...摘星門...餘孤...");
            command ("say 叫..風..風無影....他是..摘星門的..大弟子..是玉兒的...咳咳");


            command ("say 如果你遇到....玉兒....告訴她....爹對不起她....對不起她...咳咳");
            this_player()->set_temp("quest/story",7);
            obj=this_object()->carry_object(__DIR__"obj/old_stone");
            if(obj->name()!="古老的石雕")
            {
               say ("顏輿拿出一個石雕，那石雕卻突然化為粉末！！只見顏輿呆呆的望著手上的粉末。\n");
               command ("say 老天連贖罪的機會也不給我......連贖罪的機會也不給我.....");
               say ("顏輿說著說著，聲音愈來愈低微....就這樣....帶著悔恨死了....\n");
               ::die();
             }
               else
             {
               command("give stone to " + this_player()->query("id") );
               command("say 拜託你...了.....這樣....我總算....了了...心願...");
               say("顏輿說完，一掌往自己的天靈\蓋\擊\落！！顏輿死了....\n");
               ::die();
              }
 
}
void do_last()
{  
  int dex,dodge;
  object me;
  me=this_player();
  dodge=me->query_skill("dodge");
  dex=me->query_dex(); 
  if((dodge+dex)<random(70))
  {

     message_vision(HIG"
              顏輿將全身的力量集中於劍上，奮力向$P擊去！！
              只見$P閃躲不及，一把長劍竟將$P連人帶甲刺穿！\n"NOR,me);
     me->die();
     say (GRN"顏輿一招使出，便停住不動，竟是死了，片片石屑隨風飛揚在此地。\n"NOR);
     ::die();
   }      
	else{
        message_vision(RED"\n顏輿奮力一擊不中，當場吐血數升，跌倒在地。\n"NOR,me);
 	me->start_busy(7);
        say (HIR"顏輿恨恨的說道：「老夫縱橫一世，竟斃命於此。報應啊！報應啊！但是這東西我絕不會讓它落入賊人手中！！」\n"NOR);
        say (HIR"顏輿站起來大吼一聲！雙手高舉向天，就這樣站著...死了...只見他手中\落\下\許\多石屑，隨著西風吹向天際。\n"NOR);

        ::die();
        }
}
int do_kill(string arg)
{ 
  object obj;
  obj=this_object();
if (arg != "yen" && arg !="yen-eu" )  return 0;
  if(!this_player()) return 1;
   if(environment(this_player())!=environment(obj)) return 1;
  say ("顏輿咬牙眥裂喊道：「可惡的賊子！我就算死也絕不屈服於你！！！」\n");
  do_last();
}  

