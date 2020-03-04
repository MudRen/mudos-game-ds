#include <ansi.h>
inherit NPC;
void create()
{
        set_name("守衛", ({ "guard" }) );
        set("level", 10);
        set("race","人類");
        set("gender","男性");
        set("age",30);
        set_skill("parry", 20);
        set_skill("sword", 20);
        set_skill("dodge", 20);
        set("long","他是衙門裡值勤看守的守衛。\n");
        setup();
        carry_object(__DIR__"wp/sword2")->wield();
}
void init()
{
        object ob;
        ::init();
        if(!this_object()->visible(this_player())) return;
        call_out("greeting", 1, ob);
}
void greeting(object ob)
{
  object me,obj;
  me=this_player();
  obj=this_object();
  if(me->query_temp("SKYCITY/jail")>0)
  {
    command("say 惡賊！納命來！！");
    obj->kill_ob(me);
  }
  else {
    if(me->query_temp("SKYCITY/hatred")>0)
    {
      command("say 惡賊！納命來！！");
      obj->kill_ob(me);
    }
  }
}
