#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIC "警察" NOR , ({ "police" }) );
        set("title", HIW "Naboo警察" NOR);
        set("race","人類");
        set("gender","男性");
        set("age",25);
       set("level",15);
        set_skill("gun", 20);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        set("long",
        "他是一個負責保護Naboo城安全的人。\n");
      set("chat_chance",15);
        set("chat_msg", ({   
      (:command("reload clip"):),
    (: random_move :),

}) );
 set("chat_chance_combat", 150);
     set("chat_msg_combat", ({
      (:command("shoot"):),
      (:command("shoot"):),
      (:command("shoot"):),
      (:command("shoot"):),
      (:command("shoot"):),
      (:command("shoot"):),
      (:command("shoot"):),
      (:command("shoot"):),
     	 }) );
        setup();
        carry_object(__DIR__"wp/blaster")->wield();
        carry_object(__DIR__"wp/bclip");
       carry_object(__DIR__"wp/bclip");
  //      carry_object(__DIR__"wp/bclip");
 //       carry_object(__DIR__"wp/bclip");
//       carry_object(__DIR__"wp/bclip");

}
void init()
{
        ::init();
      add_action("do_kill","kill");
        if(!userp(this_player())) return;
        call_out("greeting", 0,this_player());
}
void greeting(object me)
{
  object obj;
  obj=this_object();
  if(!me) return;
  if(me->query_temp("NABOO/hatred")>0)
  {
    command("say 惡賊！納命來！！");
         obj->kill_ob(me);

  }
}

int do_kill(string arg)
{
        object *ob,me;
        int i;

        me=this_player();

        if (!arg) return 0;
        if(!objectp(present(arg, environment(me)))) return 0;
        
        if( is_fighting(me) ) return 0;
        command("say 說道﹕想殺人?!去死吧!!!\n");
        kill_ob(me);


        ob=all_inventory(environment());
	for(i=0;i<sizeof(ob);i++)
	{
		ob[i]->soldier_assist(this_object(), me);
	}
	return 1;
}












