#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name( "���Y��", ({ "xin reu yue","xin","yue"}));
        set("long", "�o�O�o�a�������ѪO�C\n\n"
                     + "  �ݦs�f�Х� <list> \n"
                     + "  �n�R�F��� <buy ���~> <buy �ƶq ���~> \n\n");
        set("level",3);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 25);
        set("combat_exp",300);         //�Լ�(���bmob level��100�����k���y)
        set("evil",-20);                //���c�� 20 (�������c, �t���})
        set_skill("dodge",10);
        set("attitude", "peaceful");   //�ũM�� NPC�C
        set("sell_list",([
           __DIR__"eq/boots2":10,
           __DIR__"eq/cloth2":10,
           __DIR__"eq/hat2":10,
        ]) );
        setup();
          add_money("coin", 150);           //�a����
          carry_object(__DIR__"eq/cloth3.c")->wear();
}

void init()
{
  add_action("do_list","list");
  add_action("do_buy","buy");
{
       object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
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
               say("���Y�л��D�G�w����{�A�аݳo��" + RANK_D->query_respect(ob)
                                + "�M�ݭn�Ǥ���O?\n");
               break;
           case 1:
               say("���Y�Ю��q�a���D�R�o��" + RANK_D->query_respect(ob)
                                + "�M�жi�жi�C\n");
               break;
           case 2:
               say("���Y�л��D�G�o��" + RANK_D->query_respect(ob)
                                + "�M�ӶR�Ǩ�����a�C\n");
               break;
        }
}
