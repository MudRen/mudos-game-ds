#include <ansi.h>

inherit NPC;
void do_ship(string arg,int flag);

void create()
{
        set_name( "����" , ({ "trainman","man" }) );
        set("long",@long
�L�O�@�Ӿr�p�s���D�����q�Ϫ��a�U�K���C�����C�ݨӬ����Q���W�U
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
        object me;
        me=this_player();
        if(!arg )
                return notify_fail("�A�Q�R����(ticket)�ܡH\n");
        if(arg!="ticket" )
                return notify_fail("�����u���c�R����(ticket)�C\n");
        if(me->query_temp("dinkey_ticket") )
                return notify_fail("�A�w�g�R�L�����F�C\n");
return notify_fail("�K���I�u���A�{�b�Ȱ��Ⲽ�C\n");
          message_vision("$N��F�������q�l���V�����n�O�F�q�l�����C\n",me);
      me->receive_money(-300);
        me->set_temp("dinkey_ticket",1);
        return 1;
}

