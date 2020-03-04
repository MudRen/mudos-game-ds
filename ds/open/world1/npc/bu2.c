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
                   (:command("think 八岐大蛇.."):),
 }));
        set("chat_chance_combat",200);

        set("talk_reply","不知閣下...唉..算了算了... "+HIC+"那廝"+NOR+""+HIG+"可不好惹啊!\n"NOR);

        set("inquiry/料子","其實也不一定要是特定的東西, 只要有趣老夫一定給他把玩個個把時辰...:D.\n"NOR); 
        set("inquiry/八歧大蛇","對呀! 我最近對那什麼大蛇的很有興趣...用它來做東西..一定很有質感..:D.\n"NOR);
        set("inquiry/那廝","聽漁夫常說..最近常在海堤外的淺海看到過一種全身透有霞光的 "+HIG+"玲瓏魚.\n"NOR);

        set("inquiry/玲瓏魚","聽說玲瓏魚魚皮奇怪之至! 既薄且柔, 既柔且韌! 真想拿來玩玩...不過它的"+HIG+"習性"+NOR+"同樣也是奇怪之極...\n");

        set("inquiry/習性","玲瓏魚非得要能反光之物才能吸引再將之捕捉, 可不知無砂有沒有這種東西??\n"NOR);

 set("chat_msg_combat",({                         
                         (:command,"hmm":),
 }));
 setup();
}


int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->query("id") == "shark bone")
           {
                if(obj->is_busy() || obj->is_fighting())
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

                if(ob->query("id") == "clam shell")
           {
                if(obj->is_busy() || obj->is_fighting())
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
             message_vision("$N給了步六弧一個 "+ob->query("name")+"。\n",who);
             command("spank");
             obj->start_busy(10);
             obj->set_temp("giveshield",1);
             destruct(ob);
             call_out("giveshield",1,obj);
        return 1;
           }
        if(ob->query("id") == "light cloth")
           {
                if(obj->is_busy() || obj->is_fighting())
           {
             command("whisper "+who->query("id")+" 我正在忙，請你等一下。\n");
             return 0;
           }
             message_vision("$N給了步六弧一張 "+ob->query("name")+"。\n",who);
             command("jump");
             obj->start_busy(10);
             obj->set_temp("givecloth",1);
             destruct(ob);
             call_out("givecloth",1,obj);
        return 1;
           }

}     

void init()
{ 
  add_action("do_givehead","givehead"); 
  add_action("do_pray","pray");
} 
/* add by JS@DS */
int do_givehead(string arg)
{ 
     object me,ob,head;
     me=this_player();
     ob=this_object(); 
     
     if(arg=="orochi black head")
     {
     if(!objectp(head=present("orochi black head",me) ) )   
       {
       message_vision("步六弧嘆氣道：這不是我要的龍頭..\n",me); 
       }else{ message_vision("步六弧一鳴驚人：就....！就是這個！\n",me); ob->add_temp("black-head",1); 
              destruct(head);
              return 1;
            }  
     }
     if(arg=="orochi red head")
     {
     
     if(!objectp(head=present("orochi red head",me) ) )   
       {
       message_vision("步六弧嘆氣道：這不是我要的龍頭..\n",me); 
       }else{ message_vision("步六弧一鳴驚人：就....！就是這個！\n",me); ob->add_temp("red-head",1); 
              destruct(head);
              return 1;
            }   
     }
     if(arg=="orochi grey head")
     {
     if(!objectp(head=present("orochi grey head",me) ) )   
       {
       message_vision("步六弧嘆氣道：這不是我要的龍頭..\n",me); 
       }else{ message_vision("步六弧一鳴驚人：就....！就是這個！\n",me); ob->add_temp("grey-head",1); 
              destruct(head);
              return 1;
            }  
     }
     if(arg=="orochi green head")
     {
     if(!objectp(head=present("orochi green head",me) ) )   
       {
       message_vision("步六弧嘆氣道：這不是我要的龍頭..\n",me); 
       }else{ message_vision("步六弧一鳴驚人：就....！就是這個！\n",me); ob->add_temp("green-head",1); 
              destruct(head);
              return 1;
            }  
     }
     if(arg=="orochi blue head")
     {
     if(!objectp(head=present("orochi blue head",me) ) )   
       {
       message_vision("步六弧嘆氣道：這不是我要的龍頭..\n",me); 
       }else{ message_vision("步六弧一鳴驚人：就....！就是這個！\n",me); ob->add_temp("blue-head",1); 
              destruct(head);
              return 1;
            }  
     }
    if(arg=="orochi white head")
    {
     if(!objectp(head=present("orochi white head",me) ) )   
       {
       message_vision("步六弧嘆氣道：這不是我要的龍頭..\n",me); 
       }else{ message_vision("步六弧一鳴驚人：就....！就是這個！\n",me); ob->add_temp("white-head",1); 
              destruct(head);
              return 1;
            }  
    }
     if(arg=="orochi purple head")
     {
     if(!objectp(head=present("orochi purple head",me) ) )   
       {
       message_vision("步六弧嘆氣道：這不是我要的龍頭..\n",me); 
       }else{ message_vision("步六弧一鳴驚人：就....！就是這個！\n",me); ob->add_temp("purple-head",1); 
              destruct(head);
              return 1;
            }   
     }
     if(arg=="orochi gold head")
     {
     if(!objectp(head=present("orochi gold head",me) ) )   
       {
       message_vision("步六弧嘆氣道：這不是我要的龍頭..\n",me); 
       }else{ message_vision("步六弧一鳴驚人：就....！就是這個！\n",me); ob->add_temp("gold-head",1); 
              destruct(head);
              return 1;
            }   
     }
} 
/* add by JS@DS */
int do_pray(string arg)
{ 
    object me=this_player(),ob=this_object();
    if(ob->query_temp("black-head")!=1 ||
       ob->query_temp("red-head")  !=1 ||
       ob->query_temp("green-head")!=1 ||
       ob->query_temp("purple-head")!=1||
       ob->query_temp("white-head")!=1 ||
       ob->query_temp("gold-head") !=1 ||
       ob->query_temp("blue-head") !=1 ||
       ob->query_temp("grey-head") !=1  ) 
    {   message_vision("步六弧搖頭嘆道：還不夠.....\n",me);  
            return 1;
    } else {
    message_vision("步六弧語道：好！請等我一會兒\n",me);
            call_out("do_ggivehead",3,me); 
            ob->delete_temp("black-head",1); 
            ob->delete_temp("red-head",1);
            ob->delete_temp("green-head",1);
            ob->delete_temp("purple-head",1);
            ob->delete_temp("white-head",1);
            ob->delete_temp("gold-head",1);
            ob->delete_temp("blue-head",1);
            ob->delete_temp("grey-head",1); 
            return 1;
            }
}
void do_ggivehead()
{
   object me=this_player(),ob=this_object(),eq; 
    int i;
   i=random(99); 
   switch(i)
   {
case 0..3:
   message("world:world1:vision",HIG"步六弧"+HIW"完成了史上最終極的裝備─"+GRN"八歧"+RED"•"+HIY"龍眠\n"NOR,users());  
   message_vision("步六弧說道：這是我畢生最完美的作品，請您拿回去，這樣我已滿足了。\n"
                  "步六弧給了$N一樣東西\n",me);
   new(__DIR__"orocho-eq")->move(me);
   return; 
break;
case 4..33:
   message_vision("步六弧嘆道：不行呀.....我失敗了！壞了你的美意，真是過意不去..\n"
                  "步六弧黯然的轉身進入房內\n",me);
   destruct(ob);
   return;
   break;
   case 34..63:  
   message_vision("步六狐道：這些龍頭..損傷太嚴重，完重不能組裝起來\n");
   destruct(ob);
   break;
   case 64..99:  
   message_vision("步六狐道：這些龍頭..損傷太嚴重，完重不能組裝起來\n");
   return;
   break; 
   }}
void givehelmet()
{
      int i;
      object me,obj,helmet;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givehelmet");
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
            helmet=new_ob(__DIR__"../eq/bone_helmet");
            helmet->move(obj);
            command("give helmet to "+ me->query("id") );
            obj->delete_temp("givehelmet");
            break;
          }
}

void giveshield()
{
      int i;
      object me,obj,shield;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("giveshield");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(CYN"步六弧看著巨蚌殼, 沉吟半刻, 自言自語道: 想來這也有點趣味...\n"NOR);
            obj->set_temp("giveshield",i+1);
            call_out("giveshield",2,me);
            break;
          case 2:
            command(CYN"say 嗯..." + RANK_D->query_respect(me) + " 你等一等.."NOR);
            obj->set_temp("giveshield",i+1);
            call_out("giveshield",2,me);
            break;
          case 3:
            say(CYN"步六弧轉身走進房間....。\n"NOR);
            obj->set_temp("giveshield",i+1);
            call_out("giveshield",3,me);
            break;
          case 4:
            say(CYN"過了一會步六弧便從房中走了出來.\n"NOR);
            obj->set_temp("giveshield",i+1);
            call_out("giveshield",2,me);
            break;
          case 5:
            command("say 這一個巨蚌盾我留著也沒用, 就送給你吧!");
            obj->set_temp("giveshield",i+1);
            call_out("giveshield",2,me);
            break;
          case 6:
            shield=new_ob(__DIR__"../eq/clam_shield");
            shield->move(obj);
            command("give shield to "+ me->query("id") );
            obj->delete_temp("giveshield");
            break;

          }       
}

void givecloth()
{
      int i;
      object me,obj,helmet;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givecloth");
      if( !me || environment(me) != environment(obj) )
        {
                command("say 咦？" + RANK_D->query_respect(me) + "人呢？？");
                return;
        }
      switch( i ) {
          case 1:
            say(CYN"步六弧興奮的看著魚皮..口中連道: 就是這個!!\n"NOR);
            obj->set_temp("givecloth",i+1);
            call_out("givecloth",2,me);
            break;
          case 2:
            command(CYN"say 嗯..." + RANK_D->query_respect(me) + " 你等一等.."NOR);
            obj->set_temp("givecloth",i+1);
            call_out("givecloth",2,me);
            break;
          case 3:
            say(CYN"步六弧拿起魚皮, 轉身走進房間....。\n"NOR);
            obj->set_temp("givecloth",i+1);
            call_out("givecloth",3,me);
            break;
          case 4:
            say(CYN"過了一會你便聽到房中傳來一陣叫聲 : 成了! 成了!\n"NOR);
            obj->set_temp("givecloth",i+1);
            call_out("givecloth",2,me);
            break;
          case 5:
            command("say 這雙玲瓏靴實是人間極品, 就給閣下拿去闖蕩江湖吧!");
            obj->set_temp("givecloth",i+1);
            call_out("givecloth",2,me);
            break;
  
          case 6:
            helmet=new_ob(__DIR__"../eq/dex_boots");
            helmet->move(obj);
            command("give boots to "+ me->query("id") );
            obj->delete_temp("givecloth");
            break;
          }
}
