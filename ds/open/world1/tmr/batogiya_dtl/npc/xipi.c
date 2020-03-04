#include <ansi.h>
#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("���H��", ({ "ha xipi", "xipi"}) );
        set_race("human");
        set_attr("int", 30 );
        set_attr("str", 19);
        set_attr("cor", 17);
        set_attr("cps", 15);
        set_attr("dex", 18);
        set("title", "����");
        set("age", 20);
        set("long",@long
���H�֬O�������������A�Q���M���A�ݤH�ˤ��A�H�A�ȥ����H
�����w���A�n�O�A��������D�A���i�H��L�������C
long
);
        set("chat_chance", 5);
        set("chat_msg", ({
            "���H�֥��ۤѼL�̵o�X�u�H��H��v���n��...\n",
            "���H�����Y�L�ӡA��ۧA�o�X�u�H��H��v���n��...\n",
            "���H�ֹ�ۧA���D�G�u�H��H��аݧA��������D�ܡH�v\n",
            "���H�ֹ�ۧA���D�G�u�H��H��A���D�x�ܡH�v\n",
        }));
        setup();
}

void relay_say(object ob, string arg)
{
    object item;

    if( arg == "�D�x" )  {
        do_chat( ({ "���H�ֻ��D�G�u�u�n�A���ڤ@�ӳD�x�A�ڴN�|���A�@��n�F��C�v\n", }) );
        return;
    }
}

int accept_object(object me, object ob)
{
    object item;

    if( is_fighting() ) {
        do_chat((: command, "say �O�n�I�S�ݨ�ڥ��b���[�ڡI" :));
        return 0;
    }

    if( ob->id("_SNAKE_GALL_") ) {
        if( file_size(__DIR__"obj/snake_belt.c") < 0 ) return 0;
        if( catch(item = new(__DIR__"obj/snake_belt.c")) ) return 0;

        if( item->move(me) ) {
            message_vision(HIW"$N�q�I�᮳�X�F�@���D�ָy�a�A�����F$n�C\n"NOR, this_object(), me);
        } else {
            if( item->move(environment(me)) ) {
                message_vision("$N�q�I�᮳�X�F�@���D�ָy�a�A�����F$n�A���O���b�a�W�F�C\n", this_object(), me);
            } else {
                destruct(item);
                return 0;
            }
        }
    } else { return 0; }

    message_vision("$N�������ݵ�" + ob->short() + "���D�G�u�����A�ӴΤF�I��b�ܷP�E�z�ڡI�v\n", this_object() );

    do_chat( ({ ( : destruct , ob : ), }) );

    return 1;
}
