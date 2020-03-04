#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
        set_name("�ڿ�j�v", ({ "forget master", "master"}) );
        set_race("human");
        set("age", 80);
        set("long",@long
�o�O�@��w���歫���j�v�A��b��ǤW���y�ڵL�H�i�H�ǼġC
�㻡�L�w�ݳz�ͦ��A�i�H�o���L�h�A�w�����ӡC
long
);
        set("title","��V");
        set("chat_chance", 5);
        set("chat_msg", ({
                 "�ڿ�j�v�q�A���e�ƤF�L�h�A���S�q�A�I��ƤF�X�ӡA�u�O�޲�����...\n",
                 "�ڿ�j�v��ۧA���D�G�u�o��I�D���L�h������дo�ܡH�i�H��ѯǧڽͽͤ߳�...�v\n",
                  "�ڿ�j�v��ۧA���D�G�u���@�o��I�D���L�o���A�Q���@�w�a�]�U�e�a�A�n���n���I���o���O�H(exchange)�v\n",
         }));
        setup();
}

void init()
{
        ::init();
        add_action("do_exchange","exchange");
}

int do_exchange(string arg)
{
        object me,card;
        me = this_player();
    
        if( me->query("bank_money") < 10000000 )
                return notify_fail("�A���M�Q�n�����A���O�A�o�{�A���Ȧ�s�ڤ����C\n");
        me->add("bank_money", -10000000 );
        card = new("/d/cards/card-02.c");
        card->move( me );
        log_file( "CARD", sprintf("[%s] %s exchange �u�O�����L�h�v�C\n" , ctime(time()), geteuid(me) ) );
        message_vision( "$N���m�F�����o�����ڿ�j�v�A�]��o�F�@�i�d����������C\n" , me);
        return 1;
}


