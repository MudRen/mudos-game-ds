#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�a�M�@��", ({ "guard" }) );
        set("level", 20);
        set("race","�H��");
        set("gender","�k��");
        set("age",30);
        set_skill("parry", 50);
        set_skill("blade", 50);
        set_skill("dodge", 50);
        set("long","�L�O�Ū��̯S����a�M�u�ê��x�L�C\n");
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
    command("say �c��I�ǩR�ӡI�I");
    obj->kill_ob(me);
  }
  else {
    if(me->query_temp("SKYCITY/hatred")>0)
    {
      command("say �c��I�ǩR�ӡI�I");
      obj->kill_ob(me);
    }
  }
}