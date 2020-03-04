#include <ansi.h>
#include <npc.h>

inherit F_VILLAGER;

void create()
{
    set_name("��Ÿ", ({ "ha zhan", "zhan"}) );
    set_race("human");
    set("age", 6);
    set("long", "�ܤ�ʦӵu�A�����N�Ӥp�A�L���U���A�@�Ƨb�Y�b�����ˤl�C\n");
    set("title","�Q����");

    set("chat_chance", 20);
    set("chat_msg", ({
        "��Ÿ���Ѩg�S�G�u���|�L�ġI�I�v\n",
        "��Ÿ���Ѩg�S�G�u�S���u�ۡI�S�������I�v\n",
        "��Ÿ��A���D�G�u�i�H���ڧ�w�����j�ѡy�����x�z���B�M�ܡH�v\n",
        "��Ÿ��A���D�G�uť������y�֤p�j�z��W�����F�`���ҾڡA�����ڳsô�o�ܡH�v\n",
        "��Ÿ��ۤѵo�b�D�G�u�ڤ��򳣥i�H���n�A�ڥu�n������A�N��u��@���]�n�ڡ�v\n",
    }));

    setup();
    switch( random(5) ) {
        case 0: carry_object(__DIR__"obj/cloth")->wear(); break;
        case 1: carry_object(__DIR__"obj/armor")->wear(); break;
        case 2: carry_object(__DIR__"obj/belt")->wear(); break;
        case 3: carry_object(__DIR__"obj/boots")->wear(); break;
        case 4: carry_object(__DIR__"obj/gloves")->wear(); break;
    }

    switch( random(5) ) {
        case 0: carry_object(__DIR__"obj/blade")->wield(); break;
        case 1: carry_object(__DIR__"obj/dagger")->wield(); break;
        case 2: carry_object(__DIR__"obj/whip")->wield(); break;
        case 3: carry_object(__DIR__"obj/axe")->wield(); break;
        case 4: carry_object(__DIR__"obj/sword")->wield(); break;
    }

    carry_money("gold", 3);
}

int accept_fight(object ob)
{
    do_chat("��Ÿ��ۧA��D�G�u�u�}�I�Oê�ۧڡI�v\n");
    return 0;
}

void relay_say(object ob, string arg)
{
    if( arg == "�֤p�j" )  {
        do_chat( ({ "��Ÿ���D�G�u�A�{�ѡy�֤p�j�z�I�H�i�H���ڸ�o���ҾڶܡH�v\n", }) );
        ob->set_temp("quest/haha_quest1", 1);
        return;
    }

    if( arg == "�����x" || arg == "���B�M" )  {
        do_chat( ({ "��Ÿ���D�G�u�A�{�ѡy�����x�z�I�H�i�H���ڸ�L�n�ҾڶܡH�v\n", }) );
        ob->set_temp("quest/haha_quest2", 1);
        return;
    }

    if( arg == "�i�H" ) {

        if( ob->query_temp("quest/haha_quest1") == 1 ) {
            do_chat( ({ "��Ÿ���D�G�u���N�·ЧA���ڸ�֤p�j�n�Ҿڧa�C�v\n", }) );
            ob->set_temp("quest/haha_quest1", 2);
        }

        if( ob->query_temp("quest/haha_quest2") == 1 ) {
            do_chat( ({ "��Ÿ���D�G�u���N�·ЧA���ڸ򧺯��x�n�Ҿڧa�C�v\n", }) );
            ob->set_temp("quest/haha_quest2", 2);
        }
    }
}

int accept_object(object me, object ob)
{
    object item;

    if( is_fighting() ) {
        do_chat((: command, "say �O�n�I�S�ݨ�ڥ��b���[�ڡI" :));
        return 0;
    }

    if( ob->id("_HAHA_PROOF_1_") ) {
        if( file_size("obj/money/gold.c") < 0 ) return 0;
        if( catch(item = new("/obj/money/gold.c")) ) return 0;
        item->set_amount(5);

        if( item->move(me) ) {
            message_vision(HIW"$N�q�f�U�̱ǥX�F�@�Ƕ����A�����F$n�C\n"NOR, this_object(), me);
        } else {
            if( item->move(environment(me)) ) {
                message_vision("$N�q�f�U�̱ǥX�F�@�Ƕ����A�����F$n�A���O���b�a�W�F�C\n", this_object(), me);
            } else {
                destruct(item);
                return 0;
            }
        }
        me->delete_temp("quest/haha_quest1");

    } else if( ob->id("_HAHA_PROOF_2_") ) {
        if( file_size(__DIR__"obj/book.c") < 0 ) return 0;
        if( catch(item = new(__DIR__"obj/book.c")) ) return 0;

        if( item->move(me) ) {
            message_vision(HIW"$N�q�I�᮳�X�F�@���ѡA�����F$n�C\n"NOR, this_object(), me);
        } else {
            if( item->move(environment(me)) ) {
                message_vision("$N�q�I�᮳�X�F�@���ѡA�����F$n�A���O���b�a�W�F�C\n", this_object(), me);
            } else {
                destruct(item);
                return 0;
            }
        }
        me->delete_temp("quest/haha_quest2");
    } else { return 0; }

    message_vision("$N�g���D�G�u�z�����I�z�����I�����ڷ�w�F�I�v�C\n", this_object(), me);
    do_chat( ({ ( : destruct , ob : ), }) );

    return 1;
}
