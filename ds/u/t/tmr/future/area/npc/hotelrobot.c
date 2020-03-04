#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
          set_name("�s�]����H",({"hotel robot","robot"}));
          set("long","�s�]���D�H�ۤv�b�h�~�e�s�y������H�A�ѩ�w�g���¤F�A\n"
                         "�ҥH�{�b�u�వ�@��²�檺�R��u�@�C\n"
          );
          set("age",50);
          set("level",1);
          set("sell_list",([
                 __DIR__"obj/alcohol"        : 50, 
                 __DIR__"obj/groundnuts"        : 50, 
                 __DIR__"obj/meat"        : 50,
        ]));
        set("chat_msg", ({
                "����H�N���~�M�����e��ȤH����W�C\n",
                "����H��B�b�M�z��W���U���C\n",
        }));
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
        switch( random(2) ) {
                case 0:
                        say( "����H���L�ӻ��D�R�w����{�M�Ӹոէڭ̪��s�a�C\n");
                        break;
                case 1:
                        say( "����H���R�o����q�u�H�M��u�@���N�ӷ����a�C\n");
                        break;
        }
}