#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("段福和" , ({ "fu han duan","duan" }) );
        set("level",20);
        set("race","人類");
        set("age", 33);
         set("no_fight",1);
        set("long","他是當鋪的掌櫃。\n");
        set("chat_chance",8);
        set("chat_msg",({
           "段福和拿著帳冊喃喃自語：今天可賺了不少啊！\n",
           (:command("grin"):),
        }) );
        set("storeroom",__DIR__"item/duanshop");
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
  say("段福和說道：這位" + RANK_D->query_respect(ob) + "，需要買賣物品嗎?\n");
                        break;
                case 1:
  say("段福和說道：這位" + RANK_D->query_respect(ob) + "，請進∼請進∼\n");
                break;
        }
}
