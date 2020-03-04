#include <path.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("�p�c", ({ "seller" }) );
        set("gender", "�k��" );
        set("age", 24+random(5));
        set("long","�o��p�c�����}�}�a��z�L���F��M�٤��ɴ§A�o�̱�F��C\n");
        set("level",1);
        set("attitude", "friendly");
        set("sell_list",([
                __DIR__"obj/noodle" : 5,
                __DIR__"obj/water" : 8,
                __DIR__"obj/pill":8,
                ALWAYS+"torch" : 1,
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
                        say( "�p�c��A���D�R�o��" + RANK_D->query_respect(ob) + "�M�n���n�Ӥ@���W�����j�ɤY��?\n");
                        break;
                case 1:
                        say( "�p�c���D�R�o��" + RANK_D->query_respect(ob) + "�M�n���n�Ӥ@�J���N�n����?\n");
                        break;
        }
}

