#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIR "錦衣衛" NOR , ({ "guard" }) );
        set("title", HIG "禁軍" NOR);
        set("race","人類");
        set("gender","男性");
        set("age",35);
     set("level",30);
        set_skill("fork", 80);
        set_skill("parry", 70);
        set_skill("dodge", 80);
        set("long",
        "他是保護朝近命官的護衛，看來武功\並不弱。\n");
        set("chat_chance_combat",30);
        set("chat_msg_combat", ({
           "錦衣衛喝道：殺∼殺∼殺∼∼\n",
        }) );
        setup();
        carry_object(__DIR__"wp/pike2")->wield();
        carry_object(__DIR__"eq/waist")->wear();
}
void init()
{
        object me;
        me=this_player();
        ::init();
        if(this_object()->visible(me)) call_out("greeting", 1, me);
}
void greeting(object me)
{
  object obj;
  obj=this_object();
	if( !me) return;
  if(me->query_temp("SKYCITY/hatred")>0)
  {
    command("say 惡賊！納命來！！");
         obj->kill_ob(me);
    command("follow "+me->query("id"));
  }
}
