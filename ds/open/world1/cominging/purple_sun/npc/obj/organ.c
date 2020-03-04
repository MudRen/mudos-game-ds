#include <ansi.h>
        
inherit ITEM;

void create()
{
        set_name("�~����Ŧ",({"king organ", "organ"}) );
        set_weight(80);
        set("long",@long
�o�O�@�κ��¦�O�O����Ŧ�A���o�����ߪ�����C
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value",0);
        }
        setup();
}

void init() 
{
        add_action("summon_book", "eat");
}

int summon_book(string arg)
{
        object me;
        if(arg != "organ")
                return 0;

        me = this_player();
    if(!me) return 0;
    if(me->is_ghost()) return 0;
         if(me->query("int") < 5) return notify_fail("�A�w�g���¤F�A���ݭn�A�Y�o�ӡC\n");
 
    message_vision(CYN "$N�Բ\\�r���N$n�]�U�{�̡C\n"NOR ,me, this_object() );
        tell_object(me, HIG"�Aı�o���U���h���D�`�F�`�A�n���ܲ¤��֤F�C\n"NOR);
        me->set("int", me->query("int")-1);
    me->start_busy(1);
        me->save();
   
    destruct( this_object() );
    return 1;
}

