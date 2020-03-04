#include <path.h>
inherit NPC;
inherit SELLMAN;

void create()
{
	set_name("���f�Ӧ��", ({"food man","man"}) );
	set("long", @LONG
�L�O�q�����g�簮�f���H��������H�A�M���B�z�U���������
�q���åB�c�檺�u�@�C
LONG
);
	set("race", "�H��");
	set("age", 210);
	set("level", 25);
        set("title","�����H");
        set("attitude", "peaceful");
        set("no_fight",1);
        set("storeroom", __DIR__"shop/shop1.c");
	set("sell_list",([
            __DIR__"obj/food1.c": 6,
            __DIR__"obj/food2.c": 6,
            __DIR__"obj/drink1.c": 6,
]));

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
        add_action("do_bespeak","bespeak");
}

void greeting(object ob)
{

        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "���: ������ݭn�O�H�Х�list(�س�...)�C \n");
                        break;
                case 1:
                        say( "���: �����d�̬O��q�P���B�Ӫ�����³��(�س�...)�C\n");
                        break;
        }
}


