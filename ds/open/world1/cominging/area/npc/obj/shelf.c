#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�Ѭ[", ({ "book shelf", "shelf" }));
        set("long", "�o�O�@�ӮѬ[, �W�����s�s�������X����, �A�i�H���ݦ��S������ѥi�H��. \n");
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("value", 1);
                set("no_sell", 1);
                set("no_sac", 1);
                set("no_get", 1);
        }
        setup();
}

void init()
{
        add_action("do_search", "search");
}

int do_search(string arg)
{
        object me = this_player(), book = new(__DIR__"oldman_book.c");

        if( !me->query_temp("get_book") )
                return 0;
        if( !this_object()->id(arg) )
                return 0;
        else if( me->query_temp("get_book") && this_object()->id(arg) && !this_object()->query_temp("no_book") )
        {
                message_vision(YEL"$N�b�Ѭ[�W��F��, ���G��������.. \n"NOR, me);
                tell_object(me, HIC"�A���F�@���p�U�l�I\n"NOR);
                book->move(me);
                me->delete_temp("get_book");
                me->set_temp("got_book", 1);
                set_temp("no_book", 1);
                set("long", "�o�O�@�ӮѬ[, �W�����s�s�������X����, ���G�̪񦳤H½�L. \n");
                call_out("delay", 600, this_object());
                return 1;
        }
        else if( me->query_temp("get_book") && this_object()->id(arg) && this_object()->query_temp("no_book") )
        {
                message_vision(YEL"$N�b�Ѭ[�W��F��, ���G�S������.. \n"NOR, me);
                return 1;
        }
        return 0;
}

void delay(object obj)
{
        delete_temp("no_book");
        set("long", "�o�O�@�ӮѬ[, �W�����s�s�������X����, �A�i�H���ݦ��S������ѥi�H��. \n");
        return;
}
