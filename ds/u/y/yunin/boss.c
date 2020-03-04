#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("爛老闆" , ({ "bad boss" }) );
        set("level",20);
        set("race","人類");
        set("age", 33);
         set("no_fight",1);
        set("long","爛老闆一個\n");
        set("chat_chance",8);
        set("chat_msg",({
           (:command("smile"):),
        }) );
                setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_sell","sell");
  add_action("do_list","list");
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

  }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
  say("爛老闆說道：這位" + RANK_D->query_respect(ob) + "，需要買賣物品嗎?\n");
                        break;
                case 1:
  say("爛老闆說道：這位" + RANK_D->query_respect(ob) + "，請進∼請進∼\n");
                break;
        }
}

