#include <path.h>

inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("�ȩ��A�ȥ�", ({ "waiter" }) );
        set("gender", "�k��" );
        set("age", 24);
        set("long","�o��ȩ��A�ȥͥ����Ԧa�۩I�q�@�ɦU�a�Ӫ��ȫȭ̡C\n");
	set("level",1);
        set("attitude", "friendly");
        set("rank_info/respect", "�A�ȥ�");
	set("sell_list",([
		"/open/world1/tmr/area/npc/obj/manto" : 8,
		"/open/world1/tmr/area/npc/obj/torch" : 5,
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
                        say( "�A�ȥͯ��}�}�a���D�R�o��" + RANK_D->query_respect(ob) + "�M�i�ӳܪM���M�𮧤@�U�a�C\n");
                        break;
                case 1:
                        say( "�A�ȥͮ��_������M���D�R�o��" + RANK_D->query_respect(ob) + "�M�жi�жi�C\n");
                        break;
                case 2:
                        say( "�A�ȥͻ��D�R�w����{�p���M�аݻݭn�Ǥ���O�H\n");
                        break;
        }
}
