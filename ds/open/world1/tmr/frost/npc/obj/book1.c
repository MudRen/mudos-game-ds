#include <ansi.h>
        
inherit ITEM;

void create()
{
        set_name("���D�C��-�D�w��",({"morality book", "book"}) );
        set_weight(80);
        set("long",@long
�o�O�D���D�ä��̦��W�u���D�C�ҡv�����D�w���C���Y�}�v
���q�g�ۡu�ӤW���H�A�����G�D�w�F�䦸���j�G�����F�䦸���j
�G�өM�F�䦸���R�G�Ѧa�F�䦸���ۥG�����F�䦸�����G�j�t�C
�ҹD�w�A�ҥH�i�D�Ӥ��i��]�v�C
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
        object me, ob, env;
        if(arg != "�Ť�")
                return notify_fail("�A�Q�n������H\n");

        me = this_player();
    if(!me) return 0;
    if(me->is_ghost()) return 0;
    env = environment(me);
    if(!env) return 0;
 
        if(me->query("hp") < 300 )
                return notify_fail("�A�����骬�p���ΡA������X�g��C\n");

    message_vision(CYN "$N���_���D�C��-�D�w�����X�@�q�ֳ�ť�������g��...\n"NOR ,me);
    if( objectp(me->query_temp("summon_book")) ) {
            message_vision("���O����Ƥ]�S���o��...\n"NOR ,me);
            return 1;
     }
     
     ob = new_ob(__DIR__"book1_npc.c");
     if( !objectp(ob) ) {
            message_vision(HIR"\t�u���ѤU�ǨӤ@���n���G�X�j���D�F�A�гq���Ův�B�z�C\n"NOR ,me);
            return 1;
     }
     
     me->receive_damage("hp", 100);
     ob->set("name", me->query("name")+"���D�w��");
     ob->set_temp("no_combine",1);   //���}���
     ob->set("owner",me);          //�аO�D�H
     ob->set_leader(me);
     me->set_temp("summon_book", ob);
    ob->move( env );
    message_vision(HIW "�u��$N�⤤�����D�C��-�D�w�������ͩR��a�B�_�A�b$N���ǥ��ण���C\n"NOR ,me);
    destruct( this_object() );
    return 1;
}

