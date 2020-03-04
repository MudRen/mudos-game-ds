#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIC "常春霖" NOR , ({ "chun lin chang","chun","lin","chang" }));
        set("title", HIG "地方知府" NOR );
        set("race","人類");
        set("gender","男性");
        set("age",43);
        set("level", 20);
        set_skill("sword", 30);
        set_skill("parry", 40);
        set_skill("unarmed", 40);
        set_skill("dodge", 45);
        set("long",
           "他是地方命官，只見他醉醺醺的調戲著身旁的姑娘。\n");
        set("chat_chance_combat",30);
        set("chat_msg_combat", ({
                "常春霖喝道：你敢跟官府作對，不要命了是嗎！？\n",
                "常春霖喝道：來人呀！！把這反賊拿下了。\n",
                   "常春霖喝道：再不住手，我就抄你全家、誅你九族。\n",
        }) );
        setup();
}
void init()
{
        object ob;
        ::init();
        call_out("greeting", 1, ob);
}
void greeting(object ob)
{
  object me,guard1,guard2,guard3,obj;
  obj=this_object();
  me=this_player();
  if(me->query_temp("SKYCITY/hatred")>0)
  {
    if(me->query_temp("SKYCITY/hatred")>5)
    {
       if(obj->query_temp("callguard")==0)
       {
         obj->set_temp("callguard",1);
         command("say 惡賊！納命來！！");
         command("kill "+me->query("id"));
         say(YEL"常春霖大聲喝道：來人啊！把這反賊拿下了！\n");
           say("\n剎那間！不知從何竄出了三名錦衣衛！！\n\n"NOR);
         guard1=new(__DIR__"superguard");
         guard2=new(__DIR__"superguard2");
         guard3=new(__DIR__"superguard3");
         guard1->move("/open/world1/acme/area/hotel2f");
         guard2->move("/open/world1/acme/area/hotel2f");
         guard3->move("/open/world1/acme/area/hotel2f");
      me->set_temp("SKYCITY/hatred",1);
       }
    }
    else {
      command("say 惡賊！納命來！！");
      command("kill "+me->query("id"));
  }
}
}
void die()
{
        int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( !ob )
        {
                ::die();
                return;
        }
  i=ob->query_temp("SKYCITY/hatred");
  if(ob->query_temp("SKYCITY/hatred")==0)
  {
message_vision(HIC"\n  江湖傳出了一則驚人的消息:"HIW"朝廷命官常春霖被"+ob->name(1)+"殺死了。\n\n"NOR,ob);
message_vision(HIC"  天城眾官兵"HIR"嘶啞地吼著：可惡的"+ob->name(1)+"，膽敢與官府作對！！\n"NOR,ob);
message_vision(HIC"  天城縣老爺"HIR"大喝：眾將聽令，見"+ob->name(1)+"者，殺∼無∼赦∼∼！！\n"NOR,ob);
  }
        ob->set_temp("SKYCITY/hatred",i+1);
        ::die();
        //destruct(this_object());
        return;

}
