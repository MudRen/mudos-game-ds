inherit NPC;
inherit SELLMAN;

#include <ansi.h>

void create()
{
        set_name("�}�ڥ�", ({ "qu chen shi","qu","chen","shi" }) );
        set("title",HIY"�}�a��H"NOR);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);



 set("chat_chance",5);
 set("chat_msg", ({"�}�ڥܫܵL�᪺�θ}�y��F��a�W�����Y�C\n",
                "�}�ڥܤp�n�a���D�R�C���o�ӮɭԴN�Q�w�G�X�ӷ�p�c�D�D�D\n",
 }));
set("inquiry", ([
"�}��":"��A�ڨ��Ӵ�a��}���Ħ��������H\n",
]));
       setup();

        set("attitude", "friendly");

        set("sell_list",([
                __DIR__"obj/item01" : 50,
                __DIR__"obj/item02" : 50,
                __DIR__"obj/item03" : 50,
                __DIR__"obj/item04" : 30,
                __DIR__"obj/item05" : 30,
                __DIR__"obj/item06" : 30,
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
                        say( "�}�ڥ��i�v�v�a���D�R�o��" + RANK_D->query_respect(ob) + "�M�n���n�R�I�����]��l���H\n");
                        break;
                case 1:
                        say( "�}�ڥܫܵL�᪺�θ}�y��F��a�W�����Y�C\n");
                        break;
                case 2:
                      say( "�}�ڥܤp�n�a���D�R�C���o�ӮɭԴN�Q�w�G�X�ӷ�p�c�D�D�D\n");
                        break;
        }
}
