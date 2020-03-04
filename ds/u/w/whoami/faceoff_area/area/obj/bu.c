#include <ansi.h>
inherit NPC;
void create()
{
 set_name("步六弧",({"bu liu hu","bu","hu"}));
 set("long","他是在這村子裡最好的工匠。\n");
 set("age",56);
 set("gender","男性");
 set("level",30);
 set("title",CYN"巧手玲瓏仙"NOR);
 set_skill("parry",100);
 set_skill("dodge",100);
 set_skill("combat",100);
 set("chat_chance",20);
 set("chat_msg", ({"步六弧嘆道: 最近都沒有啥有趣的 "+HIG+"料子"+NOR+" 啊?.....\n",
                   (:command("sigh"):),
 }));
	set("chat_chance_combat",200);

	set("talk_reply","不知閣下...唉..算了算了... "+HIC+"那廝"+NOR+""+HIG+"可不好惹啊!\n"NOR);

	set("inquiry/料子","其實也不一定要是特定的東西, 只要有趣老夫一定給他把玩個個把時辰...:D.\n"NOR);

	set("inquiry/那廝","聽漁夫常說..最近常在海堤外的淺海看到過一種全身透有霞光的 "+HIG+"玲瓏魚.\n"NOR);

	set("inquiry/玲瓏魚","聽說玲瓏魚魚皮奇怪之至! 既薄且柔, 既柔且韌! 真想拿來玩玩...不過它的"+HIG+"習性"+NOR+"同樣也是奇怪之極...\n");

	set("inquiry/習性","玲瓏魚非得要有亮光之物才能吸引再將之捕捉, 可不知無砂有沒有這種東西??\n"NOR);

 set("chat_msg_combat",({                         
                         (:command,"hmm":),
 }));
 setup();
}


int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
if(ob->query("id") != "shark bone")
        {
           command("hmm "+who->query("id"));
           command("say 這可沒啥有趣的...-.-");
           return 0;
	}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
             message_vision("$N給了步六弧一段 "+ob->query("name")+"。\n",who);
             command("jump");
             obj->start_busy(10);
             obj->set_temp("givehelmet",1);
             destruct(ob);
             call_out("givehelmet",1,obj);
return 1;
    	    }

}

void givehelmet()
{
      int i;
      object me,obj,helmet;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givehat");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(CYN"步六弧興奮的看著鯊骨...口中連道: 有趣! 有趣!\n"NOR);
            obj->set_temp("givehelmet",i+1);
            call_out("givehelmet",2,me);
            break;
          case 2:
            command(CYN"say 嗯..." + RANK_D->query_respect(me) + " 你等一等.."NOR);
            obj->set_temp("givehelmet",i+1);
            call_out("givehelmet",2,me);
            break;
          case 3:
            say(CYN"步六弧轉身走進房間....。\n"NOR);
            obj->set_temp("givehelmet",i+1);
            call_out("givehelmet",3,me);
            break;
          case 4:
            say(CYN"過了一會你便聽到房中傳來一陣叫聲 : 成了! 成了!\n"NOR);
            obj->set_temp("givehelmet",i+1);
            call_out("givehelmet",2,me);
            break;
          case 5:
            command("say 這頂骨盔也堪稱老夫的傑作之一了..老夫留著也沒用..就給了你吧!!");
            obj->set_temp("givehelmet",i+1);
            call_out("givehelmet",2,me);
            break;
          case 6:
            helmet=new(__DIR__"eq/sky_cloth");
            helmet->move(obj);
            command("give cloth to "+ me->query("id") );
            say(HIY"王轑給了一頂鯊骨盔。\n"NOR);
            obj->delete_temp("givehelmet");
            break;
          }
}

