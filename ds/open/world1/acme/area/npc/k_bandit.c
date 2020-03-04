#include <ansi.h>
inherit NPC;
void create()
{
        set_name("金過涯", ({ "gin kore ya","gin","ya" }) );
        set("level", 15);
        set("race","人類");
        set("gender","男性");
        set("title","綠林大盜");
        set("age",40);
set("nokill",1);
        set_skill("blade", 30);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        set("long","他滿面陰森，臉上一絲表情也沒有。\n");
        set("chat_chance", 10);
        set("chat_msg",({
              "金過涯向北邊的山洞叫道：臭小子，我看你能躲到什麼時候！\n",
        }) );
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
              "金過涯向北邊的山洞叫道：臭小子，我看你能躲到什麼時候！\n",
        }) );
        setup();
        carry_object(__DIR__"wp/blade3.c")->wield();
}
void init()
{
        object ob;
        ::init();
        call_out("greeting", 3, ob);
if(this_player()->query("nokill")<1)
{
     this_object()->kill_ob(this_player());
}
}
void greeting(object ob)
{
  object me;
  me=this_player();
  if(me->query("evil") > 0 && me->is_fighting() )
  {
     message_vision("金過涯笑道：這位"+ RANK_D->query_respect(me) +"，原來是同道中人，請恕小弟先前的無禮。\n",me);
     message_vision("金過涯說道：大家停手吧！\n",me);
     me->remove_all_killer();
  }
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( !ob ) 
        {
                ::die();
                return;
        }
        ob->set_temp("killbandit",1);
        ::die();
        //destruct(this_object());
        return;

}
