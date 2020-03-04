#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIC "守城官兵" NOR , ({ "garrison" }) );
        set("level", 20);
        set("race","人類");
        set("gender","男性");
        set("age",30);
        set("int", 25);
        set_skill("sword", 40);
        set_skill("parry", 30);
        set_skill("unarmed", 30);
        set_skill("dodge", 40);
        set("long",
   "一位守護城鎮的官兵，只見他眼神凝望遠方，不知是認真負責，還是想東想西。\n");
        setup();
        carry_object(__DIR__"wp/longsword1.c")->wield();
        carry_object(__DIR__"eq/boots.c")->wear();
        carry_object(__DIR__"eq/armor.c")->wear();
        carry_object(__DIR__"eq/ring.c")->wear();
        carry_object(__DIR__"eq/hat.c")->wear();
}
void init()
{
        ::init();
        if(!userp(this_player())) return;
        call_out("greeting", 0,this_player());
}
void greeting(object me)
{
  object obj;
  obj=this_object();
  if(!me) return;
  if(me->query_temp("SKYCITY/hatred")>0)
  {
    command("say 惡賊！納命來！！");
         obj->kill_ob(me);
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
	message_vision(HIR"  你聽到一聲帶著憤恨、驚恐的咆哮聲響徹整個天空。\n"NOR,ob);
	message_vision(HIC"  天城眾官兵"HIR"嘶啞地吼著：可惡的"+ob->name(1)+"，膽敢與官府作對！！\n"NOR,ob);
	message_vision(HIC"  天城縣老爺"HIR"大喝：眾將聽令，見"+ob->name(1)+"者，殺∼無∼赦∼∼！！\n"NOR,ob);
  }
  ob->set_temp("SKYCITY/hatred",i+1);
        ::die();
        //destruct(this_object());
        return;

}
