#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("�����" , ({ "chan pan","chan" }) );
        set("level",20);
        set("race","�H��");
        set("age", 33);
         set("no_fight",1);
        set("long","�L�O��Q���x�d�A�����Q���ӤH�y�C\n");
        set("chat_chance",8);
        set("chat_msg",({
           "������ݵ۱b�U�������ۡG���ѥi�F�F���ֿ��ڡI\n",
           (:command("hehe"):),
           }) );
          set("storeroom",__DIR__"item/chanshop");
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
  say("��������D�G�o��" + RANK_D->query_respect(ob) + "�A�ݭn�R�檫�~��?�������椽�D\n");
                break;
                case 1:
  say("��������D�G�o��" + RANK_D->query_respect(ob) + "�A�жi��жi��\n");
                break;
                            }
}

