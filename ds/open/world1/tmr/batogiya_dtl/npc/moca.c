#include <ansi.h>
#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("�ߦ� �i��", ({ "fuer moca", "moca"}) );
    set_race("human");
    set("age", 6);
    set("long", "���ۤ@����U�A�٦��f�n�A�@�ƨ����o�H���ˤl�C\n");
    set("title","�u�֤p�j�v");

    set("chat_chance", 20);
    set("chat_msg", ({
        "�ߦ� �i���F½��½�������D�b��ԣ...\n",
        "�ߦ� �i���L�̰�ᦳ��...\n",
    }));

    setup();
}

int accept_fight(object ob)
{
    do_chat("�ߦ� �i����ۧA���D�G�u���}�I�Oê�ۧڡI�v\n");
    return 0;
}

void relay_say(object ob, string arg)
{
    object item;

    if( ob->query_temp("quest/haha_quest1") == 2 && arg == "��Ÿ" )  {
        do_chat( ({ "�ߦ� �i�����D�G�u�@���ӧA�ѱo�y��Ÿ�z���̤p�l�ڡA��ڦ�����ƶܡH�v\n", }) );
        ob->set_temp("quest/haha_quest1", 3);
        return;
    }

    if( ob->query_temp("quest/haha_quest1") == 3 && arg == "�Ҿ�" ) {
        if( this_object()->query_temp("quest/give_item") ) {
            do_chat( ({ "�ߦ� �i�����D�G�u�@���ӧA�O�n�Ӯ��Ҿڪ��ڡA�S�h�[���e�w�g���H�Ӯ��L�F�C�v\n", }) );
            return;
        }

        do_chat( ({ "�ߦ� �i�����D�G�u�@���ӧA�O�n�Ӯ��Ҿڪ��ڡA�o�I���h�A�N�O�o�ӤF�C�v\n", }) );
        ob->set_temp("quest/haha_quest1", 4);

        if( file_size(__DIR__"obj/proof1.c") < 0 ) return;
        if( catch(item = new(__DIR__"obj/proof1.c")) ) return;

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
