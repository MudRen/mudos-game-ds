#include <ansi.h>
        
inherit ITEM;

void create()
{
        set_name("�H������",({"crush-bone pith", "pith"}) );
        set_weight(80);
        set("long",@long
�o�O�@���q�H���ӫҨ��W���U�Ӫ�����Ať���Y�F�����H
�i��j�W�A�A�]���|�`�Ȥ���ΤF�C
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value",1);
        }
        setup();
}

void init() 
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me;
        if(arg != "pith")
                return 0;

        me = this_player();
        if(!me) return 0;
        if(me->is_ghost()) return 0;
        if(me->is_busy() || me->is_fighting() ) return notify_fail("�A�����ۡA�S���ŦY�o�ӡC\n");
 
        message_vision(CYN "$N�N$n����L�̡A�D���I�P�a�l�_�ӤF�C\n"NOR ,me, this_object() );
        tell_object(me, HIG"�Aı�o�D�`�i���F�Aı�o�Ѷ�U�Ӥ]���ȡC\n"NOR);
        me->start_busy(1);
        if(me->query_condition("fear") )
                me->apply_condition("fear",0);   
    destruct( this_object() );
    return 1;
}

