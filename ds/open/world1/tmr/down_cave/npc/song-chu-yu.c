#include <ansi.h>
#include <npc.h>
inherit F_BANDIT;

string proof_file="/d/batogiya_dtl/npc/obj/proof2.c";

void create()
{
        set_name("���B�M", ({ "song chu-yu" ,"song","yu" }) );
        set("long",@long
    ���B�M�����@�I����F�m�ۡA���餼������ۧA�A���b�����a��
�q�A���W���]���A�n���@�I���W�n�W�e�m�ܤ@�ˡC���B�M���M������
��G�p�A�����W�Z�\���Z�A�u�O�׶q�U�p�A�S���ۨ��A��������̪�
�����C
long
);
        set_race("human");
        set("age", 30);
        set_stat_maximum("gin", 600);
        set_stat_maximum("hp", 600);
        set_attr("str",28);
        set_attr("cps",24);
        set_attr("cor",24);
        set_skill("blade",140 );
        set_skill("song blade" , 140 ); // ���a�M�k
        map_skill("blade","song blade");
        set_skill("parry",90);
        set_skill("dodge",90);
        set("attitude", "aggressive");
        set("title","�w�������Y��");
        setup();
        set_level(20);
        do_heal();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/yellow-cap")->wear();
        carry_object(__DIR__"obj/portable-boots")->wear();
        carry_object(__DIR__"obj/memory_card2");
}

void relay_say(object ob, string arg)
{
    object item;

    if( ob->query_temp("quest/haha_quest2") == 2 && arg == "��Ÿ" )  {
        do_chat( ({ "���B�M���D�G�u�@���ӧA�ѱo�y��Ÿ�z���̤p�l�ڡA��ڦ�����ƶܡH�v\n", }) );
        ob->set_temp("quest/haha_quest2", 3);
        return;
    }

    if( ob->query_temp("quest/haha_quest2") == 3 && arg == "�Ҿ�" ) {
        if( this_object()->query_temp("quest/give_item") ) {
            do_chat( ({ "���B�M���D�G�u�@���ӧA�O�n�Ӯ��Ҿڪ��ڡA�S�h�[���e�w�g���H�Ӯ��L�F�C�v\n", }) );
            return;
        }

        do_chat( ({ "���B�M���D�G�u�@���ӧA�O�n�Ӯ��Ҿڪ��ڡA�o�I���h�A�N�O�o�ӤF�C�v\n", }) );
        ob->set_temp("quest/haha_quest2", 4);

        if( file_size(proof_file) < 0 ) return;
        if( catch(item = new(proof_file)) ) return;

        if( item->move(ob) ) {
            message_vision(HIW"$N�q�I�᮳�X�F�@���ҾڡA�����F$n�C\n"NOR, this_object(), ob);
        } else {
            if( item->move(environment(ob)) ) {
                message_vision("$N�q�I�᮳�X�F�@���ҾڡA�����F$n�A���O���b�a�W�F�C\n", this_object(), ob);
            } else {
                destruct(item);
                return;
            }
        }

        this_object()->set_temp("quest/give_item", 1);
        call_out("reset", 900);
        return;
    }
}

void reset()
{
    this_object()->delete_temp("quest/give_item");
}

