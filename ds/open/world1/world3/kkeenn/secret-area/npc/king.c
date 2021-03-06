#include <ansi.h>
inherit NPC;

void create()
{
        set_name("城市之主",({"the city master","master"}) );
        set("long",
"地下城之主, 在他歷盡滄桑買是皺紋的臉上, 不難看出一思思的憂傷。\n"
        );
        set("age",74);
        set("level",49);
        set("race","人類");
        set("attitude", "peaceful");
        set("chat_chance",5);
        set("chat_msg",({
                (:command("reload clip"):),
                "城主說道：「唉..這可怎麼辦才好阿...」。\n",
        }) );
        set("talk_reply","唉...小兄弟...你看的出我的[憂傷]嗎 ?\n");
        set_skill("gun",100);
        set_skill("doubleshoot",100);
                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (:command("exert doubleshoot"):),
                (:command("reload clip"):), 
 }) );
set("inquiry",([
  "憂傷" : "哀...你沒看到外面那隻[怪物]嗎。\n",
  "怪物" : "它阿...是百年前本城的[沒落主因]..",
  "沒落主因" : "因為它身上有著最完美的[控制晶片]",
  "控制晶片" : "那是我們祖先的精心傑作阿...小朋友, 請問你能[幫助]我嗎?",
  "幫助" : "你能幫我拿回它身上的晶片嗎?",            
]) );

        setup();                
carry_object("/open/world3/super-light-area/weapon/wp/mag.c")->wield();  
carry_object("/open/world3/super-light-area/weapon/wp/mag_clip.c");
carry_object("/open/world3/super-light-area/weapon/wp/mag_clip.c");
carry_object("/open/world3/super-light-area/weapon/wp/mag_clip.c");
}
void init()
{
  add_action("do_say","say");
}
int do_say(string str)
{
 object npc = this_object();
  if(!str) str = "...";
  if(strsrch(str,"能")!=-1)
  {
  if(npc->query("open_war"))
  {
    command("say 啊，真是太感謝你了。");
    command("say 去吧...我感應到它早就跑出來了");
    command("say 要小心它的部下歐....");   
    command("addoil");
    return 0;
  }
    command("say 啊，真是太感謝你了。");
    new(__DIR__"killer")->move(__DIR__"../hide.c");  
    new(__DIR__"soldier")->move(__DIR__"../hide.c");
    new(__DIR__"soldier")->move(__DIR__"../hide.c");
    new(__DIR__"soldier")->move(__DIR__"../hide.c");
    new(__DIR__"soldier")->move(__DIR__"../hide.c");
    new(__DIR__"soldier")->move(__DIR__"../hide.c");
    new(__DIR__"soldier")->move(__DIR__"../hide.c");
    new(__DIR__"soldier")->move(__DIR__"../hide.c");
   new(__DIR__"soldier")->move(__DIR__"../hide.c"); 
command("say 去吧...我感應到它已經跑出來了");
 command("say 要小心它的部下歐....");   
command("addoil");
  npc->set("open_war",1);
 return 1;
  }
  return 0;
}

int accept_fight(object who)
{
        if(!is_fighting())
        {
                command("angry");
                        }
        return 0;
}
int accept_object(object who,object ob)
{
 object ic, npc=this_object();
        if(ob->name()!="生化控制器")  return 0;
        else {
        message_vision("$N給了城主一片$n。\n",who,ob);
        destruct(ob);
        command("say 這可是那珍貴的晶片！！這.....這...");
        command("thank "+who->query("id"));
        command("say 這真是太感激你了。");
        command("say 好吧！那這樣我把剛開發出來的技巧晶片給你好了。");
        ic=new(__DIR__"obj/ic");
        ic->move(who);
        set("chat_msg",({
        "城主興奮地說道：終於, 終於拿回來了..\n",
        (:command("sob"):),            
        }) );
        set_temp("control",1);
      npc->delete("open_war");
        return 1;
        }
}
void reset()
{
        set("chat_msg",({
     "城主說道：「唉..這可怎麼辦才好阿...」。\n",
        }) );
        return;
}
void die()
{
        object ob;
        object data;      
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
     message("world:world3:vision",
HIG+"\n【地城快報】"+HIW+"地下城城主被"+ob->name(1)+"殺死了！！\n\n"+NOR,users());
           ob->add("popularity",1);
           data=new(__DIR__"obj/data.c");
   tell_object(ob,HIW"你從城市之主身上取得資料碟!!(You Get The Data!!)\n"NOR);
           data->move(ob);
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");  
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");
           new(__DIR__"guard")->move(__DIR__"../hide.c");   
     message("world:world3:vision",
HIG+"\n【地城快報】"+HIW+"地下城防衛隊全體出動清城了！！\n\n"+NOR,users());
        ::die();
        return;
}
