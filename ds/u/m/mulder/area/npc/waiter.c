#include <path.h>

inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("�A�ȥ�", ({ "waiter" }) );
        set("gender", "�k��" );
        set("age", 22);
        set("long","�o�쥿�A�ȥ͹�A�L���C\n");
        set("level",1);
        set("attitude", "friendly");
        set("rank_info/respect", "�A�ȥ�");
        set("sell_list",([
	    __DIR__"obj/chicken_leg" : 30,
                __DIR__"obj/dumpling" : 30,
	    ALWAYS+"torch" : 50,
        ]) );
        setup();
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list","list");
        add_action("do_buy","buy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "�A�ȥͯ��}�}�a���D�R�o��" + RANK_D->query_respect(ob) + "�M�i�ӳܶR�ǭ����M�����L�a�C\n");
                        break;
                case 1:
                        say( "�A�ȥ͡M���D�R�o��" + RANK_D->query_respect(ob) + "�M�жi�жi�C\n");
                        break;
                case 2:
                        say( "�A�ȥͻ��D�R�o��" + RANK_D->query_respect(ob) + "�M�w����{�A�s���o�ȩ��I�C\n");
        }
}
