#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name( "������", ({ "pahafou innkeeper","innkeeper"}));
        set("long", "�@�Ӹ鲴�������ȩ�����A�@���ѹ����ѬO���P���P���b�A��
�f�U����...\n\n"
                      + "  �ݦs�f�Х� <list> \n"
                     + "  �n�R�F��� <buy ���~> <buy �ƶq ���~> \n\n");
           set("level",5);
        set("title","�ȩ�����");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 54);
        set("no_fight",1);
        set("combat_exp",500);         //�Լ�(���bmob level��100�����k���y)
//      set("env/wimpy", 20);           //�k�]wimpy (20%)
        set("evil",50);                //���c�� 20 (�������c, �t���})
        set("attitude", "peaceful");   //�ũM�� NPC�C
                   //�`�N. �n�]�w�f�~�M��
        set("sell_list",([
      __DIR__"obj/gmsoup" : 25,
          __DIR__"obj/hotwater" : 50,
        ]) );
           setup();
          add_money("coin", 120);           //�a����
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
               say("�����һ��D�G�f�¤f�¤f�¡��o��" + RANK_D->query_respect(ob)
                                + "�M�b���~�Ȧ��...�z�n���n���I��ü���{�l...�H\n");
               break;
           case 1:
               say( "��������b�ۤ��仡�ۡG�����o��" + RANK_D->query_respect(ob)
                                + "�M�}�ȵ}��...�̭����ڡC\n");
               break;
           case 2:
               say("�����Ҳ����m�ۧA���f�U�餼�������G�o��" + RANK_D->query_respect(ob)
                                + "�M�A�n�Ǥ����...\n");
               break;
        }
}


