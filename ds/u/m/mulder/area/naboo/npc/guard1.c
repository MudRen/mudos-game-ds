#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIC "警衛" NOR , ({ "guard" }) );
        set("title", HIW "Naboo護衛隊" NOR);
        set("race","人類");
        set("gender","男性");
        set("age",25);
       set("level",30);
        set_skill("gun", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        set("long",
        "他是一個負責保護Naboo城安全的人。\n");
      set("chat_chance",15);
        set("chat_msg", ({   
      (:command("reload clip"):),

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
      (:command("reload clip"):),
      (:command("shoot"):),
     	 }) );
        setup();
        carry_object(__DIR__"wp/blaster")->wield();
        carry_object(__DIR__"wp/bclip");
        carry_object(__DIR__"wp/bclip");
        carry_object(__DIR__"wp/bclip");
        carry_object(__DIR__"wp/bclip");
        carry_object(__DIR__"wp/bclip");

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
        command("say 說道﹕警衛也想殺?!去死吧!!!\n");

        ob=all_inventory(environment());
	for(i=0;i<sizeof(ob);i++)
	{
		ob[i]->soldier_assist(this_object(), me);
	}
	return 1;
}
void soldier_assist(object alert, object me)
{
          if(
             !living(this_object())
        ||      is_fighting(me) )
                return;

          switch(random(4)) {
        case 0: command("say 說道﹕兄弟們﹗幫忙拿下這個犯人﹗\n"); break;
        case 1: command("say 喝道﹕跑得了和尚跑不了廟，你還是快快束手就擒吧！\n"); break;
        case 2: command("say 喂﹗你想幹什麼﹖"); break;
        case 3: command("say 來人哪﹗拿下那個可疑的傢伙﹗"); break;
        }
        kill_ob(me);
        me->fight_ob(this_object());
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
  i=ob->query_temp("NABOO/hatred");
  if(ob->query_temp("NABOO/hatred")==0)
  ob->set_temp("NABOO/hatred",i+1);
        ::die();
        //destruct(this_object());
        return;

}










