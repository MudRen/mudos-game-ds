#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�u��", ({ "guard" }) );
        set("level", 10);
        set("race","�H��");
        set("gender","�k��");
        set("age",30);
        set_skill("parry", 20);
        set_skill("sword", 20);
        set_skill("dodge", 20);
        set("long","�L�O�Ū��̭ȶԬݦu���u�áC\n");
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
