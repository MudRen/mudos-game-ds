#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ȤH" ,({ "traveler" }) );
        set("level",4);
        set("race","�H��");
        set("gender","�k��");
        set("age", 35);
        set("long", "�L�O�@�ӹC�M�@�ɦU�a���ȤH�C\n");
        set("evil",-10);
        set("str",6);
        setup();
        add_money("coin",100);
        carry_object(__DIR__"obj/map");
        carry_object(__DIR__"eq/boots1.c")->wear();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
 say("�ȤH���D�G�ǻ��Ѧ���誺�r���ߤW�|�o�X�G���A�����O�����٬O�_��\n");
  say("�ȤH���D�G�o��" + RANK_D->query_respect(ob) + "�٬O�ƨƤp�߬����C\n");
                        break;
        }
}

