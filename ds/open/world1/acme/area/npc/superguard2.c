#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIR "�A���" NOR , ({ "guard" }) );
        set("title", HIG "�T�x" NOR);
        set("race","�H��");
        set("gender","�k��");
        set("age",35);
     set("level",30);
        set_skill("unarmed", 80);
        set_skill("parry", 70);
        set_skill("dodge", 80);
        set("long",
        "�L�O�O�@�ª�R�x���@�áA�ݨӪZ�\\�ä��z�C\n");
        set("chat_chance_combat",30);
        set("chat_msg_combat", ({
           "�A��óܹD�G�����������\n",
        }) );
        setup();
        carry_object(__DIR__"wp/fist")->wield();
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
    command("say �c��I�ǩR�ӡI�I");
         obj->kill_ob(me);
    command("follow "+me->query("id"));
  }
}
