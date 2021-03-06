#include <ansi.h>
inherit NPC;
void create()
{
        set_name("天梟守衛" , ({ "guard" }) );
        set("level",20);
        set("race","人類");
         set("gender","男性");
        set("age",30);
        set_skill("dagger", 50);
        set_skill("parry", 50);
        set_skill("bird-eight", 70);
        set_skill("sky-dagger", 40);
        set_skill("dodge", 80);
        map_skill("dagger","sky-dagger");
        map_skill("dodge","bird-eight");
        set("long","他是守護天梟派的護衛，看起來腳步沉穩，輕\功\不\錯\的\樣\子\,
但是他的肌肉不會很結實, 可見外家功\夫\尚\可。\n"
           );
        set("chat_chance", 200);
        set("chat_msg_combat",({
            "天梟守衛喝道：大伙上啊!不要讓這傢伙跑了!\n", 
        }) );
        setup();
        carry_object(__DIR__"eq/dagger.c")->wield();
        carry_object(__DIR__"eq/cloth.c")->wear();
        carry_object(__DIR__"eq/boots.c")->wear();
}
void init()
{
 object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}
void greeting(object ob)
{
 if( !ob || environment(ob) != environment() ) return;
 switch( ob->query("class1") ) {
  case "天梟教":
   command("talk with "+ob->query("id")+" about 師弟, 你可好呀！\n");
  break;

  default:
   say("天梟守衛對你說道：請尊客止步！\n");
  break;   
 }
}
