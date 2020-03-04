#include <ansi.h>
        
inherit ITEM;

void create()
{
        set_name("�H�����",({"crush-bone blood", "blood"}) );
        set_weight(80);
        set("long",@long
�o�O�@���ѸH����b�~�H��G�����Ӧ�������C
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
        add_action("summon_book", "eat");
}

int summon_book(string arg)
{
        object me;
        if(arg != "blood")
                return 0;

        me = this_player();
    if(!me) return 0;
    if(me->is_ghost()) return 0;
         if(me->query("str") < 5) return notify_fail("�A�O��w�g���p�A���ݭn�A�Y�o�ӡC\n");
 
        message_vision(CYN "$N�Բ\\�r���N$n�]�U�{�̡C\n"NOR ,me, this_object() );
        tell_object(me, HIG"�Aı�o���u�W�٦׼@�h���ԡA�n���O���ܤp�F�C\n"NOR);
        me->set("str", me->query("str")-1);
        me->start_busy(1);
        me->save();
   
    destruct( this_object() );
    return 1;
}


