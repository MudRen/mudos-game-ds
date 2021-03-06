#include <ansi.h>
inherit NPC;

void create()
{
        set_name("軍醫",({"soldier's doctor","doctor"}) );
        set("long","\n");
        set("age",40);
        set("race","人類");
        set("level",25);
        set("attitude", "peaceful");
        set("gender", "男性" );
        set("chat_chance",6);
        set_skill("unarmed",80); 
        set_skill("dodge",80);
        set_skill("parry",80); 
        set_skill("dagger",80);
        set_temp("soldier",1);
        setup();
        add_money("coin", 1000);
}

void init()
{ 
  object me=this_player(),ob=this_object(),obj,env;
  env = environment(ob);
  ::init();
  if( !me->query_temp("soldier") ) return;
  command("say 你好像受傷了..");
  message_vision("$N幫$n治療了傷口•\n",ob,me); 
  return;
} 

int accept_object(object who, object ob)
{ 
  if( ob->query("id") == "secret bottle" && who->query_temp("ask_doctor") && !this_object()->query_temp("no_give") )
  {
    command("say 這是..?");
    call_out("poison",2,this_object()); 
    destruct(ob);    return 1;
  }

  tell_object(who,this_object()->name(1)+"似乎對"+ob->name(1)+"並不感興趣•\n");
  return notify_fail("");
  return 1;
}

void poison()
{
  object me=this_player(),ob=this_object();
  switch( me->query_temp("ask_doctor") ){
        case 1:
          message_vision(YEL"$N把小瓶子拿了起來，仔細的瞧了一會•\n"NOR,ob);
          me->add_temp("ask_doctor",1); 
          call_out("poison",6,this_object());
        break;
        case 2:
          command("ack");
          command("say 這東西是毒藥啊!!"); 
          me->add_temp("ask_doctor",1); 
          call_out("poison",2,this_object());
        break;
        case 3:
          command("say 你到底是從那裡拿到這麼危險的東西..");
          message_vision(YEL"$N把取得瓶子的經過，一五一十的都跟$n講了•\n"NOR,me,ob);          me->add_temp("ask_doctor",1); 
          call_out("poison",4,this_object());
        case 4:   
          command("say 這可不得了了..我去跟將軍報告這件事..");
          command("say 你就想辦法抓住那個狗賊吧");
          me->delete_temp("ask_doctor"); 
          me->add_temp("kill_cook",1);
          command("south"); 
          destruct(ob);
        break;            
  }
 return;
}
