#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("��Q�D�H" , ({ "master" }) );
        set("level",20);
        set("race","�H��");
        set("age", 33);
         set("no_fight",1);
        set("long","�N�O��Q���x�d��\n");
        set("chat_chance",8);
        set("chat_msg",({
           (:command("smile"):),
        }) );
        set("storeroom",__DIR__"seapop");
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
  say("��Q�D�H���D�G�o��" + RANK_D->query_respect(ob) + "�A�ݭn�R�檫�~��?\n");
                        break;
                case 1:
  say("��Q�D�H���D�G�o��" + RANK_D->query_respect(ob) + "�A�жi��жi��\n");
                break;
        }
}
