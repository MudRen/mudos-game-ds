#include <ansi.h>
inherit NPC;
void create()
{
        set_name("帶刀護衛", ({ "guard" }) );
        set("level", 20);
        set("race","人類");
        set("gender","男性");
        set("age",30);
        set_skill("parry", 50);
        set_skill("blade", 50);
        set_skill("dodge", 50);
        set("long","他是衙門裡特允能帶刀守衛的官兵。\n");
        set("chat_chance", 8);
        set("chat_msg", ({
           (: random_move :),
        }) );
        setup();
        carry_object(__DIR__"wp/blade")->wield();
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