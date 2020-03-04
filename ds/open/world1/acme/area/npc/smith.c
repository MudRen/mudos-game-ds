#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name( "���K�K", ({ "smith"}));
        set("long", "�o�O�@�쨯�Ԥu�@�����K�K�C\n\n"
                      + "  �ݦs�f�Х� <list> \n"
                     + "  �n�R�F��� <buy ���~> <buy �ƶq ���~> \n\n");
        set("level",3);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
        set("combat_exp",2000);         //�Լ�(���bmob level��100�����k���y)
        set("evil",-20);                //���c�� 20 (�������c, �t���})
        set_skill("hammer",10); 
        set("attitude", "peaceful");   //�ũM�� NPC�C
        set("talk_reply","���ʨ������A�ڳo�a���ҽ檺�Z���A�i�O�Ƥ@�ƤG���@�I");
        set("sell_list",([
           __DIR__"wp/sword":10,
           __DIR__"wp/dagger":10,
           __DIR__"wp/blade":10,
           __DIR__"wp/arrow":100,
           __DIR__"wp/axe2":10,
        ]) );
        setup();
          add_money("coin", 150);           //�a����
          carry_object(__DIR__"wp/hammer.c")->wield();
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
               say("���K�K���D�G�w����{�A�аݳo��" + RANK_D->query_respect(ob)
                                + "�M�ݭn�Ǥ���O?\n");
               break;
           case 1:
               say("���K�K���q�a���D�R�o��" + RANK_D->query_respect(ob)
                                + "�M�жi�жi�C\n");
               break;
           case 2:
               say("���K�K���D�G�o��" + RANK_D->query_respect(ob)
                                + "�M�ӶR��Z�������a�C\n");
               break;
        }
}
