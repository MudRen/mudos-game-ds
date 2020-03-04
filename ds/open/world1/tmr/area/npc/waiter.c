#include <path.h>

inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("���p�G", ({ "waiter" }) );
        set("gender", "�k��" );
        set("age", 22);
        set("long","�o�쩱�p�G�����}�}�a���ۡM�٤��ɮ��_���b��l�W���٥����y�C\n");
        set("level",1);
        set("attitude", "friendly");
        set("rank_info/respect", "�p�G��");
        set("sell_list",([
                __DIR__"obj/manto" : 8,
                __DIR__"obj/bag" : 10,
                __DIR__"obj/soup":10,
          __DIR__"obj/game":10,
//              __DIR__"obj/hanoi":10,
              __DIR__"obj/guess":10,
                ALWAYS+"torch" : 5,
//        "/open/world1/moon_cake" : 20,   // ���������� 
         // "/open/world1/japan-susi" : 40, //�y�����ض���Ĺ�Ĥ@�����n������
          //"/open/world1/korea-pickles" :40,//�y�����ض���Ĺ�Ĥ@�����n������

                ALWAYS+"newspaper" : 10,
                  ALWAYS+"newspaper2" : 10,
                    ALWAYS+"scrollnote" : 10,


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
                        say( "���p�G���}�}�a���D�R�o��" + RANK_D->query_respect(ob) + "�M�i�ӳܪM���M�����L�a�C\n");

                        break;
                case 1:
                        say( "���p�G�β�l�W����y�٤F�٤�M���D�R�o��" + RANK_D->query_respect(ob) + "�M�жi�жi�C\n");
                        break;
                case 2:
                        say( "���p�G���D�R�o��" + RANK_D->query_respect(ob) + "�M�i�ӳܴX�ؤp�������s�a�M�o�X�Ѥ~�q���l�̶}�ʪ���C\n");
                        break;
        }
}

