#include <path.h>
#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name(HIB "�B"HIM"�P���R"NOR, ({ "oldgirl" }) );
        set("gender", "�k��" );
        set("age", 70);
        set("long","�o��Oking�������A�O�����������A�`��P����o���O�R�A�ѥ���
���y�W�٦����֪������A���S�X�g���F���֭����A��b�O�@��O�H�q�ت��H�A
��M�o�̯k�R���H�٬Oking�F�Aking�]��b�O�@�ө��֪��p�ġC\n
");
        set("level",70);
        set("attitude", "friendly");

        set("sell_list",([
                __DIR__"obj/pill" : 99999,
                __DIR__"obj/pill2" : 99999,
                __DIR__"obj/ttoopp": 99999,
                ALWAYS+"torch" : 5,
                ALWAYS+"newspaper" : 10,
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
                        say( "�ѥ������S�L�������R�o��" + RANK_D->query_respect(
ob) + "�Mking���b��I�i�ӳܪM���M�𮧤@�U�a�C\n");
                        break;
                case 1:
                        say( "�ѥ����ԩԦ�A�D�R�o��" + RANK_D
->query_respect(ob) + "�M�жi�жi�C\n");
 break;
case 2:
       say( "�ѥ������D�R�o��" + RANK_D->query_respect(ob) + "
�ӳܬݬݤѤs�]�د����I�I�n�ܣ��I�I�֨ӡC\n");
break;
}
}

