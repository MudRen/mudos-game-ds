#include <ansi.h>
inherit NPC;
void create()
{
        set_name("劍無名" , ({ "the sword less name","name", "__GUARD__" }) );
 set("long", "他是幽冥地窖裡的大魔頭，個性殘暴不仁，嗜殺成性。\n");
        set("level",20);
set("exp",1500);
           set("combat_exp",2000);
        set("gender","男性");
        set("gender", "男性");
        set("race", "人類");
        set("age", 42);
        set("combat_exp",2000);         //戰熟(約在mob level的100倍左右為宜)
        set("env/wimpy", 20);           //逃跑wimpy (20%)
       set("evil",50);
           set_skill("sword",40);
          set_skill("parry",40);
           set_skill("dodge",40);
//    set_skill("darksword",40);
        set("chat_chance_combat",70);
        set("chat_msg_combat", ({
           (:command("exert darksword"):),
        }) );
        set("attitude", "aggressive");
        setup();
               carry_object(__DIR__"wp/sword.c")->wield();
            carry_object(__DIR__"eq/helmet.c")->wear();
}

void init()
{   
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() && this_object()->visible(this_player()) ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
          object me;
          me=this_player();
          if( !ob || environment(ob) != environment() ) return;
          {    
            command("hehe");
              say("劍無名大喝：狗賊！！去死吧！！\n");
            message_vision("劍無名趁$N不注意時，偷襲暗算$N，發招猛攻。\n",me);
            say("你看見劍無名手上的鐵椎急飛而來，眼見閃躲不及！！\n");
 message_vision(HIR "\n$N被鐵椎攻得措手不及，鐵椎刺進了$N的胸口。\n"NOR,me);
              me->receive_wound("body",8);
                  me->receive_damage("hp",20);
               set("attitude","killer");
          }
}
