#include <ansi.h>
inherit NPC;
void do_ship(string arg,int flag);

void create()
{

        set_name( "�Ⲽ��" , ({ "trainman","man" }) );
        set("long",@long
�L�O�@�Ӿr�p�s���a�U����D�����a�U�K���Ⲽ���C�ݨӬ����Q���W�U
�A���y�ɮ᪺�ˤl�C�p�G�A�Q���q�����ܡA�аȥ��V�L�ʶR�����C
long
);

        set("age", 50);
        set("level", 5);
        set("gender","�k��");
        set("race","human");
        setup();
}

void init()
{
        add_action("do_buy","buy");
}

int do_buy(string arg)
{
        object me , ticket;
        me=this_player();
        if(!arg )
                return notify_fail("�A�Q�R����(ticket)�ܡH\n");
        if(arg!="ticket" )
                return notify_fail("�Ⲽ���u���c�R����(ticket)�C\n");
          message_vision("$N��F�������q�l���V�Ⲽ���n�O�F�q�l�����C\n",me);
        me->add("bank/future",-300);
          message_vision(MAG"$N�w�w���V�n���B���h....\n"NOR,me);
        me->move(__DIR__"../boot2.c");
        ticket=new(__DIR__"obj/ticket");
        ticket->move(me);
         me->start_busy(7);
        return 1;
}

