#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("胡買" , ({ "hu mai keeper","hu", "mai", "keeper" }) );
        set("level",20);
        set("race","人類");
        set("age", 33);
         set("no_fight",1);
        set("long","他是當鋪的掌櫃。\n");
        set("chat_chance",8);
        set("chat_msg",({
           "胡買邊清點帳冊上的帳目邊喃喃自語：最近城裡可來了不少人，賺了不少啊！\n",
           (:command("grin"):),
        }) );
        set("storeroom",__DIR__"shop_room");
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
  say("胡買滿臉笑容地說道：這位" + RANK_D->query_respect(ob) + "，需要買賣物品嗎?\n");
                        break;
                case 1:
  say("胡買說道：這位" + RANK_D->query_respect(ob) + "，請進∼請進∼\n");
                break;
        }
}


