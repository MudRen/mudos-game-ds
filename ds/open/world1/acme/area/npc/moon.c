#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name(HIM"�߮Z"NOR, ({ "the goddess of the moon","goddess","moon"}));
        set("long", "\n"
                    "�L�O��b��G�W�Y�����P�A���o�Q���нo�A\n"
                    "�B�`�`�a�ۯ��e�A�b�C�~������`�A�����\n"
                    "����L���ܼv�@�C\n"
           );
        set("level",1);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 20);
        set("evil",-20);                //���c�� 20 (�������c, �t���})
        set("attitude", "peaceful");   //�ũM�� NPC�C
        set("no_fight",1);
        set("sell_list",([
            __DIR__"obj/pomelo" : 10,
            __DIR__"obj/cake1" : 10,
            __DIR__"obj/cake2" : 10,
            __DIR__"obj/cake3" : 10,
        ]) );
        setup();
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
        switch( random(2) ) {
           case 0:
               say("�߮Z���D�G�o��" + RANK_D->query_respect(ob)
                                + "�M�ӶR�Ǥ��Y�Y�a�C\n");
               break;
           case 1:
               say("�߮Z���D�R�o��" + RANK_D->query_respect(ob)
                                + "�M�ӶR���c�l�Y�Y�a�C\n");
               break;
        }
}
