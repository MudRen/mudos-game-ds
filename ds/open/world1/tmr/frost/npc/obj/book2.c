#include <ansi.h>
        
inherit ITEM;

void create()
{
          set_name("���D�C��-���ٳ�",({"against book", "book"}) );
        set_weight(80);
        set("long",@long
�o�O�D���D�ä��̦��W�u���D�C�ҡv�������ٳ��C���Y�O��
�F�Q�١B�ӤW�}���F�_���]�_�u�w�Ӵ��z���@�j�١B�Ӿ]��ѤQ
���Q�c�ηL�w�Ӹg�Q�ٵ��ٱ��C
�ʭ��ǥβ���g�ۤ@��Ť�A�����D��۩�(read)�|�o�ͤ���ơC
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
        add_action("summon_book", "read");
}

int summon_book(string arg)
{
        object me;
        if(arg != "�Ť�")
                return notify_fail("�A�Q�n������H\n");

        me = this_player();
    if(!me) return 0;
    if(me->is_ghost()) return 0;
 
    if(me->query("hp") < 100 )
          return notify_fail("�A�����骬�p���ΡA������X�g��C\n");

    message_vision(CYN "$N���_���D�C��-���ٳ��j�n���X�Q�٪����e�C\n"NOR ,me);
    if(me->query("evil") < -500 ) {
                tell_object(me,HIM"�Aı�o�]�O�q�A�餺�����������ͥX�ӡC\n"NOR);
                  me->receive_heal("mp", me->query("max_mp")/3);
                me->start_busy(1);
    } else {
                tell_object(me,HIC"�Aı�o�ߤ����c����F�\\�h�C\n"NOR);
                me->add("evil",-50);
                me->start_busy(1);
        }
    
    destruct( this_object() );
    return 1;
}

